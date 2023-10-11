#ifndef OBJECT_H
#define OBJECT_H
#include<random>
#include "Room.h"

class Object
{
public:
	static std::random_device seed;
	static std::default_random_engine engine;
	
	virtual void update(std::map<Room::Name, Room>& dungeonMap) = 0;
	virtual Room::Name getCurrentRoom();
protected:
	Room::Name currentRoom{ Room::Name::cell };
};
#endif // !OBJECT_H
