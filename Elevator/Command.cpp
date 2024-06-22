#include "Command.h"
#include "Elevator.h"

MoveUpCommand::MoveUpCommand(Request req) : request(req) {
    priority = (req.location == Location::INSIDE_ELEVATOR) ? 1 : req.destFloor;
}

void MoveUpCommand::execute(Elevator& elevator) {
    elevator.setCurrentFloor(request.destFloor);
    std::cout << "Handling up request. Elevator stopped at floor " << request.destFloor << "." << std::endl;
}

int MoveUpCommand::getPriority() const {
    return request.destFloor;
}


MoveDownCommand::MoveDownCommand(Request req) : request(req) {
    priority = (req.location == Location::INSIDE_ELEVATOR) ? 1 : req.destFloor;
}
void MoveDownCommand::execute(Elevator& elevator) {
    elevator.setCurrentFloor(request.destFloor);
    std::cout << "Handling down request. Elevator stopped at floor " << request.destFloor << "." << std::endl;
}

int MoveDownCommand::getPriority() const {
    return request.destFloor;
}