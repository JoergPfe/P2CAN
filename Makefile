include /usr/src/yocto/poky-danny-8.0/build/tmp/environment.mk

CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11 -D_GLIBCXX_USE_NANOSLEEP

OBJS =		testMain.o guiChannel.o data.o DeadlineTimer.o canChannel.o datamanager.o SocketIO.o CalcCanFrame.o 

LIBS =		-lpthread 

TARGET =	dataserver

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)