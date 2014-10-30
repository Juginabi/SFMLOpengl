#pragma once

// Project specific headers and forward declarations
#include "../component.h"

#ifndef _NDEBUG
#include <iostream>
#endif

// Class GocVisual component is a family of components which make the entity visible
class GocVisual : public Component
{
    // Component interface
public:
    // Can be used to query family id of components inherited from this.
    const goc_type_name& getFamilyId() const;

    // Constructor
    GocVisual();

    // Destructor
    virtual ~GocVisual();

    // GocVisual interface.
public:
    // Can be used to query specific type id of component inherited from this.
    virtual const goc_type_name &getComponentId() const = 0;

    // This class introduces render method.
    virtual void render() const = 0;

private:
    static const goc_type_name familyId_;
};

inline const goc_type_name &GocVisual::getFamilyId() const {
    return familyId_;
}

inline GocVisual::~GocVisual() {
#ifndef _NDEBUG
    std::cout << "[GocVisual] destructor" << std::endl;
#endif
}

inline GocVisual::GocVisual() {
#ifndef _NDEBUG
    std::cout << "[GocVisual] constructor" << std::endl;
#endif
}
