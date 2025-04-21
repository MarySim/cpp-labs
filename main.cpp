#include <iostream>
#include "Menu.h"

int main() {
    setlocale(0, "");

    Menu menu;
    int choice;

    do {
        menu.ShowMenu();
        std::cin >> choice;
        menu.RunTask(choice);
    } while (choice != 0);

    return 0;
}
