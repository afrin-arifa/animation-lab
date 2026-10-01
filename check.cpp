#include <GL/glut.h>
#include <cmath>

const int WIDTH = 1536;
const int HEIGHT = 1024;



void setColor(float r, float g, float b)
{
    glColor3f(r, g, b);
}

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
    float x3, float y3
)
{
    glBegin(GL_TRIANGLES);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);

    glEnd();
}

void circle(float cx, float cy, float radius, int segments = 80)
{
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(cx, cy);

    for (int i = 0; i <= segments; i++)
    {
        float angle = 2.0f * M_PI * i / segments;

        glVertex2f(
            cx + cos(angle) * radius,
            cy + sin(angle) * radius
        );
    }

    glEnd();
}

void line(
    float x1, float y1,
    float x2, float y2,
    float width = 2.0f
)
{
    glLineWidth(width);

    glBegin(GL_LINES);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);

    glEnd();
}

void drawSky()
{
    setColor(0.19f, 0.68f, 0.91f);

    rectangle(
        0,
        420,
        WIDTH,
        HEIGHT
    );
}

void drawCloud(float x, float y, float scale)
{
    setColor(0.98f, 0.98f, 0.98f);

    circle(
        x + 55 * scale,
        y + 15 * scale,
        55 * scale
    );

    circle(
        x,
        y,
        43 * scale
    );
    circle(
        x + 110 * scale,
        y,
        43 * scale
    );

    rectangle(
        x - 35 * scale,
        y - 30 * scale,
        x + 145 * scale,
        y + 5 * scale
    );
}

void drawClouds()
{
    drawCloud(
        155,
        860,
        1.0f
    );
    drawCloud(
        720,
        860,
        0.68f
    );
}


void drawSun()
{
    float x = 1360;
    float y = 850;

    setColor(1.0f, 0.84f, 0.02f);

    circle(
        x,
        y,
        70
    );

    setColor(0.01f, 0.03f, 0.04f);

    line(x, y + 85, x, y + 135, 4);
    line(x, y - 85, x, y - 135, 4);

    line(x - 85, y, x - 135, y, 4);
    line(x + 85, y, x + 135, y, 4);

    line(
        x - 62,
        y + 62,
        x - 100,
        y + 100,
        4
    );

    line(
        x + 62,
        y + 62,
        x + 100,
        y + 100,
        4
    );

    line(
        x - 62,
        y - 62,
        x - 100,
        y - 100,
        4
    );

    line(
        x + 62,
        y - 62,
        x + 100,
        y - 100,
        4
    );
}

void drawBird(float x, float y, float scale)
{
    setColor(0.01f, 0.02f, 0.03f);

    glLineWidth(3);

    glBegin(GL_LINE_STRIP);

    glVertex2f(
        x - 25 * scale,
        y
    );

    glVertex2f(
        x,
        y - 18 * scale
    );

    glVertex2f(
        x + 25 * scale,
        y
    );

    glEnd();
}

void drawBirds()
{
    drawBird(1025, 755, 1.0f);
    drawBird(1090, 795, 1.0f);
    drawBird(1160, 765, 1.0f);
}

void drawMountains()
{
    setColor(0.08f, 0.42f, 0.23f);

    triangle(
        600,
        470,

        850,
        650,

        1100,
        470
    );
    triangle(
        1050,
        470,

        1320,
        645,

        1580,
        470
    );
}

void drawLake()
{
    setColor(0.03f, 0.43f, 0.90f);

    rectangle(
        600,
        145,
        WIDTH,
        470
    );
}

void drawLand()
{
    setColor(0.30f, 0.67f, 0.28f);
    rectangle(
        0,
        145,
        600,
        470
    );

    glBegin(GL_POLYGON);

    glVertex2f(0, 145);
    glVertex2f(600, 145);
    glVertex2f(600, 470);
    glVertex2f(0, 470);

    glEnd();
    glBegin(GL_POLYGON);

    glVertex2f(520, 145);
    glVertex2f(1170, 145);
    glVertex2f(740, 360);
    glVertex2f(600, 470);

    glEnd();
}

void drawHousePath()
{
    setColor(
        0.55f,
        0.58f,
        0.62f
    );

    glBegin(GL_POLYGON);

    glVertex2f(340, 305);
    glVertex2f(405, 305);

    glVertex2f(450, 145);
    glVertex2f(292, 145);

    glEnd();
}

void drawTree()
{
    setColor(0.43f, 0.20f, 0.08f);

    rectangle(
        103,
        350,
        143,
        650
    );
    triangle(
        103,
        350,

        143,
        350,

        123,
        330
    );

    setColor(
        0.02f,
        0.45f,
        0.17f
    );

    circle(
        123,
        675,
        95
    );
}


void drawHouse()
{
    setColor(
        1.0f,
        0.92f,
        0.45f
    );

    rectangle(
        220,
        305,
        525,
        515
    );
    setColor(
        0.42f,
        0.21f,
        0.08f
    );

    rectangle(
        340,
        305,
        405,
        415
    );

    setColor(
        0.01f,
        0.01f,
        0.01f
    );

    circle(
        390,
        360,
        7
    );
    setColor(
        0.01f,
        0.56f,
        0.90f
    );

    rectangle(
        248,
        410,
        305,
        470
    );

    rectangle(
        435,
        410,
        492,
        470
    );

    setColor(
        0.01f,
        0.01f,
        0.01f
    );

    line(
        276,
        410,
        276,
        470,
        3
    );

    line(
        248,
        440,
        305,
        440,
        3
    );

    line(
        463,
        410,
        463,
        470,
        3
    );

    line(
        435,
        440,
        492,
        440,
        3
    );
    setColor(
        0.43f,
        0.22f,
        0.08f
    );

    rectangle(
        447,
        565,
        487,
        665
    );
    setColor(
        0.92f,
        0.96f,
        0.98f
    );

    circle(467, 680, 7);
    circle(480, 705, 10);
    circle(502, 735, 17);
    circle(540, 770, 22);
    setColor(
        0.95f,
        0.02f,
        0.04f
    );

    triangle(
        195,
        515,

        372,
        665,

        555,
        515
    );

}

