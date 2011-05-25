/*
 *	server/zone/objects/tangible/attachment/Attachment.cpp generated by engine3 IDL compiler 0.60
 */

#include "Attachment.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/Zone.h"

/*
 *	AttachmentStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_INITIALIZEMEMBERS__,RPC_SETSKILLMODCOUNT__INT_,RPC_GETSKILLMODCOUNT__,RPC_GETSKILLMODNAME__INT_,RPC_GETSKILLMODVALUE__INT_,RPC_GETSKILLMODVALUE__STRING_,RPC_PARSESKILLMODATTRIBUTESTRING__STRING_,RPC_ADDSKILLMOD__STRING_INT_,RPC_REMOVEATTACHMENT__PLAYERCREATURE_,RPC_GENERATESKILLMODS__,RPC_GETRANDOMMODVALUE__INT_INT_,RPC_ISATTACHMENT__,RPC_ISARMORATTACHMENT__,RPC_ISCLOTHINGATTACHMENT__};

Attachment::Attachment() : TangibleObject(DummyConstructorParameter::instance()) {
	AttachmentImplementation* _implementation = new AttachmentImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

Attachment::Attachment(DummyConstructorParameter* param) : TangibleObject(param) {
}

Attachment::~Attachment() {
}


void Attachment::initializeTransientMembers() {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void Attachment::initializeMembers() {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZEMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeMembers();
}

void Attachment::loadTemplateData(SharedObjectTemplate* templateData) {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

void Attachment::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

void Attachment::setSkillModCount(int modCount) {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETSKILLMODCOUNT__INT_);
		method.addSignedIntParameter(modCount);

		method.executeWithVoidReturn();
	} else
		_implementation->setSkillModCount(modCount);
}

int Attachment::getSkillModCount() {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSKILLMODCOUNT__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getSkillModCount();
}

String Attachment::getSkillModName(int idx) {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSKILLMODNAME__INT_);
		method.addSignedIntParameter(idx);

		method.executeWithAsciiReturn(_return_getSkillModName);
		return _return_getSkillModName;
	} else
		return _implementation->getSkillModName(idx);
}

int Attachment::getSkillModValue(int idx) {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSKILLMODVALUE__INT_);
		method.addSignedIntParameter(idx);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getSkillModValue(idx);
}

int Attachment::getSkillModValue(String& name) {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSKILLMODVALUE__STRING_);
		method.addAsciiParameter(name);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getSkillModValue(name);
}

void Attachment::parseSkillModAttributeString(String& attr) {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_PARSESKILLMODATTRIBUTESTRING__STRING_);
		method.addAsciiParameter(attr);

		method.executeWithVoidReturn();
	} else
		_implementation->parseSkillModAttributeString(attr);
}

void Attachment::addSkillMod(const String& skillModType, int skillModValue) {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ADDSKILLMOD__STRING_INT_);
		method.addAsciiParameter(skillModType);
		method.addSignedIntParameter(skillModValue);

		method.executeWithVoidReturn();
	} else
		_implementation->addSkillMod(skillModType, skillModValue);
}

bool Attachment::removeAttachment(PlayerCreature* player) {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_REMOVEATTACHMENT__PLAYERCREATURE_);
		method.addObjectParameter(player);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->removeAttachment(player);
}

void Attachment::generateSkillMods() {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GENERATESKILLMODS__);

		method.executeWithVoidReturn();
	} else
		_implementation->generateSkillMods();
}

int Attachment::getRandomModValue(int luck, int creatureLevel) {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETRANDOMMODVALUE__INT_INT_);
		method.addSignedIntParameter(luck);
		method.addSignedIntParameter(creatureLevel);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getRandomModValue(luck, creatureLevel);
}

bool Attachment::isAttachment() {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISATTACHMENT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isAttachment();
}

bool Attachment::isArmorAttachment() {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISARMORATTACHMENT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isArmorAttachment();
}

bool Attachment::isClothingAttachment() {
	AttachmentImplementation* _implementation = (AttachmentImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISCLOTHINGATTACHMENT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isClothingAttachment();
}

DistributedObjectServant* Attachment::_getImplementation() {

	_updated = true;
	return _impl;
}

void Attachment::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	AttachmentImplementation
 */

AttachmentImplementation::AttachmentImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


AttachmentImplementation::~AttachmentImplementation() {
}


void AttachmentImplementation::finalize() {
}

