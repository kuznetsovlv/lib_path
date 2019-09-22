#include "private.h"

int isEnd(char c)
{
	return c == '/' || !c;
}

int normalizePath(char *path)
{
	char *f, *b;

	// "./" keys
	for(b = f = path; *f; ++f, ++b)
	{
		*b = *f;
		while(*f == '/' && *(f + 1) == '.' && isEnd(*(f + 2))) ++f;
	}
	*b = 0;

	// "../" key
	for(b = f = path; *f; ++f, ++b)
	{
		*b = *f;
		if (*f == '/' && *(f + 1) == '.' && *(f + 2) == '.' && isEnd(*(f + 3)))
		{
			f += 2;
			while(*b == '/')
			{
				if(--b <= path) return 0; // Out of root dirrectory
			}

			while(*b != '/') --b;
		}
	}
	*b = 0;

	// Remove dublicated "/"
	for(b = f = path; *f; ++f, ++b)
	{
		*b = *f;
		while(*f == '/' && *(f + 1) == '/') ++f;
	}
	*b = 0;

	return 1;
}
