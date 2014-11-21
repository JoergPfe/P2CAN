/* 
 * File:   Tankanzeige.h
 * Author: bpse_sose14
 *
 * Created on 24. September 2014, 14:51
 */

#ifndef TANKANZEIGE_H
#define	TANKANZEIGE_H
#include <GL/freeglut.h>
#include "Instrument.h"
#include "WriteText.h"
#include "ITextur.h"
class Tankanzeige {
public:
    Tankanzeige();
    Tankanzeige(const Tankanzeige& orig);
    virtual ~Tankanzeige();
    //Tankinhalt von 0 bis 40
    Tankanzeige(GLfloat tankinhalt, ITextur* textur);
private:

};

#endif	/* TANKANZEIGE_H */

