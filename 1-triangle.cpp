#include <GL/glut.h>
#include <cmath>

// Ball position
float ballX = -0.8f;
float ballY = -0.7f;

// Horizontal movement
float speedX = 0.005f;

// Vertical movement
float velocityY = 0.03f;
float gravity = -0.0015f;

// Ball size
float radius = 0.1f;

// Ground
float groundY = -0.8f;


// Draw ball
void drawBall()
{
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);

    // Center
    glVertex2f(ballX, ballY);

    // Circle
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


// Draw ground
void drawGround()
{
    glColor3f(0.0f, 0.6f, 0.0f);

    glBegin(GL_QUADS);

    glVertex2f(-1.0f, groundY);
    glVertex2f(1.0f, groundY);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);

    glEnd();
}


// Display
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawGround();
    drawBall();

    glutSwapBuffers();
}


// Animation
void update(int value)
{
    // -------------------------
    // Move forward
    // -------------------------
    ballX += speedX;


    // -------------------------
    // Jumping
    // -------------------------

    // Move vertically
    ballY += velocityY;

    // Gravity
    velocityY += gravity;


    // -------------------------
    // Check ground
    // -------------------------

    if (ballY - radius <= groundY)
    {
        ballY = groundY + radius;

        // Jump again
        velocityY = 0.03f;
    }


    // -------------------------
    // Restart from left
    // -------------------------

    if (ballX > 1.1f)
    {
        ballX = -1.1f;
    }


    // Redraw
    glutPostRedisplay();

    // Run again after 16 ms
    glutTimerFunc(16, update, 0);
}


// Initialize OpenGL
void init()
{
    // Sky blue background
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // 2D coordinate system
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}


// Main
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800, 600);

    glutCreateWindow("Jumping and Moving Ball");

    init();

    glutDisplayFunc(display);

    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}