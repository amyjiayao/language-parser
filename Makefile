all: run-main

run-main: Parser.o Evaluator.o Main.o
	c++ -std=c++11 -o run-main Parser.o Evaluator.o Main.o

Main.o: Main.cpp Parser.h Evaluator.h RuntimeException.h
	c++ -std=c++11 -c -g Main.cpp

Evaluator.o: Evaluator.cpp Evaluator.h Parser.h LinkedStack.h LinkedQueue.h TemplateDoublyLinkedList.h RuntimeException.h
	c++ -std=c++11 -c -g Evaluator.cpp

Parser.o: Parser.cpp Parser.h LinkedStack.h LinkedQueue.h TemplateDoublyLinkedList.h RuntimeException.h
	c++ -std=c++11 -c -g Parser.cpp

clean:
	rm *.o run-main
