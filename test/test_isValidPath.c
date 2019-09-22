#include "unity.h"
#include "private.h"
#include "isValidPath.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_isValidPath_absolute_valid_path(void)
{
	TEST_ASSERT_EQUAL_INT(1, isValidPath("/dir1/dir2/dir.3/file"));
}

void test_isValidPath_ref_valid_path(void)
{
	TEST_ASSERT_EQUAL_INT(1, isValidPath("dir1/dir2/dir.3/file"));
}

void test_isValidPath_home_valid_path(void)
{
	TEST_ASSERT_EQUAL_INT(1, isValidPath("~/dir1/dir2/dir.3/file"));
}

void test_isValidPath_home_in_the_middle(void)
{
	TEST_ASSERT_EQUAL_INT(0, isValidPath("/dir1/~/dir2/dir.3/file"));
}

void test_isValidPath_tilda_in_the_middle_of_filename(void)
{
	TEST_ASSERT_EQUAL_INT(1, isValidPath("/dir1/a~b/dir2/dir.3/file"));
}

void test_isValidPath_minus_in_the_path(void)
{
	TEST_ASSERT_EQUAL_INT(0, isValidPath("/dir1/-/dir2/dir.3/file"));
	TEST_ASSERT_EQUAL_INT(1, isValidPath("/dir1/a-/dir2/dir.3/file"));
}
