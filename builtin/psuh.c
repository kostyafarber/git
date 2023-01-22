#include "builtin.h"
#include "config.h"

int cmd_psuh(int argc, const char **argv, const char *prefix)
{
	printf(_("This is kostya's first command yo!\n"));

	int i;

	printf(Q_("Your args (there is %d):\n",
		  "Your args (there are %d):\n",
		  argc),
	       argc);

	for (i = 0; i < argc; i++) {
		printf("%d: %s\n", i, argv[i]);
	}

	printf(_("Your current working directory: \n<top-level>%s%s\n"),
	prefix ? "/" : "", prefix ? prefix : "");

	const char *cfg_name;

	git_config(git_default_config, NULL);
	if (git_config_get_string_tmp("user.name", &cfg_name) > 0) {
		printf(_("No name is found in config\n"));
	} else {
		printf(_("Your name is: %s\n"), cfg_name);
	}
	return 0;
}
