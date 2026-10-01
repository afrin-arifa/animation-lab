#include <GL/glut.h>
#include <cmath>

float birdX = -1.0f;
float birdY = 0.2f;

float speed = 0.01f;
float wingAngle = 0.0f;
float wingSpeed = 5.0f;

void drawBird()
{
    glColor3f(0.0f, 0.0f, 0.0f);

    // Body
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(birdX, birdY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        glVertex2f(
            birdX + 0.15f * cos(angle),
            birdY + 0.08f * sin(angle)
        );
    }

    glEnd();


    // Left wing
    glPushMatrix();

    glTranslatef(birdX - 0.05f, birdY + 0.02f, 0.0f);
    glRotatef(wingAngle, 0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLES);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.15f, 0.15f);
    glVertex2f(-0.05f, -0.02f);

    glEnd();

    glPopMatrix();


    // Right wing
    glPushMatrix();

    glTranslatef(birdX + 0.05f, birdY + 0.02f, 0.0f);
    glRotatef(-wingAngle, 0.0f, 0.0f, 1.0f);

    glBegin(GL_TRIANGLES);

    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(0.05f, -0.02f);

    glEnd();

    glPopMatrix();


    // Beak
    glColor3f(1.0f, 0.5f, 0.0f);

    glBegin(GL_TRIANGLES);

    glVertex2f(birdX + 0.14f, birdY + 0.02f);
    glVertex2f(birdX + 0.25f, birdY);
    glVertex2f(birdX + 0.14f, birdY - 0.02f);

    glEnd();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawBird();

    glutSwapBuffers();
}


void update(int value)
{
    // Move bird horizontally
    birdX += speed;

    // Make bird move up and down
    birdY += 0.002f * sin(birdX * 10.0f);

    // Move wings
    wingAngle += wingSpeed;

    if (wingAngle > 30.0f || wingAngle < -30.0f)
    {
        wingSpeed = -wingSpeed;
    }

    // When bird leaves the right side,
    // start again from the left
    if (birdX > 1.2f)
    {
        birdX = -1.2f;
    }

    glutPostRedisplay();

    glutTimerFunc(16, update, 0);
}


void init()
{
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);

    glutCreateWindow("Flying Bird Animation");

    init();

    glutDisplayFunc(display);

    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}