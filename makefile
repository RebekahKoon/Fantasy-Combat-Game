## Program name: project3
## Author:       Rebekah Koon
## Date:         7/24/19
## Description:  This program is a fantasy combat game in which the user
##               selects two character to fight. The defense and attack
##               of a character is determined by rolling dice. A character
##               loses if they run out of strength points.

project3: Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o Menu.o validInput.o main.o
	g++ -g Character.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o Menu.o validInput.o main.o -o project3

Character.o: Character.cpp Character.hpp
	g++ -c Character.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -c Vampire.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -c BlueMen.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -c Medusa.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -c HarryPotter.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

validInput.o: validInput.cpp validInput.hpp
	g++ -c validInput.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o project3