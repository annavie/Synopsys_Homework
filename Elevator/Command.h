#ifndef COMMAND_H
#define COMMAND_H

#include "Request.h"
#include<iostream>
class Elevator;

class Command {
public:
    int priority;
    Location location;
    virtual void execute(Elevator& elevator) = 0;
    virtual ~Command() = default;
};

class MoveUpCommand : public Command {
    Request request;
public:
    MoveUpCommand(Request req);
    void execute(Elevator& elevator) override;
    int getPriority() const;
};

class MoveDownCommand : public Command {
    Request request;
public:
    MoveDownCommand(Request req);
    void execute(Elevator& elevator) override;
    int getPriority() const;
};

#endif // COMMAND_H
