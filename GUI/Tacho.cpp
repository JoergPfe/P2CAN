/* 
 * File:   Tacho.cpp
 * Author: bpse_sose14
 * 
 * Created on 25. September 2014, 11:04
 */

#include "Tacho.h"
#include <stdio.h>
#include <stdlib.h>
Tacho::Tacho() {
}

Tacho::Tacho(const Tacho& orig) {
}

Tacho::~Tacho() {
}
//blinker = 0 aus; blinker = 1 rechts; blinker = 2 links;
Tacho::Tacho(GLfloat kmStand, GLfloat Geschwindigkeit, int blinker, ITextur* textur)
{
    glPushMatrix();
    Instrument((GLfloat)kmStand,textur);
    //40
    
    glPushMatrix (); 
    if(blinker == 1)
    {
        glColor3f(0,1,0);
    }    
    else
    {
        glColor3f(0,0,0);
    }
    glTranslatef(-10,0,-2.25);
    glScalef (0.01, 0.01, 0.5);
    WriteText("40");
    glPopMatrix();
    //35
    glPushMatrix ();
    glColor3f(0,0,0);
    glRotatef(-22.5,0,0,1);
    glTranslatef(-10,0,-2.25);
    glRotatef(22.5,0,0,1);
    glScalef (0.01, 0.01, 0.5);
    WriteText("35");
    glPopMatrix();
    //30
    glPushMatrix();
    glColor3f(0,0,0);
    glRotatef(-45,0,0,1);
    glTranslatef(-10,0,-2.25);
    glRotatef(45,0,0,1);
    glScalef (0.01, 0.01, 1.5);
    WriteText("30");
    glPopMatrix();
    //25
    glPushMatrix();
    glColor3f(0,0,0);
    glRotatef(-67.5,0,0,1);
    glTranslatef(-10,0,-2.25);
    glRotatef(67.5,0,0,1);
    glScalef (0.01, 0.01, 0.5);
    WriteText("25");
    glPopMatrix();
    //20
    glPushMatrix();
    glColor3f(0,0,0);
    glRotatef(-90,0,0,1);
    glTranslatef(-10,0,-2.25);
    glRotatef(90,0,0,1);
    glScalef (0.01, 0.01, 0.5);
    WriteText("20");
    glPopMatrix();   
    glPopMatrix();
    //15
    glPushMatrix();
    glColor3f(0,0,0);
    glRotatef(-112.5,0,0,1);
    glTranslatef(-10,0,-2.25);
    glRotatef(112.5,0,0,1);
    glScalef (0.01, 0.01, 0.5);
    WriteText("15");
    glPopMatrix();   
    glPopMatrix();
    //10
    glPushMatrix();
    glColor3f(0,0,0);
    glRotatef(-135,0,0,1);
    glTranslatef(-10,0,-2.25);
    glRotatef(135,0,0,1);
    glScalef (0.01, 0.01, 0.5);
    WriteText("10");
    glPopMatrix();   
    glPopMatrix();
    //5
    glPushMatrix();
    glColor3f(0,0,0);
    glRotatef(-157.5,0,0,1);
    glTranslatef(-10,0,-2.25);
    glRotatef(157.5,0,0,1);
    glScalef (0.01, 0.01, 0.5);
    WriteText("5");
    glPopMatrix();   
    glPopMatrix();
    //0
    glPushMatrix();
    if(blinker == 2)
    {
        glColor3f(0,1,0);
    }
    else
    {
        glColor3f(0,0,0);
    }
    glTranslatef(10,0,-2.25);
    glScalef (0.01, 0.01, 0.5);
    WriteText("0");
    glPopMatrix();   
    glPopMatrix();
    //Quellen:http://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
    std::stringstream ss;
    ss << Geschwindigkeit; 
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(1.2,-5,-2.25);
    glScalef (0.01, 0.01, 0.5);
    WriteText(ss.str());
    glPopMatrix();    
}
