#include "observer.h"
using namespace std;

Observer::Observer(Subject *s): subject{s} {
    s.attatch(&this);
}

Observer::~Observer() {
    s.detach(&this);
}
