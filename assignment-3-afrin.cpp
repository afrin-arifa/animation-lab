#include <GL/glut.h>
#include <cmath>

const int WIDTH = 1455;
const int HEIGHT = 970;

const float PI = 3.14159265359f;

void DDA(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);

    for (int i = 0; i <= steps; i++)
    {
        glVertex2f(round(x), round(y));

        x += xInc;
        y += yInc;
    }

    glEnd();
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
    float x3, float y3)
{
    glBegin(GL_TRIANGLES);

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);

    glEnd();
}

void polygon(float points[][2], int count)
{
    glBegin(GL_POLYGON);

    for (int i = 0; i < count; i++)
        glVertex2f(points[i][0], points[i][1]);

    glEnd();
}

void circle(float cx, float cy, float radius)
{
    glBegin(GL_POLYGON);

    for (int i = 0; i < 100; i++)
    {
        float angle = 2.0f * PI * i / 100.0f;

        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);

        glVertex2f(x, y);
    }

    glEnd();
}

void drawCloud(float x, float y)
{
    glColor3f(1.0f, 1.0f, 1.0f);

    circle(x, y, 42);
    circle(x + 45, y - 15, 58);
    circle(x + 105, y, 42);
    circle(x + 55, y + 8, 62);
}

void drawSun()
{
    glColor3f(1.0f, 0.84f, 0.0f);

    circle(1288, 165, 65);

    glColor3f(0.0f, 0.0f, 0.0f);

    glPointSize(2.0f);

    DDA(1288, 38, 1288, 88);
    DDA(1288, 242, 1288, 291);

    DDA(1155, 166, 1206, 166);
    DDA(1370, 166, 1421, 166);

    DDA(1193, 77, 1228, 112);
    DDA(1348, 112, 1383, 77);

    DDA(1193, 255, 1228, 220);
    DDA(1348, 220, 1383, 255);
}

void drawMountains()
{
    glColor3f(0.05f, 0.40f, 0.20f);

    triangle(
        580, 546,
        813, 409,
        1034, 546
    );

    triangle(
        1032, 546,
        1251, 411,
        1455, 546
    );
}

void drawLake()
{
    glColor3f(0.0f, 0.39f, 0.90f);

    float water[][2] =
    {
        {580, 546},
        {1455, 546},
        {1455, 815},
        {1110, 815},
        {704, 657}
    };

    polygon(water, 5);

    glColor3f(1.0f, 1.0f, 1.0f);

    DDA(832, 631, 933, 631);
    DDA(971, 688, 1071, 688);
    DDA(1092, 739, 1192, 739);
    DDA(1236, 671, 1336, 671);
    DDA(1298, 619, 1398, 619);
}

void drawGrass()
{
    glColor3f(0.20f, 0.64f, 0.25f);

    float grass[][2] =
    {
        {0, 546},
        {580, 546},
        {704, 657},
        {1110, 815},
        {0, 815}
    };

    polygon(grass, 5);
}

void drawTree()
{
    glColor3f(0.40f, 0.20f, 0.08f);

    rectangle(
        97, 510,
        138, 679
    );

    glColor3f(0.0f, 0.45f, 0.15f);

    circle(
        117,
        442,
        89
    );
}

void drawHouse()
{
    glColor3f(1.0f, 0.90f, 0.45f);

    rectangle(
        206, 520,
        498, 668
    );

    glColor3f(0.45f, 0.22f, 0.05f);

    rectangle(
        423, 387,
        460, 469
    );

    glColor3f(0.88f, 0.92f, 0.95f);

    circle(442, 373, 7);
    circle(453, 351, 11);
    circle(475, 322, 16);
    circle(510, 283, 21);

    glColor3f(0.95f, 0.0f, 0.05f);

    triangle(
        183, 520,
        352, 383,
        522, 520
    );

    glColor3f(0.48f, 0.23f, 0.08f);

    rectangle(
        323, 570,
        382, 668
    );

    glColor3f(0.0f, 0.0f, 0.0f);

    circle(
        370,
        623,
        6
    );

    glColor3f(0.05f, 0.60f, 0.95f);

    rectangle(
        235, 557,
        290, 612
    );

    rectangle(
        413, 557,
        469, 612
    );

    glColor3f(0.0f, 0.0f, 0.0f);

    DDA(262, 557, 262, 612);
    DDA(235, 584, 290, 584);

    DDA(441, 557, 441, 612);
    DDA(413, 584, 469, 584);
}

void drawWalkway()
{
    glColor3f(0.58f, 0.61f, 0.65f);

    float path[][2] =
    {
        {323, 668},
        {382, 668},
        {423, 815},
        {276, 815}
    };

    polygon(path, 4);
}

