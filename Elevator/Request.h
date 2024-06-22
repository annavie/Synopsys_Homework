#ifndef REQUEST_H
#define REQUEST_H

enum class Direction {
    UP,
    DOWN,
    IDLE
};

enum class Location {
    INSIDE_ELEVATOR,
    OUTSIDE_ELEVATOR
};

class Request {
public:
    int currFloor;
    int destFloor;
    Direction direction;
    Location location;

    Request(int currFloor, int destFloor, Direction dir, Location loc);
};

#endif // REQUEST_H
