
/* a min heap with the ability to 
 * remove arbitary elements from the 
 * heap
 */

/* 
 * Author       : Peter H Sudmant
 * email        : psudmant [ a t ] gmail [ d o t ] com 
 */

class test_data{
    
    public:
        int data;
        test_data(int);
        ~test_data();
        bool operator<(test_data &);
        void print();
};


class heap_element{
    
    public:

        void *data;     //a pointer to the actual data element
        unsigned int node_idx;  //this elements node
         
        heap_element(void *);
        ~heap_element();
        bool operator<(heap_element &);

        heap_element * get_parent();
        heap_element * get_child();
};

class heap{
    
    private:
         heap_element **elements;
         int curr_size;
    public:
        
        heap(int);
        ~heap();
        int push(heap_element *);
        int pop(heap_element *);
        int pop(int);
        heap_element * get_parent(int);
        heap_element * get_child(int);

};

