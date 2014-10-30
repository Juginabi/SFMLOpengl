#pragma once

#ifndef _NDEBUG
    #include <iostream>
#endif

// Project specific headers and forward declarations
#include "gocVisual.h"

class GocVisualSphere : public GocVisual {
    // GocVisual interface
public:
    // Constructor
    GocVisualSphere();

    // Destructor
    virtual ~GocVisualSphere();

    // Can be used to query family id of components inherited from this.
    const goc_type_name &getComponentId() const;

    // This method renders the entity visual on screen.
    virtual void render() const;

private:
    static const goc_type_name componentId_;
};

inline const goc_type_name &GocVisualSphere::getComponentId() const {
    return componentId_;
}

inline GocVisualSphere::~GocVisualSphere() {
#ifndef _NDEBUG
    std::cout << "[GocVisualSphere] destructor" << std::endl;
#endif
}

inline GocVisualSphere::GocVisualSphere() {
#ifndef _NDEBUG
    std::cout << "[GocVisualSphere] constructor" << std::endl;
#endif
}
