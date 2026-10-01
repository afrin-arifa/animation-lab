#include <GL/glut.h>                    // Include OpenGL GLUT library
#include <cmath>                        // Include mathematical functions

const int WIDTH = 1455;                 // Set window width
const int HEIGHT = 970;                 // Set window height

const float PI = 3.14159265359f;       // Define the value of PI

float sunAngle = 0;  // sun angle for rotation
float treeAngle = 0; // tree angle for rotation
float boatX = 0;   // boat position for movement
float boatY = 0;  // boat position for movement


void DDA(float x1, float y1, float x2, float y2)   // Define DDA line drawing function
{
    float dx = x2 - x1;                              // Calculate difference in X
    float dy = y2 - y1;                              // Calculate difference in Y

    float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);   // Find number of steps

    float xInc = dx / steps;                         // Calculate X increment
    float yInc = dy / steps;                         // Calculate Y increment

    float x = x1;                                    // Start X coordinate
    float y = y1;                                    // Start Y coordinate

    glBegin(GL_POINTS);                              // Start drawing points

    for (int i = 0; i <= steps; i++)                 // Repeat for every DDA step
    {
        glVertex2f(round(x), round(y));              // Draw current DDA point

        x += xInc;                                   // Increase X coordinate
        y += yInc;                                   // Increase Y coordinate
    }

    glEnd();                                         // Finish drawing points
}


void rectangle(float x1, float y1, float x2, float y2)   // Define rectangle function
{
    glBegin(GL_QUADS);                               // Start drawing quadrilateral

    glVertex2f(x1, y1);                              // Top-left corner
    glVertex2f(x2, y1);                              // Top-right corner
    glVertex2f(x2, y2);                              // Bottom-right corner
    glVertex2f(x1, y2);                              // Bottom-left corner

    glEnd();                                         // Finish rectangle
}


void triangle(
    float x1, float y1,                              // First point
    float x2, float y2,                              // Second point
    float x3, float y3)                              // Third point
{
    glBegin(GL_TRIANGLES);                           // Start drawing triangle

    glVertex2f(x1, y1);                              // First triangle vertex
    glVertex2f(x2, y2);                              // Second triangle vertex
    glVertex2f(x3, y3);                              // Third triangle vertex

    glEnd();                                         // Finish triangle
}


void polygon(float points[][2], int count)           // Define polygon function
{
    glBegin(GL_POLYGON);                             // Start drawing polygon

    for (int i = 0; i < count; i++)                  // Loop through all polygon points
        glVertex2f(points[i][0], points[i][1]);      // Draw each polygon point

    glEnd();                                         // Finish polygon
}


void circle(float cx, float cy, float radius)        // Define circle function
{
    glBegin(GL_POLYGON);                             // Start drawing circle

    for (int i = 0; i < 100; i++)                    // Generate 100 points for smooth circle
    {
        float angle = 2.0f * PI * i / 100.0f;       // Calculate angle

        float x = cx + radius * cos(angle);          // Calculate X coordinate
        float y = cy + radius * sin(angle);          // Calculate Y coordinate

        glVertex2f(x, y);                            // Draw circle point
    }

    glEnd();                                         // Finish circle
}


void drawCloud(float x, float y)                     // Define cloud function
{
    glColor3f(1.0f, 1.0f, 1.0f);                    // Set cloud color to white

    circle(x, y, 42);                                // Draw first cloud circle
    circle(x + 45, y - 15, 58);                      // Draw second cloud circle
    circle(x + 105, y, 42);                          // Draw third cloud circle
    circle(x + 55, y + 8, 62);                      // Draw main cloud circle
}


void drawSun()  // Define sun function
{
    glPushMatrix();  // Save current transformation matrix
    // Apply transformations to the sun

    glTranslatef(1288, 165, 0); // Move the sun to its position
    glRotatef(sunAngle, 0, 0, 1);  // Rotate the sun around its center
    glTranslatef(-1288, -165, 0);   // Move the sun back to its original position

    glColor3f(1.0f, 0.84f, 0.0f);   // Set sun color to yellow

    circle(1288, 165, 65);  // Draw the sun as a circle

    glColor3f(0.0f, 0.0f, 0.0f);  // Set sun rays color to black

    glPointSize(2.0f);    // Set point size for sun rays

    DDA(1288, 38, 1288, 88);    // Draw vertical sun ray
    DDA(1288, 242, 1288, 291);   // Draw vertical sun ray

    DDA(1155, 166, 1206, 166);    // Draw horizontal sun ray
    DDA(1370, 166, 1421, 166);    // Draw horizontal sun ray

    DDA(1193, 77, 1228, 112);    // Draw diagonal sun ray
    DDA(1348, 112, 1383, 77);    // Draw diagonal sun ray

    DDA(1193, 255, 1228, 220);    // Draw diagonal sun ray
    DDA(1348, 220, 1383, 255);    // Draw diagonal sun ray

    glPopMatrix();      // Restore previous transformation matrix
}

