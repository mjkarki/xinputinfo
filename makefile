all: xinputinfo

xinputinfo:
	gcc -o xinputinfo.exe xinputinfo.c -lxinput -s

clean:
	rm xinputinfo.exe

