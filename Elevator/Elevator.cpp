#include "Elevator.h"

Elevator::Elevator(int currFloor) : m_currFloor(currFloor), m_direction(Direction::IDLE) {}

void Elevator::addUpRequest(std::shared_ptr<Command> com) {
    if (com->location  == Location::INSIDE_ELEVATOR) {
        internalUpQueue.push(com);
    } else {
        upQueue.push(com);
    }
}

void Elevator::addDownRequest(std::shared_ptr<Command> com) {
    if (com->location  == Location::INSIDE_ELEVATOR) {
        internalDownQueue.push(com);
    } else {
        downQueue.push(com);
    }
}


void Elevator::run() {
    while (!internalUpQueue.empty() || !internalDownQueue.empty() || !upQueue.empty() || !downQueue.empty()) {
        processRequests();
    }
    
    if (m_direction == Direction::IDLE) {
        std::cout << "Elevator is idle. No pending requests." << std::endl;
    } else {
        std::cout << "Elevator is now idle. All requests processed." << std::endl;
    }
    
    m_direction = Direction::IDLE;
}

int Elevator::getCurrentFloor() const {
    return m_currFloor;
}

void Elevator::setCurrentFloor(int floor) {
    m_currFloor = floor;
}

Direction Elevator::getDirection() const {
    return m_direction;
}

void Elevator::setDirection(Direction dir) {
    m_direction = dir;
}

void Elevator::processRequests() {
    if (m_direction == Direction::UP || m_direction == Direction::IDLE) {
        processUpRequest();
        processDownRequest();
    } else {
        processDownRequest();
        processUpRequest();
    }
}
void Elevator::processUpRequest() {
    while (!internalUpQueue.empty()) {
        auto command = internalUpQueue.top();
        internalUpQueue.pop();
        command->execute(*this);
    }
    while (!upQueue.empty()) {
        auto command = upQueue.top();
        upQueue.pop();
        command->execute(*this);
    }
    m_direction = (internalDownQueue.empty() && downQueue.empty()) ? Direction::IDLE : Direction::DOWN;
}


void Elevator::processDownRequest() {
    while (!internalDownQueue.empty()) {
        auto command = internalDownQueue.top();
        internalDownQueue.pop();
        command->execute(*this);
    }
    while (!downQueue.empty()) {
        auto command = downQueue.top();
        downQueue.pop();
        command->execute(*this);
    }
    m_direction = (internalUpQueue.empty() && upQueue.empty()) ? Direction::IDLE : Direction::UP;
}


