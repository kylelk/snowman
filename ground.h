
void ground(void) {
    glEnable(GL_TEXTURE_2D);
    GLuint tex1 = LoadTexture("textures/grass.bmp");
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, tex1);
        glBegin(GL_QUADS);
            glTexCoord3f(-100.0, -100.0, 0.0);
            glVertex3f(-100.0, -100.0, 0.0);
    
            glTexCoord3f(-100.0,  100.0, 0.0);
            glVertex3f(-100.0,  100.0, 0.0);
    
            glTexCoord3f( 100.0,  100.0, 0.0);
            glVertex3f( 100.0,  100.0, 0.0);
    
            glTexCoord3f( 100.0, -100.0, 0.0);
            glVertex3f( 100.0, -100.0, 0.0);
        glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
