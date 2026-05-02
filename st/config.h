#define ALPHA_INT 0.9

static char *font = "JetBrains Mono Nerd Font:weight=900:pixelsize=15:antialias=true:autohint=true";

#if FONT2_PATCH
static char *font2[] = {
};
#endif 

#if BACKGROUND_IMAGE_PATCH
static const char *bgfile = "/path/to/image.ff";
static const int pseudotransparency = 0;
#endif 

#if RELATIVEBORDER_PATCH
int borderperc = 10;
#else
static int borderpx = 7;
#endif 

#if OPENURLONCLICK_PATCH
static uint url_opener_modkey = XK_ANY_MOD;
static char *url_opener = "xdg-open";
#endif 

static char *shell = "/bin/sh";
char *utmp = NULL;
char *scroll = NULL;
char *stty_args = "stty raw pass8 nl -echo -iexten -cstopb 38400";

#if SIXEL_PATCH
char *vtiden = "\033[?62;4c"; 
int const sixelbyteorder = LSBFirst;
#else
char *vtiden = "\033[?6c";
#endif

static float cwscale = 1.00f;
static float chscale = 1.00f;

wchar_t *worddelimiters = L" ";

#if KEYBOARDSELECT_PATCH && REFLOW_PATCH
wchar_t *kbds_sdelim = L"!\"#$%&'()*+,-./:;<=>?@[\\]^`{|}~ ";
wchar_t *kbds_ldelim = L" ";
#endif 

static unsigned int doubleclicktimeout = 300;
static unsigned int tripleclicktimeout = 600;

int allowaltscreen = 1;

int allowwindowops = 0;

static double minlatency = 2;
static double maxlatency = 33;

#if SYNC_PATCH
static uint su_timeout = 200;
#endif 

static unsigned int blinktimeout = 800;

static unsigned int cursorthickness = 2;

#if HIDECURSOR_PATCH
int hidecursor = 1;
#endif 

#if BOXDRAW_PATCH
const int boxdraw = 1;
const int boxdraw_bold = 1;

const int boxdraw_braille = 0;
#endif 

static int bellvolume = 0;

char *termname = "st-256color";

unsigned int tabspaces = 8;

#if ALPHA_PATCH
float alpha = ALPHA_INT;
#if ALPHA_GRADIENT_PATCH
float grad_alpha = ALPHA_INT; 
float stat_alpha = ALPHA_INT; 
#endif 
#if ALPHA_FOCUS_HIGHLIGHT_PATCH
float alphaUnfocused = ALPHA_INT;
#endif 
#endif 

#if DRAG_AND_DROP_PATCH
char *xdndescchar = " !\"#$&'()*;<>?[\\]^`{|}~";
#endif 

static const char *colorname[] = {
        "black",
        "red3",
        "green3",
        "#ffbb77",
        "blue2",
        "magenta3",
        "cyan3",
        "gray90",

        "gray50",
        "red",
        "green",
        "#ffbb77",
        "#5c5cff",
        "magenta",
        "cyan",
        "white",

        [255] = 0,

        "#ffffff", 
        "#555555", 
        "#000000", 
        "#e5e5e5", 
};

#if ALPHA_PATCH && ALPHA_FOCUS_HIGHLIGHT_PATCH
unsigned int bg = 258;            
unsigned int bgUnfocused = 258; 
#else
unsigned int defaultbg = 258;
#endif
unsigned int defaultfg = 259;
unsigned int defaultcs = 6;
unsigned int defaultrcs = 257;
#if SELECTION_COLORS_PATCH
unsigned int selectionfg = 258;
unsigned int selectionbg = 259;
static int ignoreselfg = 1;
#endif 
#if KEYBOARDSELECT_PATCH && REFLOW_PATCH
unsigned int highlightfg = 15;
unsigned int highlightbg = 160;
#endif 

#if BLINKING_CURSOR_PATCH
static unsigned int cursorstyle = 1;
static Rune stcursor = 0x2603; 
#else
static unsigned int cursorshape = 2;
#endif 

static unsigned int cols = 80;
static unsigned int rows = 24;

