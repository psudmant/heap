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


test_data::test_data(int _data){
    data = _data;
}

void test_data::print(){
   printf("%d\n",data); 
}

heap_element::heap_element(void * _data){
    data = _data;
}

heap_element::~heap_element(){

}

bool heap_element::operator<(heap_element *other_elem){
    
    if (data < other_elem->data){
        return true;
    }else{
        return false;
    }
}


int main(){
    
    printf("up and running\n");
    
    for (int i=0;i<10;i++){
        test_data *d = new test_data(i);
        d->print();
    }

}

