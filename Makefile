CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD -g
EXEC = quadris
OBJECTS = main.o block.o blockselector.o board.o cell.o iblock.o jblock.o lblock.o oblock.o sblock.o score.o subject.o tblock.o textdisplay.o upcoming.o zblock.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
