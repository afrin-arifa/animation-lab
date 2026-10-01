#include <GL/glut.h>
#include <cmath>

float carX = 0.0f;
float boatX = 0.0f;
float boatY = 0.0f;
float cloudX = 0.0f;
float birdX = 0.0f;

const float PI = 3.14159265359f;

/* =========================
   DDA LINE DRAWING ALGORITHM
   ========================= */

void DDA(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps;

    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);

    for (int i = 0; i <= steps; i++)
    {
        glVertex2f(round(x), round(y));

        x += xIncrement;
        y += yIncrement;
    }

    glEnd();
}

/* =========================
   BASIC SHAPES
   ========================= */

void rectangle(float x1, float y1, float x2, float y2)
{
    glBegin(GL_QUADS);

    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);

    glEnd();
}

void triangle(
    float x1, float y1,
    float x2, float y2,
    float x3, float y3)
{
    glBegin(GL_TRIANGLES);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);

    glEnd();
}

void circle(float cx, float cy, float radius)
{
    glBegin(GL_POLYGON);

    for (int i = 0; i < 100; i++)
    {
        float angle = 2.0f * PI * i / 100;

        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);

        glVertex2f(x, y);
    }

    glEnd();
}

/* =========================
   SUN
   ========================= */

void drawSun()
{
    glColor3f(1.0f, 0.85f, 0.0f);

    circle(1060, 665, 55);

    glColor3f(0.0f, 0.0f, 0.0f);

    glPointSize(2.0f);

    DDA(1060, 735, 1060, 790);
    DDA(1060, 595, 1060, 540);

    DDA(990, 665, 935, 665);
    DDA(1130, 665, 1185, 665);

    DDA(1010, 715, 970, 755);
    DDA(1110, 715, 1150, 755);

    DDA(1010, 615, 970, 575);
    DDA(1110, 615, 1150, 575);
}

/* =========================
   CLOUD
   ========================= */

void drawCloud(float x, float y)
{
    glColor3f(1.0f, 1.0f, 1.0f);

    circle(x, y, 35);
    circle(x + 40, y + 15, 45);
    circle(x + 85, y, 35);
    circle(x + 45, y - 10, 50);
}

/* =========================
   MOUNTAINS
   ========================= */

void drawMountains()
{
    glColor3f(0.05f, 0.42f, 0.22f);

    triangle(
        480, 350,
        670, 500,
        850, 350
    );

    triangle(
        800, 350,
        1030, 500,
        1230, 350
    );

    triangle(
        600, 350,
        810, 520,
        1030, 350
    );
}

/* =========================
   LAKE
   ========================= */

void drawLake()
{
    glColor3f(0.0f, 0.40f, 0.90f);

    glBegin(GL_POLYGON);

    glVertex2f(480, 350);
    glVertex2f(1200, 350);
    glVertex2f(1200, 0);
    glVertex2f(900, 0);
    glVertex2f(580, 130);
    glVertex2f(480, 220);

    glEnd();

    /* Water lines using DDA */

    glColor3f(1.0f, 1.0f, 1.0f);

    DDA(690, 275, 775, 275);
    DDA(810, 225, 900, 225);
    DDA(920, 180, 1010, 180);
    DDA(1070, 245, 1150, 245);
}

/* =========================
   GRASS / GROUND
   ========================= */

void drawGround()
{
    glColor3f(0.20f, 0.65f, 0.25f);

    glBegin(GL_POLYGON);

    glVertex2f(0, 350);
    glVertex2f(480, 350);
    glVertex2f(900, 0);
    glVertex2f(0, 0);

    glEnd();
}

/* =========================
   TREE
   ========================= */

void drawTree()
{
    glColor3f(0.40f, 0.20f, 0.08f);

    rectangle(
        80, 240,
        115, 420
    );

    glColor3f(0.0f, 0.45f, 0.15f);

    circle(
        100, 460,
        75
    );
}

/* =========================
   HOUSE
   ========================= */

