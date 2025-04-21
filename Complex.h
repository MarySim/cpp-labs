#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

class Complex {
private:
    double* re; // ��������� �� �������������� ����� �����
    double* im; // ��������� �� ������ ����� �����

public:
    Complex();  // ����������� �� ��������� (�������������� ����� ��� 0 + 0i)
    Complex(double x, double y);    // ����������� � ����������� (�������������� ����� ��� x + yi)

    ~Complex();

    void SetRe(double x);   // ������������� �������������� ����� �����
    void SetIm(double y);   // ������������� ������ ����� �����

    double GetRe() const;   // ���������� �������������� ����� �����
    double GetIm() const;   // ���������� ������ ����� �����

    double Abs() const; // ���������� ������ ������������ �����
    double Arg() const; // ���������� �������� ������������ �����
    void Print() const; // ������� ����� � �������������� ����� (a + bi)
    void TrigPrint() const; // ������� ����� � ������������������ ����� (r * (cos(phi) + i*sin(phi)))
    void ExpPrint() const;  // ������� ����� � ���������������� ����� (r * e^(i*phi))

    Complex Add(const Complex& z) const;    // �������� ���� ����������� �����
    Complex Sub(const Complex& z) const;    // ��������� ����������� �����
    Complex Mult(const Complex& z) const;   // ��������� ����������� �����
    Complex Div(const Complex& z) const;    // ������� ����������� �����
};

#endif // COMPLEX_H
