#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <iostream>

class Table {
private:
    int** data;  // ������������ ��������� ������ ��� �������� �������
    int rows;    // ���������� �����
    int cols;    // ���������� ��������

public:
    Table(int rows, int cols);
    ~Table();
    int get_value(int row, int col) const; // ����� ��� ��������� �������� �� ������
    void set_value(int row, int col, int value); // ����� ��� ��������� �������� � ������
    int n_rows() const;        // ����� ��� ��������� ���������� �����
    int n_cols() const;        // ����� ��� ��������� ���������� ��������
    void print() const;        // ����� ��� ������ ������� �� �����
    double average() const;    // ����� ��� ���������� �������� ���������������
};

#endif // TABLE_H
