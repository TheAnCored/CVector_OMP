#include "CVector.hpp"

// КОНСТРУКТОРЫ
CVector::CVector(){
    this->index=0;
    this->index=0;
}

CVector::CVector(bool index, std::vector<double> vector){
    this->index = index;
    this->vector = vector;
}

CVector::CVector(bool index, std::vector<double> vector, std::string filename){
    this->index = index;
    this->vector = vector;
    this->filename=filename;
}

CVector::CVector(bool index, size_t length){
    this->vector = std::vector<double>(length);
    this->index = index;
}
//----------------

// Конструктор копирования
CVector::CVector(const CVector& second){
    this->vector = second.vector;
    this->filename = second.filename;
}

// Оператор присваивания
CVector& CVector::operator=(const CVector& second){
    if(this!=&second){
        this->index=second.index;

        if(second.get_filename_length()>0){
            this->filename = second.filename;
        }else{
            this->filename = nullptr;
        }
        this->vector=second.vector;
    }
    return *this;
}

// Конструктор перемещения
CVector::CVector(CVector&& second){

    this->vector=second.vector;

    this->filename=second.filename;
    this->index=second.index;

    second.filename=nullptr;
}

// Оператор присваивания с перемещением
CVector& CVector::operator=( CVector&& second){
    if(this!=&second){
        this->index=second.index;
        this->vector = second.vector;
    }

    return *this;
}

// Скалярное умножение векторов
double CVector::operator*(const CVector& second) const&{

    double dot_product=0.;
    try{ 
        if(this->get_length()!=second.get_length()) throw "НЕравная длина векторов!\n";
        
        // Параллелим for на скалярном сложении
        #pragma omp parallel for reduction(+: dot_product)
        for(long long int i=0; i<second.get_length(); ++i){ dot_product+= this->vector[i]*second.vector[i]; }
    }
    catch(const char* error_message){ std::cout<<error_message<<std::endl;}

    return dot_product;
}

// Перегрузка оператора []
double& CVector::operator[](int index){ return this->vector[index]; }
double& CVector::operator[](size_t index){ return this->vector[index]; }


// Получение длины вектора
int CVector::get_length()const{ return this->vector.size(); }

// Получение название файла
std::string CVector::get_filename()const{
    std::string tmp = this->filename;
    return tmp;
}

// Получение длины файла
int CVector::get_filename_length()const{
    return this->filename.size();
}

// Получение копии вектора
std::vector<double> CVector::get_vector()const{
    std::vector<double> vect_copy(this->get_length());

    for(long long i=0;i<this->get_length(); ++i){ vect_copy[i]=this->vector[i];}
    return vect_copy;
}

// Перезапись файла вывода вектора
void CVector::rewrite_file(std::string tmp){ this->filename = tmp; }

// Добавление числа к вектору
void CVector::push_back(double tmp){ this->vector.push_back(tmp); }

void CVector::pop_back(){ this->vector.pop_back(); }