all : frsvo_test
frsvo_test : src/main.cpp
	g++ $^ -o $@