#include "Bell.h"

Bell::Bell() : lastSound("dong") {}

// ����� ��� ��������������� �����
void Bell::sound() {
    if (lastSound == "dong") {
        std::cout << "ding" << std::endl;
        lastSound = "ding";
    }
    else {
        std::cout << "dong" << std::endl;
        lastSound = "dong";
    }
}
