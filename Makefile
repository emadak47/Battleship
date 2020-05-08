Streamout.o:	Streamout.cpp Streamout.h Node.h
	g++ -c Streamout.cpp 

Game_Setting.o:	Game_Setting.cpp Game_Setting.h
	g++ -c Game_Setting.cpp

LinkedList.o:	LinkedList.cpp LinkedList.h Node.h
	g++ -c LinkedList.cpp

Game_Play.o:	Game_Play.cpp Game_Play.h 
	g++ -c Game_Play.cpp 

Streamin.o:	Streamin.cpp Streamin.h Game_Play.h Players.h ShipDetails.h
	g++ -c Streamin.cpp 

main.o:	main.cpp Game_Setting.h LinkedList.h Streamin.h Streamout.h Node.h Players.h ShipDetails.h
	g++ -c main.cpp

project:	Streamin.o Game_Setting.o Game_Play.o Streamout.o LinkedList.o main.o
	g++ Streamin.o Game_Setting.o Game_Play.o Streamout.o LinkedList.o  main.o -o project

clean:
	rm -f project main.o Streamin.o Streamout.o Game_Play.o LinkedList.o Game_Setting.o main.tgz

tar:
	tar -czvf main.tgz *.cpp *.h

.Phony: clean tar


