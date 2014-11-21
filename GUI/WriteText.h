/* 
 * File:   WriteText.h
 * Author: bpse_sose14
 *
 * Created on 24. September 2014, 16:23
 */

#ifndef WRITETEXT_H
#define	WRITETEXT_H
#include <string>
#include <GL/freeglut.h>
class WriteText {
public:
    WriteText();
    WriteText(const WriteText& orig);
    virtual ~WriteText();
    WriteText(const char* Text);
    WriteText(std::string Text);
    
private:

};

#endif	/* WRITETEXT_H */

