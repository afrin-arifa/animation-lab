#include <GL/glut.h>
#include <cmath>

float ballX = -0.8f;
float ballY = -0.7f;

float speedX = 0.005f;

float velocityY = 0.03f;
float gravity = -0.0015f;

float radius = 0.1f;

float groundY = -0.8f;


void drawBall()
{
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(ballX, ballY);

    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.14159f / 180.0f;

        glVertex2f(
            ballX + radius * std::cos(angle),
            ballY + radius * std::sin(angle)
        );
    }

    glEnd();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Ground
    glColor3f(0.0, 0.7, 0.0);

    glBegin(GL_QUADS);

        glVertex2f(-1.0f, groundY);
        glVertex2f(1.0f, groundY);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);

    glEnd();

    drawBall();

    glutSwapBuffers();
}


void update(int value)
{
    // Move forward
    ballX += speedX;

    // Jump
    ballY += velocityY;

    // Gravity
    velocityY += gravity;

    // Hit ground
    if (ballY - radius <= groundY)
    {
        ballY = groundY + radius;
        

        // Jump again
        velocityY = 0.03f;
    }

    // Start again from left
    if (ballX > 1.1f)
    {
        ballX = -1.1f;
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

    glutInitWindowSize(600, 600);

    glutCreateWindow("Jumping Ball");

    init();

    glutDisplayFunc(display);

    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}