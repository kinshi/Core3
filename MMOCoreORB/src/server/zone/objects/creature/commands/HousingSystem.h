/*
				Copyright R. Bassett Jr.
		See file COPYING for copying conditions.*/

#ifndef HOUSINGSYSTEMCOMMAND_H_
#define HOUSINGSYSTEMCOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"

class HousingSystemCommand : public QueueCommand {
public:

	HousingSystemCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		if (!creature->isPlayerCreature())
			return GENERALERROR;

		ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

		if (ghost == NULL)
			return GENERALERROR;
			
		if (!ghost->isAdmin())
			return GENERALERROR;

		StringTokenizer args(arguments.toString());

		try {
			String command;

			if(args.hasMoreTokens()){
				args.getStringToken(command);	
			} else {
				throw Exception();
			}
			
			command = command.toLowerCase();
			
			if(command == "fixplotstatus"){
				housingFixPlotStatus(creature, &args);
			} else if (command == "fixplayerplotsused"){
				housingFixPlayerPlotsUsed(creature, &args);
			} else if (command == "fixplayertourstatus") {
				housingFixPlayerTourStatus(creature, &args);
			} else if (command == "testlayout"){
							testLayout(creature, &args);
			} else {
				throw Exception();
			}
			
		} catch (Exception& e){
			StringBuffer text;
			text << "Housing System Admin Commands:" << endl;
			text << "- - - - - - - - - - - - - - - - - - -" << endl;
			text << "/housingSystem FixPlotStatus [planetName] [site] [plot] [status]"  << endl;
			text << "- Fix a plot that gotten out of sync. Status: 0 or 1."  << endl;
			text << "/housingSystem FixPlayerPlotsUsed [playerStationID] [plotsUsed]"  << endl;
			text << "- Adjust how many HHS buildings a player owns by overwriting the value."  << endl;
			text << "/housingSystem FixPlayerTourStatus [playerID]"  << endl;
			text << "- Remove erroneous status of touring a structure, as touring prevents use of the system."  << endl;
			text << "/housingSystem testLayout [layoutName] [BuildingTypeNumber]"  << endl;
			text << "- Plop a mockup site into the world for several seconds to see how it looks."  << endl;
			text << endl;
			
			creature->sendSystemMessage(text.toString());
		}

		return SUCCESS;
	}

	// Test layout by placing it into the world for a few seconds.
	void testLayout(CreatureObject* creature, StringTokenizer* args) const {
		if (creature->getParent() != NULL){
			creature->sendSystemMessage("You must be outside to place a structure.");
			throw Exception();
		}

		String layoutName = "tatooineEstateSmall";
		String building = "1";
		int buildingNumber = 1;

		if(args->hasMoreTokens()){
			args->getStringToken(layoutName);
			args->getStringToken(building);
			buildingNumber = Integer::valueOf(building);
		} else {
			creature->sendSystemMessage("Usage: /hondo admin testlayout tatooineEstateSmall 1");
			throw Exception();
		}

		Lua* lua = DirectorManager::instance()->getLuaInstance();

		Reference<LuaFunction*> adminTestLayout = lua->createFunction("HondoHousingSystem", "adminTestLayout", 0);
		*adminTestLayout << creature;
		*adminTestLayout << layoutName;
		*adminTestLayout << buildingNumber;

		adminTestLayout->callFunction();
	}

	// /housingSystem FixPlotStatus [planetName] [site] [plot] [status]
	void housingFixPlotStatus(CreatureObject* creature, StringTokenizer* args) const {
		String planetName, site, plot, status = "";

		if(args->hasMoreTokens()){
			args->getStringToken(planetName);
			args->getStringToken(site);
			args->getStringToken(plot);
			args->getStringToken(status);
		} else {
			creature->sendSystemMessage("Usage: /hondo admin housingFixPlotStatus [planetName] [site] [plot] [status] \n Example: /hondo admin housingFixPlotStatus tatooine 15 2 1");
			throw Exception();
		}

		Lua* lua = DirectorManager::instance()->getLuaInstance();

		Reference<LuaFunction*> adminFixPlotStatus = lua->createFunction("HondoHousingSystem", "adminFixPlotStatus", 0);
		*adminFixPlotStatus << creature;
		*adminFixPlotStatus << planetName;
		*adminFixPlotStatus << site;
		*adminFixPlotStatus << plot;
		*adminFixPlotStatus << status;

		adminFixPlotStatus->callFunction();
	}

	// /housingSystem FixPlayerPlotsUsed [playerAccountID] [plotsUsed]
	void housingFixPlayerPlotsUsed(CreatureObject* creature, StringTokenizer* args) const {
		String playerAccountID, plotsUsed = "";

		if(args->hasMoreTokens()){
			args->getStringToken(playerAccountID);
			args->getStringToken(plotsUsed);
		} else {
			creature->sendSystemMessage("Usage: /hondo admin housingFixPlayerPlotsUsed [playerStationID] [plotsUsed] \n Example: /hondo admin housingFixPlayerPlotsUsed 476 1");
			throw Exception();
		}

		Lua* lua = DirectorManager::instance()->getLuaInstance();

		Reference<LuaFunction*> adminFixPlayerPlotsUsed = lua->createFunction("HondoHousingSystem", "adminFixPlayerPlotsUsed", 0);
		*adminFixPlayerPlotsUsed << creature;
		*adminFixPlayerPlotsUsed << playerAccountID;
		*adminFixPlayerPlotsUsed << plotsUsed;

		adminFixPlayerPlotsUsed->callFunction();
	}

	// /housingSystem FixPlayerTourStatus [playerID]
	void housingFixPlayerTourStatus(CreatureObject* creature, StringTokenizer* args) const {
		String playerID = "";

		if(args->hasMoreTokens()){
			args->getStringToken(playerID);
		} else {
			creature->sendSystemMessage("Usage: /hondo admin housingFixPlayerTourStatus [playerID] \n Example: /hondo admin housingFixPlayerTourStatus 281474993516370");
			throw Exception();
		}

		Lua* lua = DirectorManager::instance()->getLuaInstance();

		Reference<LuaFunction*> adminFixPlayerTourStatus = lua->createFunction("HondoHousingSystem", "adminFixPlayerTourStatus", 0);
		*adminFixPlayerTourStatus << creature;
		*adminFixPlayerTourStatus << playerID;

		adminFixPlayerTourStatus->callFunction();
	}
};

#endif //HOUSINGSYSTEMCOMMAND_H_
