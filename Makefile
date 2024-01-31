CXX := g++
CXXFLAGS := -std=c++17 -Wall -O3
OBJDIR := obj

EXE := dungeon.out

all: dirs dungeon
.PHONY: clean all dirs

dirs:
	if [ ! -d "$(OBJDIR)" ]; then mkdir "$(OBJDIR)"; fi

dungeon: main.cpp $(OBJDIR)/Dungeon.o $(OBJDIR)/Monster.o $(OBJDIR)/NPC.o $(OBJDIR)/Player.o $(OBJDIR)/Record.o $(OBJDIR)/Room.o $(OBJDIR)/Item.o $(OBJDIR)/GameCharacter.o $(OBJDIR)/Object.o
	$(CXX) $^ -o $(EXE) $(CXXFLAGS)

$(OBJDIR)/Dungeon.o: Dungeon.cpp $(OBJDIR)/Monster.o $(OBJDIR)/NPC.o $(OBJDIR)/Player.o $(OBJDIR)/Record.o $(OBJDIR)/Room.o $(OBJDIR)/Object.o
	$(CXX) $< -c -o $@ $(CXXFLAGS)

$(OBJDIR)/Monster.o: Monster.cpp $(OBJDIR)/GameCharacter.o $(OBJDIR)/Player.o
	$(CXX) $< -c -o $@ $(CXXFLAGS)

$(OBJDIR)/Player.o: Player.cpp $(OBJDIR)/Room.o $(OBJDIR)/Item.o
	$(CXX) $< -c -o $@ $(CXXFLAGS)

$(OBJDIR)/Record.o: Record.cpp $(OBJDIR)/Item.o $(OBJDIR)/Monster.o $(OBJDIR)/NPC.o $(OBJDIR)/Player.o
	$(CXX) $< -c -o $@ $(CXXFLAGS)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $< -c -o $@ $(CXXFLAGS)

clean:
	/bin/rm -rf $(OBJDIR) $(EXE)