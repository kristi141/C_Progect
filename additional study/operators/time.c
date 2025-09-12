/*Необходимо продолжить программу, которая складывает время, указанное в часах, минутах и секундах. 
Исходное время хранится в переменных time_h, time_m, time_s, а добавляемое - в переменных h, m, s. 
Гарантируется, что сумма времен не превышает одни сутки. Вывести полученное суммарное время в консоль в формате:
hh:mm:ss

Например:
12:05:09

It is necessary to continue the program, which adds up the time specified in hours, minutes and seconds. 
The original time is stored in the variables time_h, time_m, time_s, and the added time is stored in the variables h, m, s. 
It is guaranteed that the sum of times does not exceed one day. Output the resulting total time to the console in the format:
hh:mm:ss

For example:
12:05:09*/

#include <stdio.h>

int main(void)
{
    unsigned short time_h = 10; // часы
    unsigned short time_m = 33; // минуты
    unsigned short time_s = 5; // секунды

    unsigned short h, m, s; // добавляемое время: h - часы; m - минуты; s - секунды
    scanf("%hu; %hu; %hu", &h, &m, &s);
    
    unsigned short time_1 = time_h * 3600 + time_m * 60 + time_s;
    unsigned short time_2 = h * 3600 + m * 60 + s;
    
    long int time = time_1 + time_2;
    
    long int sec = time % 60;
    long int min = (time / 60) % 60;
    long int hour = time / 3600;
    
    printf("%02ld:%02ld:%02ld", hour, min, sec);

    return 0;
}