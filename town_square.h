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
    
    
    // tip of obelisk
    // golden color
    glBegin(GL_QUADS);
    glColor3f( 0.85, 0.85, 0.10 );
    glVertex3f( -0.625, -0.625, 10 );
    glVertex3f( 0, 0, 11 );
    glVertex3f( 0, 0, 11 );
    glVertex3f( -0.625, 0.625, 10 );
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f( 0.85, 0.85, 0.10 );
    glVertex3f( -0.625, 0.625, 10 );
    glVertex3f( 0, 0, 11 );
    glVertex3f( 0, 0, 11 );
    glVertex3f( 0.625, 0.625, 10 );
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f( 0.85, 0.85, 0.10 );
    glVertex3f( 0.625, 0.625, 10 );
    glVertex3f( 0, 0, 11 );
    glVertex3f( 0, 0, 11 );
    glVertex3f( 0.625, -0.625, 10 );
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f( 0.85, 0.85, 0.10 );
    glVertex3f( 0.625, -0.625, 10 );
    glVertex3f( 0, 0, 11 );
    glVertex3f( 0, 0, 11 );
    glVertex3f( -0.625, -0.625, 10 );
    glEnd();

}

void town_square(void) {
    obelisk();
}
