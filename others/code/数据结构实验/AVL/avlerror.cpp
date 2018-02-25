#include "avlerror.h"





DeleteInexistentValue::DeleteInexistentValue(int val){
    this->val = val;
}

string DeleteInexistentValue::what() const{
    return string("Inexistent value ")
            +to_string(val)
            +string(" in tree");
}
