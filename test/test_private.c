#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "private.h"

char *coppyPath(char *);

void setUp(void)
{
}

void tearDown(void)
{
}

void test_isAnd(void)
{
	TEST_ASSERT_EQUAL_INT(1, isEnd('/'));
	TEST_ASSERT_EQUAL_INT(1, isEnd(0));

	TEST_ASSERT_EQUAL_INT(0, isEnd('a'));
	TEST_ASSERT_EQUAL_INT(0, isEnd('A'));
	TEST_ASSERT_EQUAL_INT(0, isEnd('.'));
}

void test_normalizePath_resolve_single_points(void)
{
	char *path = coppyPath("/dir1/./dir2/.dir3/file.test");

	TEST_ASSERT_EQUAL_INT(1, normalizePath(path));
	TEST_ASSERT_EQUAL_STRING("/dir1/dir2/.dir3/file.test", path);
	free(path);

	path = coppyPath("/dir1/dir2/././dir3/.");
	TEST_ASSERT_EQUAL_INT(1, normalizePath(path));
	TEST_ASSERT_EQUAL_STRING("/dir1/dir2/dir3/", path);
	free(path);
}

void test_normalizePath_resolve_double_points(void)
{
	char *path = coppyPath("/dir1/dir2/../dir3/d..4/file.mem");

	TEST_ASSERT_EQUAL_INT(1, normalizePath(path));
	TEST_ASSERT_EQUAL_STRING("/dir1/dir3/d..4/file.mem", path);
	free(path);

	path = coppyPath("/dir1/dir.2/..");

	TEST_ASSERT_EQUAL_INT(1, normalizePath(path));
	TEST_ASSERT_EQUAL_STRING("/dir1/", path);
	free(path);

	path = coppyPath("/dir1/dir.2/../");

	TEST_ASSERT_EQUAL_INT(1, normalizePath(path));
	TEST_ASSERT_EQUAL_STRING("/dir1/", path);
	free(path);

	path = coppyPath("/dir1/dir.2/../..");

	TEST_ASSERT_EQUAL_INT(1, normalizePath(path));
	TEST_ASSERT_EQUAL_STRING("/", path);
	free(path);

	path = coppyPath("/dir1/dir.2/../../..");

	TEST_ASSERT_EQUAL_INT(0, normalizePath(path));
	free(path);

	path = coppyPath("/dir1/dir.2/../../../dir3");

	TEST_ASSERT_EQUAL_INT(0, normalizePath(path));
	free(path);

	path = coppyPath("/..");

	TEST_ASSERT_EQUAL_INT(0, normalizePath(path));
	free(path);

	path = coppyPath("/../");

	TEST_ASSERT_EQUAL_INT(0, normalizePath(path));
	free(path);

	path = coppyPath("/dir1/dir2////dir3/dir4//dir5/dir6///");

	TEST_ASSERT_EQUAL_INT(1, normalizePath(path));
	TEST_ASSERT_EQUAL_STRING("/dir1/dir2/dir3/dir4/dir5/dir6/", path);
	free(path);

	path = coppyPath("/dir1/dir2////dir3/dir4//dir5/dir6///file");

	TEST_ASSERT_EQUAL_INT(1, normalizePath(path));
	TEST_ASSERT_EQUAL_STRING("/dir1/dir2/dir3/dir4/dir5/dir6/file", path);
	free(path);
}

void test_normalizePath_resolve_double_slash(void)
{
	char *path = coppyPath("//");

	TEST_ASSERT_EQUAL_INT(1, normalizePath(path));
	TEST_ASSERT_EQUAL_STRING("/", path);
	free(path);
}

char *coppyPath(char *path)
{
	char *result = malloc(sizeof(char) * (strlen(path) + 1));
	strcpy(result, path);
	return result;
}
