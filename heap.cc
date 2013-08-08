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
    return (2*node_idx)+1 < curr_size ? (2*node_idx)+1 : -1;
}

template <class T>
int heap<T>::get_right_child(int node_idx){
    return (2*node_idx)+2 < curr_size ? (2*node_idx)+2 : -1;
}

template <class T>
heap_element<T>* heap<T>::get_right_child(heap_element<T> * elem){
    return elements[get_right_child(elem->node_idx)];
}

template <class T>
heap_element<T>* heap<T>::get_parent(heap_element<T> * elem){
    return elements[get_parent(elem->node_idx)];
}

template <class T>
heap_element<T>* heap<T>::get_left_child(heap_element<T> * elem){
    return elements[get_left_child(elem->node_idx)];
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
    
    elements[idx1]->node_idx = idx1;
    elements[idx2]->node_idx = idx2;
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
int heap<T>::del(heap_element<T> *elem){
    return del(elem->node_idx);
}


template <class T>
int heap<T>::del(int idx){
    
    int ret_val;

    if (idx>=curr_size){
        printf("element not in heap\n");
        return -1;
    }
    
    if (curr_size==0){
        return 0;
    }else{
        curr_size--;
        elements[idx] = elements[curr_size];
        if ((idx == 0) || !( *elements[idx] < *elements[get_parent(idx)] ) ){
            ret_val = heapify_down(idx);
        } else {
            ret_val = heapify_up(idx);
        }
        return ret_val; 
    }
}

template <class T>
int heap<T>::get_min_child(int node_idx){

    int left_child, right_child; 
    
    left_child = get_left_child(node_idx); 
    right_child = get_right_child(node_idx); 
    
    if (left_child == -1){
        return -1;
    } else if (right_child == -1) {
        return left_child;
    } else {
        return *elements[left_child] < *elements[right_child] ? left_child : right_child;  
    }
}

template <class T>
int heap<T>::heapify_down(int node_idx){
    
    int min_child;
    min_child = get_min_child(node_idx);
    
    while (min_child != -1 && *elements[min_child] < *elements[node_idx]){
       if (swap(min_child,node_idx)==0){
           node_idx = min_child;
           min_child = get_min_child(node_idx); 
       }else{
            printf("swap error\n");
            exit(1);
       }
    }
    return 0;
}


/*
template <class T>
void heap<T>::print(){
    
    //0 depth tree just has the root
    int depth, 
        n_slots,
        curr_idx,
        step_size,
        elements_on_level;
    
    char str = ' ';
    depth = (int)floor(log(curr_size)/log(2));
    n_slots = ((1<<(depth+1))-1)*2;
    
    for (int i=0; i<depth+1; i++){
       step_size = n_slots/((1<<i)+1);
       
       elements_on_level= (1<<(i+1)) < curr_size ? 1<<i : curr_size-((1<<i)-1); 
       for (int k=0; k<elements_on_level;k++){
           curr_idx=((1<<i)-1)+k;
           printf("%*d",step_size,elements[curr_idx]->data);
           //printf("%*d",step_size+1,curr_idx);
       }
       printf("\n");
    }
}
*/

template <class T>
void heap<T>::print(int idx, int indent){
    if (get_right_child(idx)!=-1){
        print(get_right_child(idx),indent+1);
    }

    printf("%*d-%d\n",indent*4,elements[idx]->data,elements[idx]->node_idx);
    
    if (get_left_child(idx)!=-1){
        print(get_left_child(idx),indent+1);
    }
}

template <class T>
heap<T>::~heap(){
}

int main(){
    
    int ret_val,indent;
    
    heap<int> *my_heap = new heap<int>(30);

    //heap_element<int> **heap_elems = new heap_element<int>*[10];  

    for (int i=0;i<30;i++){
        heap_element<int> *heap_elem = new heap_element<int>(i%7);
        ret_val = my_heap->insert(heap_elem); 
    }
    indent=0; 
    my_heap->print(0,indent);

    my_heap->del(3);
    printf("----------------\n");
    my_heap->print(0,indent);
    
    my_heap->del(22);
    printf("----------------\n");
    my_heap->print(0,indent);

}

