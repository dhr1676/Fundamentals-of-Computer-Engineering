//
// Created by DING on 2018/3/10.
//

#include "Object.h"

bool Object::Equals(Object *object) {
    return !Compare(object) && !object->Compare(this);
}

unsigned int Object::Hash() {
    return 0;
}

unsigned int Object::Hash_openadd(int hashTimes) {
    return 0;
}