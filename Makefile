# Name of the project
PROJ_NAME=Minesweeper

# .c files
CPP_SOURCE=$(wildcard ./src/core/*.cpp)

# main files
MAIN_SOURCE=$(wildcard ./src/*.cpp)

# .h files
H_SOURCE=$(wildcard ./src/core/*.hpp)

# Object files
OBJ=$(subst .cpp,.o,$(subst core,objects,$(CPP_SOURCE))) 

# MAINOBJ=$(subst .cpp,.o,$(MAIN_SOURCE))
# MAINOBJ=$(subst .cpp,.o,$(subst *.cpp,objects/*.cpp,$(MAIN_SOURCE)))
MAINOBJ=$(subst .cpp,.o,$(subst src,src/objects,$(MAIN_SOURCE)))

# Compiler and linker
CC=g++

# Flags for compiler
CC_FLAGS=-c    

# Command used at clean target
RM = rm -rf

#
# Compilation and linking
#
all: objFolder $(PROJ_NAME)


light: $(CPP_SOURCE) $(MAIN_SOURCE)
	@ echo ' '
	@ echo 'Building binary using g++ linker: $(PROJ_NAME)'
	$(CC) $^ -g -o $(PROJ_NAME)
	@ echo 'Finished building binary: $(PROJ_NAME)'
	@ echo ' '

# debug: $(CPP_SOURCE) $(MAIN_SOURCE)
# 	@ echo ' '
# 	@ echo 'Building binary using g++ linker: $(PROJ_NAME)'
# 	$(CC) $^ -g -o $(PROJ_NAME)
# 	@ echo 'Finished building binary: $(PROJ_NAME)'
# 	@ echo ' '

run: 
	@ ./$(PROJ_NAME)


$(PROJ_NAME): $(OBJ) $(MAINOBJ)
	@ echo 'Building binary using g++ linker: $@'
	$(CC) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '

./src/objects/%.o: ./src/core/%.cpp ./src/core/%.hpp
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

./src/objects/main.o: ./src/main.cpp $(H_SOURCE)
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

objFolder:
	@ mkdir -p src/objects

clean:
	@ $(RM) ./src/objects/*.o $(PROJ_NAME) *~
	@ rmdir src/objects

.PHONY: all clean





