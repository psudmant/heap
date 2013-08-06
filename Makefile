ALL: heap

heap: heap.o 
	g++ $^ -o $@  
	rm *.o
