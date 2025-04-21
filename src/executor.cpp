#include "executor.hpp"
#include <unistd.h>
#include <sys/wait.h>
#include <vector>
#include <iostream>

void Executor::execute(const std::vector<Command> &commands) {
    int n = commands.size();
    int pipefd[2*n];
    
    for (int i = 0; i < n-1; ++i) {
        if (pipe(pipefd + i*2) < 0) perror("pipe");
    }

    for (int i = 0; i < n; ++i) {
        pid_t pid = fork();
        if (pid == 0) {
            // child
            if (i > 0) dup2(pipefd[(i-1)*2], 0);
            if (i < n-1) dup2(pipefd[i*2 + 1], 1);

            for (int j = 0; j < 2*(n-1); ++j) close(pipefd[j]);

            std::vector<char*> argv;
            for (auto &arg : commands[i].args)
                argv.push_back(const_cast<char*>(arg.c_str()));
            argv.push_back(nullptr);

            execvp(argv[0], argv.data());
            perror("execvp");
            exit(1);
        } else if (pid < 0) {
            perror("fork");
            return;
        }
    }
    for (int i = 0; i < 2*(n-1); ++i) close(pipefd[i]);
    if (!commands.back().background) {
        for (int i = 0; i < n; ++i) wait(nullptr);
    }
}
