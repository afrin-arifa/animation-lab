#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_TRIANGLES);

        glVertex2f(100, 100);
        glVertex2f(300, 100);
        glVertex2f(200, 300);

    glEnd();

    glFlush();
}

void init()
{
    // Light gray background
    glClearColor(0.8, 0.8, 0.8, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 400, 0, 400);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(400, 400);

    glutCreateWindow("Background Color");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}