ARG = -Wall -MD
CC = g++
COREOBJ = Core/display_manager.o Core/game.o Core/game_state.o Core/global.o Core/intro_state.o Core/menu_state.o Core/play_state.o
UTILOBJ = Util/fps_counter.o Util/image_func.o
OBJECTOBJ = Objects/collision_object.o Objects/creature.o Objects/movable_object.o Objects/wall.o
MAINOBJ = main.o
OBJ = $(COREOBJ) $(MAINOBJ) $(UTILOBJ) $(OBJECTOBJ)

rebuild: clean jeu

Core/%.o: Core/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -lSDL2

Util/%.o: Util/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -lSDL2

Object/%.o: Object/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -lSDL2

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -lSDL2


jeu: $(OBJ)
	$(CC) $(ARG) $(OBJ) -o programme -lSDL2

clean:
	rm -rf Core/*.o Util/*.o Object/*.o *.o *.c~ programme
