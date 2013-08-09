
/* a min heap with the ability to 
 * remove arbitary elements from the 
 * heap
 */

/* 
 * Author       : Peter H Sudmant
 * email        : psudmant [ a t ] gmail [ d o t ] com 
 */

template <class T>
class heap_element{
    
    public:

        T data;     //the actual data element
        unsigned int node_idx;  //this elements node
         
        heap_element(T);
        ~heap_element();
        bool operator<(heap_element &);

        heap_element * get_parent();
        heap_element * get_child();
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
        
        heap(int);
        ~heap();
        int insert(heap_element<T> *);
        int del(heap_element<T> *);
        int del(int);

        void print(int,int); 
        void print_h(); 

        heap_element<T> * get_parent(heap_element<T>*);
        heap_element<T> * get_left_child(heap_element<T>*);
        heap_element<T> * get_right_child(heap_element<T>*);
        
        int get_parent(int);
        int get_left_child(int);
        int get_right_child(int);

};

