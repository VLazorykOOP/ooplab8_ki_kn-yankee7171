#include <iostream>     
#include <cstring>      
using namespace std;

//  Шаблон функції для загальних типів 
template <typename T>
void findMaxAndCount(T arr[], int size, T& maxVal, int& count) {
    maxVal = arr[0];        // Припускаємо, що перший елемент — максимальний
    count = 1;

    for (int i = 1; i < size; ++i) {      // Проходимо решту масиву
        if (arr[i] > maxVal) {           // Якщо знайдено більший
            maxVal = arr[i];             // Зберігаємо його як новий максимум
            count = 1;                   // І скидаємо лічильник
        }
        else if (arr[i] == maxVal) {   // Якщо такий самий
            count++;                     // Збільшуємо кількість
        }
    }
}

//  Спеціалізація для char*  
template <>
void findMaxAndCount<char*>(char* arr[], int size, char*& maxVal, int& count) {
    maxVal = arr[0];        // Припускаємо, що перший рядок — максимальний
    count = 1;

    for (int i = 1; i < size; ++i) {              // Проходимо масив рядків
        if (strcmp(arr[i], maxVal) > 0) {         // Якщо arr[i]  більше
            maxVal = arr[i];                      // Зберігаємо його як новий максимум
            count = 1;                            // І скидаємо лічильник
        }
        else if (strcmp(arr[i], maxVal) == 0) { // Якщо дорівнює максимуму
            count++;                              // Збільшуємо лічильник
        }
    }
}


int main() {
    //  Масив цілих чисел 
    int numbers[] = { 4, 7, 1, 7, 3 };   // Створюємо масив int
    int maxNum;                        // Змінна для максимуму
    int countNum;                      // Змінна для кількості
    findMaxAndCount(numbers, 5, maxNum, countNum);   // Викликаємо шаблон
    cout << "max (int): " << maxNum << ", кількість: " << countNum << endl;

    //  Масив рядків (char*)
    const char* words[] = { "cat", "dog", "zebra", "dog", "zebra" }; // Створюємо масив покажчиків на рядки 
    const char* maxWord; // Змінна для зберігання покажчика на максимальний рядок
    int countWord; // Змінна для підрахунку кількості входжень максимального рядка
    findMaxAndCount(words, 5, maxWord, countWord); // Викликаємо шаблонну функцію для пошуку максимального рядката підрахунку кількості його повторень у масиві з 5 елементів
    cout << "max (char*): " << maxWord << ", кількість: " << countWord << endl; // Виводимо результат: самий "великий" за алфавітом рядок та кількість його входжень


    return 0;
}
