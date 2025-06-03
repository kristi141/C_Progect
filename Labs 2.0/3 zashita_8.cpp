//8
/*Функция удаляет строку с индексом m из массива указателей на строки p[], 
сдвигает все последующие строки на одну позицию влево и возвращает указатель на удалённую строку. 
Если индекс m выходит за границы массива — возвращает nullptr.*/

#include <iostream>
using namespace std;

char* F8(char* p[], int m) {
    int n = 0;
    char* q;

    // Определяем длину массива (до NULL)
    while (p[n] != nullptr) n++;

    // Проверка выхода за границы
    if (m >= n) return nullptr;

    // Сохраняем указатель на удаляемую строку
    q = p[m];

    // Сдвигаем элементы влево
    for (int i = m; p[i] != nullptr; i++) {
        p[i] = p[i + 1];
    }

    return q;
}

int main() {
    // Статически заданный массив строк
    char str0[] = "apple";
    char str1[] = "banana";
    char str2[] = "cherry";
    char str3[] = "date";

    // Массив указателей на строки
    char* arr[] = {str0, str1, str2, str3, nullptr};

    // Удаляем строку с индексом 1 ("banana")
    char* removed = F8(arr, 1);

    if (removed != nullptr)
        cout << "Удаление: " << removed << endl;

    cout << "Массив после удаления:\n";
    for (int i = 0; arr[i] != nullptr; ++i) {
        cout << arr[i] << endl;
    }

    return 0;
}
