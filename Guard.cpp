#include "Guard.h"
#include<random>

Guard::Guard()
{
	std::uniform_int_distribution<int> randomRoom(0, 8);
	currentRoom = (Room::Name)randomRoom(engine);

	std::bernoulli_distribution clockwisevsCounter(.5);
	if (!clockwisevsCounter(engine))
	{
		clockwise = false;
	}
}


void Guard::update(std::map<Room::Name, Room>& dungeonMap)
{
	if (clockwise)
	{
		Room::Name nextRoom{abs((int)currentRoom+1) % (int)Room::Name::numHallwayRooms};
		currentRoom = nextRoom;
	}
	else 
	{
		Room::Name nextRoom{ abs((int)currentRoom-1) % (int)Room::Name::numHallwayRooms };
		currentRoom = nextRoom;
	}
}
