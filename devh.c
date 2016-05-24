#include "devh.h"

/****************************************
 *  Get symbols from the keyboard info  *
 ***************************************/

char* get_kb_symbols(void)
{

/*  The complete description of an Xkb keyboard is given by an XkbDescRec. 
 *  The component structures in the XkbDescRec represent the major Xkb components.
 *
 *
 *	typedef struct {
 * 		struct _XDisplay * display;      // connection to X server 
 * 		unsigned short     flags;        // private to Xkb, do not modify 
 *  		unsigned short     device_spec;  // device of interest 
 *  		KeyCode            min_key_code; // minimum keycode for device 
 	  	KeyCode            max_key_code; // maximum keycode for device 
 	  	XkbControlsPtr     ctrls;        // controls 
 *  		XkbServerMapPtr    server;       // server keymap 
 	  	XkbClientMapPtr    map;          // client keymap 
 *  		XkbIndicatorPtr    indicators;   // indicator map 
 	  	XkbNamesPtr        names;        // names for all components       <--[This is our champion!]
 *  		XkbCompatMapPtr    compat;       // compatibility map 
 	  	XkbGeometryPtr     geom;         // physical geometry of keyboard 
 *	} XkbDescRec, *XkbDescPtr;
 */
	Display *display;
	XkbDescRec *keyboardDesc;
	Atom symbols;
	char* atomName;

/* 	
 *	NAME
 *       	XOpenDisplay, XCloseDisplay - connect or disconnect to X server
 *
 *	SYNTAX
 * 	     	Display *XOpenDisplay(char *display_name);
 *
 *   	   	int XCloseDisplay(Display *display);
 *
 *	ARGUMENTS
 *   	   	display   
 * 					Specifies the connection to the X server.
 *
 *      	display_name
 *          	   	Specifies the hardware display name, which determines the
 *             	 	display and communications domain to be used.  On a POSIX-
 *             		conformant system, if the display_name is NULL, it defaults
 *            		to the value of the DISPLAY environment variable.
 */

	if((display = XOpenDisplay(NULL)) == NULL)
	{
		return "Error: XOpenDisplay()";
	}

/*	
 *	NAME
 *   	   	XkbAllocKeyboard -  Creates a keyboard description from scratch
 *
 *	SYNOPSIS
 *  	   	XkbDescRec XkbAllocKeyboard (void);
 *
 *	DESCRIPTION
 *   	   	Applications  seldom  need to directly allocate a keyboard description;
 *     		calling XkbGetKeyboard usually suffices. In the event you need to  cre‐
 *    		ate  a keyboard description from scratch, however, use XkbAllocKeyboard
 *      	rather than directly calling malloc.
 *
 *      	If XkbAllocKeyboard fails to  allocate  the  keyboard  description,  it
 *     		returns  NULL.   Otherwise,  it  returns a pointer to an empty keyboard
 *    		description structure. The device_spec field will have been initialized
 *   		to  XkbUseCoreKbd. You may then either fill in the structure components
 *	    	or use Xkb functions to obtain values for the structure components from
 *  		a keyboard device.
 */
	keyboardDesc = XkbAllocKeyboard();
	if(keyboardDesc == NULL) {return "Error: XkbAllocKeyboard()";}

/*	
 *	NAME
 *    	   	XkbGetNames - Obtain symbolic names from the server
 *
 *	SYNOPSIS
 *  	   	Status XkbGetNames (Display *dpy, unsigned int which, XkbDescPtr Xkb);
 *
 *	ARGUMENTS
 *  	   	- dpy  	connection to the X server
 *
 *     		- which  mask of names or map components to be updated
 *
 *     		- Xkb  keyboard description to be updated
 *
 *	DESCRIPTION
 *  	   	XkbGetNames retrieves symbolic names for the components of the keyboard
 *     		extension from the X server. The which  parameter  specifies  the  name
 *     		components  to  be  updated  in  the  xkb parameter, and is the bitwise
 *     		inclusive OR of the valid names mask bits defined in Table 1.
 *
 *                               Table 1 Symbolic Names Masks
 *     ─────────────────────────────────────────────────────────────────────────
 *
 *     Mask Bit                 Value      Keyboard     Field
 *                                         Component
 *     ─────────────────────────────────────────────────────────────────────────────────
 *     XkbKeycodesNameMask      (1<<0)     Xkb->names   keycodes
 *     XkbGeometryNameMask      (1<<1)     Xkb->names   geometry
 *     XkbSymbolsNameMask       (1<<2)     Xkb->names   symbols      <-- [This is our champion too!]
 *     XkbPhysSymbolsNameMask   (1<<3)     Xkb->names   phys_symbols
 *     XkbTypesNameMask         (1<<4)     Xkb->names   type
 *     XkbCompatNameMask        (1<<5)     Xkb->names   compat
 *     XkbKeyTypeNamesMask      (1<<6)     Xkb->map     type[*].name
 *     XkbKTLevelNamesMask      (1<<7)     Xkb->map     type[*].lvl_names[*]
 *     XkbIndicatorNamesMask    (1<<8)     Xkb->names   indicators[*]
 *     XkbKeyNamesMask          (1<<9)     Xkb->names   keys[*], num_keys
 *     XkbKeyAliasesMask        (1<<10)    Xkb->names   key_aliases[*], num_key_aliases
 *     XkbVirtualModNamesMask   (1<<11)    Xkb->names   vmods[*]
 *     XkbGroupNamesMask        (1<<12)    Xkb->names   groups[*]
 *     XkbRGNamesMask           (1<<13)    Xkb->names   radio_groups[*], num_rg
 *     XkbComponentNamesMask    (0x3f)     Xkb->names   keycodes,
 *                                                      geometry,
 *                                                      symbols,
 *                                                      physical symbols,
 *                                                      types, and
 *                                                      compatibility map
 *     XkbAllNamesMask          (0x3fff)   Xkb->names   all name components
 *
 *     If the names field of the keyboard description xkb is NULL, XkbGetNames
 *     allocates  and initializes the names component of the keyboard descrip‐
 *     tion before obtaining the values specified  by  which.   If  the  names
 *     field  of  xkb is not NULL, XkbGetNames obtains the values specified by
 *     which and copies them into the keyboard description Xkb.
 *
 *     If the map component of the xkb parameter is NULL, XkbGetNames does not
 *     retrieve  type  or  shift  level  names, even if XkbKeyTypeNamesMask or
 *     XkbKTLevelNamesMask are set in which.
 */

      if(XkbGetNames(display, XkbSymbolsNameMask, keyboardDesc) != Success){return "ERROR: XkbGetNames()";}

      symbols = keyboardDesc->names->symbols;

/*	
 *	char* XGetAtomName(Display *display, Atom atom);
 *	   
 *	   The XGetAtomName function returns the name associated with the speci‐
 *     fied atom.  If the data returned by the server is in the Latin Portable
 *     Character Encoding, then the returned string is in the Host Portable
 *     Character Encoding.  Otherwise, the result is implementation-dependent.
 *     To free the resulting string, call XFree.
 */

       atomName = XGetAtomName(display, symbols);
       XCloseDisplay(display);

       return atomName;
}//End of get_kb_symbols()


