#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "subject.h"

class Observer {
    Subject *subject;

    public:
        Observer(Subject *);
        ~Observer();
        void onNotify(Subject *);
};

#endif

