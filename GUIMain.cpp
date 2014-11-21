//============================================================================
// Name        : testMain.cpp
// Author      : Andreas Schroll
// Version     :
// Copyright   :
// Description :
//============================================================================


#include "datamanager.h"
#include "canChannel.h"
#include "LoggingChannel.h"
#include "GUI/guiChannel.h"
#include "DeadlineTimer.h"
#include "pthread.h"
#include "LoggingChannel.h"
//
//// ++ GUI ++
//#include <iostream>
//#include <math.h>
//#include <GL/glut.h>
//
//#include "/home/bpse_sose14/NetBeansProjects/CppApplication_1/Zylinder.h"
//#include "/home/bpse_sose14/NetBeansProjects/CppApplication_1/Triangle.h"
//#include "/home/bpse_sose14/NetBeansProjects/CppApplication_1/Tankanzeige.h"
//#include "/home/bpse_sose14/NetBeansProjects/CppApplication_1/Tacho.h"
//#include "/home/bpse_sose14/NetBeansProjects/CppApplication_1/Verbrauch.h"
//#include "/home/bpse_sose14/NetBeansProjects/CppApplication_1/Armaturenbrett.h"
////--GUI --

//int run(int argc, char** argv);

int main() {




    datamanager dm;
    guiChannel guich;

    canChannel ch("can0", &dm);

    dm.add_dp(0x200);
    dm.add_dp(776);
    dm.add_dp(1544);
    dm.add_dp(410);
    dm.add_dp(1040);
    dm.add_dp(1032);

    dm.add_dp_chan(0x200, &guich, 50);
    dm.add_dp_chan(0x308, &guich, 50);
    dm.add_dp_chan(0x608, &guich, 50);
    dm.add_dp_chan(0x200, &ch, 1); //0 = nur empfangen 

    while (1) {
        dm.update_val(0x200, 0x3485839);
        sleep(1);
    }
    //    dm.add_dp_chan(0x123, &ch, 50);
    //    dm.update_val(0x123, 0x11223344);
    //    dm.send_val(0x123);
    //    dm.add_dp(0x124);
    //    dm.add_dp_chan(0x124, &ch, 50);
    //    dm.add_dp_chan(0x124, &guich, 50);
    //    dm.update_val(0x200, 0x20000000);
    //    dm.send_val(0x200);
    //--        dt.stop();

}