/*****************************************
 *  Get keycodes from the keyboard info  *
 ****************************************/

char* get_kb_keycodes(void)
{
     	Display *display;
  	XkbDescRec *keyboardDesc;
	Atom keycodes;
	char* atomName;

	if((display = XOpenDisplay(NULL)) == NULL)
	{
		return "Error: XOpenDisplay()";
	}
	keyboardDesc = XkbAllocKeyboard();

	if(keyboardDesc == NULL) {return "Error: XkbAllocKeyboard()";}

	if(XkbGetNames(display, XkbKeycodesNameMask, keyboardDesc) != Success){return "ERROR: XkbGetNames()";}

    	keycodes = keyboardDesc->names->keycodes;
    	atomName = XGetAtomName(display, keycodes);
	
	XCloseDisplay(display);

    	return atomName;
}//End of get_kb_keycodes()


/*****************************
 *  Get the keyboard layout  *
 * **************************/
 
char* get_kb_layout(char *keycodes, char *symbols)
{
   // QWERTY(italian, us, spanish), 
   //french, deutch, Colemak, Dvorak
   if(strstr(keycodes, "qwerty"))
   {
   		if(strstr(symbols, "it")){ return "it";}
   		else if(strstr(symbols, "us")){ return "us";}
		else if(strstr(symbols, "es")){return "es";}
		else return "unknown";
   }
   else if(strstr(symbols, "fr")){ return "fr";}
   else if(strstr(symbols, "de")){return "de";}
   else if(strstr(keycodes, "colemak")){ return "colemak";}
   else if(strstr(keycodes, "dvorak")){ return "dvorak";}
   else return "unknown"; 
}//End of get_kb_layout()


