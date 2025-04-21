#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include "headers/parser.hpp"
#include <vector>

class Executor {
public:
    void execute(const std::vector<Command> &commands);
};

#endif // EXECUTOR_HPP
