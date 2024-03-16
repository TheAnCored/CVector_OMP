// Класс вектора(общий)
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>

#pragma once

class CVector{
protected:
    std::vector<double> vector;
    std::string filename;
    bool index;

public:
    // Стандартный конструктор
    CVector();
    
    // Без файла
    CVector(bool, std::vector<double>);
    
    // С файлом
    CVector(bool, std::vector<double>, std::string filename);

    // Пустой вектор заданной длины
    CVector(bool, size_t);
    //--------------------------------------
    
    // Оператор копирования
    CVector(const CVector&);
    // Оператор присваивания 
    CVector& operator=(const CVector&);

    // Конструктор перемещения
    CVector(CVector&&);
    // Оператор присваивания с перемещением
    CVector& operator=(CVector&&);

    // Деструктор
    virtual ~CVector(){}

    //--------------------------------------
    // Скалярное произведение
    double operator*(const CVector&) const&;

    // Перегрузка []
    double& operator[](int);
    double& operator[](size_t);

    // Получение индекса
    bool get_index()const{ return this->index; }

    // Получение длины вектора
    int get_length()const;

    // Получение название файла и длины названия
    std::string get_filename()const;
    int get_filename_length()const;

    // Получение копии вектора
    std::vector<double> get_vector()const;

    // Перезапись файла вектора
    void rewrite_file(std::string);

    // Добавление числа к вектору 
    void push_back(double);
    // Удаление последнего числа из вектора
    void pop_back();

    // Функция вывода 
    virtual void output()=0;
};
