CC=i686-w64-mingw32-gcc
all: xinputinfo

xinputinfo:
	$(CC) -o xinputinfo.exe xinputinfo.c -lxinput -s

clean:
	rm xinputinfo.exe

