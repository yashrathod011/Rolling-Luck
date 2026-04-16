#include <GL/glut.h>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cmath>
using namespace std;

float p1Pos = 0.5f, p2Pos = 0.5f;
bool isPlayer1Turn = true;
int lastRoll = 0;
bool gameOver = false;
string winner = "";

vector<pair<float, float>> getDots(int value) {
    vector<pair<float, float>> dots;

    if (value == 1)
    {
        dots.push_back({3.0f, 3.0f});
    }
    else if (value == 2)
    {
        dots.push_back({1.5f, 1.5f});
        dots.push_back({4.5f, 4.5f});
    }
    else if (value == 3)
    {
        dots.push_back({1.5f, 1.5f});
        dots.push_back({3.0f, 3.0f});
        dots.push_back({4.5f, 4.5f});
    }
    else if (value == 4)
    {
        dots.push_back({1.5f, 1.5f});
        dots.push_back({4.5f, 1.5f});
        dots.push_back({1.5f, 4.5f});
        dots.push_back({4.5f, 4.5f});
    }
    else if (value == 5)
    {
        dots.push_back({1.5f, 1.5f});
        dots.push_back({4.5f, 1.5f});
        dots.push_back({3.0f, 3.0f});
        dots.push_back({1.5f, 4.5f});
        dots.push_back({4.5f, 4.5f});
    }
    else if (value == 6)
    {
        dots.push_back({1.5f, 1.5f});
        dots.push_back({4.5f, 1.5f});
        dots.push_back({1.5f, 3.0f});
        dots.push_back({4.5f, 3.0f});
        dots.push_back({1.5f, 4.5f});
        dots.push_back({4.5f, 4.5f});
    }

    return dots;
}

void drawDot(float x, float y) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 30) {
        float rad = i * 3.14159 / 180.0;
        glVertex2f(x + cos(rad) * 0.4, y + sin(rad) * 0.4);
    }
    glEnd();
}

void drawDice(float x, float y, vector<pair<float, float>> dots) {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(x, y); glVertex2f(x + 6, y);
        glVertex2f(x + 6, y + 6); glVertex2f(x, y + 6);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    for (const auto& dot : dots)
    {
        drawDot(x + dot.first, y + dot.second);
    }
}

void drawText(float x, float y, std::string text) {
    glRasterPos2f(x, y);
    for (char c : text) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
        glVertex2f(90.0, 0.0);
        glVertex2f(90.0, 100.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(p1Pos, 60);
        glVertex2f(p1Pos + 5, 60);
        glVertex2f(p1Pos + 5, 70);
        glVertex2f(p1Pos, 70);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2f(p2Pos, 30);
        glVertex2f(p2Pos + 5, 30);
        glVertex2f(p2Pos + 5, 40);
        glVertex2f(p2Pos, 40);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    if (gameOver)
    {
        drawText(40, 50, "WINNER: " + winner);
    }
    else
    {
        if (isPlayer1Turn)
        {
            drawText(5, 80, "P1 Turn - Press Enter to Roll");
            drawDice(45, 85, getDots(lastRoll));
        }
        else
        {
            drawText(5, 10, "P2 Turn - Press Enter to Roll");
            drawDice(45, 5, getDots(lastRoll));
        }
        drawText(45, 50, "Last Roll: " + std::to_string(lastRoll));
    }

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 13 && !gameOver)
    {
        lastRoll = (rand() % 6) + 1;

        if (isPlayer1Turn)
        {
            p1Pos += lastRoll * 2;
            if (p1Pos >= 90)
            {
                winner = "Player 1 (Red)";
                gameOver = true;
            }
        }
        else
        {
            p2Pos += lastRoll * 2;
            if (p2Pos >= 90)
            {
                winner = "Player 2 (Blue)";
                gameOver = true;
            }
        }
        isPlayer1Turn = !isPlayer1Turn;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    srand(time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("2D Dice Race");

    gluOrtho2D(0, 100, 0, 100);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