#if ANYGEOMETRY_PATCH
static Geometry geometry = PixelGeometry; 
static unsigned int width = 1000;
static unsigned int height = 600;

#endif 

#if THEMED_CURSOR_PATCH
static char* mouseshape = "xterm";
#else
static unsigned int mouseshape = XC_left_ptr;
static unsigned int mousefg = 7;
static unsigned int mousebg = 0;
#endif 

static unsigned int defaultattr = 11;

#if XRESOURCES_PATCH
ResourcePref resources[] = {
                { "font",         STRING,  &font },
                { "color0",       STRING,  &colorname[0] },
                { "color1",       STRING,  &colorname[1] },
                { "color2",       STRING,  &colorname[2] },
                { "color3",       STRING,  &colorname[3] },
                { "color4",       STRING,  &colorname[4] },
                { "color5",       STRING,  &colorname[5] },
                { "color6",       STRING,  &colorname[6] },
                { "color7",       STRING,  &colorname[7] },
                { "color8",       STRING,  &colorname[8] },
                { "color9",       STRING,  &colorname[9] },
                { "color10",      STRING,  &colorname[10] },
                { "color11",      STRING,  &colorname[11] },
                { "color12",      STRING,  &colorname[12] },
                { "color13",      STRING,  &colorname[13] },
                { "color14",      STRING,  &colorname[14] },
                { "color15",      STRING,  &colorname[15] },
                { "background",   STRING,  &colorname[258] },
                { "foreground",   STRING,  &colorname[259] },
                { "cursorColor",  STRING,  &colorname[6] },
                { "termname",     STRING,  &termname },
                { "shell",        STRING,  &shell },
                { "minlatency",   INTEGER, &minlatency },
                { "maxlatency",   INTEGER, &maxlatency },
                { "blinktimeout", INTEGER, &blinktimeout },
                { "bellvolume",   INTEGER, &bellvolume },
                { "tabspaces",    INTEGER, &tabspaces },
                #if RELATIVEBORDER_PATCH
                { "borderperc",   INTEGER, &borderperc },
                #else
                { "borderpx",     INTEGER, &borderpx },
                #endif 
                { "cwscale",      FLOAT,   &cwscale },
                { "chscale",      FLOAT,   &chscale },
                #if ALPHA_PATCH
                { "alpha",        FLOAT,   &alpha },
                #endif 
                #if ALPHA_FOCUS_HIGHLIGHT_PATCH
                { "alphaUnfocused",FLOAT,  &alphaUnfocused },
                #endif 
                #if KEYBOARDSELECT_PATCH && REFLOW_PATCH
                { "highlightfg",  INTEGER, &highlightfg },
                { "highlightbg",  INTEGER, &highlightbg },
                #endif 
};
#endif 

static uint forcemousemod = ShiftMask;

static MouseShortcut mshortcuts[] = {
        #if OPEN_SELECTED_TEXT_PATCH
        { ControlMask,          Button2, selopen,        {.i = 0},      1 },
        #endif 
        #if CLIPBOARD_PATCH
        { XK_ANY_MOD,           Button2, clippaste,      {.i = 0},      1 },
        #else
        { XK_ANY_MOD,           Button2, selpaste,       {.i = 0},      1 },
        #endif 
        #if SCROLLBACK_MOUSE_PATCH
        { ShiftMask,            Button4, kscrollup,      {.i = 1},      0, S_PRI},
        { ShiftMask,            Button5, kscrolldown,    {.i = 1},      0, S_PRI},
        #elif UNIVERSCROLL_PATCH
        { XK_ANY_MOD,           Button4, ttysend,        {.s = "\033[5;2~"}, 0, S_PRI },
        { XK_ANY_MOD,           Button5, ttysend,        {.s = "\033[6;2~"}, 0, S_PRI },
        #else
        { ShiftMask,            Button4, ttysend,        {.s = "\033[5;2~"} },
        { ShiftMask,            Button5, ttysend,        {.s = "\033[6;2~"} },
        #endif 
        #if SCROLLBACK_MOUSE_ALTSCREEN_PATCH || REFLOW_PATCH
        { XK_ANY_MOD,           Button4, kscrollup,      {.i = 3},      0, S_PRI },
        { XK_ANY_MOD,           Button5, kscrolldown,    {.i = 3},      0, S_PRI },
        { XK_ANY_MOD,           Button4, ttysend,        {.s = "\031"}, 0, S_ALT },
        { XK_ANY_MOD,           Button5, ttysend,        {.s = "\005"}, 0, S_ALT },
        #else
        { XK_ANY_MOD,           Button4, ttysend,        {.s = "\031"} },
        { XK_ANY_MOD,           Button5, ttysend,        {.s = "\005"} },
        #endif 
};

