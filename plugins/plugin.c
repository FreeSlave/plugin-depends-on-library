#include <stdio.h>

void lib_func( const char* str );

void plugin_func(void)
{
	lib_func("I'm plugin");
}
