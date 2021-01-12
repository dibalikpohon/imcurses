COMPILER_CXX = g++
APP_NAME = vimcurses

all: language main
	$(COMPILER_CXX) -g language.o main.o -o $(APP_NAME)

language: language.cpp language.hpp
	$(COMPILER_CXX) -g -c language.cpp -o language.o

main: main.cpp
	$(COMPILER_CXX) -g -c main.cpp -o main.o
