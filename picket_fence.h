#define FENCE_SIZE 4
#define FENCE_HEIGHT 1
#define PICKET_WIDTH 0.128
#define PICKET_SPACING 0.375


void picket_fence(void) {
    // north
    // bottom fence rail
    glBegin(GL_QUADS);
    glColor3f(  1,  1,  1 );
    glVertex3f(-FENCE_SIZE, FENCE_SIZE, 0.256 );
    glVertex3f(-FENCE_SIZE, FENCE_SIZE, 0.256+PICKET_WIDTH );
    glVertex3f( FENCE_SIZE, FENCE_SIZE, 0.256 );
    glVertex3f( FENCE_SIZE, FENCE_SIZE, 0.256+PICKET_WIDTH );
    glEnd();
    // top fence rail
    glBegin(GL_QUADS);
    glColor3f(  1,  1,  1 );
    glVertex3f(-FENCE_SIZE, FENCE_SIZE, 0.744 );
    glVertex3f(-FENCE_SIZE, FENCE_SIZE, 0.744-PICKET_WIDTH );
    glVertex3f( FENCE_SIZE, FENCE_SIZE, 0.744 );
    glVertex3f( FENCE_SIZE, FENCE_SIZE, 0.744-PICKET_WIDTH );
    glEnd();
    
    // south
    // bottom fence rail
    glBegin(GL_QUADS);
    glColor3f(  1,  1,  1 );
    glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.256 );
    glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.256+PICKET_WIDTH );
    glVertex3f( FENCE_SIZE, -FENCE_SIZE, 0.256 );
    glVertex3f( FENCE_SIZE, -FENCE_SIZE, 0.256+PICKET_WIDTH );
    glEnd();
    // top fence rail
    glBegin(GL_QUADS);
    glColor3f(  1,  1,  1 );
    glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.744 );
    glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.744-PICKET_WIDTH );
    glVertex3f( FENCE_SIZE, -FENCE_SIZE, 0.744 );
    glVertex3f( FENCE_SIZE, -FENCE_SIZE, 0.744-PICKET_WIDTH );
    glEnd();
    
    //east
    // bottom fence rail
    glBegin(GL_QUADS);
    glColor3f(  1,  1,  1 );
    glVertex3f(FENCE_SIZE, -FENCE_SIZE, 0.256 );
    glVertex3f(FENCE_SIZE, -FENCE_SIZE, 0.256+PICKET_WIDTH );
    glVertex3f(FENCE_SIZE, FENCE_SIZE, 0.256 );
    glVertex3f(FENCE_SIZE, FENCE_SIZE, 0.256+PICKET_WIDTH );
    glEnd();
    // top fence rail
    glBegin(GL_QUADS);
    glColor3f(  1,  1,  1 );
    glVertex3f(FENCE_SIZE, -FENCE_SIZE, 0.744 );
    glVertex3f(FENCE_SIZE, -FENCE_SIZE, 0.744-PICKET_WIDTH );
    glVertex3f(FENCE_SIZE, FENCE_SIZE, 0.744 );
    glVertex3f(FENCE_SIZE, FENCE_SIZE, 0.744-PICKET_WIDTH );
    glEnd();
    
    // west
    // bottom fence rail
    glBegin(GL_QUADS);
    glColor3f(  1,  1,  1 );
    glVertex3f(-FENCE_SIZE, FENCE_SIZE, 0.256 );
    glVertex3f(-FENCE_SIZE, FENCE_SIZE, 0.256+PICKET_WIDTH );
    glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.256 );
    glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.256+PICKET_WIDTH );
    glEnd();
    // top fence rail
    glBegin(GL_QUADS);
    glColor3f(  1,  1,  1 );
    glVertex3f(-FENCE_SIZE, FENCE_SIZE, 0.744 );
    glVertex3f(-FENCE_SIZE, FENCE_SIZE, 0.744-PICKET_WIDTH );
    glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.744 );
    glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.744-PICKET_WIDTH );
    glEnd();
    
    
    
    // draw fence pickets
    float a;
    for (a=-FENCE_SIZE; a<=FENCE_SIZE; a+=PICKET_SPACING) {
        
        // north
        glBegin(GL_QUADS);
        glColor3f(  1,  1,  1 );
        glVertex3f( a, FENCE_SIZE, 0 );
        glVertex3f( a+PICKET_WIDTH, FENCE_SIZE, 0 );
        glVertex3f( a+PICKET_WIDTH, FENCE_SIZE, FENCE_HEIGHT );
        glVertex3f( a, FENCE_SIZE, FENCE_HEIGHT );
        glEnd();
        
        // south
        glBegin(GL_QUADS);
        glColor3f(  1,  1,  1 );
        glVertex3f( a, -FENCE_SIZE, 0 );
        glVertex3f( a+PICKET_WIDTH, -FENCE_SIZE, 0 );
        glVertex3f( a+PICKET_WIDTH, -FENCE_SIZE, FENCE_HEIGHT );
        glVertex3f( a, -FENCE_SIZE, FENCE_HEIGHT );
        glEnd();
        
        // east
        glBegin(GL_QUADS);
        glColor3f(  1,  1,  1 );
        glVertex3f( FENCE_SIZE,       a, 0 );
        glVertex3f( FENCE_SIZE, a+PICKET_WIDTH, 0 );
        glVertex3f( FENCE_SIZE, a+PICKET_WIDTH, FENCE_HEIGHT );
        glVertex3f( FENCE_SIZE, a, FENCE_HEIGHT );
        glEnd();
        
        // west
        glBegin(GL_QUADS);
        glColor3f(  1,  1,  1 );
        glVertex3f( -FENCE_SIZE,       a, 0 );
        glVertex3f( -FENCE_SIZE, a+PICKET_WIDTH, 0 );
        glVertex3f( -FENCE_SIZE, a+PICKET_WIDTH, FENCE_HEIGHT );
        glVertex3f( -FENCE_SIZE, a, FENCE_HEIGHT );
        glEnd();
        
    }

}