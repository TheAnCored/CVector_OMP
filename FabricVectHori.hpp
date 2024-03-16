#include "Fabric.hpp"

class FabricVectHori:public Fabric{
public:
    virtual std::shared_ptr<CVector> create(std::vector<double>, std::string);
    ~FabricVectHori(){};
};
