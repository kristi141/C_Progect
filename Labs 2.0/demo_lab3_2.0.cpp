#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Функция поиска повторяющихся символов
vector<string> findRepeatingFragments(const string& input) {
    vector<string> fragments;
    int n = input.length();
    if (n == 0) return fragments;

    char current = input[0];
    int count = 1;
    int start = 0;

    for (int i = 1; i <= n; ++i) {
        if (i < n && input[i] == current) {
            count++;
        } else {
            if (count >= 4 && current != ' ') {
                fragments.push_back(input.substr(start, count));
            }

            if (i < n) {
                current = input[i];
                count = 1;
                start = i;
            }
        }
    }

    return fragments;
}

int main() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input);

    vector<string> result = findRepeatingFragments(input);

    cout << "Найденные фрагменты:\n";
    for (const string& frag : result) {
        cout << frag << endl;
    }

    return 0;
}
