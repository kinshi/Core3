/*
 *	server/zone/objects/tangible/wearables/ClothingObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "ClothingObject.h"

/*
 *	ClothingObjectStub
 */

ClothingObject::ClothingObject(LuaObject* templateData) : WearableObject(DummyConstructorParameter::instance()) {
	_impl = new ClothingObjectImplementation(templateData);
	_impl->_setStub(this);
}

ClothingObject::ClothingObject(DummyConstructorParameter* param) : WearableObject(param) {
}

ClothingObject::~ClothingObject() {
}


void ClothingObject::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((ClothingObjectImplementation*) _impl)->initializeTransientMembers();
}

/*
 *	ClothingObjectImplementation
 */

ClothingObjectImplementation::ClothingObjectImplementation(DummyConstructorParameter* param) : WearableObjectImplementation(param) {
	_initializeImplementation();
}

ClothingObjectImplementation::~ClothingObjectImplementation() {
}


void ClothingObjectImplementation::finalize() {
}

void ClothingObjectImplementation::_initializeImplementation() {
	_setClassHelper(ClothingObjectHelper::instance());

	_serializationHelperMethod();
}

void ClothingObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ClothingObject*) stub;
	WearableObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ClothingObjectImplementation::_getStub() {
	return _this;
}

ClothingObjectImplementation::operator const ClothingObject*() {
	return _this;
}

void ClothingObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ClothingObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ClothingObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ClothingObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ClothingObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ClothingObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ClothingObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ClothingObjectImplementation::_serializationHelperMethod() {
	WearableObjectImplementation::_serializationHelperMethod();

	_setClassName("ClothingObject");

}

ClothingObjectImplementation::ClothingObjectImplementation(LuaObject* templateData) : WearableObjectImplementation(templateData) {
	_initializeImplementation();
	// server/zone/objects/tangible/wearables/ClothingObject.idl(55):  		Logger.setLoggingName("ClothingObject");
	Logger::setLoggingName("ClothingObject");
}

void ClothingObjectImplementation::initializeTransientMembers() {
	// server/zone/objects/tangible/wearables/ClothingObject.idl(59):  		super.initializeTransientMembers();
	WearableObjectImplementation::initializeTransientMembers();
	// server/zone/objects/tangible/wearables/ClothingObject.idl(61):  		Logger.setLoggingName("ClothingObject");
	Logger::setLoggingName("ClothingObject");
}

/*
 *	ClothingObjectAdapter
 */

ClothingObjectAdapter::ClothingObjectAdapter(ClothingObjectImplementation* obj) : WearableObjectAdapter(obj) {
}

Packet* ClothingObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	default:
		return NULL;
	}

	return resp;
}

void ClothingObjectAdapter::initializeTransientMembers() {
	((ClothingObjectImplementation*) impl)->initializeTransientMembers();
}

/*
 *	ClothingObjectHelper
 */

ClothingObjectHelper* ClothingObjectHelper::staticInitializer = ClothingObjectHelper::instance();

ClothingObjectHelper::ClothingObjectHelper() {
	className = "ClothingObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ClothingObjectHelper::finalizeHelper() {
	ClothingObjectHelper::finalize();
}

DistributedObject* ClothingObjectHelper::instantiateObject() {
	return new ClothingObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* ClothingObjectHelper::instantiateServant() {
	return new ClothingObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ClothingObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ClothingObjectAdapter((ClothingObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

