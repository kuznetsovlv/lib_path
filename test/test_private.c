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

void test_isEnd(void)
{
	TEST_ASSERT_EQUAL_INT(1, isEnd('/'));
	TEST_ASSERT_EQUAL_INT(1, isEnd(0));

	TEST_ASSERT_EQUAL_INT(0, isEnd('a'));
	TEST_ASSERT_EQUAL_INT(0, isEnd('A'));
	TEST_ASSERT_EQUAL_INT(0, isEnd('.'));
}
