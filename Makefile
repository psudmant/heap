ALL: heap

heap: data.o data_heap.o heap.o main.o 
	g++ $^ -o $@  
	rm *.o

clean:
	rm *.o
