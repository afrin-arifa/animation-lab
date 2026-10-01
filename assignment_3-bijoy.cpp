#include <GL/glut.h>
#include <cmath>

const int WIDTH = 1536;
const int HEIGHT = 1024;

// ------------------------------------------------------------
// Utility
// ------------------------------------------------------------

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


// ============================================================
// SKY
// ============================================================

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


// ============================================================
// CLOUDS
// ============================================================

void drawCloud(float x, float y, float scale)
{
    setColor(0.98f, 0.98f, 0.98f);

    // Main center cloud
    circle(
        x + 55 * scale,
        y + 15 * scale,
        55 * scale
    );

    // Left cloud
    circle(
        x,
        y,
        43 * scale
    );

    // Right cloud
    circle(
        x + 110 * scale,
        y,
        43 * scale
    );

    // Bottom connection
    rectangle(
        x - 35 * scale,
        y - 30 * scale,
        x + 145 * scale,
        y + 5 * scale
    );
}

void drawClouds()
{
    // Large cloud
    drawCloud(
        155,
        860,
        1.0f
    );

    // Smaller cloud
    drawCloud(
        720,
        860,
        0.68f
    );
}


// ============================================================
// SUN
// ============================================================

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

    // Vertical
    line(x, y + 85, x, y + 135, 4);
    line(x, y - 85, x, y - 135, 4);

    // Horizontal
    line(x - 85, y, x - 135, y, 4);
    line(x + 85, y, x + 135, y, 4);

    // Diagonal
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


// ============================================================
// BIRDS
// ============================================================

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


// ============================================================
// MOUNTAINS
// ============================================================

void drawMountains()
{
    setColor(0.08f, 0.42f, 0.23f);

    // Left mountain
    triangle(
        600,
        470,

        850,
        650,

        1100,
        470
    );

    // Right mountain
    triangle(
        1050,
        470,

        1320,
        645,

        1580,
        470
    );
}


// ============================================================
// LAKE
// ============================================================

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


// ============================================================
// LAND / RIVER BANK
// ============================================================

void drawLand()
{
    setColor(0.30f, 0.67f, 0.28f);

    // Main land
    rectangle(
        0,
        145,
        600,
        470
    );

    /*
        Straight river bank.

        This is intentionally one straight diagonal.
        The previous version created an unwanted-looking
        curved/stepped boundary.
    */

    glBegin(GL_POLYGON);

    glVertex2f(0, 145);
    glVertex2f(600, 145);
    glVertex2f(600, 470);
    glVertex2f(0, 470);

    glEnd();

    // Sloping foreground land toward the lake
    glBegin(GL_POLYGON);

    glVertex2f(520, 145);
    glVertex2f(1170, 145);
    glVertex2f(740, 360);
    glVertex2f(600, 470);

    glEnd();
}


// ============================================================
// WALKWAY FROM HOUSE TO ROAD
// ============================================================

void drawHousePath()
{
    setColor(
        0.55f,
        0.58f,
        0.62f
    );

    /*
        Straight path from the house door
        down to the road.

        Top is narrow.
        Bottom is wider.
    */

    glBegin(GL_POLYGON);

    glVertex2f(340, 305);
    glVertex2f(405, 305);

    glVertex2f(450, 145);
    glVertex2f(292, 145);

    glEnd();
}


// ============================================================
// TREE
// ============================================================

void drawTree()
{
    // Straight trunk
    setColor(0.43f, 0.20f, 0.08f);

    rectangle(
        103,
        350,
        143,
        650
    );

    // Small natural base, but still straight
    triangle(
        103,
        350,

        143,
        350,

        123,
        330
    );

    // Crown
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


// ============================================================
// HOUSE
// ============================================================

void drawHouse()
{
    // Main house
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

    // Door
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

    // Door knob
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

    // Windows
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

    // Window frames
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

    // Chimney
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

    // Smoke
    setColor(
        0.92f,
        0.96f,
        0.98f
    );

    circle(467, 680, 7);
    circle(480, 705, 10);
    circle(502, 735, 17);
    circle(540, 770, 22);

    // Roof
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


// ============================================================
// BOAT
// ============================================================

void drawBoat()
{
    // Mast
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

    // Left sail
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

    // Right sail
    triangle(
        1205,
        510,

        1270,
        390,

        1205,
        390
    );

    // Flag
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

    // Boat body
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


// ============================================================
// WATER LINES
// ============================================================

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

    // line(
    //     1150,
    //     235,
    //     1255,
    //     235,
    //     2
    // );

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


// ============================================================
// DOCK
// ============================================================

void drawDock()
{
    setColor(
        0.43f,
        0.22f,
        0.08f
    );

    // Top
    // rectangle(
    //     1305,
    //     220,
    //     1536,
    //     165
    // );

    glBegin(GL_QUADS);

    glVertex2f(1305, 270);
    glVertex2f(1686, 20);
    glVertex2f(1586, 20);
    glVertex2f(1205, 270);

    glEnd();

    // Legs
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


// ============================================================
// ROAD
// ============================================================

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

    // Road markings
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


// ============================================================
// CAR
// ============================================================

void drawCar()
{
    // Main body
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

    // Front
    rectangle(
        760,
        75,
        800,
        125
    );

    // Roof
    glBegin(GL_POLYGON);

    glVertex2f(545, 125);
    glVertex2f(570, 175);
    glVertex2f(715, 175);
    glVertex2f(745, 125);

    glEnd();

    // Windows
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

    // Window divider
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

    // Wheels
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

    // Headlight
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


// ============================================================
// DISPLAY
// ============================================================

void display()
{
    glClear(
        GL_COLOR_BUFFER_BIT
    );

    /*
        IMPORTANT DRAW ORDER

        1. Sky
        2. Mountains
        3. Lake
        4. Land
        5. House path
        6. Objects
        7. Road
        8. Car
    */

    drawSky();

    drawClouds();
    drawSun();
    drawBirds();

    drawMountains();

    // Lake FIRST
    drawLake();

    // Land AFTER lake so the bank is clean
    drawLand();

    // Path must be above the land
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


// ============================================================
// INITIALIZATION
// ============================================================

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


// ============================================================
// RESIZE
// ============================================================

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


// ============================================================
// MAIN
// ============================================================

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