/* На плоскости размером rect_width x rect_height (ширина x высота) размещены непересекающиеся прямоугольники 
одинаковых размеров w x h, следующих друг за другом. Необходимо продолжить программу, 
вычислив общее число прямоугольников не умещающихся целиком на плоскости. 
Результат вывести в консоль в виде одного целого числа.

Non-intersecting rectangles are placed on a plane with dimensions rect_width x rect_height (width x height) 
identical dimensions w x h, following each other. The program must be continued 
by calculating the total number of rectangles that do not fit entirely on the plane. 
The result is output to the console as a single integer. */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int rect_width = 640, rect_height = 480;
    int w = 1, h = 1;
    scanf("%d; %d", &w, &h);

    // здесь продолжайте программу
    
    int width = rect_width / w;
    int heigth = rect_height / h;
    int rectangle = width * heigth;
    
    bool widht_fit = rect_width % w;
    bool heigth_fit = rect_height % h;
    
    int rectangle_max = (width + widht_fit) * (heigth + heigth_fit);
    
    int res = rectangle_max - rectangle;

    printf("%d",res);
    
    return 0;
}