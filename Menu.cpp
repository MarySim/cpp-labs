#include "Menu.h"
#include <iostream>
#include <vector>
#include <cmath>
#include "Circle.h"
#include "Rectangle.h"
#include "Fish.h"
#include "Bird.h"
#include "FlyingBird.h"
#include "Student.h"
#include "Teacher.h"
#include "Summator.h"
#include "SquareSummator.h"
#include "CubeSummator.h"

using namespace std;

// Инициализация меню с заданиями
void Menu::initialize() {
    // Добавляем все задания в меню
    addItem("1. Geometric figures", [this]() { task1(); });
    addItem("2. Hierarchy of animals", [this]() { task2(); });
    addItem("3. Students and teachers", [this]() { task3(); });
    addItem("4. Sequence adders", [this]() { task4(); });
}

// Добавление пункта в меню
void Menu::addItem(const string& name, function<void()> action) {
    MenuItem item;
    item.name = name;
    item.action = action;
    items.push_back(item);
}

// Запуск меню
void Menu::run() {
    while (true) {
        cout << "\n=== Main menu ===" << endl;

        // Выводим все пункты меню
        for (size_t i = 0; i < items.size(); i++) {
            cout << items[i].name << endl;
        }
        cout << "0. Exit" << endl;

        int choice;
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 0) {
            break; // Выход из программы
        }

        // Проверяем правильность выбора
        if (choice > 0 && choice <= (int)items.size()) {
            items[choice - 1].action(); // Запускаем выбранное задание
        }
        else {
            cout << "Error! Please, try again" << endl;
        }
    }
}

// Задание 1: Геометрические фигуры
void Menu::task1() {
    while (true) {
        cout << "\n=== Geometric figures ===" << endl;
        cout << "1. Circle" << endl;
        cout << "2. Rectangle" << endl;
        cout << "0. Back" << endl;

        int choice;
        cout << "Select a figure: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1: task1_circle(); break;
        case 2: task1_rectangle(); break;
        default: cout << "Wrong choice!" << endl;
        }
    }
}

void Menu::task1_circle() {
    cout << "\n--- Circle ---" << endl;
    double radius;
    cout << "Enter radius: ";
    cin >> radius;

    Circle circle(radius);
    circle.Show();

    double height;
    cout << "Enter the height of the cylinder:";
    cin >> height;

    double volume = circle.CalcArea() * height;
    cout << "Cylinder capacity:" << volume << endl;
}

void Menu::task1_rectangle() {
    cout << "\n--- Rectangle ---" << endl;
    double width, height;
    cout << "Enter width:";
    cin >> width;
    cout << "Enter height:";
    cin >> height;

    Rectangle rect(width, height);
    rect.Show();

    double cylinderHeight;
    cout << "Enter the height of the cylinder: ";
    cin >> cylinderHeight;

    double volume = rect.CalcArea() * cylinderHeight;
    cout << "Cylinder capacity:" << volume << endl;
}

// Задание 2: Иерархия животных
void Menu::task2() {
    while (true) {
        cout << "\n=== Hierarchy of animals ===" << endl;
        cout << "1. Early binding" << endl;
        cout << "2. Late binding" << endl;
        cout << "0. Back" << endl;

        int choice;
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1: task2_early_binding(); break;
        case 2: task2_late_binding(); break;
        default: cout << "Wrong choice!" << endl;
        }
    }
}

void Menu::task2_early_binding() {
    cout << "\n--- Early binding ---" << endl;

    Fish fish;
    Bird bird;
    FlyingBird flyingBird;

    cout << "Fish:" << endl;
    fish.breathe();
    fish.eat();
    fish.swim();

    cout << "\nBird:" << endl;
    bird.breathe();
    bird.eat();
    bird.lay_eggs();

    cout << "\nFlying Bird:" << endl;
    flyingBird.breathe();
    flyingBird.eat();
    flyingBird.lay_eggs();
    flyingBird.fly();
}

void Menu::task2_late_binding() {
    cout << "\n--- Late binding ---" << endl;

    Animal* animals[3];
    animals[0] = new Fish();
    animals[1] = new Bird();
    animals[2] = new FlyingBird();

    for (int i = 0; i < 3; i++) {
        animals[i]->breathe();
        animals[i]->eat();
        delete animals[i];
    }
}

// Задание 3: Студенты и преподаватели
void Menu::task3() {
    cout << "\n=== Students and teachers ===" << endl;

    // Создаем студентов
    Student student1("Tupaev", "Nikolay", "Igorovich", { 4, 2, 5, 3 });
    Student student2("Noskov", "Semyon", "Andreevich", { 5, 4, 5 });

    // Создаем преподавателей
    Teacher teacher1("Duvanov", "Ivan", "Olegovich", Position::Docent, { "Programming" });
    Teacher teacher2("Pasyutin", "Alexander", "Sergeevich", Position::Professor, { "Computer Science", "Programming" });

    // Выводим информацию
    cout << "\nStudents:" << endl;
    cout << student1.getShortStudentInfo() << endl;
    cout << student2.getFullStudentInfo() << endl;

    cout << "\nTeachers:" << endl;
    cout << teacher1.getShortTeacherInfo() << endl;
    cout << teacher2.getFullTeacherInfo() << endl;
}

// Задание 4: Сумматоры последовательностей
void Menu::task4() {
    cout << "\n=== Sequence adders ===" << endl;

    int N;
    cout << "Enter number N: ";
    cin >> N;

    Summator basic;
    SquareSummator squares;
    CubeSummator cubes;

    cout << "Sum of numbers:" << basic.sum(N) << endl;
    cout << "Sum of squares:" << squares.sum(N) << endl;
    cout << "Sum of cubes:" << cubes.sum(N) << endl;
}
