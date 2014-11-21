/* 
 * File:   Instrument.h
 * Author: bpse_sose14
 *
 * Created on 24. September 2014, 14:29
 */

#ifndef INSTRUMENT_H
#define	INSTRUMENT_H
#include "Triangle.h"
#include "ITextur.h"
#include "Zylinder.h"
#include "Zylinder_mit_Deckel.h"
#include <GL/freeglut.h>

class Instrument {
public:
    Instrument();
    Instrument(const Instrument& orig);
    virtual ~Instrument();
    Instrument(GLfloat rotation, ITextur* textur);
private:

};

#endif	/* INSTRUMENT_H */

