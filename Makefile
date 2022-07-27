CXX=g++
CXXFLAGS=-std=c++14 -Wall -MMD -Werror=vla -fsanitize=address
EXEC=cc3k
OBJECTS=cc3k.o gamecontroller.o rng.o floor/floor.o item/item.o item/gold.o item/potion.o item/compass.o item/barriersuit.o character/character.o character/enemy/enemy.o character/enemy/dragon.o character/enemy/goblin.o character/enemy/phoenix.o character/enemy/troll.o character/enemy/vampire.o character/enemy/werewolf.o character/enemy/merchant.o character/player/player.o character/player/playervisitor.o character/player/orcvisitor.o character/player/humanvisitor.o character/player/elvesvisitor.o character/player/dwarfvisitor.o
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

