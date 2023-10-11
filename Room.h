#ifndef ROOM_H
#define ROOM_H
#include<map>
#include <iostream>
#include <tuple>

class Room
{
public:
	enum class Name { exit = -4, cell, closet, pantry, NW, gate, NE, E, SE, S, SW, W, numHallwayRooms };
	enum class Direction { N, S, E, W, none };

	Room::Name exitRoom(Room::Direction action);
	void addDoor(const int& direction, const int& name);
	bool pickupKey();
	void dropKey();
	void printDoors();
	bool hasAKey();
private:
	Name name{ Name::NW };
	std::map<Direction, Name> doorways;
	bool hasKey{ false };

};

std::ostream& operator<<(std::ostream& out,Room room);
std::ostream& operator<<(std::ostream& os, const Room::Direction& direction);
std::ostream& operator<<(std::ostream& os, const Room::Name& name);
#endif // !ROOM_H