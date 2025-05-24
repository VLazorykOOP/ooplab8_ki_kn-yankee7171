#include <iostream>     
#include <cstring>      
using namespace std;

//  ������ ������� ��� ��������� ���� 
template <typename T>
void findMaxAndCount(T arr[], int size, T& maxVal, int& count) {
    maxVal = arr[0];        // ����������, �� ������ ������� � ������������
    count = 1;

    for (int i = 1; i < size; ++i) {      // ��������� ����� ������
        if (arr[i] > maxVal) {           // ���� �������� ������
            maxVal = arr[i];             // �������� ���� �� ����� ��������
            count = 1;                   // � ������� ��������
        }
        else if (arr[i] == maxVal) {   // ���� ����� �����
            count++;                     // �������� �������
        }
    }
}

//  ������������ ��� char*  
template <>
void findMaxAndCount<char*>(char* arr[], int size, char*& maxVal, int& count) {
    maxVal = arr[0];        // ����������, �� ������ ����� � ������������
    count = 1;

    for (int i = 1; i < size; ++i) {              // ��������� ����� �����
        if (strcmp(arr[i], maxVal) > 0) {         // ���� arr[i]  �����
            maxVal = arr[i];                      // �������� ���� �� ����� ��������
            count = 1;                            // � ������� ��������
        }
        else if (strcmp(arr[i], maxVal) == 0) { // ���� ������� ���������
            count++;                              // �������� ��������
        }
    }
}


int main() {
    //  ����� ����� ����� 
    int numbers[] = { 4, 7, 1, 7, 3 };   // ��������� ����� int
    int maxNum;                        // ����� ��� ���������
    int countNum;                      // ����� ��� �������
    findMaxAndCount(numbers, 5, maxNum, countNum);   // ��������� ������
    cout << "max (int): " << maxNum << ", �������: " << countNum << endl;

    //  ����� ����� (char*)
    const char* words[] = { "cat", "dog", "zebra", "dog", "zebra" }; // ��������� ����� ��������� �� ����� 
    const char* maxWord; // ����� ��� ��������� ��������� �� ������������ �����
    int countWord; // ����� ��� ��������� ������� �������� ������������� �����
    findMaxAndCount(words, 5, maxWord, countWord); // ��������� �������� ������� ��� ������ ������������� ������� ��������� ������� ���� ��������� � ����� � 5 ��������
    cout << "max (char*): " << maxWord << ", �������: " << countWord << endl; // �������� ���������: ����� "�������" �� �������� ����� �� ������� ���� ��������


    return 0;
}
