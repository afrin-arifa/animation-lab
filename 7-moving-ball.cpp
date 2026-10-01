#include <GL/glut.h>
#include <cmath>

float x = -0.8f;
float speed = 0.01f;


void drawBall()
{
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, 0.0f);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        glVertex2f(
            x + 0.1f * std::cos(angle),
            0.1f * std::sin(angle)
        );
    }

    glEnd();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawBall();

    glutSwapBuffers();
}


void update(int value)
{
    // Move right
    x += speed;

    // Restart from left
    if (x > 1.1f)
    {
        x = -1.1f;
    }

    glutPostRedisplay();

    glutTimerFunc(16, update, 0);
}


void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutCreateWindow("Moving Ball");

    init();

    glutDisplayFunc(display);

    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}