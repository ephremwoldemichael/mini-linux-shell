#include <iostream>
#include <string>
#include "headers/parser.hpp"
#include "headers/executor.hpp"
#include "headers/builtins.hpp"

int main() {
    std::string line;
    ShellParser parser;
    Executor exec;

    while (true) {
        std::cout << "mini-shell> ";
        if (!std::getline(std::cin, line) || line == "exit") break;
        auto commands = parser.parse(line);
        if (commands.empty()) continue;
        if (handle_builtin(commands)) continue;
        exec.execute(commands);
    }
    std::cout << "Exiting shell...\n";
    return 0;
}
