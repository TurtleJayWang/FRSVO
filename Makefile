INCLUDE = 
LIB_FLAGS = 

all : frsvo_main
debug : frsvo_debug

frsvo_main : src/main.cpp
	g++ $^ -o $@

frsvo_debug : src/debug.cpp
	g++ $^ -o $@ $(INCLUDE) $(LIB_FLAGS)
