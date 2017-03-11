heaps: Main.o Heap.o
	g++ Main.o Heap.o -o heaps
Main.o: Main.cpp Heap.h
	g++ -c Main.cpp
Heap.o: Heap.cpp Heap.h
	g++ -c Heap.cpp
clean: 
	rm -f *.o
remove:
	rm -f * heaps
removeall:
	rm -f *.o
	rm -f heaps
	ls