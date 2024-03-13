# Bash Script Repository

## Part One: GCC Find Bash Script

### Introduction
The `gccfind.sh` Bash script is designed to search for specific words within C files in a directory\directories of a spesific path and compile them into executable files. This script provides a convenient way to locate and compile C files containing certain keywords.

### How to Use
To use the `gccfind.sh` script, follow these steps:
1. Clone the repository containing the script to your local machine.
4. Run the script using the following command format:
   ```
   ./gccfind.sh <directory_path> <word_to_find> [-r]
   ```
   - `<directory_path>`: Path to the directory or the name of the directory in the current location.
   - `<word_to_find>`: The word you want to search for in the C files.
   - `[-r]`: (Optional) Flag for recursive traversal if you want to search in subdirectories.

### Examples
Here are some examples of how to use the `gccfind.sh` script:
- To search for the word "helloWorld" in the directory 'MyDir':
  ```
  ./gccfind.sh ./MyDir helloWorld
  ```

- To search for the word "function" recursively in a directory named "MyDir/src":
  ```
  ./gccfind.sh ./MyDir/src function -r
  ```

The gccfind.sh script simplifies the process of locating and compiling C files containing specific keywords, providing a convenient solution for software developers. It emphasizes modularity, error handling, efficiency, readability, safety, and flexibility to ensure a robust and versatile tool. 

## part two: Shell Implementation

### Introduction
This part includes `myshell.c` program, a shell implementation written in C. The shell provides a user-friendly interface for executing Linux built-in commands and offers additional functionality.

### How to Run
To compile and run the shell program, follow these steps:
1. Clone the repository to your local machine.
2. Compile the program using the following command:
   ```
   gcc myshell.c
   ```
4. Run the compiled program by executing -  Example with no arguments:
   ```
   ./a.out
   ```
   Example with arguments as environment variables:
   ```
   ./a.out /root/MyDir/src/my_command
   ```

### How to Use
The shell program presents a prompt symbol `$` on the screen, indicating that it is ready to accept commands. Users can input any standard Linux command, such as `ls`, `cat`, or `sleep`, followed by any necessary arguments.

#### Special Features:
- **Built-in Commands:** All standard built-in commands of the shell are executed using child process. However, there are three special commands that are implemented directly by the main process:
  - `exit`: Terminates the shell program.
  - `cd`: Changes the current directory.
  - `history`: Displays a list of all commands entered during the program's execution, along with their corresponding process IDs (PIDs) which executed them.
- **Foreground Execution:** All commands are executed in the foreground, ensuring that the parent process waits for the child process to complete before accepting the next command.
- **Environment Variables:** Users can define environment variables and use them in the shell program as regular commands. These variables affect the shell's behavior during runtime.

### Examples
![image](https://github.com/yeela8g/shell-implementation/assets/118124478/0a27da78-bcd1-4b31-9954-84fd455db32a) ![image](https://github.com/yeela8g/shell-implementation/assets/118124478/d393bf90-d8f1-452a-99e5-d714e470f507)



![image](https://github.com/yeela8g/shell-implementation/assets/118124478/de95ea81-71cd-4492-9d0e-f215b2ff1fae)






This shell implementation prioritizes robust error handling, modular code organization, and efficient command execution. Error reporting ensures transparency during system calls, while modular code enhances readability and maintainability. Command execution in separate processes maximizes performance. The shell offers an intuitive user experience with built-in commands as well as support for defining and using environment variables and provides a reliable, efficient, and user-friendly environment for executing Linux commands.
