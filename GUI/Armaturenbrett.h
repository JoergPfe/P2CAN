/* 
 * File:   Armaturenbrett.h
 * Author: bpse_sose14
 *
 * Created on 25. September 2014, 14:47
 */

#ifndef ARMATURENBRETT_H
#define	ARMATURENBRETT_H

#include "Verbrauch.h"
#include "Tankanzeige.h"
#include "Tacho.h"

class Armaturenbrett {
public:
    Armaturenbrett();
    Armaturenbrett(const Armaturenbrett& orig);
    virtual ~Armaturenbrett();    
    Armaturenbrett(GLfloat Verbrauch_Auto, GLfloat kmStand, GLfloat Geschwindigkeit,int blinker, GLfloat Tankanzeige_Auto, ITextur* textur_GEschwindigkeit, ITextur* textur_Tank, ITextur* textur_Verbrauch);
    
private:

};

#endif	/* ARMATURENBRETT_H */

