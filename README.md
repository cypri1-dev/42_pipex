##
<h1><img src="https://github.com/ayogun/42-project-badges/blob/main/covers/cover-pipex-bonus.png?raw=true"</h1>

## Description
The `pipex` program takes four arguments:
- `infile`: the input file to be read and piped into the first command.
- `cmd1`: the first command to be executed.
- `cmd2`: the second command to be executed.
- `outfile`: the output file where the result of the pipeline will be written.

The program executes the command pipeline `cmd1 | cmd2` and redirects the input and output accordingly, similar to the behavior of the shell command `|` (pipe).

## Projects Components Table
This is an overview of the main components located in the "sources" directory of the 42_pipex project.

| File/Header File       | Description                                                                           |
|------------------------|---------------------------------------------------------------------------------------|
| `libft`                | A directory containing the Libft library, used for auxiliary functions required for the implementation of pipex.                               |
| `Makefile`             | The Makefile script for automating project compilation. It includes rules for compiling pipex and additional rules for project management.   |
| `sources/pipex.c`              | The main file containing the pipex function, responsible for executing the command pipeline and file redirection.                              |
| `sources/utils.c`      | Contains utility functions used by the pipex program for tasks such as string manipulation and error handling.                               |
| `sources/pipex.h`      | The header file containing function prototypes and macro declarations necessary for using the pipex program.                               |

## Usage
To use the `pipex` program, compile it using the provided Makefile. Then, run the program with the required arguments:
```bash
./pipex infile "cmd1" "cmd2" outfile
```
## Features
42_pipex offers the following features:

- **Command Pipeline Simulation:** Executes the command pipeline `cmd1 | cmd2` to simulate the behavior of shell pipes.

- **File Redirection:** Redirects input and output files as specified by the user to facilitate the execution of the command pipeline.

- **Error Handling:** Properly handles errors and returns appropriate exit codes in case of failure.
