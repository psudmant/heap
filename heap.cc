/* a min heap with the ability to 
 * remove arbitary elements from the 
 * heap
 */

/* 
 * Author       : Peter H Sudmant
 * email        : psudmant [ a t ] gmail [ d o t ] com 
 */

#include  "heap.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * heap_element
 */

template <class T>
heap_element<T>::heap_element(T _data){
    data = _data;
}

template <class T>
bool heap_element<T>::operator<(heap_element &other){
    if (data<other.data){
        return true;
    }else{
        return false;
    }
}

template <class T>
heap_element<T>::~heap_element(){
}

/*
 * heap
 */

template <class T>
heap<T>::heap(int heap_size){
    
    elements = new heap_element<T>*[heap_size];
    curr_size = 0;
    max_size = heap_size;
}

template <class T>
heap<T>::push(heap_element<T> *e){
    
    if (curr_size==max_size){
        printf("heap must be resized\n");
        return;
    }
    
    elements[curr_size] = e;
    curr_size++;
}

template <class T>
heap<T>::~heap(){
}

int main(){
    
    printf("up and running\n");
    
    heap<int> *my_heap = new heap<int>(10);

    //heap_element<int> **heap_elems = new heap_element<int>*[10];  

    for (int i=0;i<10;i++){
        
        heap_element<int> *heap_elem = new heap_element<int>(i%3);
        my_heap->push(heap_elem); 

    }

}

