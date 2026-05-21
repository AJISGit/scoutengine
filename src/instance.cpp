#include <instance.hpp>
#include <instanceptr.hpp>


Scout::Instance::Instance() {

}


Scout::Instance::~Instance() {

	for (auto& pair : children) {
		if (pair.second == nullptr) continue;
		Scout::InstancePtr<Instance>(pair.second).destroy();
	}

}


Scout::InstancePtr<Scout::Instance> Scout::Instance::getChild(std::string_view name) {
	return Scout::InstancePtr<Scout::Instance>(children.at(name.data()));
}


void Scout::Instance::addChild(const Scout::InstancePtr<Scout::Instance>& child) {
	child->setParent(this);
}


Scout::InstancePtr<Scout::Instance> Scout::Instance::removeChild(std::string_view name) {
	Scout::Instance* child = children[name.data()];
	children.erase(name.data());
	return Scout::InstancePtr<Instance>(child);
}


void Scout::Instance::deleteChild(std::string_view name) {
	removeChild(name).destroy();
}


Scout::Instance* Scout::Instance::getParent() {
	return parent;
}


void Scout::Instance::setParent(Scout::Instance* parent) {

	Scout::Instance* oldParent = this->parent;

	this->parent = parent;
	parent->children[name] = this;

	if (oldParent == nullptr) return;
	oldParent->children.erase(name);

}


std::string Scout::Instance::getName() {
	return name;
}


void Scout::Instance::setName(std::string_view name) { 
	this->name = name;
}



void Scout::Instance::update() {}


void Scout::Instance::draw() {}


bool Scout::Instance::isDrawable() {
	return drawable;
}


bool Scout::Instance::isDestroyable() {
	return destroyable;
}

