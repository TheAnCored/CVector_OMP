#include "CVector.hpp"
#include "CVectorHori.hpp"

#pragma once

class CVectorVert:public CVector{
public:
    
    CVectorVert():CVector(){}
    CVectorVert(std::vector<double>);
    CVectorVert(std::vector<double>, std::string);

    // Оператор копирования
    CVectorVert(const CVector&);
    CVectorVert(const CVectorVert&);

    // Конструктор перемещения
    CVectorVert(CVector&&);

    using CVector::operator*;
    using CVector::operator=;
    CVectorVert& operator=(const CVectorVert&);

    virtual void output();

    ~CVectorVert()=default;
};
