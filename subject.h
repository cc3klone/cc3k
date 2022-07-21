#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "observer.h"

class Subject {
    std::vector<Observer *> observers;

    public:
        Subject();
        void attatch(Observer *);
        void detatch(Observer *);
        void notifyObservers();
        virtual ~Subject() = default;
};

#endif

