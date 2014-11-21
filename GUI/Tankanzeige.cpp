/* 
 * File:   Tankanzeige.cpp
 * Author: bpse_sose14
 * 
 * Created on 24. September 2014, 14:51
 */

#include "Tankanzeige.h"



Tankanzeige::Tankanzeige() {
}

Tankanzeige::Tankanzeige(const Tankanzeige& orig) {
}

Tankanzeige::~Tankanzeige() {
}

Tankanzeige::Tankanzeige(GLfloat Tankinhalt, ITextur* textur)
{
    glPushMatrix();    
    Instrument((GLfloat)Tankinhalt,textur);
    //0
    glPushMatrix ();   
    glTranslatef(-10,0,-2.25);
    glScalef (0.01, 0.01, 0.5);
    WriteText("0");
    glPopMatrix();
    //10
    glPushMatrix ();
    glRotatef(-22.5,0,0,1);
    glTranslatef(-10,0,-2.25);
    glRotatef(22.5,0,0,1);
    glScalef (0.01, 0.01, 0.5);
    WriteText("10");
    glPopMatrix();
    //20
    glPushMatrix();
    glRotatef(-45,0,0,1);
    glTranslatef(-10,0,-2.25);
    glRotatef(45,0,0,1);
    glScalef (0.01, 0.01, 1.5);
    WriteText("20");
    glPopMatrix();
    //30
    glPushMatrix();
    glRotatef(-67.5,0,0,1);
    glTranslatef(-10,0,-2.25);
    glRotatef(67.5,0,0,1);
    glScalef (0.01, 0.01, 0.5);
    WriteText("30");
    glPopMatrix();
    //40
    glPushMatrix();
    glRotatef(-90,0,0,1);
    glTranslatef(-10,0,-2.25);
    glRotatef(90,0,0,1);
    glScalef (0.01, 0.01, 0.5);
    WriteText("40");
    glPopMatrix();   
    glPopMatrix();
}