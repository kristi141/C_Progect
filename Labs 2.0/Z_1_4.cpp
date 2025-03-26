#include <iostream>
using namespace std;

void F4(char* c) {
    for (; *c != 0; c++)
        if (*c == ' ' && c[1] == ' ') {
            for (char* p = c; *p != 0; p++) *p = p[1];
            c--;
        }
}
int main() {
    char text[] = "wertyu       f dfgu      vukvhkugv      xdtfcyvgubhi";

    cout << "До: " << text << endl;
    F4(text);
    cout << "После: " << text << endl;

    return 0;
}