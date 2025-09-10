//считает, сколько раз в машинном слове встречается битовая тройка 101

#include <iostream>
using namespace std;

int F3(long n)
{
    int i, s;
    for (i = 0, s = 0; i < sizeof(long) * 8; i++, n >>= 1)
        if ((n & 0x7) == 5) {
            s++;
            i += 2;
        }
    return s;
}

int main() {
    //long value = 0x0000000000000155;
   // long value = 0x0000000000000AAA;
    long value = 0x00000000000000F5;
    int result = F3(value);
    cout << "Результат: " << result << endl;
    return 0;
}
