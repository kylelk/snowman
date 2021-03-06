// gcc -o snowman snowman.c -framework GLUT -framework OpenGL

#include <stdlib.h> // standard definitions
#include <math.h> // math definitions
#include <stdio.h> // standard I/O
#include <string.h>

#include "libbmpread/bmpread.h"

// include files are in a slightly different location for MacOS
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "LoadTexture.h"

/* START objects */
#include "ground.h"
#include "picket_fence.h"
#include "drawSnowman.h"
#include "road.h"
#include "town_square.h"
/* END objects */


// escape key (for exit)
#define ESC 27

#define MIN_VIEW_HEIGHT 0.1
#define UPDATE_FREQ 10
#define PROXIMITY 5

#define FULLSCREEN_MODE
#define WINDOW_SIZE 1000,600
//#define USE_LIGHTING

struct point {
    float x,y;
};
typedef struct point location;


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
float x = 0.0, y = -5.0, z = 0.0; // initially 5 units south of origin
float sx = 0.0, sy = 1.0; // camera side position
float deltaMove = 0.0; // initially camera doesn't move
float cameraHeightMove = 0.0;

float camera_height = 1.5;
#define CAMERA_MOVE_UP 1
#define CAMERA_MOVE_DOWN 2

// Camera direction
float lx = 0.0, ly = 1.0, lz = 0.0; // camera points initially along y-axis
float angle = 0.0; // angle of rotation for the camera direction
float deltaAngle = 0.0; // additional angle change when dragging

// Mouse drag control
int isDragging = 0; // true when dragging
int xDragStart = 0; // records the x-coordinate when dragging starts

location xy_pos;
location last_xy;

float last_distance=0;

float xd, yd;
float distance;
float x2=0, y2=0;
uint8_t update_count = 0;

float n_x, n_y;

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

int near_mult(float n, int m) {
    if (n > 0){
        return ceil(n/m) * m;
    }
    else if ( n < 0) {
        return floor(n/m) * n;
    }
    else {
        return m;
    }
}



//----------------------------------------------------------------------
// Update with each idle event
//
// This incrementally moves the camera and requests that the scene be
// redrawn.
//----------------------------------------------------------------------
void update(void) {
    
    if (deltaMove) { // update camera position
        x += deltaMove * lx * 0.1;
        y += deltaMove * ly * 0.1;
        z += deltaMove * lz * 0.1;
        
        if (update_count >= UPDATE_FREQ) {
            if (x < -39) { x = -39; }
            else if (x > 39) { x = 39; }
            
            if (y < -39) { y = -39; }
            else if (y > 39) { y = 39; }
            
            n_x = near_mult(x,12);
            n_y = near_mult(y,12);
            
            //printf("%d %d\n", n_x, n_y);
        }
        update_count++;
    }
    
    if (cameraHeightMove == CAMERA_MOVE_UP) {
        camera_height += 0.050;
    }
    else if (cameraHeightMove == CAMERA_MOVE_DOWN){
        camera_height -= 0.050;
        
        if (camera_height < MIN_VIEW_HEIGHT) {
            camera_height=0.1;
        }
        
    }
    glutPostRedisplay(); // redisplay everything
}

void render_objects(void) {
    
    int i, j;
    
    ground();
    
    for(i = -3; i < 4; i++){
        for(j = -3; j < 4; j++) {
            // skip drawing in the center
            if ( (i==0)&&(j==0) ) {
                // render the center of the town
                town_square();
                continue;
            }
            
            glPushMatrix();
                glTranslatef(i*12, j*12, 0);
                drawSnowman();
                picket_fence();
            glPopMatrix();
            
        }
    }
    road();
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
    #ifdef USE_LIGHTING
    glEnable(GL_COLOR_MATERIAL);
    #endif
    
    // Reset transformations
    glLoadIdentity();
    
    // Set the camera centered at (x,y,1) and looking along directional
    // vector (lx, ly, 0), with the z-axis pointing up
    gluLookAt(
              x,      y,      camera_height,
              x + lx, y + ly, camera_height,
              0.0,    0.0,    camera_height);
    
    render_objects();
    #ifdef USE_LIGHTING
    glDisable(GL_COLOR_MATERIAL);
    #endif
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
        case GLUT_KEY_UP:
            deltaMove = 1.0;
            break;
        case GLUT_KEY_DOWN:
            deltaMove = -1.0;
            break;
        case GLUT_KEY_LEFT:
            break;
        case GLUT_KEY_RIGHT:
            break;
        case GLUT_KEY_PAGE_UP:
            cameraHeightMove = 1;
            break;
        case GLUT_KEY_PAGE_DOWN:
            cameraHeightMove = 2;
            break;
    }
}

void releaseSpecialKey(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            deltaMove = 0.0;
            break;
        case GLUT_KEY_DOWN:
            deltaMove = 0.0;
            break;
        case GLUT_KEY_PAGE_UP:
            cameraHeightMove = 0.0;
            break;
        case GLUT_KEY_PAGE_DOWN:
            cameraHeightMove = 0.0;
            break;
            
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
        lz = -cos(angle + deltaAngle);
    }
}

void mouseButton(int button, int state, int x, int y) {
    int r=glutGetModifiers();
    
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
    
    if (button == GLUT_MIDDLE_BUTTON){
        deltaMove = 0.0;
    }
    
    if (r == GLUT_ACTIVE_CTRL) {
        if (button == GLUT_LEFT_BUTTON) {
            cameraHeightMove = 1;
        }
        if (button == GLUT_RIGHT_BUTTON) {
            cameraHeightMove = 2;
        }
    } else {
        cameraHeightMove = 0;
    }
}

//----------------------------------------------------------------------
// Main program  - standard GLUT initializations and callbacks
//----------------------------------------------------------------------
int main(int argc, char **argv)
{
    //printf("\n\
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
    glutInitWindowSize(WINDOW_SIZE);
    glutCreateWindow("snowman land");
    #ifdef FULLSCREEN_MODE
    glutFullScreen();
    #endif
    
    // register callbacks
    glutReshapeFunc(changeSize); // window reshape callback
    glutDisplayFunc(renderScene); // (re)display callback
    glutIdleFunc(update); // incremental update
    glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down
    glutMouseFunc(mouseButton); // process mouse button push/release
    glutMotionFunc(mouseMove); // process mouse dragging motion
    glutKeyboardFunc(processNormalKeys); // process standard key clicks
    glutSpecialFunc(pressSpecialKey); // process special key pressed
    glutSpecialUpFunc(releaseSpecialKey); // process special key release
    
    #ifdef USE_LIGHTING
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    
    GLfloat lightpos[] = {0, 0, 50, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    #endif
    
    // OpenGL init
    glEnable(GL_DEPTH_TEST);
    
    // enter GLUT event processing cycle
    glutMainLoop();
    
    return 0; // this is just to keep the compiler happy
}