void AttachmentImplementation::_initializeImplementation() {
	_setClassHelper(AttachmentHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void AttachmentImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Attachment*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* AttachmentImplementation::_getStub() {
	return _this;
}

AttachmentImplementation::operator const Attachment*() {
	return _this;
}

void AttachmentImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void AttachmentImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void AttachmentImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void AttachmentImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void AttachmentImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void AttachmentImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void AttachmentImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void AttachmentImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("Attachment");

}

void AttachmentImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(AttachmentImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool AttachmentImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TangibleObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "maxModifiers") {
		TypeInfo<int >::parseFromBinaryStream(&maxModifiers, stream);
		return true;
	}

	if (_name == "attachmentType") {
		TypeInfo<int >::parseFromBinaryStream(&attachmentType, stream);
		return true;
	}

	if (_name == "skillModMap") {
		TypeInfo<VectorMap<String, int> >::parseFromBinaryStream(&skillModMap, stream);
		return true;
	}


	return false;
}

void AttachmentImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = AttachmentImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int AttachmentImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "maxModifiers";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&maxModifiers, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "attachmentType";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&attachmentType, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "skillModMap";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<VectorMap<String, int> >::toBinaryStream(&skillModMap, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 3 + TangibleObjectImplementation::writeObjectMembers(stream);
}

AttachmentImplementation::AttachmentImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/attachment/Attachment.idl():  		Logger.setLoggingName("Attachment");
	Logger::setLoggingName("Attachment");
	// server/zone/objects/tangible/attachment/Attachment.idl():  		skillModMap.setNullValue(null);
	(&skillModMap)->setNullValue(NULL);
	// server/zone/objects/tangible/attachment/Attachment.idl():  		skillModMap.setNoDuplicateInsertPlan();
	(&skillModMap)->setNoDuplicateInsertPlan();
	// server/zone/objects/tangible/attachment/Attachment.idl():  		generateSkillMods();
	generateSkillMods();
}

void AttachmentImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	// server/zone/objects/tangible/attachment/Attachment.idl():  		super.loadTemplateData(templateData);
	TangibleObjectImplementation::loadTemplateData(templateData);
	// server/zone/objects/tangible/attachment/Attachment.idl():  		initializeMembers();
	initializeMembers();
}

void AttachmentImplementation::setSkillModCount(int modCount) {
	// server/zone/objects/tangible/attachment/Attachment.idl():  		maxModifiers = modCount;
	maxModifiers = modCount;
}

int AttachmentImplementation::getSkillModCount() {
	// server/zone/objects/tangible/attachment/Attachment.idl():  		return skillModMap.size();
	return (&skillModMap)->size();
}

int AttachmentImplementation::getSkillModValue(String& name) {
	// server/zone/objects/tangible/attachment/Attachment.idl():  		return skillModMap.get(name);
	return (&skillModMap)->get(name);
}

bool AttachmentImplementation::isAttachment() {
	// server/zone/objects/tangible/attachment/Attachment.idl():  		return true;
	return true;
}

bool AttachmentImplementation::isArmorAttachment() {
	// server/zone/objects/tangible/attachment/Attachment.idl():  		return super.gameObjectType == super.ARMORATTACHMENT;
	return TangibleObjectImplementation::gameObjectType == TangibleObjectImplementation::ARMORATTACHMENT;
}

bool AttachmentImplementation::isClothingAttachment() {
	// server/zone/objects/tangible/attachment/Attachment.idl():  		return super.gameObjectType == super.CLOTHINGATTACHMENT;
	return TangibleObjectImplementation::gameObjectType == TangibleObjectImplementation::CLOTHINGATTACHMENT;
}

/*
 *	AttachmentAdapter
 */

