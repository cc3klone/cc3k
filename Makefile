CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla -fsanitize=address
EXEC = cc3k
OBJECTS = main.o character/character.o item/item.o item/gold.o item/potion.o item/compass.o item/barriersuit.o 
DEPENDS = ${OBJECTS: .o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
