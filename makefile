GAME_NAME=RPG_Engine
all:
	g++ src/main.cpp src/State/*.cpp src/SDL/*.cpp `sdl2-config --cflags --libs` -lSDL2 -lSDL2_net -lSDL2_image -lSDL2_ttf -Isrc -Isrc/State -Isrc/SDL -o $(GAME_NAME)
run:
	./$(GAME_NAME)
r:
	./$(GAME_NAME)
clean:
	rm $(GAME_NAME)
c:
	rm $(GAME_NAME)
