static void outRedraw(void) {
    int i, line, y, width;
    winset(outWin); /* cpack (0x00ffffff); */
    cpack(BackgroundColor);
    clear(); /* cpack (0x00000000); */
    cpack(ForegroundColor);
    for (i = 0; i < outNumRows; i++) {
        line = SCROLLBACK - outNumRows + i - outBar;
        if (line >= 0 && line < SCROLLBACK) {
            cmov2i(15, (i + 1) * CHARHEIGHT);
            charstr(outLineBuf[line]);
        }
    }
    move2i(10, 0);
    draw2i(10, outHeight);
    y = outHeight - outBar * outHeight / (SCROLLBACK - outNumRows);
    recti(1, y - 1, 8, y - 20); /* XXX I'm not sure we should have a cursor in this window: */
    cpack(0x0000ff00);
    width = strwidth(outLineBuf[SCROLLBACK - 1]) + 14;
    y = (outNumRows + outBar - 1) * CHARHEIGHT + 4;
    rectfi(width, y, width + 8, y + CHARHEIGHT);
    swapbuffers();
}
