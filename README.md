
# Pipex

Welcome to the **Pipex** project! This project is part of the [42 School](https://www.42.fr/) common core and involves recreating a simple version of the Unix `pipe` function, handling input/output redirection between commands.

## About

The **Pipex** project aims to help students understand how Unix processes work, how to manage file descriptors, and how to use pipes for inter-process communication. In this project, you'll be mimicking the shell behavior for the following command:

```bash
< file1 cmd1 | cmd2 > file2
```

Your program will:
- Read input from `file1`
- Pass it to `cmd1`
- Pipe the output of `cmd1` to `cmd2`
- Write the final output to `file2`

## Features

- Handle basic pipe and redirection (`|`, `<`, `>`)
- Use `pipe()`, `dup2()`, `execve()`, `fork()`, and other system calls
- Error handling for invalid arguments, commands, or files

## Usage

```bash
./pipex file1 cmd1 cmd2 file2
```

Where:
- `file1`: The input file (read only)
- `cmd1`: The first command to execute (takes input from `file1`)
- `cmd2`: The second command to execute (takes input from `cmd1`'s output)
- `file2`: The output file (write only)

The program mimics the behavior of the following shell command:

```bash
< file1 cmd1 | cmd2 > file2
```

### Example

```bash
./pipex infile "grep hello" "wc -l" outfile
```

This command will:
- Open `infile`
- Execute `grep hello` on its content
- Pipe the output of `grep hello` to `wc -l`
- Write the result into `outfile`

## Project Requirements

The project adheres to the following 42 School requirements:
- Handle errors gracefully (invalid commands, files, arguments, etc.)
- Proper management of file descriptors, pipes, and child processes
- Implementing a basic pipeline (`|`) and file redirection (`<`, `>`)

### Bonus Features (Optional):
- Support for multiple pipes (e.g., `cmd1 | cmd2 | cmd3`)
- Handle `<<` (heredoc) and `>>` (append)
