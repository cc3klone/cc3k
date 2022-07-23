#include "orcvisitor.h"

void OrcVisitor::setGold(double &currentGold, int addGold) {
    currentGold += (addGold + 0.0) / 2;
}