#define FENCE_SIZE 4
#define FENCE_HEIGHT 1
#define PICKET_WIDTH 0.128
#define PICKET_SPACING 0.375

#define PICKET_BOARDER 1 // true

void pickets(void) {
    glBegin(GL_POLYGON);
        glColor3f(  0.91,  0.76,  0.65 );
        glVertex3f( 0, -FENCE_SIZE, 0 );
        glVertex3f( PICKET_WIDTH, -FENCE_SIZE, 0 );
        glVertex3f( PICKET_WIDTH, -FENCE_SIZE, FENCE_HEIGHT );
        glVertex3f( PICKET_WIDTH/2, -FENCE_SIZE, FENCE_HEIGHT+PICKET_WIDTH );//tip
        glVertex3f( 0, -FENCE_SIZE, FENCE_HEIGHT );
    glEnd();
    
    #ifdef PICKET_BOARDER
    glBegin(GL_LINE_LOOP);
        glColor3f(  0,  0,  0 );
        glVertex3f( 0, -FENCE_SIZE, 0 );
        glVertex3f( PICKET_WIDTH, -FENCE_SIZE, 0 );
        glVertex3f( PICKET_WIDTH, -FENCE_SIZE, FENCE_HEIGHT );
        glVertex3f( PICKET_WIDTH/2, -FENCE_SIZE, FENCE_HEIGHT+PICKET_WIDTH );//tip
        glVertex3f( 0, -FENCE_SIZE, FENCE_HEIGHT );
    glEnd();
    #endif
}

void side_pickets(void) {
    glBegin(GL_POLYGON);
        glColor3f(  0.91,  0.76,  0.65 );
        glVertex3f( -FENCE_SIZE, 0, 0 );
        glVertex3f( -FENCE_SIZE, PICKET_WIDTH, 0 );
        glVertex3f( -FENCE_SIZE, PICKET_WIDTH, FENCE_HEIGHT );
        glVertex3f( -FENCE_SIZE, PICKET_WIDTH/2, FENCE_HEIGHT+PICKET_WIDTH );//tip
        glVertex3f( -FENCE_SIZE, 0, FENCE_HEIGHT );
    glEnd();
    
    #ifdef PICKET_BOARDER
    glBegin(GL_LINE_LOOP);
        glColor3f(  0,  0,  0 );
        glVertex3f( -FENCE_SIZE, 0, 0 );
        glVertex3f( -FENCE_SIZE, PICKET_WIDTH, 0 );
        glVertex3f( -FENCE_SIZE, PICKET_WIDTH, FENCE_HEIGHT );
        glVertex3f( -FENCE_SIZE, PICKET_WIDTH/2, FENCE_HEIGHT+PICKET_WIDTH );//tip
        glVertex3f( -FENCE_SIZE, 0, FENCE_HEIGHT );
    glEnd();
    #endif
}

void rail(void) {
    // bottom fence rail
    glBegin(GL_QUADS);
        glColor3f(  0.91,  0.76,  0.65 );
        glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.256 );
        glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.256+PICKET_WIDTH );
        glVertex3f( FENCE_SIZE, -FENCE_SIZE, 0.256+PICKET_WIDTH );
        glVertex3f( FENCE_SIZE, -FENCE_SIZE, 0.256 );
    glEnd();
    
    // top fence rail
    glBegin(GL_QUADS);
        glColor3f(  0.91,  0.76,  0.65 );
        glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.744 );
        glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.744-PICKET_WIDTH );
        glVertex3f( FENCE_SIZE, -FENCE_SIZE, 0.744-PICKET_WIDTH );
        glVertex3f( FENCE_SIZE, -FENCE_SIZE, 0.744 );
    glEnd();
}

void side_rail(void) {
    // bottom fence rail
    glBegin(GL_QUADS);
        glColor3f(  0.91,  0.76,  0.65 );
        glVertex3f(-FENCE_SIZE, FENCE_SIZE, 0.256 );
        glVertex3f(-FENCE_SIZE, FENCE_SIZE, 0.256+PICKET_WIDTH );
        glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.256+PICKET_WIDTH );
        glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.256 );
    glEnd();
    // top fence rail
    glBegin(GL_QUADS);
        glColor3f(  0.91,  0.76,  0.65 );
        glVertex3f(-FENCE_SIZE, FENCE_SIZE, 0.744 );
        glVertex3f(-FENCE_SIZE, FENCE_SIZE, 0.744-PICKET_WIDTH );
        glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.744-PICKET_WIDTH );
        glVertex3f(-FENCE_SIZE, -FENCE_SIZE, 0.744 );
    glEnd();
}


void picket_fence(void) {
    
    // north south rails
    glPushMatrix();
        glTranslatef(0, 0, 0);
        rail();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0, 8, 0);
        rail();
    glPopMatrix();
    
    // east west rails
    glPushMatrix();
        glTranslatef(0, 0, 0);
        side_rail();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(8, 0, 0);
        side_rail();
    glPopMatrix();
    
    
    // draw fence pickets
    float a;
    for (a=-FENCE_SIZE; a<=FENCE_SIZE; a+=PICKET_SPACING) {
        // north south pickets
        glPushMatrix();
            glTranslatef(a, 0, 0);
            pickets();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(a, 8, 0);
            pickets();
        glPopMatrix();
        
        // east west pickets
        glPushMatrix();
            glTranslatef(0, a, 0);
            side_pickets();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(8, a, 0);
            side_pickets();
        glPopMatrix();
    }
}
