#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <climits>

class Stock {
private:
    struct Box {
        int weight;  // ���������������� �������
        int volume;  // ����� �������
        int serial;  // �������� ����� �������
    };

    Box* boxes;       // ������������ ������ �������
    int capacity;     // ����������� �������
    int size;         // ������� ���������� �������
    int serialCounter; // ������� ��� �������� �������

public:
    Stock();
    ~Stock();

    void Add(int w, int v);  // �������� ������� �� �����
    int GetByW(int min_w);   // �������� ������� �� ����������� ����������������
    int GetByV(int min_v);   // �������� ������� �� ������������ ������
};

#endif // STOCK_H
