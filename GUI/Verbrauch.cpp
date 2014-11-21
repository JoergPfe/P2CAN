/* 
 * File:   Verbrauch.cpp
 * Author: bpse_sose14
 * 
 * Created on 25. September 2014, 14:22
 */

#include "Verbrauch.h"

Verbrauch::Verbrauch() {
}

Verbrauch::Verbrauch(const Verbrauch& orig) {
}

Verbrauch::~Verbrauch() {
}

Verbrauch::Verbrauch(GLfloat verbrauch, ITextur* textur)
{
    glPushMatrix();    
    Instrument((GLfloat)verbrauch,textur);
    //0
    glPushMatrix ();   
    glTranslatef(10,0,-2.25);
    glScalef (0.01, 0.01, 0.5);
    WriteText("5");
    glPopMatrix();
    //10
    glPushMatrix ();
    glRotatef(-135,0,0,1);
    glTranslatef(-10,0,-2.25);
    glRotatef(135,0,0,1);
    glScalef (0.01, 0.01, 0.5);
    WriteText("10");
    glPopMatrix();
    //15
    glPushMatrix();
    glRotatef(-90,0,0,1);
    glTranslatef(-10,0,-2.25);
    glRotatef(90,0,0,1);
    glScalef (0.01, 0.01, 1.5);
    WriteText("15");
    glPopMatrix();
    glPopMatrix();   
}

