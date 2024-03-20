#include "CVectorHori.hpp"


// Обычный конструктор
CVectorHori::CVectorHori(std::vector<double> vector):
    CVector(0,vector){}

CVectorHori::CVectorHori(std::vector<double> vector, std::string filename):
    CVector(0,vector,filename){}

// Перегружаемая функция
void CVectorHori::output(){
    std::ofstream out;

    if(this->get_filename_length() > 0){
        out.open(this->filename, std::ios::app);
        for(size_t i=0;i<this->get_length(); ++i){ out<<this->vector[i]<<' ';}
        out.close();
    }
}

// Оператор присваивания
CVectorHori& CVectorHori::operator=(const CVectorHori& second){

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
CVectorHori::CVectorHori(const CVector& second) : CVector(second){}

CVectorHori::CVectorHori(const CVectorHori& second) : CVector(second){}

// Конструктор перемещения
CVectorHori::CVectorHori(CVector&& second){

    this->vector=second.get_vector();

    this->filename=second.get_filename();
    this->index=second.get_index();
}

CVectorHori operator+(const CVector& first, const CVector& second){

    int length1 = first.get_length();

    std::vector<double> tmp_vector(length1,0); //////// 

    std::vector<double> tmp_vec1 = first.get_vector();
    std::vector<double> tmp_vec2 = second.get_vector();

    try{
        int length2 = second.get_length();
        if(length1 != length2){ throw "НЕравная длина векторов!\n"; }
        
        #pragma omp parallel for
        for(long long int i=0; i<length1; ++i){
            tmp_vector[i] = tmp_vec1[i] + tmp_vec2[i];
        }
    }catch(const char* error_message){ std::cout<<error_message<<std::endl; }

    CVectorHori result = CVectorHori(tmp_vector);

    return result;
}

CVectorHori operator-(const CVector& first, const CVector& second){

    int length1 = first.get_length();

    std::vector<double> tmp_vector(length1,0); //////// 

    std::vector<double> tmp_vec1 = first.get_vector();
    std::vector<double> tmp_vec2 = second.get_vector();

    try{
        int length2 = second.get_length();
        if(length1 != length2){ throw "НЕравная длина векторов!\n"; }

        #pragma omp parallel for
        for(long long int i=0; i<length1; ++i){
            tmp_vector[i] = tmp_vec1[i] - tmp_vec2[i];
        }
    }catch(const char* error_message){ std::cout<<error_message<<std::endl; }

    CVectorHori result = CVectorHori(tmp_vector);

    return result;
}
