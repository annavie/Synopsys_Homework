# Elevator Control System

This project simulates an elevator control system. The system processes requests to move the elevator up or down, handling both internal and external requests.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Class Overview](#class-overview)
- [UML Diagram](#uml-diagram)
- [Usage](#usage)
- [Installation](#installation)
- [Examples](#examples)
- [Contributing](#contributing)

## Introduction

The Elevator Control System is designed to simulate the operation of an elevator, processing requests from both inside and outside the elevator. It prioritizes requests based on direction and floor number, ensuring efficient operation.

## Features

- Handles up and down requests.
- Prioritizes requests based on direction and floor number.
- Distinguishes between internal and external requests.
- Simulates the elevator moving to requested floors.

## Class Overview

### Elevator

The `Elevator` class represents the elevator itself. It maintains the current floor, direction, and queues for up and down requests.

- **Attributes:**
  - `int m_currFloor`: Current floor of the elevator.
  - `Direction m_direction`: Current direction of the elevator (UP, DOWN, IDLE).
  - `std::priority_queue` for up and down requests (both internal and external).

- **Methods:**
  - `void addUpRequest(std::shared_ptr<Command> com)`: Adds an up request to the appropriate queue.
  - `void addDownRequest(std::shared_ptr<Command> com)`: Adds a down request to the appropriate queue.
  - `void run()`: Processes all requests until the queues are empty.
  - Various getters and setters for current floor and direction.

### Command

The `Command` class is an abstract base class for commands that can be executed by the elevator.

- **Attributes:**
  - `int priority`: Priority of the command.
  - `Location location`: Location of the request (INSIDE_ELEVATOR, OUTSIDE_ELEVATOR).

- **Methods:**
  - `virtual void execute(Elevator& elevator) = 0`: Pure virtual method to execute the command.

### MoveUpCommand and MoveDownCommand

These classes derive from `Command` and represent specific commands to move the elevator up or down.

- **Attributes:**
  - `Request request`: Contains information about the request (current floor, desired floor, direction, location).

- **Methods:**
  - `void execute(Elevator& elevator) override`: Executes the command to move the elevator.

### Request

The `Request` class holds information about a request to move the elevator.

- **Attributes:**
  - `int currentFloor`: The floor where the request originated.
  - `int desiredFloor`: The floor the requester wants to go to.
  - `Direction direction`: The direction of the request.
  - `Location location`: The location of the request (inside or outside the elevator).

## UML Diagram

Below is the UML diagram for the Elevator Control System. It illustrates the relationships between the various classes and their interactions:

![UML Diagram](Elevator/uml.png)

## Usage

1. **Create an Elevator instance:**
   ```cpp
   Elevator elevator(0);
   ```

2. **Create Requests:**
   ```cpp
   Request request1(0, 5, UP, OUTSIDE_ELEVATOR);
   Request request2(5, 1, DOWN, INSIDE_ELEVATOR);
   ```

3. **Create Commands:**
   ```cpp
   std::shared_ptr<Command> moveUpCommand1 = std::make_shared<MoveUpCommand>(request1);
   std::shared_ptr<Command> moveDownCommand2 = std::make_shared<MoveDownCommand>(request2);
   ```

4. **Add Commands to the Elevator:**
   ```cpp
   elevator.addUpRequest(moveUpCommand1);
   elevator.addDownRequest(moveDownCommand2);
   ```

5. **Run the Elevator:**
   ```cpp
   elevator.run();
   ```

## Installation

To compile and run the project:

1. **Clone the repository:**
   ```sh
   git clone https://github.com/yourusername/elevator-system.git
   cd elevator-system
   ```

2. **Compile the project:**
   ```sh
   g++ main.cpp -o elevator
   ```

3. **Run the executable:**
   ```sh
   ./elevator
   ```

## Examples

Here is a complete example of how to use the Elevator Control System:

```cpp
#include "Elevator.h"
#include <memory>

int main() {
    Elevator elevator(0);

    Request request1(0, 5, UP, OUTSIDE_ELEVATOR);
    Request request2(5, 1, DOWN, INSIDE_ELEVATOR);
    Request request3(1, 7, UP, OUTSIDE_ELEVATOR);
    Request request4(2, 4, UP, INSIDE_ELEVATOR);

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
```

## Contributing

Contributions are welcome! Please fork this repository and submit pull requests with your improvements.
```