#Makefile
dir = test/support
tests = test_private test_isValidPath test_getAbsolutePath test_normalizePath
install:
	cd src && make install

.PHONY: test $(tests) clean
test: $(tests)

test_private: $(dir)
	ceedling test:test_private.c

test_isValidPath: $(dir)
	ceedling test:test_isValidPath.c

test_getAbsolutePath: $(dir)
	ceedling test:test_getAbsolutePath.c

test_normalizePath: $(dir)
	ceedling test:test_normalizePath.c

test/support:
	mkdir -p $(dir)

clean:
	cd src && make clean
