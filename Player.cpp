#include "Player.h"

void Player::update(std::map<Room::Name, Room>& dungeonMap)
{
	std::cout << dungeonMap[currentRoom];
	std::cout << "Health: " << health << std::endl;
	std::cout << "Equip:  ";
	if (hasKey) {
		std::cout << "1 jailer's key";
	}
	std::cout << std::endl;

	Room::Direction action{ getAction() };
	changeGameState(dungeonMap, action);
}

void Player::changeGameState(std::map<Room::Name, Room>& dungeonMap, const Room::Direction& action)
{
	//pick up the key if it is in this room.
	if (dungeonMap.at(getCurrentRoom()).pickupKey())
	{
		hasKey = true;
	}
	//if we are trying to go to the exit, but we don't have the key, it is illegal.
	if (getCurrentRoom() == Room::Name::gate && !hasKey && action == Room::Direction::E)
	{
		displayIllegalMove(action);
	}

 	currentRoom = dungeonMap.at(currentRoom).exitRoom(action); 

		if (action == Room::Direction::none)
	{
		displayIllegalMove(action);
	}
		
		health--;
}

void Player::displayIllegalMove(Room::Direction action)
{
	system("CLS");

	if (currentRoom == Room::Name::gate && !hasKey && action == Room::Direction::E)
	{
		std::cout << "The door is locked. \n Perhaps if you had a key???" << std::endl;
	}
	else
	{
		std::cout << "You wait patiently for the guard to move on." << std::endl;
	}
	std::cout << std::endl;

	system("PAUSE");
}

Room::Direction Player::getAction()
{
	char action;
	std::cout << std::endl;
	std::cout << "Select action: ";
	std::cin >> action;
	switch (action)
	{
	case 'w':
		return Room::Direction::N;
		break;
	case 'a':
		return Room::Direction::W;
		break;
	case 'd':
		return Room::Direction::E;
		break;
	case 's':
		return Room::Direction::S;
		break;
	default:
		return Room::Direction::none;
		break;
	}
}

int Player::getHealth()
{
	return health;
}
