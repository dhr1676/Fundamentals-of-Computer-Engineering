# Created by DING on 2018/2/21.

Compiler := g++

RM = rm -f
 
CompilerFLAGS = -O3 

debug: CompilerFLAGS += -DDEBUG -g -std=c++11
debug: all

# The build target executable:
TARGET = main

all: build

build: $(TARGET)

$(TARGET): *.cc
	$(Compiler) $(CompilerFLAGS) $^ -o $@ 
    
run: $(TARGET)
	./$(TARGET) 
    
clean:
	$(RM) $(TARGET) *.o *.tar* *.core* *.err *.out
