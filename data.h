class data { 
    
    public:

        data(int);
        data();
        ~data();  
        bool operator<(data &);
        int datum;
        void getValStr(int, char *);
};


