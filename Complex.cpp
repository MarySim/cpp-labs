#include "Complex.h"

Complex::Complex() {
    re = new double(0);
    im = new double(0);
}

Complex::Complex(double x, double y) {
    this->re = new double(x);
    this->im = new double(y);
}

Complex::~Complex() {
    delete re;
    delete im;
}

// ��������� �������������� �����
void Complex::SetRe(double x) {
    *re = x;
}

// ��������� ������ �����
void Complex::SetIm(double y) {
    *im = y;
}

// ��������� �������������� �����
double Complex::GetRe() const {
    return *re;
}

// ��������� ������ �����
double Complex::GetIm() const {
    return *im;
}

// ���������� ������ ������������ �����
double Complex::Abs() const {
    return std::sqrt((*re) * (*re) + (*im) * (*im));    // �������: sqrt(re^2 + im^2)
}

// ���������� ��������� ������������ �����
double Complex::Arg() const {
    return std::atan2(*im, *re);    // �������: atan2(im, re)
}

// ����� ����� � �������������� �����
void Complex::Print() const {
    std::cout << *re << " + i*" << *im << std::endl;    // ������: a + bi
}

// ����� ����� � ������������������ �����
void Complex::TrigPrint() const {
    double rho = Abs();
    double phi = Arg();
    std::cout << rho << " * (cos(" << phi << ") + i*sin(" << phi << "))" << std::endl;  // ������: r * (cos(phi) + i*sin(phi))
}

// ����� ����� � ���������������� �����
void Complex::ExpPrint() const {
    double rho = Abs();
    double phi = Arg();
    std::cout << rho << " * e^(i*" << phi << ")" << std::endl;  // ������: r * e^(i*phi)
}

// �������� ���� ����������� �����
Complex Complex::Add(const Complex& z) const {
    return Complex(*re + *z.re, *im + *z.im);   // �������: (a + bi) + (c + di) = (a + c) + (b + d)i
}

// ��������� ����������� �����
Complex Complex::Sub(const Complex& z) const {
    return Complex(*re - *z.re, *im - *z.im);   // �������: (a + bi) - (c + di) = (a - c) + (b - d)i
}

// ��������� ����������� �����
Complex Complex::Mult(const Complex& z) const {
    return Complex(*re * *z.re - *im * *z.im, *re * *z.im + *im * *z.re);   // �������: (a + bi) * (c + di) = (a*c - b*d) + (a*d + b*c)i
}

// ������� ����������� �����
Complex Complex::Div(const Complex& z) const {
    double denominator = *z.re * *z.re + *z.im * *z.im; // �����������: c^2 + d^2
    return Complex((*re * *z.re + *im * *z.im) / denominator, (*im * *z.re - *re * *z.im) / denominator);   // �������: (a + bi) / (c + di) = [(a*c + b*d) + (b*c - a*d)i] / (c^2 + d^2)
}