/*****************************************
 *  Get the title of the active window.  *
 ****************************************/

char* get_window_title(void)
{
	
/*
 *  int XGetWindowProperty(Display *display, Window w, Atom property, long long_offset, 
 *			   long long_length, Bool delete, Atom req_type, Atom *actual_type_return, 
 *			   int *actual_for‐mat_return, unsigned long *nitems_return, 
 *			   unsigned long *bytes_after_return, unsigned char **prop_return);
 */

	Display *display;
	Window rwindow;
	Atom active, actual_type_return;
	int actual_format_return;
	unsigned long bytes_after_return, nitems_return, focused;
	unsigned char *prop_return;
  
  	if ((display = XOpenDisplay(NULL)) == NULL)
	{
		return "No-Window - (\"Unable to open Display\")";
	}
 
	rwindow = XDefaultRootWindow(display);
	active = XInternAtom(display, "_NET_ACTIVE_WINDOW", False);

	if(XGetWindowProperty(display, rwindow, active, 0, ~0, False,
               		      AnyPropertyType, &actual_type_return, &actual_format_return, &nitems_return, &bytes_after_return,
               		      &prop_return) && prop_return)
	{
		fprintf(stderr,"Unable to obtain Window properties.\n");  
		return "No-Window";
	}
  
	focused = *(unsigned long *) prop_return;
	XFree (prop_return);

	if(!focused)          
	{
		fprintf(stderr,"Unable to obtain Window properties.\n");  
		return "No-Window";
	}

	if(XGetWindowProperty(display, (Window) focused, XA_WM_NAME, 0, ~0, False,
			      AnyPropertyType, &actual_type_return, &actual_format_return, &nitems_return, &bytes_after_return,
	              	      &prop_return) && prop_return)
	{
		fprintf(stderr,"Unable to obtain Window properties.\n");  
		return "No-Window";
	}
  
	XSync(display, False);
	XCloseDisplay(display);
	return (char*) prop_return;
}//End get_window_title()


/*************************************************************
 *  Return a socket, referred to by the file descriptor lc,  * 
 *  connected to the address and to the port specified by    *
 *  *addr and by *port, respectively.                        *
 ************************************************************/

