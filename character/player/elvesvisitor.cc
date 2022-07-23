#include "elvesvisitor.h"

void ElvesVisitor::setAtk(int &currentAtk, int addAtk) {
    currentAtk += abs(addAtk);
}

void ElvesVisitor::setDef(int &currentDef, int addDef) {
    currentDef += abs(addDef);
}

void ElvesVisitor::setHP(int &currentHP, int maxHP, int addHP) {
    int tempHP = currentHP;
    tempHP += addHP;
    if (tempHP > maxHP) {
        currentHP = maxHP;
    } else {
        currentHP += abs(addHP);
    }
}