#include <instance.hpp>


Scout::Instance::Instance() {

}


Scout::Instance::~Instance() {

	for (auto& pair : children) {
		if (pair.second == nullptr) continue;
		delete pair.second;
	}

}


Scout::Instance* Scout::Instance::getChild(std::string_view name) {
	return children[name.data()];
}


void Scout::Instance::addChild(Scout::Instance* child) {
	child->setParent(this);
}


Scout::Instance* Scout::Instance::removeChild(std::string_view name) {
	Scout::Instance* child = children[name.data()];
	children.erase(name.data());
	return child;
}


void Scout::Instance::deleteChild(std::string_view name) {
	delete removeChild(name);
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

