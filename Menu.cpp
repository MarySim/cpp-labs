#include "Menu.h"

// �����������
Menu::Menu() {}

// ����� ��� ������� �������
void Menu::ClearConsole() {
#ifdef _WIN32
    system("cls"); // ��� Windows
#else
    system("clear"); // ��� Linux/MacOS
#endif
}

// ����� ��� ����������� ����
void Menu::ShowMenu() {
    ClearConsole();
    std::cout << "����:" << std::endl;
    std::cout << "1. ������� 1 (Bell)" << std::endl;
    std::cout << "2. ������� 2 (OddEvenSeparator)" << std::endl;
    std::cout << "3. ������� 3 (Table)" << std::endl;
    std::cout << "4. ������� 4 (Complex)" << std::endl;
    std::cout << "5. ������� 5 (Stock)" << std::endl;
    std::cout << "0. �����" << std::endl;
    std::cout << "�������� �������: ";
}

// ����� ��� ���������� ���������� �������
void Menu::RunTask(int choice) {
    ClearConsole();
    switch (choice) {
    case 1:
        TaskBell();
        break;
    case 2:
        TaskOddEvenSeparator();
        break;
    case 3:
        TaskTable();
        break;
    case 4:
        TaskComplex();
        break;
    case 5:
        TaskStock();
        break;
    case 0:
        std::cout << "����� �� ���������." << std::endl;
        break;
    default:
        std::cout << "�������� �����. ���������� �����." << std::endl;
        break;
    }
    if (choice != 0) {
        std::cout << "������� Enter ��� �����������...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
}

// ����� ��� ������ � ������� Bell
void Menu::TaskBell() {
    std::cout << "������� 1: ���������� ������ Bell." << std::endl;
    std::cout << "������� ���������� ������: ";
    int count;
    std::cin >> count;

    if (count <= 0) {
        std::cerr << "������: ���������� ������ ������ ���� ������������� ������." << std::endl;
        return;
    }

    Bell bell;
    for (int i = 0; i < count; ++i) {
        bell.sound();
    }
}

// ����� ��� ������ � ������� OddEvenSeparator
void Menu::TaskOddEvenSeparator() {
    std::cout << "������� 2: ���������� ������ OddEvenSeparator." << std::endl;
    std::cout << "������� ����� ����� ������ (��� ���������� ����� ������� ����� ���������� ������): ";

    OddEvenSeparator separator;
    int number;
    while (std::cin >> number) {
        separator.add_number(number);
    }

    // ������� ������ �����
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    separator.even();
    separator.odd();
}

// ����� ��� ������ � ������� Table
void Menu::TaskTable() {
    std::cout << "������� 3: ���������� ������ Table." << std::endl;
    std::cout << "������� ���������� ����� � ��������: ";
    int rows, cols;
    std::cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) {
        std::cerr << "������: ���������� ����� � �������� ������ ���� ������������� ������." << std::endl;
        return;
    }

    Table table(rows, cols);

    // ��������� ������� ����������
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            table.set_value(i, j, i * cols + j + 1); // ������ ����������
        }
    }

    // ������� �������
    std::cout << "�������:" << std::endl;
    table.print();

    // ������� ������� ��������������
    std::cout << "������� ��������������: " << table.average() << std::endl;
}

// ����� ��� ������ � ������� Complex
void Menu::TaskComplex() {
    std::cout << "������� 4: ���������� ������ Complex." << std::endl;
    std::cout << "������� �������������� � ������ ����� ������� ������������ �����: ";
    double re1, im1;
    std::cin >> re1 >> im1;
    Complex z1(re1, im1);

    std::cout << "������� �������������� � ������ ����� ������� ������������ �����: ";
    double re2, im2;
    std::cin >> re2 >> im2;
    Complex z2(re2, im2);

    // ����� �����
    std::cout << "������ �����: ";
    z1.Print();
    std::cout << "������ �����: ";
    z2.Print();

    // �������������� ��������
    Complex sum = z1.Add(z2);
    std::cout << "�����: ";
    sum.Print();

    Complex diff = z1.Sub(z2);
    std::cout << "��������: ";
    diff.Print();

    Complex prod = z1.Mult(z2);
    std::cout << "������������: ";
    prod.Print();

    Complex quot = z1.Div(z2);
    std::cout << "�������: ";
    quot.Print();
}

// ����� ��� ������ � ������� Stock
void Menu::TaskStock() {
    std::cout << "������� 5: ���������� ������ Stock." << std::endl;
    Stock stock;

    // ��������� ������� �� �����
    stock.Add(10, 5);  // ������� 0: ���=10, �����=5
    stock.Add(20, 3);  // ������� 1: ���=20, �����=3
    stock.Add(15, 8);  // ������� 2: ���=15, �����=8

    // �������� ������� �� ����������� ����������������
    stock.GetByW(12);  // ������ ���� ������ ������� 2 (���=15)

    // �������� ������� �� ������������ ������
    stock.GetByV(4);   // ������ ���� ������ ������� 0 (�����=5)
}
