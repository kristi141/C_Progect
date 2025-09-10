#include <iostream>
using namespace std;

struct btree {
    int val;
    btree *l;
    btree *r;
};

int F9(btree *p) { 
    if (p == NULL) return 0;

    int nr = F9(p->r);
    int nl = F9(p->l);

    return 1 + (nr > nl ? nr : nl);
}

int main() {
    // Лист
    btree n4 = {4, nullptr, nullptr};

    // Поддеревья
    btree n2 = {2, nullptr, nullptr};
    btree n3 = {3, &n4, nullptr};

    // Корень
    btree n1 = {1, &n2, &n3};

    // Вызов функции
    int result = F9(&n1);
    cout << "Высота дерева: " << result << endl;

    return 0;
}
