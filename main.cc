#include "heap.h"
#include "data.h"

int main(){
    
    int ret_val;
    heap<data> *my_heap = new heap<data>();
    my_heap->init_heap(50);

    data d; 

    for (int i=0;i<50;i++){
        d.datum = i%17; 
        heap_element<data> *heap_elem = new heap_element<data>(d);
        ret_val = my_heap->insert(heap_elem); 
    }
    my_heap->print_h(3);
    my_heap->remove(3);
    my_heap->print_h(3);
}    
