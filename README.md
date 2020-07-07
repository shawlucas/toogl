# toogl
x86_64 Toogl: A port of SGI's IRIS GL to OpenGL Converter

## Requirements for building:

```
build-essential
libYgl4-dev libgl1-mesa-dev libglew-dev libsdl2-dev libsdl2-image-dev libglm-dev libfreetype6-dev
```

Then to build just run `make` and the application will be output as `toogl`

### Usage 

```
./toogl [-cwq] < infile > outfile
```

``-c`` : Don't clutter up the output with comments

``-w`` : Don't remove window manager calls like ``winopen()`` and ``mapcolor()``

``-q`` : Don't remove event queue calls like ``qread()`` and ``setvaluator()``

For more info, visit http://retrogeeks.org/sgi_bookshelves/SGI_Developer/books/OpenGL_Porting/sgi_html/ch02.html

I've found that the program works best when working with small functions.

Also the program crashes if you have any whitespace between lines for some reason

