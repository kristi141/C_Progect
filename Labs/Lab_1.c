/*Задание:
Квадраты-палиндромы. Вот любопытный предмет для исследований: найти 
квадраты целых чисел, которые можно читать как обычным образом, так и 
справа налево. Некоторые из них найти очень легко. Например, квадраты чисел 
1, 11, 111 и 1111 равны соответственно 1, 121, 12321 и 1 234321.Все 
получившиеся числа — палиндромы, и данное правило применимо к любому 
числу единиц, не превосходящему 9. Однако существуют и другие случаи, 
которые мы могли бы назвать нерегулярными. Например, 2642 = 69 696, а 22852 
= 5 221 225. Во всех приведенных выше примерах число цифр было нечетным. 
Не мог бы читатель привести примеры с четным числом цифр?

Объяснение кода:
Подключаем стандартную библиотеку stdio.h. В функции main создаём цикл for 
в котором перебираем числа от 1 до 10 000 каждый раз увеличивая num на 1. 
Внутри цикла ищем квадрат square текущего числа num. Переменная 
temp принимает значение square, 
i — счётчик для количества цифр. 
temp % 10 - извлекаем последнюю цифру числа temp, сохраняем ее в array[i]. 
temp /= 10 - удаляем последнюю цифру из temp. 
Цикл while продолжается, пока не будут извлечены все цифры. 
После завершения цикла в массиве array будут храниться все цифры числа square, 
а переменная i будет содержать количество цифр.
Создаём 2 цикла for, в первом цикле мы записываем массив в прямом порядке 
в переменную normal, для этого берём цифры с конца массива, 
во втором цикле записываем массив в переменную reverse в обратном порядке, 
для этого берём цифры с начала массива. Далее мы проверяем условием if, 
равно ли число в прямом и обратном порядке, то есть, 
является ли оно палиндромом. Далее проверяем имеет ли square 
четное количество цифр. Если все условия выполняются, выводим square.
В результате работы программы получим ответ: 698896.

Task:
Squares are palindromes. Here is a curious subject for research: to find
squares of integers that can be read both in the usual way and
from right to left. Some of them are very easy to find. For example, squares of numbers 
1, 11, 111 and 1111 are equal to 1, 121, 12321 and 1 234321, respectively.All
the resulting numbers are palindromes, and this rule applies to any
number of units not exceeding 9. However, there are other cases
that we could call irregular. For example, 2642 = 69,696, and 22852 
= 5 221 225. In all the examples above, the number of digits was odd. 
Could the reader give examples with an even number of digits?

Code explanation:
Connect the standard library stdio.h. In the main function, create a for loop
in which we iterate over the numbers from 1 to 10,000 each time increasing num by 1.
Inside the loop, we look for the square of the current number num. Variable 
temp takes the value square,
i is the counter for the number of digits. 
temp % 10 - extract the last digit of the temp number, save it in array[i]. 
temp /= 10 - remove the last digit from temp. 
The while loop continues until all the digits are extracted. 
After the loop is completed, all the digits of the square number will be stored in the array array, 
and the variable i will contain the number of digits.
We create 2 for cycles, in the first cycle we write the array in direct order
to the normal variable, for this we take the numbers from the end of the array,
in the second cycle we write the array to the reverse variable in reverse order,
for this we take the numbers from the beginning of the array. Next, we check with the if condition
whether the number is equal in forward and reverse order, that is, 
whether it is a palindrome. Next, we check whether square has
an even number of digits. If all the conditions are met, we output square.
As a result of the program, we get the answer: 698896.
*/

#include <stdio.h>

int main() {

    for (int num = 1; num <= 10000; num++) {
        int square = num * num; 

        int array[100001]; 

        int i = 0, temp = square;
        int normal = 0, reverse = 0;

        while (temp > 0) {

            array[i] = temp % 10;
            i++;
            temp /= 10;
        }

        for (int j = i - 1; j >= 0; j--) {

            normal = normal * 10 + array[j];
        }

        for (int k = 0; k < i; k++) {

            reverse = reverse * 10 + array[k];
        }

        if (normal == reverse) {

            if (i % 2 == 0) {
                printf("%d\n", square);
            }
        }
    }

    return 0;
}