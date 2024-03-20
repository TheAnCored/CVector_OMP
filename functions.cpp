#include "header.hpp"

// Функция, считывающая все вектора из файла
std::vector<std::shared_ptr<CVector>> reading_from_file(std::string filename, std::map<std::string,std::unique_ptr<Fabric>>& fabrics){

    std::string tmp;
    std::ifstream filestream(filename);
    std::vector<std::shared_ptr<CVector>> vectors;


    if(!filestream.is_open()) throw std::runtime_error("File not found!\n");


    while(getline(filestream, tmp)){

        std::string type, filename_str, vector_str;
        std::stringstream stream;

        stream<<tmp;

        stream>>type;
        stream>>filename_str;

        // Это делается для того, чтобы очистить содержимое, если оно там было
        std::ofstream filename(filename_str, std::ios_base::trunc);
        filename.close();

        std::vector<double> vector;

        double elem;
        while(stream>>elem){
            vector.push_back(elem);
        }

        // Сборка
        vectors.push_back(fabrics[type]->create(vector, filename_str));
    }
    filestream.close();

    return vectors;
}

CVectorHori addition(CVectorHori first, CVectorHori second){
    std::vector<double> add(0, first.get_length());

    for(int i=0; i<first.get_length(); i++){
        add[i] = first[i]+second[i];
    }

    return CVectorHori(add);
}

CVectorVert addition(CVectorVert first, CVectorVert second){
    std::vector<double> add(first.get_length(),0);

    for(int i=0; i<first.get_length(); i++){
        add[i] = first[i]+second[i];
    }
    return CVectorHori(add);
}