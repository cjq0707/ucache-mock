#include <stdio.h>
#include "foo.h"
int foo(callback cb)
{
	printf("in normal foo\n");
	cb();
	return 1;
}
