CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall -o2
DEBUG = -g
OBJECTS = hashTable.o wordPuzzle.o timer.o 

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "The Hash Table is Compiled."

hashTable.o: hashTable.h hashTable.cpp
wordPuzzle.o: hashTable.h wordPuzzle.cpp
timer.o: timer.h timer.cpp

.PHONEY: clean
clean: 
	-rm -f *.o a.out