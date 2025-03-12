CXX = g++
CXXFLAGS = -Iinclude -Wall -O3 --std=c++20 -static

ifeq ($(OS),Windows_NT)
	LDFLAGS = -Llib/win -lraylib -lopengl32 -lgdi32 -lwinmm
	BIN = bin/game.exe
else
	LDFLAGS = -Llib/linux -lraylib -ldl -lglfw3
	BIN = bin/game
endif

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))

all: $(BIN)

$(BIN): $(OBJ) | bin
	$(CXX) $^ -o $@ $(CXXFLAGS) $(LDFLAGS)

obj/%.o: src/%.cpp | obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

obj:
	mkdir -p obj

bin:
	mkdir -p bin

clean:
	rm -rf obj bin
