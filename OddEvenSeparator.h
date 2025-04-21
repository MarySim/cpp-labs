#ifndef ODDEVENSEPARATOR_H
#define ODDEVENSEPARATOR_H

#include <iostream>

class OddEvenSeparator {
private:
    int* numbers;  // ������������ ������ ��� �������� ���� �����
    int* evens;    // ������������ ������ ��� �������� ������ �����
    int* odds;     // ������������ ������ ��� �������� �������� �����
    int numbers_count;  // ������� ���������� �����
    int evens_count;    // ������� ���������� ������ �����
    int odds_count;     // ������� ���������� �������� �����
    int capacity;       // ������������ ����������� ��������

public:
    OddEvenSeparator();
    ~OddEvenSeparator();
    void add_number(int number);  // ����� ��� ���������� �����
    void even() const;            // ����� ��� ������ ������ �����
    void odd() const;             // ����� ��� ������ �������� �����
};

#endif // ODDEVENSEPARATOR_H
