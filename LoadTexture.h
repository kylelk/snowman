
/** Load the specified bitmap file from disk and copy it into an OpenGL texture.
 * Return the GLuint representing the texture.
 */
GLuint LoadTexture(const char * bitmap_file)
{
    GLuint texture = 0;
    bmpread_t bitmap;
    
    if(!bmpread(bitmap_file, 0, &bitmap))
    {
        fprintf(stderr, "%s: error loading bitmap file\n", bitmap_file);
        exit(1);
    }
    
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexImage2D(GL_TEXTURE_2D, 0, 3, bitmap.width, bitmap.height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, bitmap.rgb_data);
    
    bmpread_free(&bitmap);
    
    return texture;
}
