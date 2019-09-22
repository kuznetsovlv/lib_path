#include <string.h>
#include "isValidPath.h"
#include "private.h"

int isValidPath(const char *path)
{
	int length = strlen(path);
	int i;

	for (i = 0; i < length; ++i)
	{
		switch (*(path + i))
		{
			case '/': continue;
			case '~': if(!isEnd(*(path + (++i)))) break;
			case '-': return 0;
		}
		while(!isEnd(*(path + (++i))));
	}
	return 1;
}
