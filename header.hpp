#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <chrono>

#include "CVector.hpp"
#include "CVectorHori.hpp"
#include "Fabric.hpp"
#include "FabricVectHori.hpp"
#include "FabricVectVert.hpp"

// Функция, считывающая все вектора из файла
std::vector<std::shared_ptr<CVector>> reading_from_file(std::string, std::map<std::string, std::unique_ptr<Fabric>>&);

CVectorHori addition(CVectorHori, CVectorHori);
CVectorVert addition(CVectorVert, CVectorVert);