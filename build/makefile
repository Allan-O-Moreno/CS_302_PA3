CC = g++
CXXFLAGS = -g -Wall -std=c++11
O_FILES = main.o LinkedSortedList.o SL_PriorityQueue.o

INCLUDES = -I../include

# BUILD RULES
all: $(O_FILES)
	$(CC) $(CXXFLAGS) -o main $(O_FILES) #$(LIBS)

main.o: ../src/main.cpp
	$(CC) $(CXXFLAGS) -c ../src/main.cpp -o main.o $(INCLUDES)

LinkedSortedList.o: ../src/LinkedSortedList.cpp
	$(CC) $(CXXFLAGS) -c ../src/LinkedSortedList.cpp -o LinkedSortedList.o $(INCLUDES)

SL_PriorityQueue.o: ../src/SL_PriorityQueue.cpp
	$(CC) $(CXXFLAGS) -c ../src/SL_PriorityQueue.cpp -o SL_PriorityQueue.o $(INCLUDES)

clean:
	-@if rm *.o main 2>/dev/null || true; then echo "Main Removed"; else echo "No Main"; fi
