xinputinfo
==========

What is this?
-------------

A simple utility to check battery status of all connected wireless Xbox 360 controllers under Windows operating system.

Here is an example ouput:

```
Controller #0 found:
  Battery type: alkaline.
  Battery level: medium.
```

Usage
-----

Just start xinputinfo.exe from the command line. No command line arguments needed.

Compiling
---------

1. Install MinGW64 and MSYS2 or Cygwin with MinGW compiler set
2. Fetch the xinputinfo.c and Makefile
3. Check the $(CC) variable in the makefile (*gcc* under MinGW, *i686-w64-mingw32-gcc* or *x86_64-w64-mingw32-gcc* under Cygwin)
4. Call make
5. Done

License
-------

The 3-Clause BSD License

