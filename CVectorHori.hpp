#include "CVector.hpp"

#pragma once

class CVectorHori:public CVector{
public:
    CVectorHori():CVector(){}
    CVectorHori(std::vector<double>);
    CVectorHori(std::vector<double>, std::string);

    // Оператор копирования
    CVectorHori(const CVector&);
    CVectorHori(const CVectorHori&);

    // Конструктор перемещения
    CVectorHori(CVector&&);

    friend CVectorHori operator+(const CVector&, const CVector&);
    friend CVectorHori operator-(const CVector&, const CVector&);

    using CVector::operator*;
    using CVector::operator=;
    CVectorHori& operator=(const CVectorHori&);

    virtual void output();

    ~CVectorHori()=default;
};

// Объявление оператора сложения
CVectorHori operator+(const CVector& first, const CVector& second);
CVectorHori operator-(const CVector& first, const CVector& second);
