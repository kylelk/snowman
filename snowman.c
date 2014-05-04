// gcc -o snowman snowman.c -framework GLUT -framework OpenGL


#include <stdlib.h> // standard definitions
#include <math.h> // math definitions
#include <stdio.h> // standard I/O

// include files are in a slightly different location for MacOS
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


/* START objects */

#include "picket_fence.h"
#include "drawSnowman.h"

/* END objects */



// escape key (for exit)
#define ESC 27

//----------------------------------------------------------------------
// Global variables
//
// The coordinate system is set up so that the (x,y)-coordinate plane
// is the ground, and the z-axis is directed upwards. The y-axis points
// to the north and the x-axis points to the east.
//
// The values (x,y) are the current camera position. The values (lx, ly)
// point in the direction the camera is looking. The variables angle and
// deltaAngle control the camera's angle. The variable deltaMove
// indicates the amount of incremental motion for the camera with each
// redraw cycle. The variables isDragging and xDragStart are used to
// monitor the mouse when it drags (with the left button down).
//----------------------------------------------------------------------

// Camera position
float x = 0.0, y = -5.0; // initially 5 units south of origin
float deltaMove = 0.0; // initially camera doesn't move

// Camera direction
float lx = 0.0, ly = 1.0; // camera points initially along y-axis
float angle = 0.0; // angle of rotation for the camera direction
float deltaAngle = 0.0; // additional angle change when dragging

// Mouse drag control
int isDragging = 0; // true when dragging
int xDragStart = 0; // records the x-coordinate when dragging starts

unsigned int random_snowmen[36];


//----------------------------------------------------------------------
// Reshape callback
//
// Window size has been set/changed to w by h pixels. Set the camera
// perspective to 45 degree vertical field of view, a window aspect
// ratio of w/h, a near clipping plane at depth 1, and a far clipping
// plane at depth 100. The viewport is the entire window.
//
//----------------------------------------------------------------------


void changeSize(int w, int h)
{
    float ratio =  ((float) w) / ((float) h); // window aspect ratio
    glMatrixMode(GL_PROJECTION); // projection matrix is active
    glLoadIdentity(); // reset the projection
    gluPerspective(45.0, ratio, 0.1, 100.0); // perspective transformation
    glMatrixMode(GL_MODELVIEW); // return to modelview mode
    glViewport(0, 0, w, h); // set viewport (drawing area) to entire window
}


//----------------------------------------------------------------------
// Update with each idle event
//
// This incrementally moves the camera and requests that the scene be
// redrawn.
//----------------------------------------------------------------------
void update(void)
{
    if (deltaMove) { // update camera position
        x += deltaMove * lx * 0.1;
        y += deltaMove * ly * 0.1;
        printf("%f, %f\n", x,y);
        
//        for(i = -3; i < 3; i++){
//            for(j = -3; j < 3; j++) {
//                glTranslatef(i*12, j*12, 0);
//            }
//        }
    }
    glutPostRedisplay(); // redisplay everything
}

