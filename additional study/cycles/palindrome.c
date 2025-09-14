/* Напишите программу, которая читает натуральное число, содержащее одну и более цифр. 
Определить, что это число является палиндромом, то есть, оно не меняет своего значения при просмотре слева-направо 
и справа-налево. Например: 121, 23032, 11 и т.п. Если число является палиндромом, 
то в консоль вывести строку "yes", иначе - строку "no".

Write a program that reads a natural number containing one or more digits. 
Determine that this number is a palindrome, that is, it does not change its value when viewed from left to right
and from right to left. For example: 121, 23032, 11, etc. If the number is a palindrome,
then output the string "yes" to the console, otherwise the string "no".*/

#include <stdio.h>

int main()
{
    int n, copy_n = 0; 
    int rev = 0,a;
    
    scanf("%d", &n);
    copy_n = n;
    
    while(n  != 0){
        a = n % 10;
        rev = rev * 10 + a;
   
        n /= 10;   
    }
    
    if(copy_n == rev){
        printf("yes");
    }else{
        printf("no");
    }

        return 0;
}