AttachmentAdapter::AttachmentAdapter(AttachmentImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* AttachmentAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_INITIALIZEMEMBERS__:
		initializeMembers();
		break;
	case RPC_SETSKILLMODCOUNT__INT_:
		setSkillModCount(inv->getSignedIntParameter());
		break;
	case RPC_GETSKILLMODCOUNT__:
		resp->insertSignedInt(getSkillModCount());
		break;
	case RPC_GETSKILLMODNAME__INT_:
		resp->insertAscii(getSkillModName(inv->getSignedIntParameter()));
		break;
	case RPC_GETSKILLMODVALUE__INT_:
		resp->insertSignedInt(getSkillModValue(inv->getSignedIntParameter()));
		break;
	case RPC_GETSKILLMODVALUE__STRING_:
		resp->insertSignedInt(getSkillModValue(inv->getAsciiParameter(_param0_getSkillModValue__String_)));
		break;
	case RPC_PARSESKILLMODATTRIBUTESTRING__STRING_:
		parseSkillModAttributeString(inv->getAsciiParameter(_param0_parseSkillModAttributeString__String_));
		break;
	case RPC_ADDSKILLMOD__STRING_INT_:
		addSkillMod(inv->getAsciiParameter(_param0_addSkillMod__String_int_), inv->getSignedIntParameter());
		break;
	case RPC_REMOVEATTACHMENT__PLAYERCREATURE_:
		resp->insertBoolean(removeAttachment((PlayerCreature*) inv->getObjectParameter()));
		break;
	case RPC_GENERATESKILLMODS__:
		generateSkillMods();
		break;
	case RPC_GETRANDOMMODVALUE__INT_INT_:
		resp->insertSignedInt(getRandomModValue(inv->getSignedIntParameter(), inv->getSignedIntParameter()));
		break;
	case RPC_ISATTACHMENT__:
		resp->insertBoolean(isAttachment());
		break;
	case RPC_ISARMORATTACHMENT__:
		resp->insertBoolean(isArmorAttachment());
		break;
	case RPC_ISCLOTHINGATTACHMENT__:
		resp->insertBoolean(isClothingAttachment());
		break;
	default:
		return NULL;
	}

	return resp;
}

void AttachmentAdapter::initializeTransientMembers() {
	((AttachmentImplementation*) impl)->initializeTransientMembers();
}

void AttachmentAdapter::initializeMembers() {
	((AttachmentImplementation*) impl)->initializeMembers();
}

void AttachmentAdapter::setSkillModCount(int modCount) {
	((AttachmentImplementation*) impl)->setSkillModCount(modCount);
}

int AttachmentAdapter::getSkillModCount() {
	return ((AttachmentImplementation*) impl)->getSkillModCount();
}

String AttachmentAdapter::getSkillModName(int idx) {
	return ((AttachmentImplementation*) impl)->getSkillModName(idx);
}

int AttachmentAdapter::getSkillModValue(int idx) {
	return ((AttachmentImplementation*) impl)->getSkillModValue(idx);
}

int AttachmentAdapter::getSkillModValue(String& name) {
	return ((AttachmentImplementation*) impl)->getSkillModValue(name);
}

void AttachmentAdapter::parseSkillModAttributeString(String& attr) {
	((AttachmentImplementation*) impl)->parseSkillModAttributeString(attr);
}

void AttachmentAdapter::addSkillMod(const String& skillModType, int skillModValue) {
	((AttachmentImplementation*) impl)->addSkillMod(skillModType, skillModValue);
}

bool AttachmentAdapter::removeAttachment(PlayerCreature* player) {
	return ((AttachmentImplementation*) impl)->removeAttachment(player);
}

void AttachmentAdapter::generateSkillMods() {
	((AttachmentImplementation*) impl)->generateSkillMods();
}

int AttachmentAdapter::getRandomModValue(int luck, int creatureLevel) {
	return ((AttachmentImplementation*) impl)->getRandomModValue(luck, creatureLevel);
}

bool AttachmentAdapter::isAttachment() {
	return ((AttachmentImplementation*) impl)->isAttachment();
}

bool AttachmentAdapter::isArmorAttachment() {
	return ((AttachmentImplementation*) impl)->isArmorAttachment();
}

bool AttachmentAdapter::isClothingAttachment() {
	return ((AttachmentImplementation*) impl)->isClothingAttachment();
}

/*
 *	AttachmentHelper
 */

AttachmentHelper* AttachmentHelper::staticInitializer = AttachmentHelper::instance();

AttachmentHelper::AttachmentHelper() {
	className = "Attachment";

	Core::getObjectBroker()->registerClass(className, this);
}

void AttachmentHelper::finalizeHelper() {
	AttachmentHelper::finalize();
}

DistributedObject* AttachmentHelper::instantiateObject() {
	return new Attachment(DummyConstructorParameter::instance());
}

DistributedObjectServant* AttachmentHelper::instantiateServant() {
	return new AttachmentImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* AttachmentHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new AttachmentAdapter((AttachmentImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

