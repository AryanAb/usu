CXX = g++
CXXFLAGS = -std=c++20 -Wall -MMD -g
EXEC = usu
OBJECTS = main.o DFA.o Lexer.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lncurses

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
