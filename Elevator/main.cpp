#include "Elevator.h"
#include "Request.h"
#include"Command.h"
#include <memory>
#include <iostream>

int main() {
    Elevator elevator(0);

    Request request1(0, 5, Direction::UP, Location::OUTSIDE_ELEVATOR);
    Request request2(5, 1, Direction::DOWN, Location::INSIDE_ELEVATOR);
    Request request3(1, 7, Direction::UP, Location::OUTSIDE_ELEVATOR);
    Request request4(2, 4, Direction::UP, Location::INSIDE_ELEVATOR);

    std::shared_ptr<Command> moveUpCommand1 = std::make_shared<MoveUpCommand>(request1);
    std::shared_ptr<Command> moveDownCommand2 = std::make_shared<MoveDownCommand>(request2);
    std::shared_ptr<Command> moveUpCommand3 = std::make_shared<MoveUpCommand>(request3);
    std::shared_ptr<Command> moveUpCommand4 = std::make_shared<MoveUpCommand>(request4);

    elevator.addUpRequest(moveUpCommand1);
    elevator.addDownRequest(moveDownCommand2);
    elevator.addUpRequest(moveUpCommand3);
    elevator.addUpRequest(moveUpCommand4);

    elevator.run();

    return 0;
}
