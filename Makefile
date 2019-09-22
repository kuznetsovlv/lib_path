#Makefile
dir = test/support
tests = test_private test_isValidPath
install:
	cd src && make install

.PHONY: test $(tests) clean
test: $(tests)

test_private: $(dir)
	ceedling test:test_private.c

test_isValidPath: $(dir)
	ceedling test:test_isValidPath.c

test/support:
	mkdir -p test/support

clean:
	cd src && make clean
