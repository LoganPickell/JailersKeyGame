#include "Room.h"
#include "Player.h"

Room::Name Room::exitRoom(Room::Direction action)
{
	if (auto hasDoor{
			std::find_if(doorways.begin(),
			doorways.end(),
		[&](std::pair<Room::Direction,Room::Name> doorway)
		{
			return  action == doorway.first;
		}) }; hasDoor != doorways.end())
	{
		std::cout << "You open the door to " << hasDoor->second; //check this
		system("PAUSE");
		return hasDoor->second;
	}
	else 
	{
		action = Direction::none;
		return name;
	}
}

void Room::addDoor(const int& direction,const int& name)
{
	doorways.insert(std::make_pair((Room::Direction)direction, (Room::Name)name));
	return;
}

bool Room::pickupKey()
{
	if (hasKey)
	{
		hasKey = false;
		return true;
	}
	return false;
}

void Room::dropKey()
{
	hasKey = true;
}

bool Room::hasAKey()
{
	return hasKey;
}
void Room::printDoors()
{
	std::for_each(doorways.begin(), doorways.end(), [](const std::pair<const Room::Direction,const Room::Name>& door)
		{
			std::cout << door.first;
		});
}

std::ostream& operator<<(std::ostream& out, Room room)
{
	std::cout << "You are in a dark, dank room with doors to the ";// need to display the doors, but doorways is private.

	room.printDoors();

	std::cout << std::endl;
	if (room.hasAKey())
	{
		std::cout << "        There is a key on the floor.You pick it up." << std::endl;
	}


	return out;
}

std::ostream& operator<<(std::ostream& os, const Room::Direction& direction)
{
	switch (direction)
	{
	case Room::Direction::N:
		os << "N, ";
		break;
	case Room::Direction::S:
		os << "S, ";
		break;
	case Room::Direction::E:
		os << "E, ";
		break;
	case Room::Direction::W:
		os << "W, ";
		break;
	case Room::Direction::none:
		os << "none";
		break;
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, const Room::Name& name)
{
	switch (name)
	{
	case (Room::Name::exit):
		os << "Exit\n";
		break;
	case(Room::Name::cell):
		os << "Cell\n";
		break;
	case(Room::Name::closet):
		os << "Closet\n";
		break;
	case(Room::Name::pantry):
		os << "Pantry\n";
		break;
	case(Room::Name::NW):
		os << "NW\n";
		break;
	case(Room::Name::gate):
		os << "Gate\n";
		break;
	case(Room::Name::NE):
		os << "NE\n";
		break;
	case(Room::Name::E):
		os << "E\n";
		break;
	case(Room::Name::SE):
		os << "SE\n";
		break;
	case(Room::Name::S):
		os << "S\n";
		break;
	case(Room::Name::SW):
		os << "SW\n";
		break;
	case(Room::Name::W):
		os << "W\n";
		break;
	}
	return os;
}
