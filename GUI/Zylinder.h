/* 
 * File:   Zylinder.h
 * Author: bpse_sose14
 *
 * Created on 24. September 2014, 12:50
 */

#ifndef ZYLINDER_H
#define	ZYLINDER_H
#include <GL/freeglut.h>
#include <math.h>

class Zylinder {
public:
    Zylinder();
    Zylinder(const Zylinder& orig);
    virtual ~Zylinder();
    Zylinder(GLfloat size, GLuint texture);
private:

};

#endif	/* ZYLINDER_H */

