#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_LINES);

        // Horizontal line
        glVertex2i(0, 200);
        glVertex2i(400, 200);

        // Vertical line
        glVertex2i(200, 0);
        glVertex2i(200, 400);

    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 400, 0, 400);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(400, 400);

    glutCreateWindow("Lines");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}