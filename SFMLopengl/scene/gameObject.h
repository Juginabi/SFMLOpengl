#pragma once

// Project specific headers
#include "component.h"
#include "../commonTypeDefs.h"

// GameObject (GO) class is the database key in GameObject/GameObjectComponent-map.
// GO acts as an entry point for all the Components which define the GameObject.
class GameObject
{
public:
    // Constructor
    // Explicit, meaning no implicit type conversion can not be done.
    explicit GameObject(go_type_name _myID);

    // Destructor
    ~GameObject();

    // Return GameObject id
    const go_type_name& getId() const;

    // Registers Component to this gameobject. If GOC already exists, returns pointer to replaced GOC.
    Component* attachComponent(Component* _goc);

    // Request Component from GameObject using GOC family id, returns NULL if no GOC found.
    Component* getComponent(goc_type_name _id);

    // Removes Component from GameObject.
    void detachComponent(goc_type_name _id);

    // Remove all Components from GameObject
    void clearComponents();

private:
    // My id in the world
    go_type_name myID_;

    // Map containing all the Components this entity has registered into.
    Component_map ComponentMap_;
};

inline const go_type_name& GameObject::getId() const {
    return myID_;
}
