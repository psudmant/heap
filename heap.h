
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
         int curr_size;
    public:
        
        heap(int);
        ~heap();
        int push(heap_element<T> *);
        int pop(heap_element<T> *);
        int pop(int);
        heap_element<T> * get_parent(int);
        heap_element<T> * get_child(int);

};

