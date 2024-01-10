<h1 align ="center">0x16. C - Simple Shell</h1><br>
<p align="center">
  <img width="240" height="250" src="https://automatedprogrammer.sh/wp-content/uploads/2018/05/Linux-Shell.png">
</p>

------------


This repository comprises the necessary files for simulating a fundamental Unix Shell along with its associated commands. Utilizing the POSIX API, it replicates numerous functionalities found in the initial Ken Thompson's Shell. The project is tailored for the completion of the 0x16. C - Simple Shell project at ALX SE.


This uncomplicated shell serves as a C programming language-based shell interface. It presents the user with a prompt '#cisfun$.' Upon accepting user input, it proceeds to execute the provided command within a distinct process referred to as the child process.

## This shell includes the following functionalities:
----------

* It displays a prompt and waits for the user to type in a command. The command line always end with a new line.
* The prompt is displayed again each time a command has been executed, or when terminated by a built-in command 'exit' and returns the status 0.
* The program can be stop when the user uses *Ctrl + D* (end of file).
* The shell handles the command lines with arguments and pathways.
* The program quits when the user imputs ^C (Ctrl + C).
* The program executes most common shel commands as *ls*, *pwd*, *rm*, *cp*, *mv*, *exit*, ... with arguments.
* If an executable cannot be found, it prints an error message and displays the prompt again.

## Process table
----------

1. First, the parent process is created when the user run the program.
2. Then, the program waits for an input from the user.
3. When the user types a command, *getline()* function reads an entire line from stream and *strtok()* is used with a *" "* delimiter to create array of strings.
4. Array is passed for thorough check by *stat()* function to verify if a valid command was passed, if *stat()* fails an error message is printed and the prompt displays again.
5. If *stat()* did not fail and valid commands were passed, array will be passed to *execve()* to execute commands.
6. frees all allocated memory areas.
7. Finally, the program returns to main process: prints the prompts, and waits for another user input.

## Requirements:

* Operating System: [Ubuntu 14.04 LTS](http://releases.ubuntu.com/14.04/)

* Compiler: [GCC 4.8.4](https://gcc.gnu.org/gcc-4.8/)

## General
- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded

## Basic beggining

To run this shell with its respective commands its necessary to clone this reposotory in your terminal. Do it like this:
- HTTPS:

```c
git clone https://github.com/Lex9jar/simple_shell.git
```

- SSH:

```
git clone git@github.com:Lex9jar/simple_shell.git
```
## Compiling, Debugging and Runing
- All of your and our programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall`, `-Werror`, `-Wextra`, `-pedantic` and `-std=gnu89`

- To **compile** your functions use: `

```
gcc -Wall -Wextra -Werror -pedantic -Wno-format -g *.c -o hsh
```
- If you want to **debugging** the shell, use valgrind:
```
valgrind --leak-check=full ./hsh
```
- Or just **run** and try this shell using:
```
./hsh
```

## Examples

Here are shown some examples of the usage of the Shell:

- ls
```shell
\#cisfun$ ls
0-string_utils.c  cmd                      hsh             out
1-string_utils.c  cmd.sh                   i               shell.c
2-getenv.c        execute_command.c        memory_utils.c  shell.h
built_in.c        general_purpose_utils.c  modifiers.c     test_ls_2
```
```shell
/#cisfun$ /bin/ls
0-string_utils.c  cmd                      hsh             out
1-string_utils.c  cmd.sh                   i               shell.c
2-getenv.c        execute_command.c        memory_utils.c  shell.h
built_in.c        general_purpose_utils.c  modifiers.c     test_ls_2
```

```shell
\#cisfun$ ls -lat
total 92
drwxr-xr-x 2 lex lex  4096 Jan 10 08:38 .
-rw-r--r-- 1 lex lex  2881 Jan 10 08:38 modifiers.c
-rwxr-xr-x 1 lex lex 21864 Jan 10 00:57 hsh
-rw-r--r-- 1 lex lex  1704 Jan 10 00:51 execute_command.c
-rw-r--r-- 1 lex lex   713 Jan 10 00:51 shell.c
-rw-r--r-- 1 lex lex  1489 Jan 10 00:48 shell.h
-rw-r--r-- 1 lex lex   111 Jan 10 00:24 built_in.c
-rw-r--r-- 1 lex lex   357 Jan 10 00:17 general_purpose_utils.c
-rwxr--r-- 1 lex lex    37 Jan  9 23:11 cmd.sh
-rw-r--r-- 1 lex lex   604 Jan  9 23:11 i
-rw-r--r-- 1 lex lex   812 Jan  9 23:11 memory_utils.c
-rw-r--r-- 1 lex lex  1544 Jan  9 23:11 out
-rw-r--r-- 1 lex lex    16 Jan  9 23:11 test_ls_2
-rw-r--r-- 1 lex lex  1234 Jan  9 23:11 0-string_utils.c
-rw-r--r-- 1 lex lex  1727 Jan  9 23:11 1-string_utils.c
-rw-r--r-- 1 lex lex   467 Jan  9 23:11 2-getenv.c
-rw-r--r-- 1 lex lex     8 Jan  9 23:11 cmd
drwxr-xr-x 7 lex lex  4096 Jan  9 23:10 ..
```
- pwd

```shell
\#cisfun$ pwd
/home/lex/ALX_SCHOOL/shell/4-task
```

- echo
```shell
\#cisfun$ echo hello world
hello world
```

- *Ctrl + D* and *Ctrl + C*

```shell
#cisfun$ ^C

 lex on AlexanderEdim at …/4-task
```
