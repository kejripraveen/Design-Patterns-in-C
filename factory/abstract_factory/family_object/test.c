
#include <stdio.h>
#include <stdlib.h>

#include <test_suite.h>
#include "widget.h"
#include "widget_motif_factory.h"
#include "widget_windows_factory.h"

static int test_factory_family_object(char *output, size_t sz)
{
	int ii;
	struct widget *widget1 = 0;
	struct widget_motif_factory motif;
	struct widget_windows_factory windows;

	widget_motif_factory_init(&motif);
	widget_windows_factory_init(&windows);

	for (ii=0; ii < 4; ++ii) {
		switch (ii) {
		case 0: widget1 = widget_factory_create_button(&motif.factory); break;
		case 1: widget1 = widget_factory_create_menu(&motif.factory); break;
		case 2: widget1 = widget_factory_create_button(&windows.factory); break;
		case 3: widget1 = widget_factory_create_menu(&windows.factory); break;
		}

		if (!widget1)
			return -1;
		widget_draw(widget1);
		//@TODO add virtual method 'free' to class widget
	}

	return 0;
}

void abstract_factory_family_objest_test(void);
void abstract_factory_family_objest_test(void)
{
	my_test_suite_add(test_factory_family_object, "Abstract Factory: family objects");
}
