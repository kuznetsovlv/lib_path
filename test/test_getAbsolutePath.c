#include <stdlib.h>
#include <string.h>
#include "unity.h"
#include "private.h"
#include "getAbsolutePath.h"
#include "mock_getHome.h"
#include "mock_getCurrentPath.h"

char *coppyPath(char *);

void setUp(void)
{
}

void tearDown(void)
{
}

void test_getAbsolutePath_home(void)
{
	getHome_ExpectAndReturn("/home/");

	char *path = getAbsolutePath("~/dir1/dir2/.dir3/file.test");

	TEST_ASSERT_EQUAL_STRING("/home/dir1/dir2/.dir3/file.test", path);
	free(path);
}

void test_getAbsoutePath_home_resolve_single_points(void)
{
	getHome_ExpectAndReturn("/home/");

	char *path = getAbsolutePath("~/dir1/./dir2/.dir3/file.test");
	TEST_ASSERT_EQUAL_STRING("/home/dir1/dir2/.dir3/file.test", path);
	free(path);

	getHome_ExpectAndReturn("/home/");

	path = getAbsolutePath("~/dir1/dir2/././dir3/.");
	TEST_ASSERT_EQUAL_STRING("/home/dir1/dir2/dir3/", path);
	free(path);
}

void test_getAbsolutePath_home_resolve_double_points(void)
{
	getHome_ExpectAndReturn("/home/");

	char *path = getAbsolutePath("~/dir1/dir2/../dir3/d..4/file.mem");
	TEST_ASSERT_EQUAL_STRING("/home/dir1/dir3/d..4/file.mem", path);
	free(path);

	getHome_ExpectAndReturn("/home/");

	path = getAbsolutePath("~/dir1/dir.2/..");
	TEST_ASSERT_EQUAL_STRING("/home/dir1/", path);
	free(path);

	getHome_ExpectAndReturn("/home/");

	path = getAbsolutePath("~/dir1/dir.2/../");
	TEST_ASSERT_EQUAL_STRING("/home/dir1/", path);
	free(path);

	getHome_ExpectAndReturn("/home/");

	path = getAbsolutePath("~/..");
	TEST_ASSERT_EQUAL_STRING("/", path);
	free(path);
}

void test_getAbsolutePath_home_resolve_double_slash(void)
{
	getHome_ExpectAndReturn("/home/");

	char *path = getAbsolutePath("~//");
	TEST_ASSERT_EQUAL_STRING("/home/", path);
	free(path);
}

void test_getAbsolutePath(void)
{
	getCurrentPath_ExpectAndReturn("/current/");

	char *path = getAbsolutePath("dir1/dir2/.dir3/file.test");

	TEST_ASSERT_EQUAL_STRING("/current/dir1/dir2/.dir3/file.test", path);
	free(path);
}

void test_getAbsoutePath_resolve_single_points(void)
{
	getCurrentPath_ExpectAndReturn("/current/");

	char *path = getAbsolutePath("dir1/./dir2/.dir3/file.test");
	TEST_ASSERT_EQUAL_STRING("/current/dir1/dir2/.dir3/file.test", path);
	free(path);

	getCurrentPath_ExpectAndReturn("/current/");

	path = getAbsolutePath("./dir1/dir2/.dir3/file.test");
	TEST_ASSERT_EQUAL_STRING("/current/dir1/dir2/.dir3/file.test", path);
	free(path);

	getCurrentPath_ExpectAndReturn("/current/");

	path = getAbsolutePath(".");
	TEST_ASSERT_EQUAL_STRING("/current/", path);
	free(path);

	getCurrentPath_ExpectAndReturn("/current/");

	path = getAbsolutePath("dir1/dir2/././dir3/.");
	TEST_ASSERT_EQUAL_STRING("/current/dir1/dir2/dir3/", path);
	free(path);
}

void test_getAbsolutePath_resolve_double_points(void)
{
	getCurrentPath_ExpectAndReturn("/current/");

	char *path = getAbsolutePath("dir1/dir2/../dir3/d..4/file.mem");
	TEST_ASSERT_EQUAL_STRING("/current/dir1/dir3/d..4/file.mem", path);
	free(path);

	getCurrentPath_ExpectAndReturn("/current/");

	path = getAbsolutePath("dir1/dir.2/..");
	TEST_ASSERT_EQUAL_STRING("/current/dir1/", path);
	free(path);

	getCurrentPath_ExpectAndReturn("/current/");

	path = getAbsolutePath("dir1/dir.2/../");
	TEST_ASSERT_EQUAL_STRING("/current/dir1/", path);
	free(path);

	getCurrentPath_ExpectAndReturn("/current/");

	path = getAbsolutePath("..");
	TEST_ASSERT_EQUAL_STRING("/", path);
	free(path);

	getCurrentPath_ExpectAndReturn("/current/path/");

	path = getAbsolutePath("..");
	TEST_ASSERT_EQUAL_STRING("/current/", path);
	free(path);
}

void test_getAbsolutePath_resolve_double_slash(void)
{
	getCurrentPath_ExpectAndReturn("/current/path/");

	char *path = getAbsolutePath("some//path");
	TEST_ASSERT_EQUAL_STRING("/current/path/some/path", path);
	free(path);
}

void test_getAbsolutePath_absolute(void)
{
	char *path = getAbsolutePath("/some/absolute/path");
	TEST_ASSERT_EQUAL_STRING("/some/absolute/path", path);
	free(path);

	path = getAbsolutePath("/some/./absolute/path/new/../file");
	TEST_ASSERT_EQUAL_STRING("/some/absolute/path/file", path);
	free(path);
}
