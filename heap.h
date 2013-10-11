/* a min heap with the ability to 
 * remove arbitary elements from the 
 * heap
 */

/* 
 * Author       : Peter H Sudmant
 * email        : psudmant [ a t ] gmail [ d o t ] com 
 */

#ifndef HEAP_H 
#define HEAP_H

template <class T>
class heap_element{
    
    public:

        heap_element(T);
        heap_element();
        ~heap_element();
        
        T data;     //the actual data element
        unsigned int node_idx;  //this elements node
         
        bool operator<(heap_element<T> &);

};

template <class T>
class heap{
    
    private:
        heap_element<T> **elements;
        
        int heapify_up(int);
        int heapify_down(int);
        int swap(int, int);
        
        int get_min_child(int);

        int curr_size;
        int max_size;
        
    public:
        
        heap();
        //heap(const heap<T> &);
        heap(int);
        void init_heap(int);
        ~heap();
        
        int insert(heap_element<T> *);
        int remove(heap_element<T> *);
        int remove(int);

        void print_v(int, int, int); 
        void print_h(int); 

        T peek_element(int); 

        heap_element<T> * get_parent(heap_element<T>*);
        heap_element<T> * get_left_child(heap_element<T>*);
        heap_element<T> * get_right_child(heap_element<T>*);
        
        heap_element<T> * get_element(int); 

        int get_parent(int);
        int get_left_child(int);
        int get_right_child(int);
        int heap_integrity();

};

#endif
