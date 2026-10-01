#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // House body
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_LINE_LOOP);

        glVertex2i(100, 0);
        glVertex2i(300, 0);
        glVertex2i(300, 200);
        glVertex2i(100, 200);

    glEnd();


    // Roof
    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_LINE_LOOP);

        glVertex2i(100, 200);
        glVertex2i(200, 300);
        glVertex2i(300, 200);

    glEnd();


    // Door
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_LINE_LOOP);

        glVertex2i(170, 0);
        glVertex2i(230, 0);
        glVertex2i(230, 120);
        glVertex2i(170, 120);

    glEnd();


    // Left window
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINE_LOOP);

        glVertex2i(120, 80);
        glVertex2i(150, 80);
        glVertex2i(150, 130);
        glVertex2i(120, 130);

    glEnd();


    // Right window
    glBegin(GL_LINE_LOOP);

        glVertex2i(250, 80);
        glVertex2i(280, 80);
        glVertex2i(280, 130);
        glVertex2i(250, 130);

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

    glutCreateWindow("House");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}