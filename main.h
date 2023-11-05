#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <stddef.h>

void readInput(char *input, int inputSize);
void executeEnv(void);
void executeCommand(char *command);
void runShell(void);

#endif
