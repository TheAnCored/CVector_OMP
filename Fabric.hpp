#include "CVector.hpp"
#include "CVectorHori.hpp"
#include "CVectorVert.hpp"
#include <memory>

#pragma once

class Fabric{
public:
    virtual std::shared_ptr<CVector> create(std::vector<double>, std::string)=0;

    virtual ~Fabric(){};
};