int conn(char *addr, char *port)
{
	int lc;
	struct addrinfo hints, *result, *rp;

	memset(&hints,0,sizeof(struct addrinfo));
			hints.ai_canonname = NULL;
			hints.ai_addr = NULL;
			hints.ai_next = NULL;
			hints.ai_socktype = 0; 		 //TCP  && UDP
			hints.ai_family = AF_UNSPEC; 	 //IPv4 && IPv6
			hints.ai_flags = AI_NUMERICSERV; //Interpret service as a numeric port number

	if(getaddrinfo(addr, port, &hints, &result) ==-1)
	{
		fprintf(stderr,"Failed to get address info");
	}
	for(rp = result; rp != NULL; rp = rp->ai_next)
	{
		lc = socket(rp->ai_family,rp->ai_socktype,rp->ai_protocol);
		if(lc == -1)				 //If socket has failed, try with the next addrinfo structure
		{		
			continue;
		}
		if(connect(lc, rp->ai_addr, rp->ai_addrlen) != -1)
		{					 //If connect does not return an error, we can exit from the for-loop
			break;
		}

		close(lc);				//Else close the socket and try with the next addrinfo structure
	}
	
	if(rp == NULL)
	{
		fprintf(stderr,"Failed to find a good address");
		return 1;
	}

	freeaddrinfo(result);

	return lc;
}//End of conn()


/*********************************************
 *  Get the keystroke corresponding to code. *
 *											 *
 *  Supported Layouts:						 *
 *						-QWERTY:(us,it,es)   *
 *  					-AZERTY: fr          *
 *  					-QWERTZ: de          *
 *  					-COLEMAK             *
 *  					-DVORAK: us          *
 ********************************************/

