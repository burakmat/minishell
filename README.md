
# minishell

Minishell is a simple Unix shell written in C. It provides a command-line interface for the user to interact with the operating system.
Features

    Execute commands and programs
    Support for command line arguments
    Support for input/output redirection
    Support for pipes
    Basic built-in commands (e.g. cd, exit)

## Building and Running

Minishell can be built and run on any system with a C compiler.

To build minishell, clone the repository and run make:

git clone https://github.com/burakmat/minishell.git
cd minishell
make

This will create an executable minishell in the current directory. To run minishell, simply execute the file:

./minishell

## Usage

Minishell supports a variety of commands, including both external programs and built-in commands.

To run an external program, simply type the program name followed by any necessary arguments. For example, to run the ls command to list the files in the current directory:

ls

To run a built-in command, type the command name followed by any necessary arguments. For example, to change the current working directory:

cd /path/to/directory

Minishell also supports input/output redirection and pipes. For example, to redirect the output of the ls command to a file:

ls > output.txt

To pipe the output of one command to another command, use the | symbol:

ls | grep "pattern"

To exit minishell, use the exit command:

exit

# License

MIT