void drawMountains()                                  // Define mountains function
{
    glColor3f(0.05f, 0.40f, 0.20f);                 // Set mountain color to green

    triangle(
        580, 546,                                   // First mountain left point
        813, 409,                                   // First mountain top point
        1034, 546                                   // First mountain right point
    );

    triangle(
        1032, 546,                                  // Second mountain left point
        1251, 411,                                  // Second mountain top point
        1455, 546                                   // Second mountain right point
    );
}


void drawLake()                                      // Define lake function
{
    glColor3f(0.0f, 0.39f, 0.90f);                  // Set lake color to blue

    float water[][2] =                              // Define lake polygon points
    {
        {580, 546},                                 // Top-left lake point
        {1455, 546},                                // Top-right lake point
        {1455, 815},                                // Bottom-right lake point
        {1110, 815},                                // Bottom-middle lake point
        {704, 657}                                  // Diagonal lake point
    };

    polygon(water, 5);                              // Draw lake polygon

    glColor3f(1.0f, 1.0f, 1.0f);                   // Set water line color to white

    DDA(832, 631, 933, 631);                        // Draw first water line
    DDA(971, 688, 1071, 688);                       // Draw second water line
    DDA(1092, 739, 1192, 739);                      // Draw third water line
    DDA(1236, 671, 1336, 671);                      // Draw fourth water line
    DDA(1298, 619, 1398, 619);                      // Draw fifth water line
}


void drawGrass()                                     // Define grass function
{
    glColor3f(0.20f, 0.64f, 0.25f);                // Set grass color to green

    float grass[][2] =                             // Define grass polygon points
    {
        {0, 546},                                  // Top-left grass point
        {580, 546},                                // Top-middle grass point
        {704, 657},                                // Diagonal grass point
        {1110, 815},                               // Bottom-right grass point
        {0, 815}                                   // Bottom-left grass point
    };

    polygon(grass, 5);                              // Draw grass polygon
}


void drawTree()                                     // Define tree function
{
    glColor3f(0.40f, 0.20f, 0.08f);                // Set trunk color to brown

    rectangle(
        97, 510,                                    // Top-left trunk coordinate
        138, 679                                     // Bottom-right trunk coordinate
    );

      glPushMatrix();     // Save current transformation matrix

    glTranslatef(117, 442, 0);    // Move the tree leaves to their position
    glRotatef(treeAngle, 0, 0, 1);    // Rotate the tree leaves around their center
    glTranslatef(-117, -442, 0);   // Move the tree leaves back to their original position

    glColor3f(0.0f, 0.45f, 0.15f);                 // Set leaf color to green

    circle(
        117, 442,                                   // Center of tree leaves
        89                                           // Radius of tree leaves
    );

    glPopMatrix();   // Restore previous transformation matrix
}


