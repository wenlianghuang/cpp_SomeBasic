CC:=g++
CXXFLAGS=-g -m64 -O2 -Wall -std=c++14

.PHONY:	Basic clean clear
src=$(wildcard ./src/*.cxx)
directory=$(notdir $(src))
obj := $(patsubst %.cxx,%.o,$(directory))

all	:	Basic

Basic	:	$(obj)
	$(CC) $^ -o $@
main.o	:	./src/main.cxx ./inc/TemplateClass.h
	$(CC) -c $(CXXFLAGS) $< -o $@


clean:	clear

clear:
	rm -rf *.o
