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
 * test_data
 */
test_data::test_data(int _data){
    data = _data;
}

void test_data::print(){
   printf("%d\n",data); 
}



/*
 * heap_element
 */

heap_element::heap_element(void * _data){
    data = _data;
}

bool test_data::operator<(test_data &other){
    if (data<other.data){
        return true;
    }else{
        return false;
    }

}

heap_element::~heap_element(){

}

bool heap_element::operator<(heap_element &other){
    
    if (data < other.data){
        return true;
    }else{
        return false;
    }
}

/*
 * heap
 */

heap::heap(int heap_size){
    elements = new heap_elements*[heap_size];
    curr_size = 0;
}



int main(){
    
    printf("up and running\n");
    
    heap_element **heap_elems = new heap_element*[10];  

    for (int i=0;i<10;i++){
        
        test_data *d = new test_data(i%3);
        heap_elems[i] = new heap_element(d);
        ((test_data*)heap_elems[i]->data)->print();
    }

}

