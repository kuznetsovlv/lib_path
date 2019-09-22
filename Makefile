#Makefile
install:
	cd src && make install

.PHONY: test
test: test/support
	ceedling test:test_private.c

test/support:
	mkdir -p test/support

.PHONY: clean
clean:
	cd src && make clean
