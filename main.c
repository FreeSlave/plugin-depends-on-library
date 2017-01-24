#include <dlfcn.h>
#include <stdio.h>

void lib_func( const char* str );

int main()
{
	void* plugin = dlopen("plugins/libplugin.so", RTLD_NOW);
	if (!plugin) {
		fprintf(stderr, "%s\n", dlerror());
		return 1;
	}
	
	void (*plugin_func)(void);
	plugin_func = dlsym(plugin, "plugin_func");
	
	if (!plugin_func) {
		fprintf(stderr, "%s\n", dlerror());
		return 1;
	}
	
	plugin_func();
	dlclose(plugin);
	lib_func("I'm application");
}
