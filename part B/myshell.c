//Ye'ela Granot 209133107
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_COMMANDS 100

int main(int argc, char* argv[]) {
    char command[MAX_COMMAND_LENGTH];
    char* args[MAX_COMMAND_LENGTH];
    char* commands[MAX_COMMANDS]; // store up to 100 commands
    pid_t pids[MAX_COMMANDS]; // store the PIDs of up to 100 commands
    int num_commands = 0; // keep track of the number of commands entered
    
    // set environment variables from command line arguments
    for (int i = 1; i < argc; i++) {
        char* env_var = malloc(strlen(argv[i]) + strlen(getenv("PATH")) + 2);
        sprintf(env_var, "%s:%s", argv[i], getenv("PATH"));
        setenv("PATH", env_var, 1);
        free(env_var); // free the allocated memory

    }
    while (1) {
        printf("$ "); // display the cursor
	fflush(stdout); //empties the output buffer of the std stream
        fgets(command, MAX_COMMAND_LENGTH, stdin); // read the command from the user

        // remove the newline character from the end of the command
        if (command[strlen(command)-1] == '\n') {
            command[strlen(command)-1] = '\0';
        }
        
		args[0] = strtok(command, " "); // split the command into arguments
            for (int i = 1; i < MAX_COMMAND_LENGTH; i++) {
                args[i] = strtok(NULL, " ");
                if (args[i] == NULL) {
                    break;
                }
            }
		if (strcmp(command, "exit") == 0) { // check if the user entered the exit command
            exit(0);
		}else if (strcmp(command, "history") == 0) { // check if the user entered the history command
			commands[num_commands] = strdup(command);
			pids[num_commands] = getpid(); // store the PID of the current process
			num_commands++;
			// print all the commands in the history
			for (int i = 0; i < num_commands; i++) {
				printf("%d %s\n", pids[i], commands[i]);
			}
        }  
		else if(strcmp(args[0], "cd") == 0){ // check if the command is "cd"
			commands[num_commands] = strdup(command);
			pids[num_commands] = getpid(); // store the PID of the current process
			num_commands++;
			if (args[1] == NULL) {
				if (chdir(getenv("HOME")) == -1) {
                perror("chdir failed");
				}
			} else {
				if (chdir(args[1]) == -1) {
					perror("chdir failed");
				}
			}
		}
		else {
			// add the command to the history
			commands[num_commands] = strdup(command);
            
            
            // execute the command in a separate process
            pid_t pid;
			 if ((pid = fork()) == -1) {
				perror("fork failed");
			}else if (pid == 0) {
                 if (execvp(args[0], args) == -1) {
					perror("execvp failed");
				 }
            } else {
				pids[num_commands] = pid; // store the PID of the current process
				num_commands++;
                if (wait(NULL) == -1) {
					perror("wait failed");
				}
            }
        }
 
        // reset command and args
        memset(command, 0, sizeof(command));
        memset(args, 0, sizeof(args));
    }

    return 0;
}

