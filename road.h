
void road(void) {
    int i,j;
    glEnable(GL_TEXTURE_2D);
    GLuint tex2 = LoadTexture("textures/cobblestone.bmp");
    
    for(i = -3; i < 3; i++){
        for(j = -3; j < 3; j++) {
            
            glPushMatrix();
            glBindTexture(GL_TEXTURE_2D, tex2);
            // street
            // north
            glBegin(GL_QUADS);
                glTexCoord3f( -40, (i*12)+4, 0.003 );
                glVertex3f( -40, (i*12)+4, 0.003 );
            
                glTexCoord3f( -40, (i*12)+8, 0.003 );
                glVertex3f( -40, (i*12)+8, 0.003 );
            
                glTexCoord3f( 40,  (i*12)+8, 0.003 );
                glVertex3f( 40,  (i*12)+8, 0.003 );
            
                glTexCoord3f( 40,  (i*12)+4, 0.003 );
                glVertex3f( 40,  (i*12)+4, 0.003 );
            glEnd();
            // south
            glBegin(GL_QUADS);
                glTexCoord3f( (i*12)+4, -40, 0.003 );
                glVertex3f( (i*12)+4, -40, 0.003 );
            
                glTexCoord3f( (i*12)+8, -40, 0.003 );
                glVertex3f( (i*12)+8, -40, 0.003 );
            
                glTexCoord3f( (i*12)+8,  40, 0.003 );
                glVertex3f( (i*12)+8,  40, 0.003 );
            
                glTexCoord3f( (i*12)+4,  40, 0.003 );
                glVertex3f( (i*12)+4,  40, 0.003 );
            glEnd();

            glColor3f(0.75, 0.75, 0.75);
            glPopMatrix();
        }
    }
    glDisable(GL_TEXTURE_2D);
}
