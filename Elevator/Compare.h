#ifndef COMPARE_H
#define COMPARE_H

#include "Command.h"

struct CompareUp {
    bool operator()(const std::shared_ptr<Command>& a, const std::shared_ptr<Command>& b) const {
        return a->priority > b->priority; 
    }
};

struct CompareDown {
    bool operator()(const std::shared_ptr<Command>& a, const std::shared_ptr<Command>& b) const {
        return a->priority < b->priority;
    }
};

#endif // COMPARE_H
