/* 
 * File:   Dreieck.h
 * Author: bpse_sose14
 *
 * Created on 24. September 2014, 13:38
 */

#ifndef DREIECK_H
#define	DREIECK_H

#include <GL/freeglut.h>

class Triangle {
public:
    Triangle();
    Triangle(const Triangle& orig);
    virtual ~Triangle();
    Triangle(GLfloat radius,GLfloat dicke);
private:

};

#endif	/* DREIECK_H */

