ARG = -Wall -MD
CC = g++
COREOBJ = .Obj/display_manager.o .Obj/game.o .Obj/game_state.o .Obj/global.o .Obj/intro_state.o .Obj/menu_state.o .Obj/play_state.o
UTILOBJ = .Obj/fps_counter.o .Obj/image_func.o
OBJECTOBJ = .Obj/collision_object.o .Obj/creature.o .Obj/movable_object.o .Obj/wall.o
MAINOBJ = .Obj/main.o
OBJ = $(COREOBJ) $(MAINOBJ) $(UTILOBJ) $(OBJECTOBJ)

rebuild: clean jeu

.Obj/%.o: Core/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -lSDL2

.Obj/%.o: Util/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -lSDL2

.Obj/%.o: Objects/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -lSDL2

.Obj/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -lSDL2


jeu: $(OBJ)
	$(CC) $(ARG) $(OBJ) -o programme -lSDL2

clean:
	rm -rf Obj/*.o programme
