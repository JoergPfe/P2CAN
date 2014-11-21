/* 
 * File:   Zylinder.cpp
 * Author: bpse_sose14
 * 
 * Created on 24. September 2014, 12:50
 */

#include "Zylinder.h"

Zylinder::Zylinder() {
}

Zylinder::Zylinder(const Zylinder& orig) {
}

Zylinder::~Zylinder() {
}

void Kreis (GLfloat radius)
{
	glBegin(GL_POLYGON);   //Kreis
	for(float i = 0;i <= 360;i++)
	{
		glVertex2f(radius*cos(i),radius*sin(i));
	}		
	glEnd();
}

void Mantel(GLfloat radius)
{
	float genauigkeit = 0.2;
	glBegin(GL_QUAD_STRIP);   //Kreis
	for(float i = 0;i <= 360;i = i+ genauigkeit)
	{
		glVertex3f(radius*cos(i),radius*sin(i),1);
		glVertex3f(radius*cos(i),radius*sin(i),-1);
		glVertex3f(radius*cos(i+genauigkeit),radius*sin(i),1);
		glVertex3f(radius*cos(i+genauigkeit),radius*sin(i),-1);
	}
	glEnd();
}


Zylinder::Zylinder(GLfloat radius, GLuint texture)
{
    //Mantel Zylinder Zeichnen	
    glPushMatrix();
    glRotatef(90,1,0,0);
    Mantel(radius);
    glPopMatrix();
	
    //Deckel Zylinder Zeichnen
    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(90,1,0,0);
    Kreis(radius);
    glPopMatrix();

	//Boden Zylinder Zeichnen
    glPushMatrix();
    glTranslatef(0,-1,0);
    glRotatef(90,1,0,0);
    Kreis(radius);
    glPopMatrix();	
}

