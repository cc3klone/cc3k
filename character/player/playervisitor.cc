#include "playervisitor.h"

void PlayerVisitor::setAtk(int &currentAtk, int addAtk) {
    int tempAtk = currentAtk;
    tempAtk += addAtk;
    if (tempAtk > 0) {
        currentAtk += addAtk;
    }
}

void PlayerVisitor::setDef(int &currentDef, int addDef) {
    int tempDef = currentDef;
    tempDef += addDef;
    if (tempDef > 0) {
        currentDef += addDef;
    }
}

void PlayerVisitor::setHP(int &currentHP, int maxHP, int addHP) {
    int tempHP = currentHP;
    tempHP += addHP;
    if (tempHP > maxHP) {
        currentHP = maxHP;
    } else {
        currentHP += addHP;
    }
}

void PlayerVisitor::setGold(double &currentGold, int addGold) {
    currentGold += addGold;
}

PlayerVisitor::~PlayerVisitor() {}