char* code_to_str(char* layout, int code)
{
	int lyt = 0;
	if(!strcmp(layout, "fr")){ lyt = FR;}
	else if(!strcmp(layout, "de")){ lyt = DE;}
	else if(!strcmp(layout, "it")){ lyt = IT;}
	else if(!strcmp(layout, "es")){ lyt = ES;}
	else if(!strcmp(layout, "colemak")){ lyt = COLEMAK;}
	else if(!strcmp(layout, "dvorak")){ lyt = DVORAK;}
	//us is default..

	switch(code)
	{
		//Letters:
		case KEY_A: 
					switch(lyt)
					{
						case FR: return "q"; break;
						default: return "a"; break;
					}
					break;
		case KEY_B: 
					switch(lyt)
					{
						case DVORAK: return "x"; break;
						default: return "b"; break;
					}
					break;
		case KEY_C: 
					switch(lyt)
					{
						case DVORAK: return "j"; break;
						default: return "c"; break;
					}
					break;
		case KEY_D: 
					switch(lyt)
					{
						case DVORAK: return "e"; break;
						case COLEMAK: return "s"; break; 
						default:  return "d"; break;
					}
					break;
		case KEY_E: 
					switch(lyt)
					{
						case DVORAK: return "."; break;
						case COLEMAK: return "f"; break; 
						default: return "e"; break;
					}
					break;
		case KEY_F: 
					switch(lyt)
					{
						case DVORAK: return "u"; break;
						case COLEMAK: return "t"; break; 
						default:  return "f"; break;
					}
					break;
		case KEY_G: 
					switch(lyt)
					{
						case DVORAK: return "i"; break;
						case COLEMAK: return "d"; break; 
						default:  return "g"; break;
					}
					break;
		case KEY_H: 
					switch(lyt)
					{
						case DVORAK: return "d"; break;
						default: return "h"; break;
					}
					break;
		case KEY_I: 
					switch(lyt)
					{
						case DVORAK: return "c"; break;
						case COLEMAK: return "u"; break; 
						default:  return "i"; break;
					}
					break;
		case KEY_J: 
					switch(lyt)
					{
						case DVORAK: return "h"; break;
						case COLEMAK: return "n"; break; 
						default:  return "j"; break;
					}
					break;
		case KEY_K: 
					switch(lyt)
					{
						case DVORAK: return "t"; break;
						case COLEMAK: return "e"; break; 
						default:  return "k"; break;
					}
					break;
		case KEY_L: 
					switch(lyt)
					{
						case DVORAK: return "n"; break;
						case COLEMAK: return "i"; break; 
						default:  return "l"; break;
					}
					break;
		case KEY_M: 
					switch(lyt)
					{
						case FR: return ",";
						default: return "m"; break;
					}
					break;
		case KEY_N: 
					switch(lyt)
					{
						case DVORAK: return "b"; break;
						case COLEMAK: return "k"; break; 
						default:  return "n"; break;
					}
					break;
		case KEY_O: 
					switch(lyt)
					{
						case DVORAK: return "r"; break;
						case COLEMAK: return "y"; break; 
						default:  return "o"; break;
					}
					break;
		case KEY_P: 
					switch(lyt)
					{
						case DVORAK: return "l"; break;
						case COLEMAK: return ";"; break; 
						default:  return "p"; break;
					}
					break;
		case KEY_Q: 
					switch(lyt)
					{
						case DVORAK: return "\'"; break;
						case FR: return "a"; break;
						default: return "q"; break;
					}
					break;
		case KEY_R: 
					switch(lyt)
					{
						case DVORAK:
						case COLEMAK: return "p"; break; 
						default: return "r"; break;
					}
					break;
		case KEY_S: 
					switch(lyt)
					{
						case DVORAK: return "o"; break;
						case COLEMAK: return "r"; break; 
						default:  return "s"; break;
					}
					break;
		case KEY_T: 
					switch(lyt)
					{
						case DVORAK: return "y"; break;
						case COLEMAK: return "g"; break; 
						default:  return "t"; break;
					}
					break;
		case KEY_U: 
					switch(lyt)
					{
						case DVORAK: return "g"; break;
						case COLEMAK: return "l"; break; 
						default:  return "u"; break;
					}
					break;
		case KEY_V: 
					switch(lyt)
					{
						case DVORAK: return "k"; break;
						default: return "v"; break;
					}
					break;
		case KEY_W: 
					switch(lyt)
					{
						case DVORAK: return ","; break;
						case FR: return "z"; break;
						default: return "w"; break;
					}
					break;
		case KEY_X: 
					switch(lyt)
					{
						case DVORAK: return "q"; break;
						default: return "x"; break;
					}
					break;
		case KEY_Y: 
					switch(lyt)
					{
						case DVORAK: return "f"; break;
						case COLEMAK: return "j"; break;
						case DE: return "z"; break;
						default: return "y"; break;
					}
					break;
		case KEY_Z: 
					switch(lyt)
					{
						case DVORAK: return ";"; break;
						case DE: return "y"; break;
						case FR: return "w"; break;
						default: return "z"; break;
					}
					break;
		//Numbers:
		case KEY_0: 
					switch(lyt)
					{
						case FR: return "à"; break;
						default: return "0"; break;
					}
					break;
		case KEY_1: 
					switch(lyt)
					{
						case FR: return "&"; break;
						default: return "1"; break;
					}
					break;
		case KEY_2: 
					switch(lyt)
					{
						case FR: return "é"; break;
						default: return "2"; break;
					}
					break;
		case KEY_3: 
					switch(lyt)
					{
						case FR: return "\""; break;
						default:  return "3"; break;
					}
					break;
		case KEY_4: 
					switch(lyt)
					{
						case FR: return "\'"; break;
						default:   return "4"; break;
					}
					break;
		case KEY_5: 
					switch(lyt)
					{
						case FR: return "("; break;
						default:   return "5"; break;

					}
					break;
		case KEY_6: 
					switch(lyt)
					{
						case FR: return "-"; break;
						default: return "6"; break;
					}
					break;
		case KEY_7: 
					switch(lyt)
					{
						case FR: return "è"; break;
						default: return "7"; break;
					}
					break;
		case KEY_8: 
					switch(lyt)
					{
						case FR: return "_"; break;
						default: return "8"; break;
					}
					break;
		case KEY_9: 
					switch(lyt)
					{
						case FR: return "ç"; break;
						default: return "9"; break;
					}
					break;
		//Special chars:
		case KEY_ESC: return "[ESC]"; break;
		case KEY_BACKSPACE: return "[BACKSPACE]"; break;
 		case KEY_TAB: return "[TAB]"; break;
		case KEY_MINUS: 
						switch(lyt)
						{
							//case COLEMAK: return "="; break;
							case DVORAK: return "["; break;
							case DE: return "ß"; break;
							case FR: return ")"; break;
							case ES: 
							case IT: return "\'"; break;
							default: return "-"; break;
						}
						break;
		case KEY_EQUAL: 
						switch(lyt)
						{ 	
							//case COLEMAK: return "="; break;
							//case FR: return "="; break;
							case DVORAK: return "]"; break;
							case DE: return "´";
							case ES: return "¡"; break;
							case IT: return "ì"; break;
							default: return "="; break;
						}
						break;
		case KEY_LEFTBRACE: 
						switch(lyt)
						{
							//case COLEMAK: return "["; break;
							case DVORAK: return "/"; break;
							case DE: return "ü"; break;
							case FR: return "^"; break;
							case ES: return "`"; break;
							case IT: return "è"; break;
							default: return "["; break;
						}
						break;
		case KEY_RIGHTBRACE: 
						switch(lyt)
						{
							//case COLEMAK: return "]"; break;
							case DVORAK: return "="; break;
							case FR: return "$"; break;
							case DE:
							case ES:
							case IT: return "+"; break;
							default: return "]"; break;
						}
						break;
		case KEY_ENTER: return "[ENTER]"; break;
		case KEY_LEFTCTRL: return "[LEFTCTRL]"; break;
		case KEY_COMPOSE: return "[MENU]"; break;
		case KEY_LEFTMETA: return "[WIN]"; break;
		case KEY_SEMICOLON: 
						switch(lyt)
						{
							case DVORAK: return "s"; break;
							case COLEMAK: return "o"; break;
							case DE: return "ö"; break;
							case FR: return "m"; break;
							case ES: return "ñ"; break;
							case IT: return "ò"; break;
							default: return ";"; break;
						}
						break;
		case KEY_APOSTROPHE: 
						switch(lyt)
						{
							case DVORAK: return "-"; break;
							case COLEMAK: return "\'"; break;
							case DE: return "ä"; break;
							case FR: return "ù"; break;
							case ES: return "´"; break;
							case IT: return "à"; break;
							default: return "'"; break;
						}
						break;
		case KEY_GRAVE: 
						switch(lyt)
						{
							//case COLEMAK: return "`"; break;
							//case DVORAK: return "`"; break;
							case DE: return "^"; break;
							case FR: return "²"; break;
							case ES: return "º"; break;
							case IT: return "\\"; break;
							default: return "`"; break;
						}
						break;
		case KEY_LEFTSHIFT: return "[LEFTSHIFT]"; break;
		case KEY_BACKSLASH: 
						switch(lyt)
						{
							//case DVORAK: return "\\"; break;
							//case COLEMAK: return "\\"; break;
							case DE: return "#"; break;
							case FR: return "*"; break;
							case ES: return "ç"; break;
							case IT: return "ù"; break;
							default: return "\\"; break;
						}
						break;
		case KEY_COMMA: 
						switch(lyt)
						{
							case DVORAK: return "w"; break;
							case FR:  return ";"; break;
							default: return ","; break;
						}
						break;
		case KEY_DOT: 
						switch(lyt)
						{
							case DVORAK: return "v"; break;
							case FR:  return ":"; 
							default: break;return "."; break;
						}
						break;
		case KEY_SLASH: 
						switch(lyt)
						{
							//case COLEMAK: return "/"; break;
							case DVORAK: return "z"; break;
							case FR: return "!"; break;
							case DE:
							case ES:
							case IT: return "-"; break;
							default: return "/"; break;
						}
						break;
		case KEY_102ND: return "<"; break;
		case KEY_RIGHTSHIFT: return "[RIGHTSHIFT]"; break;
		case KEY_KPASTERISK: return "[Keypad *]"; break;
		case KEY_LEFTALT: return "[LEFTALT]"; break;
		case KEY_SPACE: return "[SPACE]"; break;
		case KEY_CAPSLOCK: return "[CAPSLOCK]"; break;
		case KEY_F1: return "[F1]"; break;
		case KEY_F2: return "[F2]"; break;
		case KEY_F3: return "[F3]"; break;
		case KEY_F4: return "[F4]"; break;
		case KEY_F5: return "[F5]"; break;
		case KEY_F6: return "[F6]"; break;
		case KEY_F7: return "[F7]"; break;
		case KEY_F8: return "[F8]"; break;
		case KEY_F9: return "[F9]"; break;
		case KEY_F10: return "[F10]"; break;
		case KEY_F11: return "[F11]"; break;
		case KEY_F12: return "[F12]"; break;
		case KEY_F13: return "[F13]"; break;
		case KEY_F14: return "[F14]"; break;
		case KEY_F15: return "[F15]"; break;
		case KEY_F16: return "[F16]"; break;
		case KEY_F17: return "[F17]"; break;
		case KEY_F18: return "[F18]"; break;
		case KEY_F19: return "[F19]"; break;
		case KEY_F20: return "[F20]"; break;
		case KEY_F21: return "[F21]"; break;
		case KEY_F22: return "[F22]"; break;
		case KEY_F23: return "[F23]"; break;
		case KEY_F24: return "[F24]"; break;
		case KEY_NUMLOCK: return "[NUMLOCK]"; break;
		case KEY_KP0: return "[Keypad 0]"; break;
		case KEY_KP1: return "[Keypad 1]"; break;
		case KEY_KP2: return "[Keypad 2]"; break;
		case KEY_KP3: return "[Keypad 3]"; break;
		case KEY_KP4: return "[Keypad 4]"; break;
		case KEY_KP5: return "[Keypad 5]"; break;
		case KEY_KP6: return "[Keypad 6]"; break;
		case KEY_KP7: return "[Keypad 7]"; break;
		case KEY_KP8: return "[Keypad 8]"; break;
		case KEY_KP9: return "[Keypad 9]"; break;
		case KEY_KPPLUS: return "[Keypad +]"; break;
		case KEY_KPMINUS: return "[Keypad -]"; break;
		case KEY_KPDOT: return "[Keypad .]"; break;
		case KEY_KPENTER: return "[Keypad ENTER]"; break;
		case KEY_RIGHTCTRL: return "[RIGHTCTRL]"; break;
		case KEY_KPSLASH: return "[Keypad /]"; break;
		case KEY_RIGHTALT: return "[RIGHTALT]"; break;
		case KEY_UP: return "[UP]"; break;
		case KEY_PAGEUP: return "[PAGEUP]"; break;
		case KEY_LEFT: return "[LEFT]"; break;
		case KEY_RIGHT: return "[RIGHT]"; break;
		case KEY_PAUSE: return "[PAUSE]"; break;
		case KEY_SYSRQ: return "[STAMP]"; break;
		case KEY_HOME: return "[BEGIN]"; break;
		case KEY_END: return "[END]"; break;
		case KEY_DOWN: return "[DOWN]"; break;
		case KEY_PAGEDOWN: return "[PAGEDOWN]"; break;
		case KEY_INSERT: return "[INSERT]"; break;
		case KEY_DELETE: return "[DELETE]"; break;
		case KEY_MUTE: return "[MUTE]"; break;
		case KEY_VOLUMEDOWN: return "[VOLUMEDOWN]"; break;
		case KEY_VOLUMEUP: return "[VOLUMEUP]"; break;
		case KEY_POWER: return "[POWER]"; break;
		
		default: return "[UNKNOWN]"; break;
	}
}//End of code_to_str()
