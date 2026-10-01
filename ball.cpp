#include <GL/glut.h>
#include <cmath>

float x = -0.9f;
float speed = 0.01f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw ball
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, 0.0f);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(x + 0.1f * cos(angle),
                   0.1f * sin(angle));
    }

    glEnd();

    glutSwapBuffers();
}

void update(int value)
{
    x += speed;

    // Reverse direction at boundaries
    if (x > 0.9f || x < -0.9f)
        speed = -speed;

    glutPostRedisplay();

    glutTimerFunc(16, update, 0);
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Animation");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}