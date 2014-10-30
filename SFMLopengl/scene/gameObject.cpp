#ifndef _NDEBUG
#include <iostream>
#endif
#include <memory>
#include "gameObject.h"

GameObject::GameObject(go_type_name _myID) :
    myID_(_myID) {
#ifndef _NDEBUG
    std::cout << "[GameObject] with ID: " << myID_ << " created!" << std::endl;
#endif
}

GameObject::~GameObject() {
    clearComponents();
#ifndef _NDEBUG
    std::cout << "[GameObject] with ID: " << myID_ << " destroyed!" << std::endl;
#endif
}

Component *GameObject::attachComponent(Component *_goc) {
    const goc_type_name familyId = _goc->getFamilyId();
    const goc_type_name componentId = _goc->getComponentId();

    Component_map::iterator iter = ComponentMap_.find(familyId);
    if ( iter == ComponentMap_.end() ) {
        ComponentMap_.insert(std::pair<goc_type_name, Component*>(familyId, _goc));
        _goc->setOwner(this);
#ifndef _NDEBUG
        std::cout << "[GameObject] Component with ID: " << familyId << "(" << componentId << ")" << " attached!" << std::endl;
#endif
        return 0;
    } else {
        Component *oldComp = iter->second;
        iter->second = _goc;
#ifndef _NDEBUG
        std::cout << "[GameObject] Replacing Component with ID: " << familyId << "(" << componentId << ")" << std::endl;
#endif
        return oldComp;
    }
}

Component *GameObject::getComponent(goc_type_name _id) {
    // Locate goc type and return it. If not found return 0.
    Component_map::iterator iter = ComponentMap_.find(_id);
    if (iter == ComponentMap_.end()) {
        return 0;
    } else {
        return iter->second;
    }
}

void GameObject::detachComponent(goc_type_name _id) {
    // Find goc type and erase it
    Component_map::iterator iter = ComponentMap_.find(_id);
    if (iter != ComponentMap_.end()) {
        // Remove Component here
        ComponentMap_.erase(iter);
    }
}

void GameObject::clearComponents() {
    // smart pointer frees the memory properly
    ComponentMap_.clear();
}
