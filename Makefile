CXX = g++
CXXFLAGS = -g -std=c++17 -Wall
EXEC = main
OBJECTS = main.o display.o player.o link.o board.o graphics.o boardObjects.o server.o abilities.o linkBoost.o download.o polarize.o scan.o fireAbil.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