void drawHouse()                                    // Define house function
{
    glColor3f(1.0f, 0.90f, 0.45f);                 // Set house wall color

    rectangle(
        206, 520,                                   // Top-left house coordinate
        498, 668                                    // Bottom-right house coordinate
    );

    glColor3f(0.45f, 0.22f, 0.05f);                // Set chimney color

    rectangle(
        423, 387,                                   // Top-left chimney coordinate
        460, 469                                    // Bottom-right chimney coordinate
    );

    glColor3f(0.88f, 0.92f, 0.95f);                // Set smoke color

    circle(442, 373, 7);                            // Draw first smoke bubble
    circle(453, 351, 11);                           // Draw second smoke bubble
    circle(475, 322, 16);                           // Draw third smoke bubble
    circle(510, 283, 21);                           // Draw fourth smoke bubble

    glColor3f(0.95f, 0.0f, 0.05f);                 // Set roof color to red

    triangle(
        183, 520,                                   // Left roof point
        352, 383,                                   // Top roof point
        522, 520                                    // Right roof point
    );

    glColor3f(0.48f, 0.23f, 0.08f);                // Set door color to brown

    rectangle(
        323, 570,                                   // Top-left door coordinate
        382, 668                                    // Bottom-right door coordinate
    );

    glColor3f(0.0f, 0.0f, 0.0f);                   // Set door knob color to black

    circle(
        370, 623,                                   // Door knob center
        6                                             // Door knob radius
    );

    glColor3f(0.05f, 0.60f, 0.95f);                // Set window color to blue

    rectangle(
        235, 557,                                   // Top-left left-window coordinate
        290, 612                                    // Bottom-right left-window coordinate
    );

    rectangle(
        413, 557,                                   // Top-left right-window coordinate
        469, 612                                    // Bottom-right right-window coordinate
    );

    glColor3f(0.0f, 0.0f, 0.0f);                   // Set window frame color to black

    DDA(262, 557, 262, 612);                        // Draw vertical left window frame
    DDA(235, 584, 290, 584);                        // Draw horizontal left window frame

    DDA(441, 557, 441, 612);                        // Draw vertical right window frame
    DDA(413, 584, 469, 584);                        // Draw horizontal right window frame
}


void drawWalkway()                                  // Define walkway function
{
    glColor3f(0.58f, 0.61f, 0.65f);                // Set walkway color

    float path[][2] =                               // Define walkway points
    {
        {323, 668},                                // Top-left walkway point
        {382, 668},                                // Top-right walkway point
        {423, 815},                                // Bottom-right walkway point
        {276, 815}                                 // Bottom-left walkway point
    };

    polygon(path, 4);                               // Draw walkway polygon
}


void drawRoad()                                     // Define road function
{
    glColor3f(0.20f, 0.22f, 0.26f);                // Set road color

    rectangle(
        0, 815,                                     // Top-left road coordinate
        1455, 970                                   // Bottom-right road coordinate
    );

    glColor3f(1.0f, 1.0f, 1.0f);                  // Set road marking color to white

    DDA(21, 884, 94, 884);                          // Draw first road marking
    DDA(156, 884, 229, 884);                        // Draw second road marking
    DDA(291, 884, 364, 884);                        // Draw third road marking
    DDA(425, 884, 498, 884);                        // Draw fourth road marking
    DDA(559, 884, 632, 884);                        // Draw fifth road marking
    DDA(694, 884, 767, 884);                        // Draw sixth road marking
    DDA(829, 884, 902, 884);                        // Draw seventh road marking
    DDA(964, 884, 1037, 884);                       // Draw eighth road marking
    DDA(1099, 884, 1172, 884);                      // Draw ninth road marking
    DDA(1234, 884, 1307, 884);                      // Draw tenth road marking
    DDA(1369, 884, 1442, 884);                      // Draw eleventh road marking
}


void drawBoat()                                    // Define boat function
{
    glPushMatrix();  // Save current transformation matrix

    glTranslatef(boatX, boatY, 0);   // Move the boat to its position

    glColor3f(0.48f, 0.23f, 0.07f);               // Set boat body color

    float body[][2] =                              // Define boat body points
    {
        {1068, 620},                               // Top-left boat point
        {1212, 620},                               // Top-right boat point
        {1193, 655},                               // Bottom-right boat point
        {1091, 655}                                // Bottom-left boat point
    };

    polygon(body, 4);                              // Draw boat body

    glColor3f(0.0f, 0.0f, 0.0f);                  // Set mast color to black

    rectangle(
        1135, 501,                                 // Top-left mast coordinate
        1145, 620                                  // Bottom-right mast coordinate
    );

    glColor3f(1.0f, 1.0f, 1.0f);                 // Set left sail color to white

    triangle(
        1135, 503,                                 // Top-left sail point
        1135, 618,                                 // Bottom-left sail point
        1076, 618                                  // Bottom-right sail point
    );

    glColor3f(1.0f, 1.0f, 1.0f);                 // Set right sail color to white

    triangle(
        1145, 503,                                 // Top-right sail point
        1145, 618,                                 // Bottom-left sail point
        1209, 618                                  // Bottom-right sail point
    );

    glColor3f(0.95f, 0.0f, 0.05f);                // Set flag color to red

    triangle(
        1142, 501,                                 // Left flag point
        1142, 529,                                 // Bottom flag point
        1177, 514                                  // Right flag point
    );
    glPopMatrix();   // Restore previous transformation matrix
}