void drawHouse()
{
    /* House body */

    glColor3f(1.0f, 0.90f, 0.45f);

    rectangle(
        170, 120,
        420, 350
    );

    /* Roof */

    glColor3f(0.95f, 0.0f, 0.05f);

    triangle(
        150, 350,
        295, 475,
        440, 350
    );

    /* Door */

    glColor3f(0.50f, 0.25f, 0.08f);

    rectangle(
        265, 120,
        315, 235
    );

    /* Door knob */

    glColor3f(0.0f, 0.0f, 0.0f);

    circle(
        307, 175,
        6
    );

    /* Windows */

    glColor3f(0.05f, 0.60f, 0.95f);

    rectangle(
        195, 260,
        245, 315
    );

    rectangle(
        345, 260,
        395, 315
    );

    /* Window frames using DDA */

    glColor3f(0.0f, 0.0f, 0.0f);

    DDA(220, 260, 220, 315);
    DDA(195, 287, 245, 287);

    DDA(370, 260, 370, 315);
    DDA(345, 287, 395, 287);

    /* Chimney */

    glColor3f(0.45f, 0.22f, 0.05f);

    rectangle(
        350, 350,
        380, 460
    );

    /* Smoke */

    glColor3f(0.85f, 0.90f, 0.95f);

    circle(365, 475, 10);
    circle(375, 495, 14);
    circle(385, 520, 18);
}

/* =========================
   ROAD
   ========================= */

void drawRoad()
{
    glColor3f(0.20f, 0.22f, 0.25f);

    rectangle(
        0, 0,
        1200, 120
    );

    /* Road lane markings using DDA */

    glColor3f(1.0f, 1.0f, 1.0f);

    for (int x = 20; x < 1200; x += 110)
    {
        DDA(x, 70, x + 60, 70);
    }

    /* House path */

    glColor3f(0.55f, 0.58f, 0.62f);

    glBegin(GL_POLYGON);

    glVertex2f(270, 120);
    glVertex2f(315, 120);
    glVertex2f(350, 0);
    glVertex2f(225, 0);

    glEnd();
}

/* =========================
   DOCK
   ========================= */

void drawDock()
{
    glColor3f(0.45f, 0.22f, 0.07f);

    rectangle(
        1030, 85,
        1200, 115
    );

    /* Dock legs */

    rectangle(
        1040, 40,
        1060, 105
    );

    rectangle(
        1150, 20,
        1170, 105
    );
}

/* =========================
   BOAT
   ========================= */

void drawBoat()
{
    glPushMatrix();

    glTranslatef(
        boatX,
        boatY,
        0
    );

    /* Boat body */

    glColor3f(0.50f, 0.25f, 0.08f);

    glBegin(GL_POLYGON);

    glVertex2f(880, 285);
    glVertex2f(1000, 285);
    glVertex2f(975, 250);
    glVertex2f(905, 250);

    glEnd();

    /* Mast */

    glColor3f(0.0f, 0.0f, 0.0f);

    DDA(
        940, 285,
        940, 390
    );

    /* Sail */

    glColor3f(1.0f, 1.0f, 1.0f);

    triangle(
        940, 385,
        940, 290,
        875, 290
    );

    triangle(
        945, 385,
        945, 290,
        1000, 290
    );

    /* Flag */

    glColor3f(0.95f, 0.0f, 0.05f);

    triangle(
        945, 380,
        945, 405,
        980, 393
    );

    glPopMatrix();
}

/* =========================
   CAR
   ========================= */

