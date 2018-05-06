//
// Created by DING on 2018/2/23.
//

#include "Person.h"

Person::Person(std::string first, std::string last, int age, std::string email)
        : first(first), last(last) {
    this->age = age;
    this->email = email;
}

void Person::Print() {
    std::cout << "Name: " << first.s << ' ' << last.s << '\n';
    std::cout << "Age: " << age << '\n';
    std::cout << "Email: " << email << '\n';
}

bool Person::Compare(Object *object) {
// Function not used, doesn't matter
    return false;
}