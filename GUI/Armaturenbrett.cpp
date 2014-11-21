/* 
 * File:   Armaturenbrett.cpp
 * Author: bpse_sose14
 * 
 * Created on 25. September 2014, 14:47
 */

#include "Armaturenbrett.h"

Armaturenbrett::Armaturenbrett() {
    
}

Armaturenbrett::Armaturenbrett(const Armaturenbrett& orig) {
}

Armaturenbrett::~Armaturenbrett() {
}

Armaturenbrett::Armaturenbrett(GLfloat Verbrauch_Auto, GLfloat kmStand, GLfloat Geschwindigkeit,int blinker, GLfloat Tankanzeige_Auto, ITextur* textur_GEschwindigkeit, ITextur* textur_Tank, ITextur* textur_Verbrauch) {
    glPushMatrix();    
    Tacho(kmStand,Geschwindigkeit,blinker,textur_GEschwindigkeit);
    glPopMatrix();
    glPushMatrix();    
    glTranslatef(13,0,0);
    glScalef(0.6,0.6,1);
    Verbrauch((GLfloat)Verbrauch_Auto, textur_Verbrauch);
    glPopMatrix();
    glPushMatrix();    
    glTranslatef(-13,0,0);
    glScalef(0.6,0.6,1);
    Tankanzeige((GLfloat)Tankanzeige_Auto, textur_Tank);
    glPopMatrix();
}