void drawDock()                                     // Define dock function
{
    glColor3f(0.43f, 0.22f, 0.08f);                // Set dock color to brown

    glBegin(GL_QUADS);                              // Start drawing dock

    glVertex2f(1200, 710);                          // Top-left dock point
    glVertex2f(1360, 710);                          // Top-right dock point
    glVertex2f(1580, 815);                          // Bottom-right dock point
    glVertex2f(1390, 815);                          // Bottom-left dock point

    glEnd();                                        // Finish dock

    glBegin(GL_QUADS);                              // Start drawing first leg

    glVertex2f(1220, 720);                          // Top-left first leg
    glVertex2f(1240, 720);                          // Top-right first leg
    glVertex2f(1240, 790);                          // Bottom-right first leg
    glVertex2f(1220, 790);                          // Bottom-left first leg

    glEnd();                                        // Finish first leg

    glBegin(GL_QUADS);                              // Start drawing second leg

    glVertex2f(1265, 730);                          // Top-left second leg
    glVertex2f(1285, 730);                          // Top-right second leg
    glVertex2f(1285, 805);                          // Bottom-right second leg
    glVertex2f(1265, 805);                          // Bottom-left second leg

    glEnd();                                        // Finish second leg

    glBegin(GL_QUADS);                              // Start drawing third leg

    glVertex2f(1320, 750);                          // Top-left third leg
    glVertex2f(1340, 750);                          // Top-right third leg
    glVertex2f(1340, 815);                          // Bottom-right third leg
    glVertex2f(1320, 815);                          // Bottom-left third leg

    glEnd();                                        // Finish third leg
}


void drawCar()                                      // Define car function
{
    glColor3f(0.95f, 0.0f, 0.05f);                 // Set car color to red

    rectangle(
        490, 836,                                   // Top-left car body
        758, 890                                    // Bottom-right car body
    );

    float roof[][2] =                               // Define car roof points
    {
        {515, 836},                                 // Bottom-left roof point
        {540, 786},                                 // Top-left roof point
        {676, 786},                                 // Top-right roof point
        {708, 836}                                  // Bottom-right roof point
    };

    polygon(roof, 4);                               // Draw car roof

    glColor3f(0.05f, 0.62f, 0.92f);                // Set window color

    float leftWindow[][2] =                         // Define left window points
    {
        {536, 832},                                 // Bottom-left window point
        {553, 800},                                 // Top-left window point
        {600, 800},                                 // Top-right window point
        {600, 832}                                  // Bottom-right window point
    };

    polygon(leftWindow, 4);                         // Draw left window

    float rightWindow[][2] =                        // Define right window points
    {
        {606, 832},                                 // Bottom-left window point
        {606, 800},                                 // Top-left window point
        {670, 800},                                 // Top-right window point
        {692, 832}                                  // Bottom-right window point
    };

    polygon(rightWindow, 4);                        // Draw right window

    glColor3f(0.0f, 0.0f, 0.0f);                   // Set divider color to black

    DDA(
        603,                                         // Start X coordinate
        799,                                         // Start Y coordinate
        603,                                         // End X coordinate
        832                                          // End Y coordinate
    );

    glColor3f(0.0f, 0.0f, 0.0f);                   // Set wheel color to black

    circle(
        545,                                         // First wheel center X
        890,                                         // First wheel center Y
        25                                           // First wheel radius
    );

    circle(
        697,                                         // Second wheel center X
        890,                                         // Second wheel center Y
        25                                           // Second wheel radius
    );

    glColor3f(1.0f, 0.85f, 0.0f);                  // Set headlight color

    circle(
        748,                                         // Headlight center X
        854,                                         // Headlight center Y
        11                                           // Headlight radius
    );
}


void drawBird(float x, float y)                     // Define bird function
{
    glColor3f(0.0f, 0.0f, 0.0f);                   // Set bird color to black

    DDA(
        x,                                           // Start X coordinate
        y,                                           // Start Y coordinate
        x + 13,                                      // Middle X coordinate
        y + 10                                       // Middle Y coordinate
    );

    DDA(
        x + 13,                                      // Middle X coordinate
        y + 10,                                      // Middle Y coordinate
        x + 27,                                      // End X coordinate
        y                                           // End Y coordinate
    );
}


