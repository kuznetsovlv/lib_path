#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "private.h"
#include "getHome.h"
#include "getCurrentPath.h"

char *getAbsolutePath(const char *path)
{
	char *result;

	if(*path == '~' && isEnd(*(path + 1)))
	{
		char *home = getHome();
		result = malloc(sizeof(char) * (strlen(home) + strlen(path)));

		if(!result)
			return NULL;

		strcpy(result, home);
		strcat(result, path + 1);
	}
	else if(*path != '/')
	{
		char *current = getCurrentPath();
		result = malloc(sizeof(char) * (strlen(current) + strlen(path) + 2));

		if(!result)
			return NULL;

		strcpy(result, current);
		strcat(result, "/");
		strcat(result, path);
	}

	if (!normalizePath(result))
	{
		fprintf(stderr, "The resulting path of %s is out of root dirrectory.\n", path);
		exit(-1);
	}
	return result;
}
