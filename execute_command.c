#include "main.h"


void execute_command(const char *comnd)
{
        pid_t childpid = fork();
        int i = 0;
        char *token;
        char **argv;
        int argc = 0;
        if (childpid == -1)
        {
                perror("fork");
                exit(EXIT_FAILURE);
        }
        else if (childpid == 0)
        {
                token = strtok((char *)comnd, " \n");

                while (token)
                {
                        argc++;
                        token = strtok(NULL, " \n");
                }

                argv = malloc(sizeof(char *) * (argc + 1));
                if (argv == NULL)
                {
                        perror("malloc");
                        exit(EXIT_FAILURE);
                }

                token = strtok((char *)comnd, " \n");
                while (token)
                {
                        argv[i] = strdup(token);
                        if (argv[i] == NULL)
                        {
                                perror("strdup");
                                exit(EXIT_FAILURE);
                        }
                        token = strtok(NULL, " \n");
                        i++;
                }
                argv[i] = NULL;

                execve(argv[0], argv, NULL);
                perror("execve");

                exit(EXIT_FAILURE);
        }
        else
        {
                wait(NULL);
        }
}
