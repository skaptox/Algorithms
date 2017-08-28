
TARGET = test
SRCS = main.cpp

CXX = clang++
CXXFLAGS= -std=c++11

OBJS = $(SRCS:.cpp=.o)

execute: makeclean resetconsole all
	./$(TARGET).exe

makeclean:
	make clean

resetconsole:
	reset

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o  $(TARGET).exe

$(OBJS):$(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -c -g

clean:
	rm -fr *.o *.exe *.out



