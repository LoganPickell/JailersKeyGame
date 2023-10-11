#include "Object.h"

Room::Name Object::getCurrentRoom()
{
	return currentRoom;
}

std::random_device Object::seed{};
std::default_random_engine Object::engine{ Object::seed() };