#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include "getHome.h"

char *getHome()
{
	char *home = getenv("HOME");
	return home ? home : getpwuid(getuid())->pw_dir;
}
