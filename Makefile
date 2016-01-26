EXEC    = InferniGame
CC      = g++
CFLAGS  = -Wall -Werror
LDFLAGS = -MD -lSDL2
MODULES = Core \
          Util \
          Objects \
		  Loader

SRC := $(foreach ssrc,$(MODULES),$(wildcard $(ssrc)/*.cpp)) main.cpp
OBJ := $(SRC:.cpp=.o)

.PHONY: rebuild clean directories

$(EXEC): loader directories $(OBJ)
	$(CC) -o $@ $(addprefix build/,$(OBJ)) build/Loader/parser.o $(LDFLAGS)

all: $(EXEC)

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c -o build/$@ $<

directories:
	mkdir -p build
	mkdir -p build/Core
	mkdir -p build/Util
	mkdir -p build/Objects

loader:
	mkdir -p build/Loader
	gcc -c -o build/Loader/parser.o Loader/parser.c
	g++ -c -o build/Loader/loader.o Loader/loader.cpp

clean:
	rm -rf build/

rebuild: clean all