#define MODKEY Mod1Mask
#define TERMMOD (ControlMask|ShiftMask)

#if EXTERNALPIPE_PATCH 
static char *openurlcmd[] = { "/bin/sh", "-c",
        "xurls | dmenu -l 10 -w $WINDOWID | xargs -r open",
        "externalpipe", NULL };

#if EXTERNALPIPEIN_PATCH 
static char *setbgcolorcmd[] = { "/bin/sh", "-c",
        "printf '\033]11;#008000\007'",
        "externalpipein", NULL };
#endif 
#endif 

static Shortcut shortcuts[] = {
        { XK_ANY_MOD,           XK_Break,       sendbreak,       {.i =  0} },
        { ControlMask,          XK_Print,       toggleprinter,   {.i =  0} },
        { ShiftMask,            XK_Print,       printscreen,     {.i =  0} },
        { XK_ANY_MOD,           XK_Print,       printsel,        {.i =  0} },
        { TERMMOD,              XK_Prior,       zoom,            {.f = +1} },
        { TERMMOD,              XK_Next,        zoom,            {.f = -1} },
        { TERMMOD,              XK_Home,        zoomreset,       {.f =  0} },
        { TERMMOD,              XK_C,           clipcopy,        {.i =  0} },
        { TERMMOD,              XK_V,           clippaste,       {.i =  0} },
        #if ALPHA_PATCH
        { TERMMOD,              XK_O,           changealpha,     {.f = +0.05} },
        { TERMMOD,              XK_P,           changealpha,     {.f = -0.05} },
        #if ALPHA_FOCUS_HIGHLIGHT_PATCH
        #endif 
        #endif 
        #if FULLSCREEN_PATCH
        { XK_NO_MOD,            XK_F11,         fullscreen,      {.i =  0} },
        { MODKEY,               XK_Return,      fullscreen,      {.i =  0} },
        #endif 
        #if SCROLLBACK_PATCH || REFLOW_PATCH
        { ShiftMask,            XK_Page_Up,     kscrollup,       {.i = -1}, S_PRI },
        { ShiftMask,            XK_Page_Down,   kscrolldown,     {.i = -1}, S_PRI },
        #endif 
        #if CLIPBOARD_PATCH
        { TERMMOD,              XK_Y,           clippaste,       {.i =  0} },
        { ShiftMask,            XK_Insert,      clippaste,       {.i =  0} },
        #else
        { TERMMOD,              XK_Y,           selpaste,        {.i =  0} },
        { ShiftMask,            XK_Insert,      selpaste,        {.i =  0} },
        #endif 
        { TERMMOD,              XK_Num_Lock,    numlock,         {.i =  0} },
        #if COPYURL_PATCH || COPYURL_HIGHLIGHT_SELECTED_URLS_PATCH
        { MODKEY,               XK_l,           copyurl,         {.i =  0} },
        #endif 
        #if OPENCOPIED_PATCH
        { MODKEY,               XK_o,           opencopied,      {.v = "xdg-open"} },
        #endif 
        #if NEWTERM_PATCH
        { TERMMOD,              XK_Return,      newterm,         {.i =  0} },
        #endif 
        #if EXTERNALPIPE_PATCH
        { TERMMOD,              XK_U,           externalpipe,    { .v = openurlcmd } },
        #if EXTERNALPIPEIN_PATCH
        { TERMMOD,              XK_M,           externalpipein,  { .v = setbgcolorcmd } },
        #endif 
        #endif 
        #if KEYBOARDSELECT_PATCH
        { TERMMOD,              XK_Escape,      keyboard_select, { 0 } },
        #endif 
        #if KEYBOARDSELECT_PATCH && REFLOW_PATCH
        { TERMMOD,              XK_F,           searchforward,   { 0 } },
        { TERMMOD,              XK_B,           searchbackward,  { 0 } },
        #endif 
        #if ISO14755_PATCH
        { TERMMOD,              XK_I,           iso14755,        {.i =  0} },
        #endif 
        #if INVERT_PATCH
        { TERMMOD,              XK_X,           invert,          { 0 } },
        #endif 
        #if OSC133_PATCH
        { ControlMask,          XK_Page_Up,     scrolltoprompt,  {.i = -1}, S_PRI },
        { ControlMask,          XK_Page_Down,   scrolltoprompt,  {.i =  1}, S_PRI },
        #endif 
};

