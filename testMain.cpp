//============================================================================
// Name        : testMain.cpp
// Author      : Andreas Schroll
// Version     :
// Copyright   :
// Description :
//============================================================================


#include "datamanager.h"
#include "canChannel.h"
#include "SocketIO.h"
#include "guiChannel.h"



int main() {

	//ch.send(0x124,0x1122334455667788);
	 datamanager dm;

	 canChannel ch("can0", &dm);

	SocketIO so(&dm);

	dm.add_dp(0x200);
	dm.add_dp_chan(0x200,&ch,1);
	//dm.add_dp_chan(0x123,&ch);
	dm.update_val(0x200,0x11223344);
//	dm.send_val(0x123);
	dm.add_dp(0x208);
	dm.add_dp_chan(0x208,&ch,0);


	dm.add_dp(0x308);
	dm.add_dp_chan(0x308,&ch,1);


	dm.add_dp(0x608);

	dm.add_dp_chan(0x608,&ch,1);

	dm.add_dp(410);
	dm.add_dp_chan(410,&ch,1);

	dm.add_dp(1040);
	dm.add_dp_chan(1040,&ch,1);

	dm.add_dp(1032);
	dm.add_dp_chan(1032,&ch,1);

	//dm.add_dp(1544);
	//dm.add_dp_chan(1544,&ch,1);


	//dm.add_dp_chan(0x308,&guich,1);
	//dm.update_val(0x124,0x112233);
//	dm.send_val(0x124);

       // sleep(5);


/*	int i = 0;
 *
	while(1){
		//dm.send_val(0x200);
		sleep(1);
	}
	*/
	while(1){
		//dm.send_val(0x124);
		//dm.send_val(0x123);
		sleep(5);
                
	}
}
