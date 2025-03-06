CXX = g++
CXXFLAGS = -Iinclude -Wall -O3 --std=c++20 -static
LDFLAGS = -Llib -lraylib -lopengl32 -lgdi32 -lwinmm 

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))
BIN = bin/game.exe

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
