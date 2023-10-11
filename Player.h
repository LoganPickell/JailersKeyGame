#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"
#include "Room.h"

class Player:public Object
{
public:
	void update(std::map<Room::Name, Room>& dungeonMap) override;
	int getHealth();

private:
	void changeGameState(std::map<Room::Name, Room>& dungeonMap, const Room::Direction& action); 
	void displayIllegalMove(Room::Direction action);
	Room::Direction getAction();

	int health{ 10 };
	bool hasKey{ false };
};

#endif // !PLAYER_H