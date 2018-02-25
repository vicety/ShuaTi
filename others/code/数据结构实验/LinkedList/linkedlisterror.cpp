#include "linkedlisterror.h"
#include<iostream>
#include<string>
using namespace std;

IndexOutOfRange::IndexOutOfRange(int validLen, int index){
    this->validlen = validLen;
    this->index = index;
}

string IndexOutOfRange::what(){
    return string("Index out of range(list length ")
            +to_string(validlen)
            +string(", access index ")
            +to_string(index)
            +string(")");
}
