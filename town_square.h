void obelisk(void) {
    
    // main body of the obelisk
    // gray color
    glBegin(GL_QUADS);
        glColor3f( 0.75, 0.75, 0.75 );
        glVertex3f(-1, -1, 0 );
        glVertex3f( -0.625, -0.625, 10 );
        glVertex3f( -0.625, 0.625, 10 );
        glVertex3f(-1, 1, 0 );
    glEnd();
    
    glBegin(GL_QUADS);
        glColor3f( 0.75, 0.75, 0.75 );
        glVertex3f(-1, 1, 0 );
        glVertex3f( -0.625, 0.625, 10 );
        glVertex3f( 0.625, 0.625, 10 );
        glVertex3f(1, 1, 0 );
    glEnd();
    
    glBegin(GL_QUADS);
        glColor3f( 0.75, 0.75, 0.75 );
        glVertex3f(1, 1, 0 );
        glVertex3f( 0.625, 0.625, 10 );
        glVertex3f( 0.625, -0.625, 10 );
        glVertex3f(1, -1, 0 );
    glEnd();
    
    glBegin(GL_QUADS);
        glColor3f( 0.75, 0.75, 0.75 );
        glVertex3f(1, -1, 0 );
        glVertex3f( 0.625, -0.625, 10 );
        glVertex3f( -0.625, -0.625, 10 );
        glVertex3f(-1, -1, 0 );
    glEnd();
    
    // the edges of the obelisk
    glBegin(GL_LINES);
        glColor3f( 0, 0, 0 );
        glVertex3f(-1, -1, 0 );
        glVertex3f( -0.627, -0.627, 10 );
        glVertex3f( -0.627, 0.627, 10 );
        glVertex3f(-1, 1, 0 );
    glEnd();
    
    glBegin(GL_LINES);
        glColor3f( 0, 0, 0 );
        glVertex3f(-1, 1, 0 );
        glVertex3f( -0.627, 0.627, 10 );
        glVertex3f( 0.627, 0.627, 10 );
        glVertex3f(1, 1, 0 );
    glEnd();
    
    glBegin(GL_LINES);
        glColor3f( 0, 0, 0 );
        glVertex3f(1, 1, 0 );
        glVertex3f( 0.627, 0.627, 10 );
        glVertex3f( 0.627, -0.627, 10 );
        glVertex3f(1, -1, 0 );
    glEnd();
    
    glBegin(GL_LINES);
        glColor3f( 0, 0, 0 );
        glVertex3f(1, -1, 0 );
        glVertex3f( 0.627, -0.627, 10 );
        glVertex3f( -0.627, -0.627, 10 );
        glVertex3f(-1, -1, 0 );
    glEnd();

    // tip of obelisk
    // golden color
    glBegin(GL_TRIANGLES);
        glColor3f( 0.85, 0.85, 0.10 );
        glVertex3f( -0.625, -0.625, 10 );
        glVertex3f( 0, 0, 11 );
        glVertex3f( -0.625, 0.625, 10 );
    glEnd();
    
    glBegin(GL_TRIANGLES);
        glColor3f( 0.85, 0.85, 0.10 );
        glVertex3f( -0.625, 0.625, 10 );
        glVertex3f( 0, 0, 11 );
        glVertex3f( 0.625, 0.625, 10 );
    glEnd();
    
    glBegin(GL_TRIANGLES);
        glColor3f( 0.85, 0.85, 0.10 );
        glVertex3f( 0.625, 0.625, 10 );
        glVertex3f( 0, 0, 11 );
        glVertex3f( 0.625, -0.625, 10 );
    glEnd();
    
    glBegin(GL_TRIANGLES);
        glColor3f( 0.85, 0.85, 0.10 );
        glVertex3f( 0.625, -0.625, 10 );
        glVertex3f( 0, 0, 11 );
        glVertex3f( -0.625, -0.625, 10 );
    glEnd();
    
    // base of obelisk
    glPushMatrix();
        glColor3f( 0, 0, 0 );
        glTranslatef(0,0,-0.875);
        glutWireCube(2.5);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f( 0.75, 0.75, 0.75 );
        glTranslatef(0,0,-0.875);
        glutSolidCube(2.5);
    glPopMatrix();

}

void town_square(void) {
    obelisk();
}
