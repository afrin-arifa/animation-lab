#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.0, 0.0, 0.0);

    // Triangle 1
    glBegin(GL_TRIANGLES);
    glVertex2f(5, 20);
    glVertex2f(9, 20);
    glVertex2f(7, 17);
    glEnd();

    // Triangle 2
    glBegin(GL_TRIANGLES);
    glVertex2f(8, 16);
    glVertex2f(10, 19);
    glVertex2f(12, 16);
    glEnd();

    // Triangle 3
    glBegin(GL_TRIANGLES);
    glVertex2f(8, 15);
    glVertex2f(12, 15);
    glVertex2f(10, 12);
    glEnd();

    // Triangle 4
    glBegin(GL_TRIANGLES);
    glVertex2f(13, 15);
    glVertex2f(11, 12);
    glVertex2f(15, 12);
    glEnd();

    // Triangle 5
    glBegin(GL_TRIANGLES);
    glVertex2f(14, 15);
    glVertex2f(16, 12);
    glVertex2f(18, 15);
    glEnd();

    // Triangle 6
    glBegin(GL_TRIANGLES);
    glVertex2f(11, 11);
    glVertex2f(15, 11);
    glVertex2f(13, 8);
    glEnd();

    // Triangle 7
    glBegin(GL_TRIANGLES);
    glVertex2f(14, 16);
    glVertex2f(18, 16);
    glVertex2f(16, 19);
    glEnd();

    // Triangle 7
    glBegin(GL_TRIANGLES);
    glVertex2f(17, 20);
    glVertex2f(19, 17);
    glVertex2f(21, 20);
    glEnd();





    glFlush();
}

void init() {
    glClearColor(0.0, 0.5, 0.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(0, 25, 0, 25);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Basic Shapes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}