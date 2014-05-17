//----------------------------------------------------------------------
// Draw one snowmen (at the origin)
//
// A snowman consists of a large body sphere and a smaller head sphere.
// The head sphere has two black eyes and an orange conical nose. To
// better create the impression they are sitting on the ground, we draw
// a fake shadow, consisting of a dark circle under each.
//
// We make extensive use of nested transformations. Everything is drawn
// relative to the origin. The snowman's eyes and nose are positioned
// relative to a head sphere centered at the origin. Then the head is
// translated into its final position. The body is drawn and translated
// into its final position.
//----------------------------------------------------------------------


void drawSnowman()
{
    // Draw body (a 20x20 spherical mesh of radius 0.75 at height 0.75)
    glColor3f(1.0, 1.0, 1.0); // set drawing color to white
    glPushMatrix();
        glTranslatef(0.0, 0.0, 0.75);
        glutSolidSphere(0.75, 20, 20);
    glPopMatrix();
    
    // Draw the head (a sphere of radius 0.25 at height 1.75)
    glPushMatrix();
        glTranslatef(0.0, 0.0, 1.70); // position head
        glutSolidSphere(0.25, 20, 20); // head sphere
        // Draw Eyes (two small black spheres)
        glColor3f(0, 0, 0); // eyes are black
        glPushMatrix();
            glTranslatef(0.0, -0.18, 0.10); // lift eyes to final position
            glPushMatrix();
                glTranslatef(-0.05, 0.0, 0.0);
                glutSolidSphere(0.05, 10, 10); // right eye
            glPopMatrix();
        glPushMatrix();
            glTranslatef(+0.05, 0.0, 0.0);
            glutSolidSphere(0.05, 10, 10); // left eye
        glPopMatrix();
    glPopMatrix();
    
    // Draw Nose (the nose is an orange cone)
    glPushMatrix();
        glColor3f(1.0, 0.5, 0.5); // nose is orange
        glRotatef(90.0, 1.0, 0.0, 0.0); // rotate to point along -y
        glutSolidCone(0.08, 0.5, 10, 2); // draw cone
    glPopMatrix();
    
    
    glPopMatrix();
    
//    // Draw a faux shadow beneath snow man (dark green circle)
//    glPushMatrix();
//        glColor3f(0.0, 0.5, 0.0);
//        glTranslatef(0.2, 0.2, 0.001);	// translate to just above ground
//        glScalef(1.0, 1.0, 0.0); // scale sphere into a flat pancake
//        glutSolidSphere(0.75, 20, 20); // shadow same size as body
//    glPopMatrix();
    
    
    glPushMatrix();
        glTranslatef(-1.0, 1.0, 0.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glScalef(1.0, 40.0, 1.0);
        glColor3f(1.0, 1.0, 0.0);
        glutSolidCube(0.125);
    glPopMatrix();
    
    // Draw the legs
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    
    glPushMatrix();
        glTranslatef(1.0, 1.0, 0.0);
        glRotatef(0.0, 0.0, 1.0, 0.0);
        glColor3f(1.0, 1.0, 0.0);
        gluCylinder(quadratic, 0.075, 0.075, 2.5, 32,32);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(1.0, -1.0, 0.0);
        glRotatef(0.0, 0.0, 1.0, 0.0);
        glColor3f(1.0, 1.0, 0.0);
        gluCylinder(quadratic, 0.075, 0.075, 2.5, 32,32);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-1.0, -1.0, 0.0);
        glRotatef(0.0, 0.0, 1.0, 0.0);
        glColor3f(1.0, 1.0, 0.0);
        gluCylinder(quadratic, 0.075, 0.075, 2.5, 32,32);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(-1.0, 1.0, 0.0);
        glRotatef(0.0, 0.0, 1.0, 0.0);
        glColor3f(1.0, 1.0, 0.0);
        gluCylinder(quadratic, 0.075, 0.075, 2.5, 32,32);
    glPopMatrix();
    
    
    // draw roof using a cone
    glPushMatrix();
        glTranslatef(0.0, 0.0, 2.5);
        glColor3f(255, 0.0, 0.0);
        glutSolidCone(1.75, 1, 32, 16);
    glPopMatrix();
    
    // draw a ring
    glPushMatrix();  // Green Torus
        glTranslatef(0.0, 0.0, 2.5);
        glRotatef(0.0, 1.0, 0.0, 0.0);
        glColor3f(0.75, 0.75, 0.75);
        glutSolidTorus(0.075, 1.75, 32, 32);
    glPopMatrix();
}
