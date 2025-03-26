#include <iostream>
using namespace std;

int F2(char* c) {
    int nc;
    char* p;
    for (nc = 0, p = c; *c != 0; c++)
        if (*c != ' ' && (p == c || c[-1] == ' ')) nc++;
    return nc;

}

int main() {
    char text[] = "qwer tyuiop fghj";

    int words = F2(text);

    cout << "Количество слов: " << words << endl;

    return 0;
}