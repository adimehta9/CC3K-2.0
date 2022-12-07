CXX = g++
CXXFLAGS = -g -std=c++17 -Wall
EXEC = raiinet
OBJECTS = main.o display.o player.o link.o board.o graphics.o boardObjects.o server.o linkBoost.o download.o polarize.o scan.o fireAbil.o incStren.o firewall.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
