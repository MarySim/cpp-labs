#ifndef BELL_H
#define BELL_H

#include <iostream>
#include <string>

class Bell {
private:
    std::string lastSound;

public:
    Bell();
    void sound(); // ����� ��� ��������������� ����� (����������� ������� "ding" � "dong")
};

#endif // BELL_H
