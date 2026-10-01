#include <GL/glut.h>

float angle = 0.0f;


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_QUADS);

        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(-0.5f, 0.5f);

    glEnd();

    glutSwapBuffers();
}


void update(int value)
{
    angle += 2.0f;

    if (angle > 360.0f)
    {
        angle -= 360.0f;
    }

    glutPostRedisplay();

    glutTimerFunc(25, update, 0);
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

    glutCreateWindow("Rotating Square");

    init();

    glutDisplayFunc(display);

    glutTimerFunc(25, update, 0);

    glutMainLoop();

    return 0;
}