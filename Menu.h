#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <limits>
#include "Bell.h"
#include "OddEvenSeparator.h"
#include "Table.h"
#include "Complex.h"
#include "Stock.h"

class Menu {
public:
    Menu();  // �����������

    void ShowMenu(); // ����� ��� ����������� ����
    void RunTask(int choice); // ����� ��� ���������� ���������� �������

private:
    void ClearConsole(); // ����� ��� ������� �������
    void TaskBell();     // ����� ��� ������ � ������� Bell
    void TaskOddEvenSeparator(); // ����� ��� ������ � ������� OddEvenSeparator
    void TaskTable();    // ����� ��� ������ � ������� Table
    void TaskComplex();  // ����� ��� ������ � ������� Complex
    void TaskStock();    // ����� ��� ������ � ������� Stock
};

#endif // MENU_H
