#include "heap.h"

int main(){
    
    int ret_val,indent;
    
    heap<int> *my_heap = new heap<int>();
    my_heap->init_heap(50);


    for (int i=0;i<50;i++){
        heap_element<int> *heap_elem = new heap_element<int>(i%17);
        ret_val = my_heap->insert(heap_elem); 
    }
    indent=0; 
    my_heap->print_h();

    my_heap->remove(3);
    my_heap->print_h();
}    
