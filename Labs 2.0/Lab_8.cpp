#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

using namespace std;

// Преобразует десятичную строку в битовый вектор (LSB — младший бит)
vector<uint8_t> decimalToBits(const string& num) {
    vector<uint8_t> bits;
    string n = num;

    while (n != "0") {
        int remainder = 0;
        string temp = "";

        for (char c : n) {
            int digit = remainder * 10 + (c - '0');
            temp += (digit / 2) + '0';
            remainder = digit % 2;
        }
        bits.push_back(remainder & 1); // маска для младшего бита
        n = temp.erase(0, temp.find_first_not_of('0'));

        if (n.empty()){
             n = "0";
        }
    }
    return bits;
}

// Преобразует битовый вектор обратно в десятичную строку
string bitsToDecimal(const vector<uint8_t>& bits) {
    vector<uint8_t> decimal = {0};

    for (int i = bits.size() - 1; i >= 0; --i) {
        int carry = bits[i];

        for (int j = decimal.size() - 1; j >= 0; --j) {
            int val = (decimal[j] << 1) + carry;
            decimal[j] = val % 10;
            carry = val / 10;
        }
        while (carry > 0) {
            decimal.insert(decimal.begin(), carry % 10);
            carry /= 10;
        }
    }
    string res;

    for (uint8_t d : decimal){
         res += (d | 0x30); // маска для перевода в ASCII-цифру
    }

    return res;
}

// Побитное умножение через маски и сдвиги
vector<uint8_t> bitwiseMultiply(const vector<uint8_t>& a, const vector<uint8_t>& b) {
    vector<uint8_t> result(a.size() + b.size(), 0);

    for (size_t i = 0; i < b.size(); ++i) {
        if ((b[i] & 1) == 1) {
            uint8_t carry = 0;

            for (size_t j = 0; j < a.size(); ++j) {
                uint8_t sum = result[i + j] ^ a[j] ^ carry;
                uint8_t carry_new = ((result[i + j] & a[j]) | (result[i + j] & carry) 
                | (a[j] & carry)) & 1;

                result[i + j] = sum & 1;
                carry = carry_new;
            }
            if (carry){
                result[i + a.size()] ^= carry;
            }
        }
    }
    return result;
}

int main() {
    string num1, num2;
    cout << "Введите первое число: ";
    cin >> num1;

    cout << "Введите второе число: ";
    cin >> num2;

    vector<uint8_t> bits1 = decimalToBits(num1);
    vector<uint8_t> bits2 = decimalToBits(num2);

    vector<uint8_t> productBits = bitwiseMultiply(bits1, bits2);
    string result = bitsToDecimal(productBits);

    cout << "Произведение: " << result << endl;
    
    return 0;
}