void drawBoat()
{
    setColor(
        0.02f,
        0.02f,
        0.02f
    );

    rectangle(
        1197,
        375,
        1203,
        535
    );
    setColor(
        0.98f,
        0.98f,
        0.98f
    );

    triangle(
        1200,
        515,

        1135,
        390,

        1200,
        390
    );
    triangle(
        1205,
        510,

        1270,
        390,

        1205,
        390
    );
    setColor(
        0.95f,
        0.02f,
        0.02f
    );

    triangle(
        1203,
        535,

        1245,
        515,

        1203,
        500
    );

    setColor(
        0.43f,
        0.22f,
        0.08f
    );

    glBegin(GL_POLYGON);

    glVertex2f(1125, 385);
    glVertex2f(1280, 385);
    glVertex2f(1260, 345);
    glVertex2f(1150, 345);

    glEnd();
}

void drawWaterLines()
{
    setColor(
        1.0f,
        1.0f,
        1.0f
    );

    line(
        880,
        350,
        985,
        350,
        2
    );

    line(
        1000,
        290,
        1100,
        290,
        2
    );

    line(
        1370,
        365,
        1475,
        365,
        2
    );

    line(
        1305,
        310,
        1410,
        310,
        2
    );
}

void drawDock()
{
    setColor(
        0.43f,
        0.22f,
        0.08f
    );

    glBegin(GL_QUADS);

    glVertex2f(1305, 270);
    glVertex2f(1686, 20);
    glVertex2f(1586, 20);
    glVertex2f(1205, 270);

    glEnd();
    rectangle(
        1210,
        269,
        1232,
        195
    );

    rectangle(
        1258,
        265,
        1280,
        160
    );

    rectangle(
        1306,
        220,
        1328,
        145
    );
}

void drawRoad()
{
    setColor(
        0.20f,
        0.23f,
        0.28f
    );

    rectangle(
        0,
        0,
        WIDTH,
        145
    );

    setColor(
        0.95f,
        0.95f,
        0.95f
    );

    for (int x = 25; x < WIDTH; x += 145)
    {
        rectangle(
            x,
            65,
            x + 80,
            71
        );
    }
}

void drawCar()
{
    setColor(
        0.95f,
        0.02f,
        0.04f
    );

    rectangle(
        518,
        70,
        800,
        125
    );
    rectangle(
        760,
        75,
        800,
        125
    );
    glBegin(GL_POLYGON);

    glVertex2f(545, 125);
    glVertex2f(570, 175);
    glVertex2f(715, 175);
    glVertex2f(745, 125);

    glEnd();
    setColor(
        0.03f,
        0.58f,
        0.85f
    );

    glBegin(GL_POLYGON);

    glVertex2f(580, 130);
    glVertex2f(592, 165);
    glVertex2f(635, 165);
    glVertex2f(635, 130);

    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(643, 130);
    glVertex2f(643, 165);
    glVertex2f(700, 165);
    glVertex2f(720, 130);

    glEnd();
    setColor(
        0.05f,
        0.05f,
        0.05f
    );

    rectangle(
        636,
        130,
        642,
        166
    );
    setColor(
        0.01f,
        0.01f,
        0.01f
    );

    circle(
        575,
        70,
        27
    );

    circle(
        735,
        70,
        27
    );
    setColor(
        1.0f,
        0.85f,
        0.05f
    );

    circle(
        790,
        105,
        10
    );
}

void display()
{
    glClear(
        GL_COLOR_BUFFER_BIT
    );

    drawSky();

    drawClouds();
    drawSun();
    drawBirds();

    drawMountains();

    drawLake();
    drawLand();
    drawHousePath();

    drawTree();
    drawHouse();

    drawBoat();
    drawDock();

    drawWaterLines();

    drawRoad();

    drawCar();

    glutSwapBuffers();
}

void init()
{
    glClearColor(
        0.19f,
        0.68f,
        0.91f,
        1.0f
    );

    glMatrixMode(
        GL_PROJECTION
    );

    glLoadIdentity();

    gluOrtho2D(
        0,
        WIDTH,
        0,
        HEIGHT
    );

    glMatrixMode(
        GL_MODELVIEW
    );

    glLoadIdentity();

    glDisable(
        GL_DEPTH_TEST
    );
}

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
        WIDTH,
        0,
        HEIGHT
    );

    glMatrixMode(
        GL_MODELVIEW
    );

    glLoadIdentity();
}


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
        WIDTH,
        HEIGHT
    );

    glutInitWindowPosition(
        100,
        50
    );

    glutCreateWindow(
        "2D OpenGL Landscape"
    );

    init();

    glutDisplayFunc(
        display
    );

    glutReshapeFunc(
        reshape
    );

    glutMainLoop();

    return 0;
}