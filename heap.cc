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
#include <math.h>

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
int heap<T>::get_parent(int node_idx){
    return (int)floor((node_idx-1)/2);
}

template <class T>
int heap<T>::get_left_child(int node_idx){
    return (2*node_idx)+1;
}

template <class T>
int heap<T>::get_right_child(int node_idx){
    return (2*node_idx)+2;
}

template <class T>
int heap<T>::insert(heap_element<T> *e){
    
    int ret_val;

    if (curr_size==max_size){
        printf("heap must be resized\n");
        return -1;
    }
    
    elements[curr_size] = e;
    e->node_idx=curr_size;
    curr_size++;
    
    if (curr_size==0){
        return 0;
    }else{
        ret_val = heapify_up(curr_size-1);     
        return ret_val; 
    }
}

template <class T>
int heap<T>::swap(int idx1, int idx2){
    
    heap_element<T> *elem1, *elem2;
    elem1 = elements[idx1];
    elements[idx1] = elements[idx2];
    elements[idx2] = elem1;
    elements[idx1]->node_idx = idx2;
    elements[idx2]->node_idx = idx1;
    return 0; 
}

template <class T>
int heap<T>::heapify_up(int node_idx){
    
    int ret_val, parent; 
    parent = get_parent(node_idx); 

    while (parent!=0 && (*elements[node_idx] < *elements[parent])){
       if (swap(node_idx,parent)==0){
           node_idx = parent;
           parent = get_parent(node_idx); 
       }else{
            printf("swap error\n");
            exit(1);
       }
    }
}

template <class T>
void heap<T>::print(){
    
    //0 depth tree just has the root
    int depth, n_slots;
    depth = (int)floor(log(curr_size)/log(2));
    n_slots = (1<<(depth+1))-1;

    for (int i=0; i<depth+1; i++){
       int step_size = n_slots/((1<<i)+1);
        
       for (int k=0; k<(1<<i);k++){

           printf("%*d",step_size+1,);
       }
       printf("\n");
    }
}


template <class T>
heap<T>::~heap(){
}

int main(){
    

    int ret_val;
    printf("up and running\n");
    
    heap<int> *my_heap = new heap<int>(10);

    //heap_element<int> **heap_elems = new heap_element<int>*[10];  

    for (int i=0;i<10;i++){
        
        heap_element<int> *heap_elem = new heap_element<int>(i%3);
        ret_val = my_heap->insert(heap_elem); 
    }
    my_heap->print();

}

