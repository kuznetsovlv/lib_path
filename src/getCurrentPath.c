#define _GNU_SOURCE
#include <unistd.h>
#include "getCurrentPath.h"

char *getCurrentPath()
{
	return get_current_dir_name();
}
