LIB=opencc
CXXFLAGS=-std=c++11

all: cccvt
.PHONY: cccvt clean

cccvt: cccvt.cpp
		$(CXX) -o $@ $^ -l$(LIB) $(CXXFLAGS)

clean: 
		rm -rf cccvt