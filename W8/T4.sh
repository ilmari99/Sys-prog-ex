#!/bin/bash

echo 'Printing cmd args and env variables'
for i; do
	echo $i
done
printenv


: '
./T4.sh -a 1 -b 2 -c 3
Printing cmd args and env variables
-a
1
-b
2
-c
3
SHELL=/bin/bash
SESSION_MANAGER=local/ilmari99:@/tmp/.ICE-unix/1488,unix/ilmari99:/tmp/.ICE-unix/1488
QT_ACCESSIBILITY=1
COLORTERM=truecolor
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
NVM_INC=/home/ilmari/.nvm/versions/node/v12.22.12/include/node
XDG_MENU_PREFIX=gnome-
TERM_PROGRAM_VERSION=1.72.0
GNOME_DESKTOP_SESSION_ID=this-is-deprecated
LC_ADDRESS=fi_FI.UTF-8
GNOME_SHELL_SESSION_MODE=ubuntu
LC_NAME=fi_FI.UTF-8
SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
XMODIFIERS=@im=ibus
DESKTOP_SESSION=ubuntu
LC_MONETARY=fi_FI.UTF-8
SSH_AGENT_PID=1452
BAMF_DESKTOP_FILE_HINT=/var/lib/snapd/desktop/applications/code_code.desktop
GTK_MODULES=gail:atk-bridge
PWD=/home/ilmari/python/systeemiohjelmointi/W8
GSETTINGS_SCHEMA_DIR=/snap/code/109/usr/share/glib-2.0/schemas
LOGNAME=ilmari
XDG_SESSION_DESKTOP=ubuntu
XDG_SESSION_TYPE=x11
GPG_AGENT_INFO=/run/user/1000/gnupg/S.gpg-agent:0:1
XAUTHORITY=/run/user/1000/gdm/Xauthority
VSCODE_GIT_ASKPASS_NODE=/snap/code/109/usr/share/code/code
GJS_DEBUG_TOPICS=JS ERROR;JS LOG
WINDOWPATH=2
HOME=/home/ilmari
USERNAME=ilmari
IM_CONFIG_PHASE=1
LANG=en_US.UTF-8
LC_PAPER=fi_FI.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
XDG_CURRENT_DESKTOP=Unity
GIT_ASKPASS=/snap/code/109/usr/share/code/resources/app/extensions/git/dist/askpass.sh
INVOCATION_ID=671b918d871d41d7aad6a1dc34bcced8
MANAGERPID=1140
CHROME_DESKTOP=code-url-handler.desktop
GJS_DEBUG_OUTPUT=stderr
NVM_DIR=/home/ilmari/.nvm
VSCODE_GIT_ASKPASS_EXTRA_ARGS=--ms-enable-electron-run-as-node
LESSCLOSE=/usr/bin/lesspipe %s %s
XDG_SESSION_CLASS=user
LC_IDENTIFICATION=fi_FI.UTF-8
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=ilmari
VSCODE_GIT_IPC_HANDLE=/run/user/1000/vscode-git-33d28902ce.sock
DISPLAY=:0
SHLVL=2
NVM_CD_FLAGS=
LC_TELEPHONE=fi_FI.UTF-8
QT_IM_MODULE=ibus
LC_MEASUREMENT=fi_FI.UTF-8
XDG_RUNTIME_DIR=/run/user/1000
LC_TIME=fi_FI.UTF-8
VSCODE_GIT_ASKPASS_MAIN=/snap/code/109/usr/share/code/resources/app/extensions/git/dist/askpass-main.js
JOURNAL_STREAM=8:50487
XDG_DATA_DIRS=/usr/share/ubuntu:/usr/local/share/:/usr/share/:/var/lib/snapd/desktop
GDK_BACKEND=x11
PATH=/home/ilmari/.local/bin:/home/ilmari/.nvm/versions/node/v12.22.12/bin:/home/ilmari/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
GDMSESSION=ubuntu
ORIGINAL_XDG_CURRENT_DESKTOP=ubuntu:GNOME
DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
NVM_BIN=/home/ilmari/.nvm/versions/node/v12.22.12/bin
GIO_LAUNCHED_DESKTOP_FILE_PID=14001
GIO_LAUNCHED_DESKTOP_FILE=/var/lib/snapd/desktop/applications/code_code.desktop
LC_NUMERIC=fi_FI.UTF-8
OLDPWD=/home/ilmari/python/systeemiohjelmointi/W7
TERM_PROGRAM=vscode
_=/usr/bin/printenv
'