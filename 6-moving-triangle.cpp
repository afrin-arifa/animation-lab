#include <GL/glut.h>
#include <stdlib.h>

float triX = 0.0f;


void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
            exit(0);
            break;

        case 'a':
        case 'A':
            triX -= 0.1f;
            break;

        case 'd':
        case 'D':
            triX += 0.1f;
            break;
    }

    glutPostRedisplay();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Move triangle
    glTranslatef(triX, 0.0f, 0.0f);

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_TRIANGLES);

        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(0.0f, 1.0f);

    glEnd();

    glutSwapBuffers();
}


void init()
{
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-5.0, 5.0, -5.0, 5.0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutCreateWindow("Moving Triangle");

    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(handleKeypress);

    glutMainLoop();

    return 0;
}