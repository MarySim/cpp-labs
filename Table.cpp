#include "Table.h"

Table::Table(int rows, int cols) : rows(rows), cols(cols) {
    data = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols]();
    }
}

Table::~Table() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

// ����� ��� ��������� �������� �� ������
int Table::get_value(int row, int col) const {
    return data[row][col];
}

// ����� ��� ��������� �������� � ������
void Table::set_value(int row, int col, int value) {
    data[row][col] = value;
}

// ����� ��� ��������� ���������� �����
int Table::n_rows() const {
    return rows;
}

// ����� ��� ��������� ���������� ��������
int Table::n_cols() const {
    return cols;
}

// ����� ��� ������ ������� �� �����
void Table::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// ����� ��� ���������� �������� ���������������
double Table::average() const {
    double sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += data[i][j];
        }
    }
    return sum / (rows * cols);
}
