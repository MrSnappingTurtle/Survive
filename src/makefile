CC = g++
COMPILER_FLAGS = -std=c++11 -pthread
FILES = *.cpp
LINKER_FLAGS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
OBJS = *.o
LINUX_BIN = Survive 

#Compile(output into error.txt if there is an error), link, then run
linux:
	$(CC) $(COMPILER_FLAGS) -c $(FILES) 2> "errors.txt"
	$(CC) $(COMPILER_FLAGS) $(OBJS) -o $(LINUX_BIN) $(LINKER_FLAGS)
	./$(LINUX_BIN)        

linux-debug: 
	$(CC) $(COMPILER_FLAGS) -g -c $(FILES) 2> "errors.txt"
	$(CC) $(COMPILER_FLAGS) $(OBJS) -o $(LINUX_BIN) $(LINKER_FLAGS)
	gdb $(LINUX_BIN)        

