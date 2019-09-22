#include "build/temp/_test_private.c"
#include "private.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_isAnd(void)

{

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((isEnd('/'))), (

((void *)0)

), (UNITY_UINT)(14), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((isEnd(0))), (

((void *)0)

), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((isEnd('a'))), (

((void *)0)

), (UNITY_UINT)(17), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((isEnd('A'))), (

((void *)0)

), (UNITY_UINT)(18), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((isEnd('.'))), (

((void *)0)

), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);

}
