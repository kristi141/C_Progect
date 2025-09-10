//возвращает длину самой длинной последовательности подряд идущих единиц в машинном слове.

#include <iostream>
using namespace std;

int F9(long n) {
    int i, m, k;
    for (i = m = k = 0; i < sizeof(long) * 8; i++, n >>= 1)
        if (n & 1) k++;
        else {
            if (k > m) m = k;
            k = 0;
        }
    return m;
}

int main() {
   long value = 0x0000000000000F38;
    int result = F9(value);
    cout << "Максимальная длина последовательности единиц: " << result << endl;
    return 0;
}
