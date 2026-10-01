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
    glColor3f(0.1, 0.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(150, 150);
        glVertex2i(350, 150);
        glVertex2i(350, 350);
        glVertex2i(150, 350);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2i(150, 350);
        glVertex2i(250, 450);
        glVertex2i(350, 350);
    glEnd();
    glColor3f(0.1, 0.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2i(170, 290);
        glVertex2i(200, 290);
        glVertex2i(200, 320);
        glVertex2i(170, 320);
    glEnd();
    glColor3f(0.1, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2i(290, 290);
        glVertex2i(320, 290);
        glVertex2i(320, 320);
        glVertex2i(290, 320);
    glEnd();
    glColor3f(0.0, 0.1, 0.0);
    glBegin(GL_QUADS);
        glVertex2i(235, 150);
        glVertex2i(275, 150);
        glVertex2i(275, 270);
        glVertex2i(235, 270);
    glEnd();
    

    glutSwapBuffers();
}
void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 600, 0, 600);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("House");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}