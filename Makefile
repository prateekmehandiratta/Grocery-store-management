all:sample

sample:main.o fruitsclassfunctions.o vegetablesclassfunctions.o itemsclassfunctions.o linkedlistclassfunctions.o
	g++ main.o fruitsclassfunctions.o vegetablesclassfunctions.o itemsclassfunctions.o linkedlistclassfunctions.o -o sample

main.o: main.cpp
	g++ -c main.cpp

fruitsclassfunctions.o: fruitsclassfunctions.cpp
	g++ -c fruitsclassfunctions.cpp

vegetablesclassfunctions.o: vegetablesclassfunctions.cpp
	g++ -c vegetablesclassfunctions.cpp

itemsclassfunctions.o: itemsclassfunctions.cpp
	g++ -c itemsclassfunctions.cpp

linkedlistclassfunctions.o: linkedlistclassfunctions.cpp
	g++ -c linkedlistclassfunctions.cpp

clean:
	rm -f *o sample
