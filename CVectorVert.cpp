#include "CVectorVert.hpp"


// Обычный конструктор
CVectorVert::CVectorVert(std::vector<double> vector):
    CVector(1,vector){}

CVectorVert::CVectorVert(std::vector<double> vector, std::string filename):
    CVector(1,vector,filename){}

// Перегружаемая функция
void CVectorVert::output(){
    std::ofstream out;

    if(this->get_filename_length() > 0){
        out.open(this->filename, std::ios::app);
        for(long int i=0;i<this->get_length(); ++i){ out<<this->vector[i]<<'\n';}
        out.close();
    }
}

// Оператор присваивания
CVectorVert& CVectorVert::operator=(const CVectorVert& second){

    if(this!=&second){
        this->index=second.index;

        if(second.get_filename_length()>0){
            this->filename = second.filename;
        }

        this->vector = second.vector;
    }
    return *this;
}

// Конструктор копирования
CVectorVert::CVectorVert(const CVector& second) : CVector(second){}

CVectorVert::CVectorVert(const CVectorVert& second) : CVector(second){}

// Конструктор перемещения
CVectorVert::CVectorVert(CVector&& second){

    this->vector=second.get_vector();

    this->filename=second.get_filename();
    this->index=second.get_index();
}