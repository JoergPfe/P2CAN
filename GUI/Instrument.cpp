/* 
 * File:   Instrument.cpp
 * Author: bpse_sose14
 * 
 * Created on 24. September 2014, 14:29
 */

#include "Instrument.h"
#include <iostream>
Instrument::Instrument() {
}

Instrument::Instrument(const Instrument& orig) {
}

Instrument::~Instrument() {
}

Instrument::Instrument(GLfloat rotation, ITextur* textur)
{
    //instrument
    //glPushMatrix();
    
    
    //neuer Code
    glPushMatrix();
    glColor4f(0.52, 0.30, 0.30, 1.0f); 
    glScalef(13,13,2);
    Zylinder_mit_Deckel(textur->deckel, textur->boden, textur->mantel);  
    std::cout << std::endl << textur->deckel;
    glPopMatrix();
    /*glColor4f(0.52, 0.30, 0.30, 1.0f); // Braune Farbe
    glBegin(GL_POLYGON);
    GLUquadricObj *obj = gluNewQuadric();
    gluCylinder(obj, 13, 13, 2, 50, 50);
    glEnd();*/
    //glPopMatrix();
    //punkt für Tacho Nadel
    glPushMatrix();
    glColor3f(0, 0, 0); // Schwarze Farbe
    glTranslatef(0,0,-2);
    glRotatef(90,1,0,0);
    
    Zylinder(1.0, NULL);
    glPopMatrix();
    //glPopMatrix();
    //Nadel Rechteck
    glPushMatrix();
    glRotatef(rotation,0,0,1);
    glPushMatrix();
    glColor3f(0, 0, 0); // Schwarze Farbe    
    glTranslatef(4.5,0,-2); 
    glScalef(9,0.8,1);
    glutSolidCube(1);
    glPopMatrix();
    //Nadel Pfeil
    glPushMatrix();
    glColor3f(0, 0, 0); // Schwarze Farbe
    glTranslatef(8.5,0,-2);    
    glRotatef(-90,0,0,1);
    Triangle(1,1);
    glPopMatrix();
    glPopMatrix();
}

