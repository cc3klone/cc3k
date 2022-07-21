#include "subject.h"
using namespace std;

Subject::Subject() {}
Subject::~Subject() {}

void subject::attach(Observer *o) {
    observers.push_back(o);
}

void Subject::detach(Observer *o) {
    for(auto i = observers.begin(); i != observers.end(); i++) {
        if(*i == o) {
            observers.erase(i);
            break;
        }
    }
}
