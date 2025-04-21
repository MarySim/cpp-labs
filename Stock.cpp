#include "Stock.h"

Stock::Stock() : capacity(10), size(0), serialCounter(0) {
    boxes = new Box[capacity];
}

Stock::~Stock() {
    delete[] boxes;
}

// ����� ��� ���������� ������� �� �����
void Stock::Add(int w, int v) {
    if (size >= capacity) {
        std::cerr << "������: ��������� ������������ ���������� �������." << std::endl;
        return;
    }

    boxes[size].weight = w;
    boxes[size].volume = v;
    boxes[size].serial = serialCounter++;

    size++;
    std::cout << "������� ���������. �������� �����: " << boxes[size - 1].serial << std::endl;
}

// ����� ��� ��������� ������� �� ����������� ����������������
int Stock::GetByW(int min_w) {
    int selectedSerial = -1;  // �������� ����� ��������� �������
    int minWeight = INT_MAX;  // ����������� ����������������

    for (int i = 0; i < size; ++i) {
        if (boxes[i].weight >= min_w && boxes[i].weight < minWeight) {
            minWeight = boxes[i].weight;
            selectedSerial = boxes[i].serial;
        }
    }

    if (selectedSerial != -1) {
        std::cout << "������ ������� � �������� �������: " << selectedSerial << std::endl;
    }
    else {
        std::cout << "���������� ������� �� �������." << std::endl;
    }

    return selectedSerial;
}

// ����� ��� ��������� ������� �� ������������ ������
int Stock::GetByV(int min_v) {
    int selectedSerial = -1;  // �������� ����� ��������� �������
    int minVolume = INT_MAX;  // ����������� �����

    for (int i = 0; i < size; ++i) {
        if (boxes[i].volume >= min_v && boxes[i].volume < minVolume) {
            minVolume = boxes[i].volume;
            selectedSerial = boxes[i].serial;
        }
    }

    if (selectedSerial != -1) {
        std::cout << "������ ������� � �������� �������: " << selectedSerial << std::endl;
    }
    else {
        std::cout << "���������� ������� �� �������." << std::endl;
    }

    return selectedSerial;
}