void drawRoad()
{
    glColor3f(0.20f, 0.22f, 0.26f);

    rectangle(
        0, 815,
        1455, 970
    );

    glColor3f(1.0f, 1.0f, 1.0f);

    DDA(21, 884, 94, 884);
    DDA(156, 884, 229, 884);
    DDA(291, 884, 364, 884);
    DDA(425, 884, 498, 884);
    DDA(559, 884, 632, 884);
    DDA(694, 884, 767, 884);
    DDA(829, 884, 902, 884);
    DDA(964, 884, 1037, 884);
    DDA(1099, 884, 1172, 884);
    DDA(1234, 884, 1307, 884);
    DDA(1369, 884, 1442, 884);
}

void drawBoat()
{
    glColor3f(0.48f, 0.23f, 0.07f);

    float body[][2] =
    {
        {1068, 620},
        {1212, 620},
        {1193, 655},
        {1091, 655}
    };

    polygon(body, 4);

    glColor3f(0.0f, 0.0f, 0.0f);

    rectangle(
        1135, 501,
        1145, 620
    );

    glColor3f(1.0f, 1.0f, 1.0f);

    triangle(
        1135, 503,
        1135, 618,
        1076, 618
    );

    glColor3f(1.0f, 1.0f, 1.0f);

    triangle(
        1145, 503,
        1145, 618,
        1209, 618
    );

    glColor3f(0.95f, 0.0f, 0.05f);

    triangle(
        1142, 501,
        1142, 529,
        1177, 514
    );
}

void drawDock()
{
    glColor3f(0.43f, 0.22f, 0.08f);

    glBegin(GL_QUADS);

    glVertex2f(1200, 710);
    glVertex2f(1360, 710);
    glVertex2f(1580, 815);
    glVertex2f(1390, 815);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(1220, 720);
    glVertex2f(1240, 720);
    glVertex2f(1240, 790);
    glVertex2f(1220, 790);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(1265, 730);
    glVertex2f(1285, 730);
    glVertex2f(1285, 805);
    glVertex2f(1265, 805);

    glEnd();

    glBegin(GL_QUADS);

    glVertex2f(1320, 750);
    glVertex2f(1340, 750);
    glVertex2f(1340, 815);
    glVertex2f(1320, 815);

    glEnd();
}

void drawCar()
{
    glColor3f(0.95f, 0.0f, 0.05f);

    rectangle(
        490, 836,
        758, 890
    );

    float roof[][2] =
    {
        {515, 836},
        {540, 786},
        {676, 786},
        {708, 836}
    };

    polygon(roof, 4);

    glColor3f(0.05f, 0.62f, 0.92f);

    float leftWindow[][2] =
    {
        {536, 832},
        {553, 800},
        {600, 800},
        {600, 832}
    };

    polygon(leftWindow, 4);

    float rightWindow[][2] =
    {
        {606, 832},
        {606, 800},
        {670, 800},
        {692, 832}
    };

    polygon(rightWindow, 4);

    glColor3f(0.0f, 0.0f, 0.0f);

    DDA(
        603,
        799,
        603,
        832
    );

    glColor3f(0.0f, 0.0f, 0.0f);

    circle(
        545,
        890,
        25
    );

    circle(
        697,
        890,
        25
    );

    glColor3f(1.0f, 0.85f, 0.0f);

    circle(
        748,
        854,
        11
    );
}

void drawBird(float x, float y)
{
    glColor3f(0.0f, 0.0f, 0.0f);

    DDA(
        x,
        y,
        x + 13,
        y + 10
    );

    DDA(
        x + 13,
        y + 10,
        x + 27,
        y
    );
}

void drawBirds()
{
    drawBird(944, 292);
    drawBird(1008, 242);
    drawBird(1075, 292);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    drawSun();

    drawCloud(
        155,
        155
    );

    drawCloud(
        720,
        190
    );

    drawBirds();

    drawMountains();

    drawLake();

    drawGrass();

    drawTree();

    drawHouse();

    drawWalkway();

    drawRoad();

    drawBoat();

    drawDock();

    drawCar();

    glutSwapBuffers();
}

void init()
{
    glClearColor(
        0.25f,
        0.65f,
        0.90f,
        1.0f
    );

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(
        0,
        WIDTH,
        HEIGHT,
        0
    );

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glPointSize(1.0f);
}

void reshape(int width, int height)
{
    glViewport(
        0,
        0,
        width,
        height
    );

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(
        0,
        WIDTH,
        HEIGHT,
        0
    );

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
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
        50,
        30
    );

    glutCreateWindow(
        "Computer Graphics - DDA"
    );

    init();

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}