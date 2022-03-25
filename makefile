CXX = g++
CXXFLAGS = -std=c++20 -Wall -MMD -g
EXEC = usu
OBJECTS = Messages.o Exception.o main.o DFA.o Lexer.o Expressions.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
