#include <iostream>
using namespace std;

// Структура узла дерева
struct ltree {
    int val;
    ltree *child; // указатель на первого 
    ltree *next;  // указатель на следующего 
};

// Рекурсивная функция поиска максимального значения
int F3(ltree *p) {
    int n = p->val;

    for (ltree *q = p->child; q != nullptr; q = q->next) {
        int vv = F3(q);
        if (vv > n) n = vv;
    }

    return n;
}

int main() {
    ltree n7   = {7, nullptr, nullptr};
    ltree n30  = {30, nullptr, nullptr};
    ltree n5   = {5, nullptr, nullptr};

    // Узел 20 с детьми: 7 -> 30
    ltree n20  = {20, &n7, nullptr};
    n7.next    = &n30;

    // Корень 10 с детьми: 20 -> 5
    ltree n10  = {10, &n20, nullptr};
    n20.next   = &n5;

    // Вызов функции и вывод результата
    int result = F3(&n10);
    cout << "Максимальное значение в дереве: " << result << endl;

    return 0;
}