//----------------------------------------------------------------------
// Draw the entire scene
//
// We first update the camera location based on its distance from the
// origin and its direction.
//----------------------------------------------------------------------
void renderScene(void)
{
    int i, j;
    
    // Clear color and depth buffers
    glClearColor(0.0, 0.7, 1.0, 1.0); // sky color is light blue
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Reset transformations
    glLoadIdentity();
    
    // Set the camera centered at (x,y,1) and looking along directional
    // vector (lx, ly, 0), with the z-axis pointing up
    gluLookAt(
              x,      y,      1.0,
              x + lx, y + ly, 1.0,
              0.0,    0.0,    1.0);
    
    // Draw ground - 200x200 square colored green
    glColor3f(0.0, 0.7, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(-100.0, -100.0, 0.0);
    glVertex3f(-100.0,  100.0, 0.0);
    glVertex3f( 100.0,  100.0, 0.0);
    glVertex3f( 100.0, -100.0, 0.0);
    glEnd();
    
    // draw a picket fence
    // declared in "picket_fence.h"
    //picket_fence();

    // Draw 36 snow men
    //int snowman_number=0;
    for(i = -3; i < 3; i++){
        for(j = -3; j < 3; j++) {
            glPushMatrix();
            //int rand_n = random_snowmen[snowman_number];
            //glTranslatef(i*7.5+(rand_n%5), j*7.5+(rand_n%5), 0);
            glTranslatef(i*12, j*12, 0);
            drawSnowman();
            picket_fence();
            //snowman_number++;
            glPopMatrix();
        }
    }
    
    for(i = -3; i < 3; i++){
        for(j = -3; j < 3; j++) {
            glPushMatrix();
            
            // street
            glBegin(GL_QUADS);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f( -40, (i*12)+5, 0.001 );
            glVertex3f( -40, (i*12)+7, 0.001 );
            glVertex3f( 40,  (i*12)+7, 0.001 );
            glVertex3f( 40,  (i*12)+5, 0.001 );
            glEnd();
            glBegin(GL_QUADS);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f( (i*12)+5, -40, 0.001 );
            glVertex3f( (i*12)+7, -40, 0.001 );
            glVertex3f( (i*12)+7,  40, 0.001 );
            glVertex3f( (i*12)+5,  40, 0.001 );
            glEnd();
            
            glPopMatrix();
        }
    }
    
    glutSwapBuffers(); // Make it all visible
}

//----------------------------------------------------------------------
// User-input callbacks
//
// processNormalKeys: ESC, q, and Q cause program to exit
// pressSpecialKey: Up arrow = forward motion, down arrow = backwards
// releaseSpecialKey: Set incremental motion to zero
//----------------------------------------------------------------------
void processNormalKeys(unsigned char key, int xx, int yy)
{
    if (key == ESC || key == 'q' || key == 'Q') exit(0);
}

void pressSpecialKey(int key, int xx, int yy)
{
    switch (key) {
        case GLUT_KEY_UP : deltaMove = 1.0; break;
        case GLUT_KEY_DOWN : deltaMove = -1.0; break;
    }
}

void releaseSpecialKey(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP : deltaMove = 0.0; break;
        case GLUT_KEY_DOWN : deltaMove = 0.0; break;
    }
}

//----------------------------------------------------------------------
// Process mouse drag events
//
// This is called when dragging motion occurs. The variable
// angle stores the camera angle at the instance when dragging
// started, and deltaAngle is a additional angle based on the
// mouse movement since dragging started.
//----------------------------------------------------------------------
void mouseMove(int x, int y)
{
    if (isDragging) { // only when dragging
                      // update the change in angle
        deltaAngle = (x - xDragStart) * 0.005;
        
        // camera's direction is set to angle + deltaAngle
        lx = -sin(angle + deltaAngle);
        ly = cos(angle + deltaAngle);
    }
}

void mouseButton(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) { // left mouse button pressed
            isDragging = 1; // start dragging
            xDragStart = x; // save x where button first pressed
        }
        else  { /* (state = GLUT_UP) */
            angle += deltaAngle; // update camera turning angle
            isDragging = 0; // no longer dragging
        }
    }
}

//----------------------------------------------------------------------
// Main program  - standard GLUT initializations and callbacks
//----------------------------------------------------------------------
int main(int argc, char **argv)
{
    printf("\n\
           -----------------------------------------------------------------------\n\
           OpenGL snowman game:\n\
           - Drag mouse left-right to rotate camera\n\
           - Hold up-arrow/down-arrow to move camera forward/backward\n\
           - q or ESC to quit\n\
           -----------------------------------------------------------------------\n");
    
    // general initializations
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 500);
    glutCreateWindow("snowman land");
    //glutFullScreen();
    
    int i;
    for (i=0; i<=36; i++) {
        random_snowmen[i] = rand();
    }
    
    // register callbacks
    glutReshapeFunc(changeSize); // window reshape callback
    glutDisplayFunc(renderScene); // (re)display callback
    glutIdleFunc(update); // incremental update
    glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down
    glutMouseFunc(mouseButton); // process mouse button push/release
    glutMotionFunc(mouseMove); // process mouse dragging motion
    glutKeyboardFunc(processNormalKeys); // process standard key clicks
    glutSpecialFunc(pressSpecialKey); // process special key pressed
                                      // Warning: Nonstandard function! Delete if desired.
    glutSpecialUpFunc(releaseSpecialKey); // process special key release
    
    // OpenGL init
    glEnable(GL_DEPTH_TEST);
    
    // enter GLUT event processing cycle
    glutMainLoop();
    
    return 0; // this is just to keep the compiler happy
}
