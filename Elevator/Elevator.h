#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <queue>
#include <vector>
#include <memory>
#include <iostream>
#include "Command.h"
#include "Request.h"
#include "Compare.h"


class Elevator {
public:
    Elevator(int currFloor);

    void addUpRequest(std::shared_ptr<Command> com);
    void addDownRequest(std::shared_ptr<Command> com);
    void run();
    int getCurrentFloor() const;
    void setCurrentFloor(int floor);
    Direction getDirection() const;
    void setDirection(Direction dir);

private:
    int m_currFloor;
    Direction m_direction;
    using UpQueueType = std::priority_queue<std::shared_ptr<Command>, std::vector<std::shared_ptr<Command>>, CompareUp>;
    using DownQueueType = std::priority_queue<std::shared_ptr<Command>, std::vector<std::shared_ptr<Command>>, CompareDown>;
    UpQueueType upQueue;
    DownQueueType downQueue;
    UpQueueType internalUpQueue;
    DownQueueType internalDownQueue;

    void processRequests();
    void processUpRequest();
    void processDownRequest();
};

#endif // ELEVATOR_H
