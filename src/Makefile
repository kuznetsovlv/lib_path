#Makefile
objects = getAbsolutePath.o getCurrentPath.o getHome.o isValidPath.o private.o version.o
path_to_lib = /usr/local/lib
headers = getAbsolutePath.h getCurrentPath.h getHome.h isValidPath.h version.h
full_lib_name = libPath.so.`head -n 2 version.h | tail -n +2 | cut -d " " -f 3 | cut -d \" -f 2`

install: libPath.so
	mkdir -p $(path_to_lib)
	cp libPath.so $(path_to_lib)/$(full_lib_name)
	-rm -f $(path_to_lib)/libPath.so 2>/dev/null
	ln -s $(path_to_lib)/$(full_lib_name) $(path_to_lib)/libPath.so
	./update_ld.sh /etc/ld.so.conf $(path_to_lib)

libPath.so: $(objects) path.h
	gcc -shared $(objects) -fPIC -o libPath.so

path.h: $(headers) compile_headers.sh
	./compile_headers.sh $(headers) > path.h

getAbsolutePath.o: getAbsolutePath.h
	gcc -c getAbsolutePath.c -fPIC -o getAbsolutePath.o
getCurrentPath.o: getCurrentPath.h
	gcc -c getCurrentPath.c -fPIC -o getCurrentPath.o
getHome.o: getHome.h
	gcc -c getHome.c -fPIC -o getHome.o
isValidPath.o: isValidPath.h
	gcc -c isValidPath.c -fPIC -o isValidPath.o
private.o: private.h
	gcc -c private.c -fPIC -o private.o
version.o: version.h
	gcc -c version.c -fPIC -o version.o

.PHONY: clean
clean:
	-rm -f path.h *.o *.so *.gz 2>/dev/null
