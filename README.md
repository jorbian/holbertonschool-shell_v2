# holbertonschool-shell_v2

This is an abortive attempt at a re-implementation of the Unix shell. It is only in a semi-functional state and DOES NOT support piping and re-directs like it was supposed to. It does, however, handle single commands fairly well...

## How to use shell_v2
You must first compile all the source files using the provided makefile.

Then run the executable (shown on the first line of the example) to get into the custom shell:
```
$./hsh
($)_ /* You can type commands here */
```
After you have entered into the hsh prompt you can enter commands such as ls to make a list of files and display them:
```
($) ls
Hello_World.c README.md simple_shell.h hsh etc...
($) 
($) echo chicken nuggets
chicken nuggets
($) 
```
## Description

#### Syntax
```
($)[program/command name] [options] [argumemts]
```
When you run the `simple_shell` / `hsh` is run, a command line is written just as any other line interpreter.
`hsh` will attempt to execute the program name (searching into the PATH environment variable) with the given arguments specified by [options] you give it. There is a 100* character limit per line, including the new line character. All tab characters that are found should be ignored/removed in the code.
>*this could be wrong

## Links

https://github.com/jorbian/holbertonschool-simple_shell
> you should already be here if you are viewing this
