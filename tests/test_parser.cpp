#include "../src/headers/parser.hpp"
#include <cassert>

int main() {
    ShellParser p;
    auto cmds = p.parse("echo hello world");
    assert(cmds.size() == 1);
    assert(cmds[0].args[0] == "echo");
    assert(cmds[0].args[1] == "hello");
    assert(cmds[0].args[2] == "world");
    return 0;
}
