#include <iostream>
#include <vector>
#include <string>

using namespace std;

void findExpressions(string expr, int pos, int target, int currentValue, int lastValue,
 vector<string>& results) {

    if (pos == 9) {
        if (currentValue == target) {
            results.push_back(expr);
        }
        return;
    }

    int nextPos = pos + 1;
    string numStr = to_string(nextPos);
    int num = nextPos;

    findExpressions(expr + "+" + numStr, nextPos, target, currentValue + num, num, results);
    findExpressions(expr + "-" + numStr, nextPos, target, currentValue - num, -num, results);
    findExpressions(expr + "*" + numStr, nextPos, target, currentValue - lastValue + lastValue * num, 
    lastValue * num, results);

    if (num != 0 && lastValue % num == 0) {
        findExpressions(expr + "/" + numStr, nextPos, target, currentValue - lastValue + lastValue / num, 
        lastValue / num, results);
    }
}

void findTargetExpressions(int target) {
    vector<string> results;
    findExpressions("1", 1, target, 1, 1, results);

    if (results.empty()) {
        cout << "Не найдено выражений для получения числа " << target << endl;
    } else {
        cout << "Выражения, которые достигают числа " << target << ":" << endl;
        for (const string& expr : results) {
            cout << expr << endl;
        }
    }
}

int main() {
    int target;

    cout << "Введите необходимое значение: ";
    cin >> target;

    findTargetExpressions(target);
    
    return 0;
}