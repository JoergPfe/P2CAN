/* 
 * File:   Tacho.h
 * Author: bpse_sose14
 *
 * Created on 25. September 2014, 11:04
 */

#ifndef TACHO_H
#define	TACHO_H
#include <GL/freeglut.h>
#include "Instrument.h"
#include "WriteText.h"
#include "ITextur.h"
#include <math.h>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
class Tacho {
public:
    Tacho();
    Tacho(const Tacho& orig);
    virtual ~Tacho();
    Tacho(GLfloat kmStand, GLfloat Geschwindigkeit, int blinker, ITextur* textur);
private:

};

#endif	/* TACHO_H */

