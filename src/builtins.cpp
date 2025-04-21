#include "builtins.hpp"
#include <iostream>
#include <unistd.h>

bool handle_builtin(const std::vector<Command> &cmds) {
    if (cmds.empty()) return false;
    const auto &args = cmds[0].args;
    if (args[0] == "cd") {
        if (args.size() > 1) chdir(args[1].c_str());
        return true;
    }
    if (args[0] == "help") {
        std::cout << "Built-in commands: cd, exit, help\n";
        return true;
    }
    return false;
}
