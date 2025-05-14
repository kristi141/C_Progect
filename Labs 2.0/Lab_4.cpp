#include <iostream>
using namespace std;

struct node {
    int value;
    node* next;
    node* prev;
    node(int value) : value(value), next(nullptr), prev(nullptr) {}
};

struct List {
    node* first;
    node* last;

    List() : first(nullptr), last(nullptr) {}

    bool empty() {
        return first == nullptr;
    }

    void pushBack(int value) {
        node* p = new node(value);

        if (empty()) {
            first = p;
            last = p;
            return;
        }

        p->prev = last;
        last->next = p;
        last = p;
    }

    void print() {
        if (empty()) {
            cout << "Список пуст" << endl;
            return;
        }
        node* p = first;

        while (p) {
            cout << p->value << " ";
            p = p->next;
        }

        cout << endl;
    }

    // Функция объединения двух списков
    void mergeLists(List& other) {
        if (other.empty()) return;
        if (empty()) {
            first = other.first;
            last = other.last;
        } else {
            last->next = other.first;
            other.first->prev = last;
            last = other.last;
        }
        // Обнуляем второй список
        other.first = other.last = nullptr;
    }
};

int main() {
    List list1, list2;
    int n, count1, count2;

    cout << "Введите количество элементов первого списка: ";
    cin >> count1;
    cout << "Введите элементы первого списка: ";
    for (int i = 0; i < count1; i++) {
        cin >> n;
        list1.pushBack(n);
    }

    cout << "Введите количество элементов второго списка: ";
    cin >> count2;
    cout << "Введите элементы второго списка: ";
    for (int i = 0; i < count2; i++) {
        cin >> n;
        list2.pushBack(n);
    }

    list1.mergeLists(list2);

    cout << "Объединенный список: ";
    list1.print();

    return 0;
}
