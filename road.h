void side_walk(int i) {
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.75, 0.75);
    glVertex3f( -40, (i*12)+4, 0.001 );
    glVertex3f( -40, (i*12)+5, 0.001 );
    glVertex3f( 40,  (i*12)+5, 0.001 );
    glVertex3f( 40,  (i*12)+4, 0.001 );
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.75, 0.75);
    glVertex3f( -40, (i*12)+7, 0.001 );
    glVertex3f( -40, (i*12)+8, 0.001 );
    glVertex3f( 40,  (i*12)+8, 0.001 );
    glVertex3f( 40,  (i*12)+7, 0.001 );
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.75, 0.75, 0.75);
    glVertex3f( (i*12)+4, -40, 0.001 );
    glVertex3f( (i*12)+5, -40, 0.001 );
    glVertex3f( (i*12)+5,  40, 0.001 );
    glVertex3f( (i*12)+4,  40, 0.001 );
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.75, 0.75, 0.75);
    glVertex3f( (i*12)+7, -40, 0.001 );
    glVertex3f( (i*12)+8, -40, 0.001 );
    glVertex3f( (i*12)+8,  40, 0.001 );
    glVertex3f( (i*12)+7,  40, 0.001 );
    glEnd();

}


void road(void) {
    int i,j;
    for(i = -3; i < 4; i++){
        for(j = -3; j < 4; j++) {
            glPushMatrix();
            
            // street
            // north
            glBegin(GL_QUADS);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f( -40, (i*12)+5, 0.002 );
            glVertex3f( -40, (i*12)+7, 0.002 );
            glVertex3f( 40,  (i*12)+7, 0.002 );
            glVertex3f( 40,  (i*12)+5, 0.002 );
            glEnd();
            // south
            glBegin(GL_QUADS);
            glColor3f(0.0, 0.0, 0.0);
            glVertex3f( (i*12)+5, -40, 0.002 );
            glVertex3f( (i*12)+7, -40, 0.002 );
            glVertex3f( (i*12)+7,  40, 0.002 );
            glVertex3f( (i*12)+5,  40, 0.002 );
            glEnd();
            
            side_walk(i);
            
            glPopMatrix();
            
        }
    }
}