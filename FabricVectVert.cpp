#include "FabricVectVert.hpp"

std::shared_ptr<CVector> FabricVectVert::create(std::vector<double> vector, std::string filename){
    return std::make_shared<CVectorVert>(vector, filename);
}
