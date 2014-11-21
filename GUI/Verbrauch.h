/* 
 * File:   Verbrauch.h
 * Author: bpse_sose14
 *
 * Created on 25. September 2014, 14:22
 */

#ifndef VERBRAUCH_H
#define	VERBRAUCH_H

#include <GL/freeglut.h>
#include "Instrument.h"
#include "WriteText.h"
#include "ITextur.h"

class Verbrauch {
public:
    Verbrauch();
    Verbrauch(const Verbrauch& orig);
    virtual ~Verbrauch();
    Verbrauch(GLfloat verbrauch,  ITextur* textur);
private:

};

#endif	/* VERBRAUCH_H */

