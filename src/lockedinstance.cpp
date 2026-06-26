#include <lockedinstance.hpp>
#include <instanceptr.hpp>
#include <stdexcept>


Scout::LockedInstance::LockedInstance(std::string_view name, const Scout::BasicInstPtr& parent) : Scout::Instance::Instance(name, parent) {

	destroyable = false;

}


void Scout::LockedInstance::setParent(const Scout::BasicInstPtr& parent) {
	throw std::runtime_error("Cannot change the parent of a LockedInstance.");
}


void Scout::LockedInstance::setName(std::string_view name) {
	throw std::runtime_error("Cannot change the name of a LockedInstance.");
}

