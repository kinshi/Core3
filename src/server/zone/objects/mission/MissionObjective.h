/*
 *	server/zone/objects/mission/MissionObjective.h generated by engine3 IDL compiler 0.60
 */

#ifndef MISSIONOBJECTIVE_H_
#define MISSIONOBJECTIVE_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {

class Observer;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class Observable;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace mission {

class MissionObject;

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

namespace server {
namespace zone {
namespace objects {
namespace mission {

class MissionObserver;

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace mission {

class MissionObjective : public ManagedObject {
public:
	MissionObjective(MissionObject* parent);

	void destroyObjectFromDatabase();

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void activate();

	void abort();

	void complete();

	MissionObject* getMissionObject();

	unsigned int getObjectiveType();

protected:
	MissionObjective(DummyConstructorParameter* param);

	virtual ~MissionObjective();

	friend class MissionObjectiveHelper;
};

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

namespace server {
namespace zone {
namespace objects {
namespace mission {

class MissionObjectiveImplementation : public ManagedObjectImplementation, public Logger {
protected:
	SortedVector<ManagedReference<MissionObserver* > > observers;

	ManagedWeakReference<MissionObject* > mission;

	unsigned int objectiveType;

public:
	MissionObjectiveImplementation(MissionObject* parent);

	MissionObjectiveImplementation(DummyConstructorParameter* param);

	virtual void destroyObjectFromDatabase();

	virtual int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	virtual void activate();

	virtual void abort();

	virtual void complete();

	MissionObject* getMissionObject();

	unsigned int getObjectiveType();

	MissionObjective* _this;

	operator const MissionObjective*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~MissionObjectiveImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class MissionObjective;
};

class MissionObjectiveAdapter : public ManagedObjectAdapter {
public:
	MissionObjectiveAdapter(MissionObjectiveImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void destroyObjectFromDatabase();

	int notifyObserverEvent(MissionObserver* observer, unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2);

	void activate();

	void abort();

	void complete();

	MissionObject* getMissionObject();

	unsigned int getObjectiveType();

};

class MissionObjectiveHelper : public DistributedObjectClassHelper, public Singleton<MissionObjectiveHelper> {
	static MissionObjectiveHelper* staticInitializer;

public:
	MissionObjectiveHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<MissionObjectiveHelper>;
};

} // namespace mission
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::mission;

#endif /*MISSIONOBJECTIVE_H_*/
