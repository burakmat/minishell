
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

### Built-in Commands

Minishell includes a number of built-in commands that allow you to interact with the shell and the operating system.
#### echo

The echo command prints a message to the terminal. It takes a single argument, which can be a string or a variable.

echo message

#### cd

The cd command changes the current working directory. It takes a single argument specifying the new directory to change to.

cd directory

#### exit

The exit command terminates minishell.

exit

#### export

The export command adds an environment variable to the shell. It takes a single argument in the form name=value.

export name=value

#### unset

The unset command deletes an environment variable from the shell. It takes a single argument specifying the name of the variable to delete.

unset name

#### env

The env command displays all of the current environment variables. It takes no arguments.

env

#### pwd

The pwd command prints the current working directory. It takes no arguments.

pwd


# License

MIT
