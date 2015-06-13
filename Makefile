EXEC    = InferniGame
CC      = g++
CFLAGS  = -Wall -Werror
LDFLAGS = -MD -lSDL2
MODULES = Core \
	Util \
	Objects
 
SRC := $(foreach ssrc,$(MODULES),$(wildcard $(ssrc)/*.cpp)) main.cpp
OBJ := $(SRC:.cpp=.o)
 
.PHONY: rebuild clean directories
 
$(EXEC): directories $(OBJ)
	$(CC) -o $@ $(addprefix build/,$(OBJ)) $(LDFLAGS)
 
all: $(EXEC)
 
%.o: %.cpp %.hpp
	$(CC) -o build/$@ -c $< $(CFLAGS)
 
directories:
	mkdir -p build
	mkdir -p build/Core
	mkdir -p build/Util
	mkdir -p build/Objects
 
clean:
	rm -rf build/
 
rebuild: clean all