#include "Fabric.hpp"

class FabricVectVert:public Fabric{
public:
    virtual std::shared_ptr<CVector> create(std::vector<double>, std::string);
    ~FabricVectVert(){};
};
