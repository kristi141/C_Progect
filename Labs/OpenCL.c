#include <stdlib.h>
#include <glut.h>
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>

GLint Width = 512, Height = 512;

void display()
{
    // Отрисовка прямоугольника-каркаса для основного светофора

    glClear(GL_COLOR_BUFFER_BIT); // очищаем экран
    gluOrtho2D(-200, 200, -200, 200);
    glColor3f(0.0, 0.0, 0.0); // устанавливаем цвет прямоугольника
    glBegin(GL_QUADS);
    glVertex2f(-160, -190); // левая нижняя вершина
    glVertex2f(-160, 190); // левая верхняя вершина
    glVertex2f(-20, 190); // правая верхняя вершина
    glVertex2f(-20, -190); // правая нижняя вершина
    glEnd();

    // Отрисовка прямоугольника-каркаса для маленького светофора
    glBegin(GL_QUADS);
    glVertex2f(30, -170); // левая нижняя вершина
    glVertex2f(30, 60); // левая верхняя вершина
    glVertex2f(150, 60); // правая верхняя вершина
    glVertex2f(150, -170); // правая нижняя вершина
    glEnd();

    // Отрисовка верхней окружности

    float radius = 53.0; // радиус окружности
    int num_segments = 1000; // количество сегментов (точность рисования)

    glColor3f(1.0, 0.0, 0.0); // устанавливаем цвет окружности
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-110, 290, -310, 90); // задаем систему координат
    glBegin(GL_LINE_LOOP); // рисуем линию, замыкающую окружность
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * (float)i / (float)num_segments; // угол текущего сегмента
        float x = radius * cosf(theta); // x-координата точки
        float y = radius * sinf(theta); // y-координата точки
        glVertex2f(x, y); // добавляем точку в список вершин
    }
    glEnd();

    // Отрисовка средней окружности

    glColor3f(1.0, 1.0, 0.0); // устанавливаем цвет окружности
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-110, 290, -200, 200); // задаем систему координат
    glBegin(GL_LINE_LOOP); // рисуем линию, замыкающую окружность
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * (float)i / (float)num_segments; // угол текущего сегмента
        float x = radius * cosf(theta); // x-координата точки
        float y = radius * sinf(theta); // y-координата точки
        glVertex2f(x, y); // добавляем точку в список вершин
    }
    glEnd();

    // Отрисовка нижней окружности

    glColor3f(0.0, 1.0, 0.0); // устанавливаем цвет окружности
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-110, 290, -90, 310); // задаем систему координат
    glBegin(GL_LINE_LOOP); // рисуем линию, замыкающую окружность
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * (float)i / (float)num_segments; // угол текущего сегмента
        float x = radius * cosf(theta); // x-координата точки
        float y = radius * sinf(theta); // y-координата точки
        glVertex2f(x, y); // добавляем точку в список вершин
    }
    glEnd();

    // Отрисовка верхней окружности пешеходного светофора

    glColor3f(1.0, 0.0, 0.0); // устанавливаем цвет окружности
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-290, 110, -200, 200); // задаем систему координат
    glBegin(GL_LINE_LOOP); // рисуем линию, замыкающую окружность
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * (float)i / (float)num_segments; // угол текущего сегмента
        float x = radius * cosf(theta); // x-координата точки
        float y = radius * sinf(theta); // y-координата точки
        glVertex2f(x, y); // добавляем точку в список вершин
    }
    glEnd();

    // Отрисовка нижней окружности пешеходного светофора

    glColor3f(0.0, 1.0, 0.0); // устанавливаем цвет окружности
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-290, 110, -90, 310); // задаем систему координат
    glBegin(GL_LINE_LOOP); // рисуем линию, замыкающую окружность
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * (float)i / (float)num_segments; // угол текущего сегмента
        float x = radius * cosf(theta); // x-координата точки
        float y = radius * sinf(theta); // y-координата точки
        glVertex2f(x, y); // добавляем точку в список вершин
    }
    glEnd();


    for (int color = 0;;)
        switch (color) {
        case 0: //красный

            glColor3f(0.0, 0.0, 0.0);               // "Гасим" предыдущий
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluOrtho2D(-110, 290, -200, 200);
            glBegin(GL_POLYGON);

            for (int i = 0; i < 360; i++) {
                float angle = 2.0f * 3.1415926f * i / 360.0f;
                float x = (radius - 1) * cosf(angle);
                float y = (radius - 1) * sinf(angle);
                glVertex2f(x, y);
            }
            glEnd();


            glColor3f(1.0, 0.0, 0.0);               // устанавливаем цвет круга
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluOrtho2D(-110, 290, -310, 90);        // задаем систему координат
            glBegin(GL_POLYGON);                    // Начинаем рисовать полигон
            // Рисуем круг с помощью многоугольника с большим количеством вершин
            for (int i = 0; i < 360; i++) {
                float angle = 2.0f * 3.1415926f * i / 360.0f;
                float x = radius * cosf(angle);
                float y = radius * sinf(angle);
                glVertex2f(x, y);
            }
            glEnd();

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluOrtho2D(-290, 110, -200, 200);
            glBegin(GL_POLYGON);
            glColor3f(0.0, 0.0, 0.0);
            for (int i = 0; i < 360; i++) {
                float angle = 2.0f * 3.1415926f * i / 360.0f;
                float x = (radius - 1) * cosf(angle);
                float y = (radius - 1) * sinf(angle);
                glVertex2f(x, y);
            }
            glEnd();
            glFlush();

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluOrtho2D(-290, 110, -90, 310);
            glBegin(GL_POLYGON);
            glColor3f(0.0, 1.0, 0.0);
            for (int i = 0; i < 360; i++) {
                float angle = 2.0f * 3.1415926f * i / 360.0f;
                float x = (radius)*cosf(angle);
                float y = (radius)*sinf(angle);
                glVertex2f(x, y);
            }
            glEnd();

            glFlush();

            color = 1;
            Sleep(5000);


        case 1://жёлтый
            glColor3f(0.0, 0.0, 0.0);               // "Гасим" предыдущий
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluOrtho2D(-110, 290, -310, 90);
            glBegin(GL_POLYGON);

            for (int i = 0; i < 1000; i++) {
                float angle = 2.0f * 3.1415926f * i / 360.0f;
                float x = (radius - 1) * cosf(angle);
                float y = (radius - 1) * sinf(angle);
                glVertex2f(x, y);
            }
            glEnd();

            glColor3f(1.0, 1.0, 0.0);               // устанавливаем цвет круга
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluOrtho2D(-110, 290, -200, 200);           // задаем систему координат
            glBegin(GL_POLYGON);                        // Начинаем рисовать полигон
            // Рисуем круг с помощью многоугольника с большим количеством вершин
            for (int i = 0; i < 360; i++) {
                float angle = 2.0f * 3.1415926f * i / 360.0f;
                float x = radius * cosf(angle);
                float y = radius * sinf(angle);
                glVertex2f(x, y);
            }
            glEnd();

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluOrtho2D(-290, 110, -90, 310);
            glBegin(GL_POLYGON);
            glColor3f(0.0, 0.0, 0.0);
            for (int i = 0; i < 360; i++) {
                float angle = 2.0f * 3.1415926f * i / 360.0f;
                float x = (radius - 1) * cosf(angle);
                float y = (radius - 1) * sinf(angle);
                glVertex2f(x, y);
            }
            glEnd();

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluOrtho2D(-290, 110, -200, 200);
            glBegin(GL_POLYGON);
            glColor3f(1.0, 0.0, 0.0);
            for (int i = 0; i < 360; i++) {
                float angle = 2.0f * 3.1415926f * i / 360.0f;
                float x = (radius)*cosf(angle);
                float y = (radius)*sinf(angle);
                glVertex2f(x, y);
            }
            glEnd();
            glFlush();

            color = 2;
            Sleep(2000);


        case 2://зелёный
            glColor3f(0.0, 0.0, 0.0);               // "Гасим" предыдущий
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluOrtho2D(-110, 290, -200, 200);
            glBegin(GL_POLYGON);

            for (int i = 0; i < 360; i++) {
                float angle = 2.0f * 3.1415926f * i / 360.0f;
                float x = (radius - 1) * cosf(angle);
                float y = (radius - 1) * sinf(angle);
                glVertex2f(x, y);
            }
            glEnd();

            glColor3f(0.0, 1.0, 0.0);               // устанавливаем цвет круга
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluOrtho2D(-110, 290, -90, 310);            // задаем систему координат
            glBegin(GL_POLYGON);                        // Начинаем рисовать полигон
            // Рисуем круг с помощью многоугольника с большим количеством вершин
            for (int i = 0; i < 360; i++) {
                float angle = 2.0f * 3.1415926f * i / 360.0f;
                float x = radius * cosf(angle);
                float y = radius * sinf(angle);
                glVertex2f(x, y);
            }
            glEnd();
            glFlush();
            color = 3;
            Sleep(5000);

            
        case 3://жёлтый
            glColor3f(0.0, 0.0, 0.0);               // "Гасим" предыдущий
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluOrtho2D(-110, 290, -90, 310);            // задаем систему координат
            glBegin(GL_POLYGON);                        // Начинаем рисовать полигон
            // Рисуем круг с помощью многоугольника с большим количеством вершин
            for (int i = 0; i < 360; i++) {
                float angle = 2.0f * 3.1415926f * i / 360.0f;
                float x = (radius - 1) * cosf(angle);
                float y = (radius - 1) * sinf(angle);
                glVertex2f(x, y);
            }
            glEnd();

            glColor3f(1.0, 1.0, 0.0);               // устанавливаем цвет круга
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluOrtho2D(-110, 290, -200, 200);           // задаем систему координат
            glBegin(GL_POLYGON);                        // Начинаем рисовать полигон
            // Рисуем круг с помощью многоугольника с большим количеством вершин
            for (int i = 0; i < 360; i++) {
                float angle = 2.0f * 3.1415926f * i / 360.0f;
                float x = radius * cosf(angle);
                float y = radius * sinf(angle);
                glVertex2f(x, y);
            }
            glEnd();
            glFlush();
            color = 0;
            Sleep(2000);
        }
}

void Keyboard(unsigned char key, int x, int y) {
#define ESCAPE '\033'	// Событие - символ клавиатуры
    if (key == ESCAPE)		// Клавиша ESCAPE
        exit(0);			// Закрыть программу
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // инициализация GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // установка режима отображения
    glutInitWindowSize(Width, Height); // установка размеров окна
    glutCreateWindow("Traffic Lights"); // создание окна с заголовком
    glClearColor(1.0, 1.0, 1.0, .0); // установка цвета фона
    glutDisplayFunc(display); // регистрация функции отображения
    glutMainLoop(); // запуск основного цикла GLUT

    return 0;
}
