/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#ifndef ROTATEFURNITURECOMMAND_H_
#define ROTATEFURNITURECOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/tangible/components/vendor/VendorDataComponent.h"
#include "server/zone/objects/tangible/components/EventPerkDataComponent.h"

class RotateFurnitureCommand : public QueueCommand {
public:

	RotateFurnitureCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

		if (ghost == NULL)
			return GENERALERROR;

		ZoneServer* zoneServer = creature->getZoneServer();
		ManagedReference<SceneObject*> obj = zoneServer->getObject(target);

		if (obj == NULL || !obj->isTangibleObject() || obj->isPlayerCreature() || obj->isPet()) {
			creature->sendSystemMessage("@player_structure:rotate_what"); //What do you want to rotate?
			return GENERALERROR;
		}

		ManagedReference<SceneObject*> rootParent = creature->getRootParent();

		BuildingObject* buildingObject = rootParent != NULL ? (rootParent->isBuildingObject() ? cast<BuildingObject*>( rootParent.get()) : NULL) : NULL;
		EventPerkDataComponent* data = cast<EventPerkDataComponent*>(obj->getDataObjectComponent()->get());

		// Allow admin to skip misc rules
		if (!ghost->isAdmin()){
			if (data != NULL) {
				EventPerkDeed* deed = data->getDeed();

				if (deed == NULL) {
					return GENERALERROR;
				}

				ManagedReference<CreatureObject*> owner = deed->getOwner().get();

				if (owner != creature) {
					return GENERALERROR;
				}

			} else if (buildingObject == NULL) {
				creature->sendSystemMessage("@player_structure:must_be_in_building"); //You must be in a building to do that.
				return GENERALERROR;

			} else {
				if (obj->isVendor() && !obj->checkContainerPermission(creature, ContainerPermissions::MOVEVENDOR)) {
					return GENERALERROR;
				}

				if (!obj->isVendor() && !buildingObject->isOnAdminList(creature)) {
					creature->sendSystemMessage("@player_structure:must_be_admin"); //You must be a building admin to do that.
					return GENERALERROR;
				}

				if (obj->getRootParent() != buildingObject || buildingObject->containsChildObject(obj)) {
					creature->sendSystemMessage("@player_structure:rotate_what"); //What do you want to rotate?
					return GENERALERROR;
				}

				if (buildingObject->isGCWBase()) {
					creature->sendSystemMessage("@player_structure:no_move_hq"); // You may not move or rotate objects inside a factional headquarters.
					return GENERALERROR;
				}
			}
		}
		
		// End general rules, handle input and rotation
		
		String dir = "";
		String deg = "";
		int degrees = 0;
		
		try {
			UnicodeTokenizer tokenizer(arguments.toString());
			tokenizer.getStringToken(dir);
			tokenizer.getStringToken(deg);
			
			// Prevent overlflow input values
			if (deg.length() > 4)
				throw Exception();
				
			degrees = Integer::valueOf(deg);
			
			if (abs(degrees) > 360)
				throw Exception();
			
			dir = dir.toLowerCase();
			
			// Setup rotation
			if (dir == "right"){
				obj->rotate(-degrees);
			}
			else if (dir == "left"){
				obj->rotate(degrees);
			}
			else if (dir == "yaw" || dir == "yxx"){
				obj->rotate(degrees);
			}
			else if (dir == "pitch" || dir == "pxx"){
				obj->rotateYaxis(degrees);
			}
			else if (dir == "roll" || dir == "rxx"){
				obj->rotateXaxis(degrees);
			}
			else if (dir == "reset" || dir == "xresetx"){
				obj->setDirection(1, 0, 0, 0);
			} else {
				throw Exception();
			}
			
		} catch (const Exception& e) {
			creature->sendSystemMessage("Error: /rotateFurniture command requires using the whole direction word and a number between -360 to 360.");
			creature->sendSystemMessage("Options: left right yaw pitch roll reset yxx pxx rxx xresetx");
			creature->sendSystemMessage("Examples: /rotate reset 1  ... /rotate left 45 ... /rotate pitch -270");
			return GENERALERROR;
		}
		
        // Apply rotation
        obj->incrementMovementCounter();
        if (obj->getParent() != NULL)
			obj->teleport(obj->getPositionX(), obj->getPositionZ(), obj->getPositionY(), obj->getParent().get()->getObjectID());
		else
			obj->teleport(obj->getPositionX(), obj->getPositionZ(), obj->getPositionY());

		return SUCCESS;
	}

};

#endif //ROTATEFURNITURECOMMAND_H_
