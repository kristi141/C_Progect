//односвязный список

#include <iostream>
using namespace std;

struct list {
    int val;
    list* next;
};

list* F8(list* ph) {
    list *q, *out, *p, *pr;
    out = nullptr;

    while (ph != nullptr) {
        q = ph;
        ph = ph->next;

        for (p = out, pr = nullptr; p != nullptr && q->val > p->val; pr = p, p = p->next);

        if (pr == nullptr) {
            q->next = out;
            out = q;
        } else {
            q->next = p;
            pr->next = q;
        }
    }

    return out;
}

void print(list* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    list n4 = {2, nullptr};
    list n3 = {4, &n4};
    list n2 = {1, &n3};
    list n1 = {3, &n2};

    list* sorted = F8(&n1);

    cout << "Отсортированный список: ";
    print(sorted);

    return 0;
}
