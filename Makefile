LIB=opencc
all: cccvt
.PHONY: cccvt clean

cccvt: cccvt.cpp
		$(CXX) -o $@ $^ -l$(LIB)

clean: 
		rm -rf cccvt