void drawBirds()                                     // Define birds function
{
    drawBird(944, 292);                              // Draw first bird
    drawBird(1008, 242);                             // Draw second bird
    drawBird(1075, 292);                             // Draw third bird
}

void update(int value)
{
     treeAngle += 2;
    sunAngle += 2;

    if (sunAngle >= 360)
        sunAngle -= 360;
    if (treeAngle >= 360)
        treeAngle -= 360;

    glutPostRedisplay();
    glutTimerFunc(50, update, 0);
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'a' || key == 'A')
        boatX -= 10;

    if (key == 'd' || key == 'D')
        boatX += 10;

    if (key == 'w' || key == 'W')
        boatY -= 10;

    if (key == 's' || key == 'S')
        boatY += 10;

    glutPostRedisplay();
}

void display()                                      // Define display function
{
    glClear(GL_COLOR_BUFFER_BIT);                    // Clear the screen

    glLoadIdentity();                                // Reset transformation matrix

    drawSun();                                       // Draw sun

    drawCloud(
        155,                                         // Cloud X position
        155                                          // Cloud Y position
    );

    drawCloud(
        720,                                         // Cloud X position
        190                                          // Cloud Y position
    );

    drawBirds();                                     // Draw birds

    drawMountains();                                 // Draw mountains

    drawLake();                                      // Draw lake

    drawGrass();                                     // Draw grass

    drawTree();                                      // Draw tree

    drawHouse();                                     // Draw house

    drawWalkway();                                   // Draw walkway

    drawRoad();                                      // Draw road

    drawBoat();                                      // Draw boat

    drawDock();                                      // Draw dock

    drawCar();                                       // Draw car

    glutSwapBuffers();                               // Display completed frame
}


void init()                                          // Define initialization function
{
    glClearColor(
        0.25f,                                       // Background red value
        0.65f,                                       // Background green value
        0.90f,                                       // Background blue value
        1.0f                                         // Background alpha value
    );

    glMatrixMode(GL_PROJECTION);                     // Select projection matrix

    glLoadIdentity();                                // Reset projection matrix

    gluOrtho2D(
        0,                                             // Left coordinate
        WIDTH,                                         // Right coordinate
        HEIGHT,                                        // Bottom coordinate
        0                                               // Top coordinate
    );

    glMatrixMode(GL_MODELVIEW);                       // Select model-view matrix

    glLoadIdentity();                                 // Reset model-view matrix

    glPointSize(1.0f);                                // Set point size
}


void reshape(int width, int height)                  // Define window resize function
{
    glViewport(
        0,                                             // Viewport X position
        0,                                             // Viewport Y position
        width,                                         // Viewport width
        height                                         // Viewport height
    );

    glMatrixMode(GL_PROJECTION);                       // Select projection matrix

    glLoadIdentity();                                  // Reset projection matrix

    gluOrtho2D(
        0,                                              // Left coordinate
        WIDTH,                                          // Right coordinate
        HEIGHT,                                         // Bottom coordinate
        0                                                // Top coordinate
    );

    glMatrixMode(GL_MODELVIEW);                       // Select model-view matrix
}


int main(int argc, char** argv)                         // Main function
{
    glutInit(
        &argc,                                          // Command-line argument count
        argv                                             // Command-line arguments
    );

    glutInitDisplayMode(
        GLUT_DOUBLE |                                    // Enable double buffering
        GLUT_RGB                                          // Use RGB color mode
    );

    glutInitWindowSize(
        WIDTH,                                           // Window width
        HEIGHT                                           // Window height
    );

    glutInitWindowPosition(
        50,                     // Window X position
        30                      // Window Y position
    );

    glutCreateWindow(
        "Computer Graphics - DDA"    // Window title
    );

    init();                           // Initialize OpenGL

    glutDisplayFunc(display);         // Register display function

    glutReshapeFunc(reshape);         // Register resize function

    glutKeyboardFunc(keyboard);       // Register keyboard function

     glutTimerFunc(50, update, 0);    //sun rotation timer function

    glutMainLoop();                                       // Start OpenGL event loop

    
    return 0;                                             // End program successfully
}