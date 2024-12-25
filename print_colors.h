
#define SET_COLOR(fg, r, g, b) printf("\033[%i;2;%i;%i;%im", fg ? 38 : 48, r, g, b)

#define BG_RED()    SET_COLOR(1, 255, 0, 0)
#define BG_GREEN()   SET_COLOR(1, 0, 255, 0)
#define BG_BLUE()  SET_COLOR(1, 0, 0, 255)
#define BG_ORANGE() SET_COLOR(1, 255, 170, 0)
#define BG_WHITE() SET_COLOR(1, 255, 255, 255)


