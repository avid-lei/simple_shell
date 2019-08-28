# :turtle::turtle::shell: Simple Shell :shell::turtle::turtle:
- - -
### Description
A simple UNIX command interpreter that replicates functionalities of the simple shell (sh). Additional functions are also included. This program was written entirely in C.

### Installation
Clone this repository into your working directory. For best results, files should be compiled with GCC and the following flags: -Wall -Wextra -Werror -pedantic -Wno-format.

### Usage
After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.

#### Interactive Mode
In interactive mode, simply run the program and wait for the prompt to appear. From there, you can type commands freely, exiting with either the "exit" command or ctrl-D.

#### Non-Interactive Mode
In non-interactive mode, echo your desired command and pipe it into the program like this:
```sh
echo "ls" | ./shell
```
In non-interactive mode, the program will exit after finishing your desired command(s).

#### Included Built-Ins
Our shell has support for the following built-in commands:

Command | Definition
--------|---------------
exit [n] | Exit the shell, with an optional exit status, n.
env      | Print the environment.
setenv [var] [value] | Set an environment variable and value. If the variable exists, the value will be updated.
unsetenv [var] | Remove an environment variable.
cd [dir] | Change the directory.

The following built-in commands may be supported in future versions:

Command | Definition
--------|---------------
alias   | Set an Alias.
history | View the history of the shell.


#### Outside Programs
Our shell can run outside programs by typing their absolute paths (/bin/ls) or the executable name (ls), If their directory is included in the PATH.

### Examples

```sh
divalicious$ ls -l
total 76
-rw-rw-r-- 1 vagrant vagrant  2492 Aug 28 02:27 #README.md#
-rw-rw-r-- 1 vagrant vagrant     7 Aug 27 20:51 README.md
-rw-rw-r-- 1 vagrant vagrant  1232 Aug 27 20:39 addnode.c
-rw-rw-r-- 1 vagrant vagrant  1995 Aug 27 20:51 builtin.c
-rw-rw-r-- 1 vagrant vagrant  1004 Aug 27 20:51 builtin2.c
-rw-rw-r-- 1 vagrant vagrant   319 Aug 27 20:39 freelist.c
-rw-rw-r-- 1 vagrant vagrant   800 Aug 27 20:39 getenv.c
-rw-rw-r-- 1 vagrant vagrant  1670 Aug 27 20:39 header.h
-rwxrwxr-x 1 vagrant vagrant 19257 Aug 28 02:28 hsh
-rw-rw-r-- 1 vagrant vagrant   765 Aug 27 20:51 isa.c
-rw-rw-r-- 1 vagrant vagrant   923 Aug 27 20:51 path.c
-rw-rw-r-- 1 vagrant vagrant   262 Aug 27 20:39 printlist.c
-rw-rw-r-- 1 vagrant vagrant  1930 Aug 27 20:51 shell.c
-rw-rw-r-- 1 vagrant vagrant  1310 Aug 27 20:39 strings.c
-rw-rw-r-- 1 vagrant vagrant   670 Aug 27 20:51 strtok.c
```
```sh
divalicious$ /bin/pwd
/home/vagrant/simple_shell
```
```sh
divalicious$ hello world
./hsh: 1: hello: not found
```
```sh
env: env
XDG_SESSION_ID=3
TERM=xterm-256color
SHELL=/bin/bash
SSH_CLIENT=10.0.2.2 56306 22
SSH_TTY=/dev/pts/0
USER=vagrant
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lz=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.axa=00;36:*.oga=00;36:*.spx=00;36:*.xspf=00;36:
MAIL=/var/mail/vagrant
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
PWD=/home/vagrant/simple_shell
LANG=en_US.UTF-8
SHLVL=1
HOME=/home/vagrant
LOGNAME=vagrant
SSH_CONNECTION=10.0.2.2 56306 10.0.2.15 22
LESSOPEN=| /usr/bin/lesspipe %s
XDG_RUNTIME_DIR=/run/user/1000
LESSCLOSE=/usr/bin/lesspipe %s %s
OLDPWD=/home/vagrant
_=./hsh
```
### Included Files

 - _getenv.c - gets the environmental character.
 - _putchar.c - writes the output to the prompt.
 - _which.c - determines which character pointers is going through the struct.
 - adddnode.c - Add a node at the front of a linked list.
 - addnode2.c - Second interation of add functions that need to be used.
 - builtin.c - takes the string arguments and checks them with the env.
 - builtin2.c - second interation of function needed for the builtin functions.
 - freelist.c - frees the list.
 - header.h - handles libraries and prototype.
 - hsh - This will be the compiled file once ran through GCC.
 - int_getn.c - compares the strings in the environment.
 - is_a.c -checks if its a character.
 - path.c - pathchecker and helps with path token.
 - printlist.c - prints the list array.
 - shell.c - function for running the basis shell logic.
 - sighandler.c - hands the signal for inside the main function.
 - strings.c - string implementation multiple functions.
 - strings2.c - second interation of string functions that are in use.
 - strok.c - seperate and create tokens from the string.

### Credits
All code written by [Akeem Seymens](https://github.com/akeemseymens) and [Diva Lei](https://github.com/avid-lei).

