#include <iostream>
using namespace std;

struct list {
    int val;
    list* next;
    list* prev;
};

void F12(list*& ph, int v, int n) {
    list* q = new list;
    int n0 = n;
    q->val = v;
    q->next = q->prev = q;

    if (ph == nullptr) {
        ph = q;
        return;
    }

    list* p;
    for (p = ph; n-- != 0; p = p->next);

    q->next = p;
    q->prev = p->prev;
    p->prev->next = q;
    p->prev = q;

    if (n0 == 0) ph = q;
}

void print(list* ph) {
    if (!ph) return;
    list* p = ph;
    do {
        cout << p->val << " ";
        p = p->next;
    } while (p != ph);
    cout << endl;
}

int main() {
    // Создание статического циклического списка: 10 <-> 20 <-> 30
    list a = {10, nullptr, nullptr};
    list b = {20, nullptr, nullptr};
    list c = {30, nullptr, nullptr};

    // Установка связей (кольцо)
    a.next = &b; a.prev = &c;
    b.next = &c; b.prev = &a;
    c.next = &a; c.prev = &b;

    list* head = &a;

    // Вставка числа 15 перед 2-м элементом (счёт от головы)
    F12(head, 15, 2);  // Список: 10 20 15 30

    print(head);

    return 0;
}
