#include "GL20GUI.h"
#include <string.h>
#include <iostream>
#include <GraphicsEngine/Screen.h>

void GL20GUI::Label(int x, int y, int w, int h, const char * pText) {
    GLint width = Screen::GetWidth();
    GLint height = Screen::GetHeight();
    GLint text_width    = glutStrokeLength(GLUT_STROKE_ROMAN,
                                           reinterpret_cast<const unsigned char*>(pText));
    GLfloat text_height = glutStrokeHeight(GLUT_STROKE_ROMAN);
    glMatrixMode( GL_PROJECTION );
    glPushMatrix(); // save
    glLoadIdentity();// and clear
//    gluOrtho2D(0.0, width, 0.0, height);
    glMatrixMode( GL_MODELVIEW );
    glPushMatrix();
    glLoadIdentity();

    glDisable( GL_DEPTH_TEST ); // also disable the depth test so renders on top
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
//    std::cout << height << " " << width << std::endl;
    glTranslatef(-1.f, -1.f, 1.f);
    glScalef((float) w / (float)width * 0.001f, (float)h / (float)height * 0.001f, 1.f);
//    glRasterPos2i(x, y);
    glutStrokeString(GLUT_STROKE_ROMAN, reinterpret_cast<const unsigned char*>(pText));
//    do {
//        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *pText);
//    glutBitmapString( GLUT_BITMAP_HELVETICA_18, reinterpret_cast<const unsigned char*>(pText));
//    } while( *(++pText) );
    glEnable( GL_DEPTH_TEST ); // Turn depth testing back on

    glMatrixMode( GL_PROJECTION );
    glPopMatrix(); // revert back to the matrix I had before.
    glMatrixMode( GL_MODELVIEW );
    glPopMatrix();
}
