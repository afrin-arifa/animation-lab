#include <GL/glut.h>
#include <cmath>

// Ball position
float ballX = 0.0f;
float ballY = -0.7f;

// Ball movement
float velocityY = 0.03f;
float gravity = -0.0015f;

// Ball radius
float radius = 0.1f;

// Ground position
float groundY = -0.8f;


// Draw the ball
void drawBall()
{
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);

    // Center of the ball
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


// Draw the ground
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


// Display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawGround();
    drawBall();

    glutSwapBuffers();
}


// Animation function
void update(int value)
{
    // Apply velocity to the ball
    ballY += velocityY;

    // Apply gravity
    velocityY += gravity;

    // Check if ball hits the ground
    if (ballY - radius <= groundY)
    {
        ballY = groundY + radius;

        // Jump again
        velocityY = 0.03f;
    }

    // Redraw
    glutPostRedisplay();

    // Call update again after 16 milliseconds
    glutTimerFunc(16, update, 0);
}


// Initialize OpenGL
void init()
{
    // Background color
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);

    // Set 2D projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}


// Main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    // Double buffering + RGB color
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Window size
    glutInitWindowSize(800, 600);

    // Window title
    glutCreateWindow("Jumping Ball Animation");

    // Initialize
    init();

    // Display function
    glutDisplayFunc(display);

    // Start animation
    glutTimerFunc(0, update, 0);

    // Start OpenGL loop
    glutMainLoop();

    return 0;
}