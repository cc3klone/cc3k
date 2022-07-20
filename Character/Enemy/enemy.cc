#include "enemy.h"
#include <random>

Direction Enemy::generateDirection() { //requires a vector of directions in floor
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::uniform_int_distribution<size_t> dis(0, v.size() - 1);
	Direction randomDirection = v[dis(rng)]; //v is the name of the vector, should be replaced later
    return randomDirection;
}

void Enemy::attack(AttackType attackType, Character *target) { //need to be implemented
    if (didNotMiss) {
        attack(attackType, target);
    } else {
        //do nothing because missed
    }
}

void Enemy::move(Direction direction) {
    Direction randomDirection = generateDirection;
    move(randomDirection);
}
