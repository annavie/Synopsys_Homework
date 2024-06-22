#include "Request.h"

Request::Request(int currFloor, int destFloor, Direction dir, Location loc)
    : currFloor(currFloor), destFloor(destFloor), direction(dir), location(loc) {}

