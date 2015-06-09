EXEC    = InferniGame
CC      = g++
LD      = ld
CFLAGS  = -Wall -Werror
LDFLAGS = -llibstd++ -MD -lSDL2
MODULES = Core \
          Util \
          Objects

SRC := $(foreach ssrc,$(MODULES),$(wildcard $(ssrc)/*.cpp)) main.cpp
OBJ := $(SRC:.cpp=.o)

.PHONY: rebuild clean directories game

$(EXEC): directories $(OBJ)
	$(LD) $(LFLAGS) -o $@ $(addprefix build/,$(OBJ))

all: $(EXEC)

%.o: %.cpp %.hpp
	$(CC) $(CFLAGS) -c -o build/$@ $<

directories:
	mkdir -p build
	mkdir -p build/Core
	mkdir -p build/Util
	mkdir -p build/Objects

clean:
	rm -rf build/

rebuild: clean game
