#ifndef GUARD_H
#define GUARD_H
#include "Object.h"

class Guard: public Object
{
public:
	Guard();
	void update(std::map<Room::Name, Room>& dungeonMap) override;

private:
	bool clockwise{ true };
};

#endif // !GUARD_H