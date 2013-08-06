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
}

template <class T>
heap<T>::~heap(){
}

int main(){
    
    printf("up and running\n");
    
    heap_element<int> **heap_elems = new heap_element<int>*[10];  

    for (int i=0;i<10;i++){
        
        heap_elems[i] = new heap_element<int>(i%3);
        if (i>0){
            int e1 = heap_elems[i]->data;
            int e2 = heap_elems[i-1]->data;

            if (*heap_elems[i]<*heap_elems[i-1]){
                printf("\t %d is < %d\n",e1,e2);
            }else{
                printf("\t %d !< %d\n",e1,e2);
            }
        } 
    }

}

