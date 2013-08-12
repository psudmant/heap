#include "data.h"
#include <stdio.h>
#include <stdlib.h>

data::data(int _datum){
    datum = _datum;
}

data::data(){
    datum = 0;
}

bool data::operator<(data &other){
    if (datum <other.datum){
        return true;
    }else{
        return false;
    }
}

data::~data(){
}

void data::getValStr(int width, char * c){
    sprintf(c,"%*.*d",width,width,datum);
}



