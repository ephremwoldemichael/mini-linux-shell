#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

struct Command {
    std::vector<std::string> args;
    bool background = false;
};

class ShellParser {
public:
    std::vector<Command> parse(const std::string &line);
};

#endif // PARSER_HPP
