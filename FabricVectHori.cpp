#include "FabricVectHori.hpp"

std::shared_ptr<CVector> FabricVectHori::create(std::vector<double> vector, std::string filename){
    return std::make_shared<CVectorHori>(vector, filename);
}
