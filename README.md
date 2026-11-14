# Minishell 1

A small Unix shell in C, inspired by tcsh: a prompt, program lookup through the `PATH` (fork/execve/waitpid) and built-in commands `cd`, `env`, `setenv`, `unsetenv` and `exit`.

- **Team:** solo project
- **My part:** everything: the shell loop, running programs through the PATH, built-in commands, and my own printf library.

## Build and run

```sh
make
./mysh
```

Known issue: the shell expects `OLDPWD` to be set in the environment (`OLDPWD=$PWD ./mysh`). The follow-up project [minishell2](https://github.com/HediBannour/minishell2) adds redirections and pipes.

---

School project at Epitech (France). More projects: [hedibannour.com](https://hedibannour.com/#projects)
