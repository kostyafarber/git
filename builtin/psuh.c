#include "builtin.h"
#include "config.h"
#include "wt-status.h"
#include "commit.h"
#include "pretty.h"

int cmd_psuh(int argc, const char **argv, const char *prefix)
{
	/* Print this to stdout*/
	printf(_("This is kostya's first command yo!\n"));

	/* Print our all cmd args to stdou*/
	int i;

	printf(Q_("Your args (there is %d):\n",
		  "Your args (there are %d):\n",
		  argc),
	       argc);

	for (i = 0; i < argc; i++) {
		printf("%d: %s\n", i, argv[i]);
	}

	/* print current working directory */
	printf(_("Your current working directory: \n<top-level>%s%s\n"),
	prefix ? "/" : "", prefix ? prefix : "");

	/* print any name as defined by git config*/
	const char *cfg_name;

	git_config(git_default_config, NULL);
	if (git_config_get_string_tmp("user.name", &cfg_name) > 0) {
		printf(_("No name is found in config\n"));
	} else {
		printf(_("Your name is: %s\n"), cfg_name);
	}

	/* print current branch*/
	struct wt_status status;

	wt_status_prepare(the_repository, &status);
	git_config(git_default_config, &status);

	printf(_("Your current branch is: %s\n"), status.branch);

	struct commit *c = NULL;
	struct strbuf commitline = STRBUF_INIT;

	c = lookup_commit_reference_by_name("origin/master");

	if (c != NULL) {
		pp_commit_easy(CMIT_FMT_ONELINE, c, &commitline);
		printf(_("Current commit: %s\n"), commitline.buf);
	}
	return 0;
}
