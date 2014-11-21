/* 
 * File:   WriteText.cpp
 * Author: bpse_sose14
 * 
 * Created on 24. September 2014, 16:23
 */

#include <string>

#include "WriteText.h"
WriteText::WriteText(std::string Text)
{  
    glPushMatrix ();
    glRotatef(180,0,1,0);
    for(int i = 0;i < Text.size();i++)
    {                        
        glutStrokeCharacter (GLUT_STROKE_ROMAN, Text.at(i));            
    }        
    glPopMatrix();
}


WriteText::WriteText() {
}

WriteText::WriteText(const WriteText& orig) {
}

WriteText::~WriteText() {
}

WriteText::WriteText(const char *Text)
{  
    while(*Text)
    {        
        glPushMatrix ();        
        glRotatef(180,0,1,0);
        while (*Text)
        {
            glutStrokeCharacter (GLUT_STROKE_ROMAN, *Text);
            Text ++;
        }
    glPopMatrix();
    }     
}


    
    
    
      


