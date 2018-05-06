//
// Created by DING on 2018/2/23.
//

#include <iostream>
#include "String.h"

String::String(std::string s) {
    this->s = s;
}

void String::Print() {
    std::cout << s << '\n';
}

bool String::Compare(Object *object) {
    return s < dynamic_cast<String *>(object)->s;
}

unsigned int String::Hash() {
    unsigned int i;
    unsigned int c;
    unsigned int hash;
    unsigned int prime;

    hash = 5381;
    prime = 16777619;
//    std::cout << "Hashing: " << s << std::endl;
    for (i = 0; i < s.length(); i++) {
        // c stores the ascii code of input string type s
        c = s[i];
//        std::cout << "c: " << c << std::endl;
        hash = (hash ^ c) * prime;
    }
//    std::cout << "After hash is: " << hash << std::endl;
    return hash;
}

unsigned int String::Hash_openadd(int hashTimes) {
    unsigned int i;
    unsigned int c;
    unsigned int hash;
    unsigned int prime;

    hash = 5381;
    prime = 16777619;
//    std::cout << "Hashing: " << s << std::endl;
    for (i = 0; i < s.length(); i++) {
        // c stores the ascii code of input string type s
        c = s[i];
//        std::cout << "c: " << c << std::endl;
        hash = (hash ^ c) * prime;
    }
    hash = hash + hashTimes;
//    std::cout << "After hash is: " << hash << std::endl;
    return hash;
}