output: main.o List.o Item.o
	g++ main.o List.o Item.o -std=c++11 -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

List.o: List.cpp List.hpp
	g++ -std=c++11 -c List.cpp

Item.o: Item.cpp Item.hpp
	g++ -std=c++11 -c Item.cpp

clean:
	rm *.o output