void drawCar()
{
    glPushMatrix();

    glTranslatef(
        carX,
        0,
        0
    );

    /* Main body */

    glColor3f(0.95f, 0.0f, 0.05f);

    rectangle(
        410, 45,
        630, 95
    );

    /* Car roof */

    glBegin(GL_POLYGON);

    glVertex2f(450, 95);
    glVertex2f(485, 145);
    glVertex2f(570, 145);
    glVertex2f(605, 95);

    glEnd();

    /* Wheels */

    glColor3f(0.0f, 0.0f, 0.0f);

    circle(465, 45, 23);
    circle(590, 45, 23);

    /* Windows */

    glColor3f(0.1f, 0.65f, 0.95f);

    glBegin(GL_POLYGON);

    glVertex2f(475, 100);
    glVertex2f(495, 133);
    glVertex2f(525, 133);
    glVertex2f(525, 100);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(530, 100);
    glVertex2f(530, 133);
    glVertex2f(565, 133);
    glVertex2f(590, 100);

    glEnd();

    /* Headlight */

    glColor3f(1.0f, 0.85f, 0.0f);

    circle(
        625, 78,
        10
    );

    glPopMatrix();
}

/* =========================
   BIRD
   ========================= */

void drawBird(float x, float y)
{
    glColor3f(0.0f, 0.0f, 0.0f);

    DDA(
        x, y,
        x + 15, y - 10
    );

    DDA(
        x + 15, y - 10,
        x + 30, y
    );
}

void drawBirds()
{
    drawBird(
        800 + birdX,
        570
    );

    drawBird(
        870 + birdX,
        550
    );

    drawBird(
        930 + birdX,
        610
    );
}

/* =========================
   DISPLAY
   ========================= */

void display()
{
    glClear(
        GL_COLOR_BUFFER_BIT
    );

    glLoadIdentity();

    /* Sky objects */

    drawSun();

    drawCloud(
        140 + cloudX,
        660
    );

    drawCloud(
        570 + cloudX,
        600
    );

    /* Landscape */

    drawMountains();

    drawLake();

    drawGround();

    /* Objects */

    drawTree();

    drawHouse();

    drawRoad();

    drawDock();

    drawBoat();

    drawBirds();

    drawCar();

    glutSwapBuffers();
}

/* =========================
   ANIMATION
   ========================= */

void update(int value)
{
    /* Car movement */

    carX += 2.0f;

    if (carX > 1200)
        carX = -650;


    /* Boat movement */

    boatX += 0.5f;

    if (boatX > 200)
        boatX = -100;


    /* Boat floating */

    boatY =
        5.0f *
        sin(
            glutGet(GLUT_ELAPSED_TIME)
            * 0.003f
        );


    /* Cloud movement */

    cloudX += 0.15f;

    if (cloudX > 250)
        cloudX = -100;


    /* Bird movement */

    birdX += 0.8f;

    if (birdX > 250)
        birdX = -200;


    glutPostRedisplay();

    glutTimerFunc(
        16,
        update,
        0
    );
}

/* =========================
   INITIALIZATION
   ========================= */

void init()
{
    glClearColor(
        0.25f,
        0.65f,
        0.90f,
        1.0f
    );

    glMatrixMode(
        GL_PROJECTION
    );

    glLoadIdentity();

    gluOrtho2D(
        0,
        1200,
        0,
        800
    );

    glMatrixMode(
        GL_MODELVIEW
    );

    glPointSize(1.0f);
}

/* =========================
   RESHAPE
   ========================= */

void reshape(
    int width,
    int height
)
{
    glViewport(
        0,
        0,
        width,
        height
    );

    glMatrixMode(
        GL_PROJECTION
    );

    glLoadIdentity();

    gluOrtho2D(
        0,
        1200,
        0,
        800
    );

    glMatrixMode(
        GL_MODELVIEW
    );
}

/* =========================
   MAIN
   ========================= */

int main(
    int argc,
    char** argv
)
{
    glutInit(
        &argc,
        argv
    );

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB
    );

    glutInitWindowSize(
        1200,
        800
    );

    glutInitWindowPosition(
        100,
        50
    );

    glutCreateWindow(
        "Computer Graphics - DDA Animation"
    );

    init();

    glutDisplayFunc(
        display
    );

    glutReshapeFunc(
        reshape
    );

    glutTimerFunc(
        0,
        update,
        0
    );

    glutMainLoop();

    return 0;
}