#if !FIXKEYBOARDINPUT_PATCH
static KeySym mappedkeys[] = { -1 };
#endif 

static uint ignoremod = Mod2Mask|XK_SWITCH_MOD;

#if !FIXKEYBOARDINPUT_PATCH
static Key key[] = {
        { XK_KP_Home,       ShiftMask,      "\033[2J",       0,   -1},
        { XK_KP_Home,       ShiftMask,      "\033[1;2H",     0,   +1},
        { XK_KP_Home,       XK_ANY_MOD,     "\033[H",        0,   -1},
        { XK_KP_Home,       XK_ANY_MOD,     "\033[1~",       0,   +1},
        { XK_KP_Up,         XK_ANY_MOD,     "\033Ox",       +1,    0},
        { XK_KP_Up,         XK_ANY_MOD,     "\033[A",        0,   -1},
        { XK_KP_Up,         XK_ANY_MOD,     "\033OA",        0,   +1},
        { XK_KP_Down,       XK_ANY_MOD,     "\033Or",       +1,    0},
        { XK_KP_Down,       XK_ANY_MOD,     "\033[B",        0,   -1},
        { XK_KP_Down,       XK_ANY_MOD,     "\033OB",        0,   +1},
        { XK_KP_Left,       XK_ANY_MOD,     "\033Ot",       +1,    0},
        { XK_KP_Left,       XK_ANY_MOD,     "\033[D",        0,   -1},
        { XK_KP_Left,       XK_ANY_MOD,     "\033OD",        0,   +1},
        { XK_KP_Right,      XK_ANY_MOD,     "\033Ov",       +1,    0},
        { XK_KP_Right,      XK_ANY_MOD,     "\033[C",        0,   -1},
        { XK_KP_Right,      XK_ANY_MOD,     "\033OC",        0,   +1},
        { XK_KP_Prior,      ShiftMask,      "\033[5;2~",     0,    0},
        { XK_KP_Prior,      XK_ANY_MOD,     "\033[5~",       0,    0},
        { XK_KP_Begin,      XK_ANY_MOD,     "\033[E",        0,    0},
        { XK_KP_End,        ControlMask,    "\033[J",       -1,    0},
        { XK_KP_End,        ControlMask,    "\033[1;5F",    +1,    0},
        { XK_KP_End,        ShiftMask,      "\033[K",       -1,    0},
        { XK_KP_End,        ShiftMask,      "\033[1;2F",    +1,    0},
        { XK_KP_End,        XK_ANY_MOD,     "\033[4~",       0,    0},
        { XK_KP_Next,       ShiftMask,      "\033[6;2~",     0,    0},
        { XK_KP_Next,       XK_ANY_MOD,     "\033[6~",       0,    0},
        { XK_KP_Insert,     ShiftMask,      "\033[2;2~",    +1,    0},
        { XK_KP_Insert,     ShiftMask,      "\033[4l",      -1,    0},
        { XK_KP_Insert,     ControlMask,    "\033[L",       -1,    0},
        { XK_KP_Insert,     ControlMask,    "\033[2;5~",    +1,    0},
        { XK_KP_Insert,     XK_ANY_MOD,     "\033[4h",      -1,    0},
        { XK_KP_Insert,     XK_ANY_MOD,     "\033[2~",      +1,    0},
        { XK_KP_Delete,     ControlMask,    "\033[M",       -1,    0},
        { XK_KP_Delete,     ControlMask,    "\033[3;5~",    +1,    0},
        { XK_KP_Delete,     ShiftMask,      "\033[2K",      -1,    0},
        { XK_KP_Delete,     ShiftMask,      "\033[3;2~",    +1,    0},
        #if DELKEY_PATCH
        { XK_KP_Delete,     XK_ANY_MOD,     "\033[3~",      -1,    0},
        #else
        { XK_KP_Delete,     XK_ANY_MOD,     "\033[P",       -1,    0},
        #endif 
        { XK_KP_Delete,     XK_ANY_MOD,     "\033[3~",      +1,    0},
        { XK_KP_Multiply,   XK_ANY_MOD,     "\033Oj",       +2,    0},
        { XK_KP_Add,        XK_ANY_MOD,     "\033Ok",       +2,    0},
        { XK_KP_Enter,      XK_ANY_MOD,     "\033OM",       +2,    0},
        { XK_KP_Enter,      XK_ANY_MOD,     "\r",           -1,    0},
        { XK_KP_Subtract,   XK_ANY_MOD,     "\033Om",       +2,    0},
        { XK_KP_Decimal,    XK_ANY_MOD,     "\033On",       +2,    0},
        { XK_KP_Divide,     XK_ANY_MOD,     "\033Oo",       +2,    0},
        { XK_KP_0,          XK_ANY_MOD,     "\033Op",       +2,    0},
        { XK_KP_1,          XK_ANY_MOD,     "\033Oq",       +2,    0},
        { XK_KP_2,          XK_ANY_MOD,     "\033Or",       +2,    0},
        { XK_KP_3,          XK_ANY_MOD,     "\033Os",       +2,    0},
        { XK_KP_4,          XK_ANY_MOD,     "\033Ot",       +2,    0},
        { XK_KP_5,          XK_ANY_MOD,     "\033Ou",       +2,    0},
        { XK_KP_6,          XK_ANY_MOD,     "\033Ov",       +2,    0},
        { XK_KP_7,          XK_ANY_MOD,     "\033Ow",       +2,    0},
        { XK_KP_8,          XK_ANY_MOD,     "\033Ox",       +2,    0},
        { XK_KP_9,          XK_ANY_MOD,     "\033Oy",       +2,    0},
        { XK_Up,            ShiftMask,      "\033[1;2A",     0,    0},
        { XK_Up,            Mod1Mask,       "\033[1;3A",     0,    0},
        { XK_Up,         ShiftMask|Mod1Mask,"\033[1;4A",     0,    0},
        { XK_Up,            ControlMask,    "\033[1;5A",     0,    0},
        { XK_Up,      ShiftMask|ControlMask,"\033[1;6A",     0,    0},
        { XK_Up,       ControlMask|Mod1Mask,"\033[1;7A",     0,    0},
        { XK_Up,ShiftMask|ControlMask|Mod1Mask,"\033[1;8A",  0,    0},
        { XK_Up,            XK_ANY_MOD,     "\033[A",        0,   -1},
        { XK_Up,            XK_ANY_MOD,     "\033OA",        0,   +1},
        { XK_Down,          ShiftMask,      "\033[1;2B",     0,    0},
        { XK_Down,          Mod1Mask,       "\033[1;3B",     0,    0},
        { XK_Down,       ShiftMask|Mod1Mask,"\033[1;4B",     0,    0},
        { XK_Down,          ControlMask,    "\033[1;5B",     0,    0},
        { XK_Down,    ShiftMask|ControlMask,"\033[1;6B",     0,    0},
        { XK_Down,     ControlMask|Mod1Mask,"\033[1;7B",     0,    0},
        { XK_Down,ShiftMask|ControlMask|Mod1Mask,"\033[1;8B",0,    0},
        { XK_Down,          XK_ANY_MOD,     "\033[B",        0,   -1},
        { XK_Down,          XK_ANY_MOD,     "\033OB",        0,   +1},
        { XK_Left,          ShiftMask,      "\033[1;2D",     0,    0},
        { XK_Left,          Mod1Mask,       "\033[1;3D",     0,    0},
        { XK_Left,       ShiftMask|Mod1Mask,"\033[1;4D",     0,    0},
        { XK_Left,          ControlMask,    "\033[1;5D",     0,    0},
        { XK_Left,    ShiftMask|ControlMask,"\033[1;6D",     0,    0},
        { XK_Left,     ControlMask|Mod1Mask,"\033[1;7D",     0,    0},
        { XK_Left,ShiftMask|ControlMask|Mod1Mask,"\033[1;8D",0,    0},
        { XK_Left,          XK_ANY_MOD,     "\033[D",        0,   -1},
        { XK_Left,          XK_ANY_MOD,     "\033OD",        0,   +1},
        { XK_Right,         ShiftMask,      "\033[1;2C",     0,    0},
        { XK_Right,         Mod1Mask,       "\033[1;3C",     0,    0},
        { XK_Right,      ShiftMask|Mod1Mask,"\033[1;4C",     0,    0},
        { XK_Right,         ControlMask,    "\033[1;5C",     0,    0},
        { XK_Right,   ShiftMask|ControlMask,"\033[1;6C",     0,    0},
        { XK_Right,    ControlMask|Mod1Mask,"\033[1;7C",     0,    0},
        { XK_Right,ShiftMask|ControlMask|Mod1Mask,"\033[1;8C",0,   0},
        { XK_Right,         XK_ANY_MOD,     "\033[C",        0,   -1},
        { XK_Right,         XK_ANY_MOD,     "\033OC",        0,   +1},
        { XK_ISO_Left_Tab,  ShiftMask,      "\033[Z",        0,    0},
        { XK_Return,        Mod1Mask,       "\033\r",        0,    0},
        { XK_Return,        XK_ANY_MOD,     "\r",            0,    0},
        { XK_Insert,        ShiftMask,      "\033[4l",      -1,    0},
        { XK_Insert,        ShiftMask,      "\033[2;2~",    +1,    0},
        { XK_Insert,        ControlMask,    "\033[L",       -1,    0},
        { XK_Insert,        ControlMask,    "\033[2;5~",    +1,    0},
        { XK_Insert,        XK_ANY_MOD,     "\033[4h",      -1,    0},
        { XK_Insert,        XK_ANY_MOD,     "\033[2~",      +1,    0},
        { XK_Delete,        ControlMask,    "\033[M",       -1,    0},
        { XK_Delete,        ControlMask,    "\033[3;5~",    +1,    0},
        { XK_Delete,        ShiftMask,      "\033[2K",      -1,    0},
        { XK_Delete,        ShiftMask,      "\033[3;2~",    +1,    0},
        #if DELKEY_PATCH
        { XK_Delete,        XK_ANY_MOD,     "\033[3~",      -1,    0},
        #else
        { XK_Delete,        XK_ANY_MOD,     "\033[P",       -1,    0},
        #endif 
        { XK_Delete,        XK_ANY_MOD,     "\033[3~",      +1,    0},
        { XK_BackSpace,     XK_NO_MOD,      "\177",          0,    0},
        { XK_BackSpace,     Mod1Mask,       "\033\177",      0,    0},
        { XK_Home,          ShiftMask,      "\033[2J",       0,   -1},
        { XK_Home,          ShiftMask,      "\033[1;2H",     0,   +1},
        { XK_Home,          XK_ANY_MOD,     "\033[H",        0,   -1},
        { XK_Home,          XK_ANY_MOD,     "\033[1~",       0,   +1},
        { XK_End,           ControlMask,    "\033[J",       -1,    0},
        { XK_End,           ControlMask,    "\033[1;5F",    +1,    0},
        { XK_End,           ShiftMask,      "\033[K",       -1,    0},
        { XK_End,           ShiftMask,      "\033[1;2F",    +1,    0},
        { XK_End,           XK_ANY_MOD,     "\033[4~",       0,    0},
        { XK_Prior,         ControlMask,    "\033[5;5~",     0,    0},
        { XK_Prior,         ShiftMask,      "\033[5;2~",     0,    0},
        { XK_Prior,         XK_ANY_MOD,     "\033[5~",       0,    0},
        { XK_Next,          ControlMask,    "\033[6;5~",     0,    0},
        { XK_Next,          ShiftMask,      "\033[6;2~",     0,    0},
        { XK_Next,          XK_ANY_MOD,     "\033[6~",       0,    0},
        { XK_F1,            XK_NO_MOD,      "\033OP" ,       0,    0},
        { XK_F1,            ShiftMask,      "\033[1;2P",     0,    0},
        { XK_F1,            ControlMask,    "\033[1;5P",     0,    0},
        { XK_F1,            Mod4Mask,       "\033[1;6P",     0,    0},
        { XK_F1,            Mod1Mask,       "\033[1;3P",     0,    0},
        { XK_F1,            Mod3Mask,       "\033[1;4P",     0,    0},
        { XK_F2,            XK_NO_MOD,      "\033OQ" ,       0,    0},
        { XK_F2,            ShiftMask,      "\033[1;2Q",     0,    0},
        { XK_F2,            ControlMask,    "\033[1;5Q",     0,    0},
        { XK_F2,            Mod4Mask,       "\033[1;6Q",     0,    0},
        { XK_F2,            Mod1Mask,       "\033[1;3Q",     0,    0},
        { XK_F2,            Mod3Mask,       "\033[1;4Q",     0,    0},
        { XK_F3,            XK_NO_MOD,      "\033OR" ,       0,    0},
        { XK_F3,            ShiftMask,      "\033[1;2R",     0,    0},
        { XK_F3,            ControlMask,    "\033[1;5R",     0,    0},
        { XK_F3,            Mod4Mask,       "\033[1;6R",     0,    0},
        { XK_F3,            Mod1Mask,       "\033[1;3R",     0,    0},
        { XK_F3,            Mod3Mask,       "\033[1;4R",     0,    0},
        { XK_F4,            XK_NO_MOD,      "\033OS" ,       0,    0},
        { XK_F4,            ShiftMask,      "\033[1;2S",     0,    0},
        { XK_F4,            ControlMask,    "\033[1;5S",     0,    0},
        { XK_F4,            Mod4Mask,       "\033[1;6S",     0,    0},
        { XK_F4,            Mod1Mask,       "\033[1;3S",     0,    0},
        { XK_F5,            XK_NO_MOD,      "\033[15~",      0,    0},
        { XK_F5,            ShiftMask,      "\033[15;2~",    0,    0},
        { XK_F5,            ControlMask,    "\033[15;5~",    0,    0},
        { XK_F5,            Mod4Mask,       "\033[15;6~",    0,    0},
        { XK_F5,            Mod1Mask,       "\033[15;3~",    0,    0},
        { XK_F6,            XK_NO_MOD,      "\033[17~",      0,    0},
        { XK_F6,            ShiftMask,      "\033[17;2~",    0,    0},
        { XK_F6,            ControlMask,    "\033[17;5~",    0,    0},
        { XK_F6,            Mod4Mask,       "\033[17;6~",    0,    0},
        { XK_F6,            Mod1Mask,       "\033[17;3~",    0,    0},
        { XK_F7,            XK_NO_MOD,      "\033[18~",      0,    0},
        { XK_F7,            ShiftMask,      "\033[18;2~",    0,    0},
        { XK_F7,            ControlMask,    "\033[18;5~",    0,    0},
        { XK_F7,            Mod4Mask,       "\033[18;6~",    0,    0},
        { XK_F7,            Mod1Mask,       "\033[18;3~",    0,    0},
        { XK_F8,            XK_NO_MOD,      "\033[19~",      0,    0},
        { XK_F8,            ShiftMask,      "\033[19;2~",    0,    0},
        { XK_F8,            ControlMask,    "\033[19;5~",    0,    0},
        { XK_F8,            Mod4Mask,       "\033[19;6~",    0,    0},
        { XK_F8,            Mod1Mask,       "\033[19;3~",    0,    0},
        { XK_F9,            XK_NO_MOD,      "\033[20~",      0,    0},
        { XK_F9,            ShiftMask,      "\033[20;2~",    0,    0},
        { XK_F9,            ControlMask,    "\033[20;5~",    0,    0},
        { XK_F9,            Mod4Mask,       "\033[20;6~",    0,    0},
        { XK_F9,            Mod1Mask,       "\033[20;3~",    0,    0},
        { XK_F10,           XK_NO_MOD,      "\033[21~",      0,    0},
        { XK_F10,           ShiftMask,      "\033[21;2~",    0,    0},
        { XK_F10,           ControlMask,    "\033[21;5~",    0,    0},
        { XK_F10,           Mod4Mask,       "\033[21;6~",    0,    0},
        { XK_F10,           Mod1Mask,       "\033[21;3~",    0,    0},
        { XK_F11,           XK_NO_MOD,      "\033[23~",      0,    0},
        { XK_F11,           ShiftMask,      "\033[23;2~",    0,    0},
        { XK_F11,           ControlMask,    "\033[23;5~",    0,    0},
        { XK_F11,           Mod4Mask,       "\033[23;6~",    0,    0},
        { XK_F11,           Mod1Mask,       "\033[23;3~",    0,    0},
        { XK_F12,           XK_NO_MOD,      "\033[24~",      0,    0},
        { XK_F12,           ShiftMask,      "\033[24;2~",    0,    0},
        { XK_F12,           ControlMask,    "\033[24;5~",    0,    0},
        { XK_F12,           Mod4Mask,       "\033[24;6~",    0,    0},
        { XK_F12,           Mod1Mask,       "\033[24;3~",    0,    0},
        { XK_F13,           XK_NO_MOD,      "\033[1;2P",     0,    0},
        { XK_F14,           XK_NO_MOD,      "\033[1;2Q",     0,    0},
        { XK_F15,           XK_NO_MOD,      "\033[1;2R",     0,    0},
        { XK_F16,           XK_NO_MOD,      "\033[1;2S",     0,    0},
        { XK_F17,           XK_NO_MOD,      "\033[15;2~",    0,    0},
        { XK_F18,           XK_NO_MOD,      "\033[17;2~",    0,    0},
        { XK_F19,           XK_NO_MOD,      "\033[18;2~",    0,    0},
        { XK_F20,           XK_NO_MOD,      "\033[19;2~",    0,    0},
        { XK_F21,           XK_NO_MOD,      "\033[20;2~",    0,    0},
        { XK_F22,           XK_NO_MOD,      "\033[21;2~",    0,    0},
        { XK_F23,           XK_NO_MOD,      "\033[23;2~",    0,    0},
        { XK_F24,           XK_NO_MOD,      "\033[24;2~",    0,    0},
        { XK_F25,           XK_NO_MOD,      "\033[1;5P",     0,    0},
        { XK_F26,           XK_NO_MOD,      "\033[1;5Q",     0,    0},
        { XK_F27,           XK_NO_MOD,      "\033[1;5R",     0,    0},
        { XK_F28,           XK_NO_MOD,      "\033[1;5S",     0,    0},
        { XK_F29,           XK_NO_MOD,      "\033[15;5~",    0,    0},
        { XK_F30,           XK_NO_MOD,      "\033[17;5~",    0,    0},
        { XK_F31,           XK_NO_MOD,      "\033[18;5~",    0,    0},
        { XK_F32,           XK_NO_MOD,      "\033[19;5~",    0,    0},
        { XK_F33,           XK_NO_MOD,      "\033[20;5~",    0,    0},
        { XK_F34,           XK_NO_MOD,      "\033[21;5~",    0,    0},
        { XK_F35,           XK_NO_MOD,      "\033[23;5~",    0,    0},
};
#endif 

static uint selmasks[] = {
        [SEL_RECTANGULAR] = Mod1Mask,
};

static char ascii_printable[] =
        " !\"#$%&'()*+,-./0123456789:;<=>?"
        "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_"
        "`abcdefghijklmnopqrstuvwxyz{|}~";

#if RIGHTCLICKTOPLUMB_PATCH
static char *plumb_cmd = "plumb";
#endif 

#if UNDERCURL_PATCH
#define UNDERCURL_CURLY 0
#define UNDERCURL_SPIKY 1
#define UNDERCURL_CAPPED 2
#define UNDERCURL_STYLE UNDERCURL_SPIKY
#endif
