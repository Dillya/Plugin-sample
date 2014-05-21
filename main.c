#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "sdk.h"

int main(int argc, const char *argv[])
{
	func *plugin_func;
	void *plugin;
	char *str;

	/* Open the plugin */
	plugin = dlopen("./module.so", RTLD_LAZY);
	if(plugin == NULL)
	{
		fprintf(stderr, "Failed to load plugin!\n");
		return -1;
	}

	/* Load the function "module_func" from the plugin */
	plugin_func = dlsym(plugin, "module_func");
	if(plugin_func == NULL)
	{
		fprintf(stderr, "Failed to load plugin function!\n");
		dlclose(plugin);
		return -1;
	}

	/* Execute function */
	str = plugin_func("this is", 15);
	if(str == NULL)
	{
		fprintf(stderr, "Plugin function failed!\n");
		dlclose(plugin);
		return -1;
	}

	/* Print results */
	printf("%s\n", str);

	/* Close plugin and free string */
	dlclose(plugin);
	free(str);

	return 0;
}
