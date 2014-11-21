/* 
 * File:   Dreieck.cpp
 * Author: bpse_sose14
 * 
 * Created on 24. September 2014, 13:38
 */

#include "Triangle.h"

Triangle::Triangle() {
}

Triangle::Triangle(const Triangle& orig) {
}

Triangle::~Triangle() {
}

Triangle::Triangle(GLfloat size,GLfloat dicke)
{    
    GLfloat tiefePunkte = dicke/2;
    glBegin(GL_TRIANGLES);
    //rechtes Dreieck
    glVertex3f(size,0,-tiefePunkte);
    //linker Punkt
    glVertex3f(-size,0,-tiefePunkte);
    //oberer Punkt
    glVertex3f(0,size,-tiefePunkte);
    glEnd();
    glBegin(GL_TRIANGLES);
    //linkes Dreieck
    glVertex3f(size,0,tiefePunkte);
    //linker Punkt
    glVertex3f(-size,0,tiefePunkte);
    //oberer Punkt
    glVertex3f(0,size,tiefePunkte);
    glEnd();
    
    //Mantel Dreieck
    glBegin(GL_QUADS);    
    glVertex3f(-size,0,-tiefePunkte);   
    glVertex3f(0,size,-tiefePunkte);
    glVertex3f(0,size,tiefePunkte);
    glVertex3f(-size,0,tiefePunkte);
    glEnd();
    
    glBegin(GL_QUADS);    
    glVertex3f(size,0,-tiefePunkte);   
    glVertex3f(0,size,-tiefePunkte);
    glVertex3f(0,size,tiefePunkte);
    glVertex3f(size,0,tiefePunkte);
    glEnd();
    
}