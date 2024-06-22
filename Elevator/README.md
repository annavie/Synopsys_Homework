# Elevator Control System

This project simulates an elevator control system. The system processes requests to move the elevator up or down, handling both internal and external requests.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Class Overview](#class-overview)
- [Usage](#usage)
- [Installation](#installation)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

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

## Usage

1. **Create an Elevator instance:**
   ```cpp
   Elevator elevator(0);
