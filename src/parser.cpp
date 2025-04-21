#include "headers/parser.hpp"
#include <sstream>

std::vector<Command> ShellParser::parse(const std::string &line) {
    std::vector<Command> result;
    std::istringstream iss(line);
    Command cmd;
    std::string token;

    while (iss >> token) {
        if (token == "&") {
            cmd.background = true;
            continue;
        }
        if (token == "|") {
            result.push_back(cmd);
            cmd = Command();
        } else {
            cmd.args.push_back(token);
        }
    }
    if (!cmd.args.empty()) result.push_back(cmd);
    return result;
}
