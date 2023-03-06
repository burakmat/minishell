
# minishell

Minishell is a simple Unix shell written in C. It provides a command-line interface for the user to interact with the operating system.
Features:

1. Execute commands and programs
1. Support for command line arguments
1. Support for input/output redirection
1. Support for pipes
1. Basic built-in commands (e.g. cd, exit)

<img src="https://github.com/burakmat/minishell/blob/master/imgs/demo.png" alt="demo" width="50%" />

## Building and Running

Minishell can be built and run on any system with a C compiler.

To build minishell, clone the repository and run make:
```
git clone https://github.com/burakmat/minishell.git
cd minishell
make
```
This will create an executable minishell in the current directory. To run minishell, simply execute the file:
```
./minishell
```
## Usage

Minishell supports a variety of commands, including both external programs and built-in commands.

### Built-in Commands

Minishell includes a number of built-in commands that allow you to interact with the shell and the operating system.
#### ECHO

The echo command prints a message to the terminal. It takes a single argument, which can be a string or a variable.
```
echo message
```
#### CD

The cd command changes the current working directory. It takes a single argument specifying the new directory to change to.
```
cd directory
```
#### EXIT

The exit command terminates minishell.

```
exit
```
#### EXPORT

The export command adds an environment variable to the shell. It takes a single argument in the form name=value.

```
export name=value
```
#### UNSET

The unset command deletes an environment variable from the shell. It takes a single argument specifying the name of the variable to delete.
```
unset name
```
#### ENV

The env command displays all of the current environment variables. It takes no arguments.
```
env
```
#### PWD

The pwd command prints the current working directory. It takes no arguments.
```
pwd
```
### Other Commands

In addition to the built-in commands, minishell also allows you to execute external programs that are located in directories listed in your PATH environment variable.

The PATH variable is a list of directories that the shell searches for executables when you run a command. When you type a command into minishell, it will search through each directory listed in PATH in order, looking for an executable file with the same name as the command you entered.

For example, if your PATH variable is set to /usr/bin:/usr/local/bin, and you run the command ls, minishell will first search for an executable named ls in /usr/bin, and then in /usr/local/bin. If it finds the executable in one of these directories, it will run it. If it doesn't find the executable in either directory, it will return an error.

You can view the current value of your PATH variable by running the env command. To add a directory to your PATH, you can use the export command to set the PATH variable. For example:
```
export PATH=$PATH:/path/to/directory
```
This will add /path/to/directory to the end of the current PATH variable.

Keep in mind that the directories listed in PATH are only searched when you run a command by itself, without specifying the full path to the executable. If you want to run an executable from a specific directory, you can specify the full path to the executable. For example:
```
/path/to/executable
```
## Contributor

I devoloped this project with [Osman Selim Yalçın](https://github.com/osman-selim-yalcin)

## License

minishell is licensed under the [MIT](https://github.com/burakmat/minishell/blob/master/LICENSE) License.
