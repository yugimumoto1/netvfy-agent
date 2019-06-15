/*
 * NetVirt - Network Virtualization Platform
 * Copyright (C) 2009-2014
 * Nicolas J. Bouliane <admin@netvirt.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 3
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <QApplication>
#include <QStyle>

#if __APPLE__
#include <libgen.h>
#include <unistd.h>
#endif

#include "maindialog.h"

#include <event2/event.h>

#include "../agent.h"

struct event_base	*ev_base = NULL;

int main(int argc, char *argv[])
{
	#if __APPLE__
		/* On Mac OS, the current directory is /, but the
		 * config file is beside the executable.
		 */
		char *executable_path = dirname(argv[0]);
		chdir(executable_path);
	#endif

	ndb_init();
	//XXX spawned in another thread
	//ev_base = event_base_new();
	//event_base_dispatch(ev_base);

	QApplication app(argc, argv);
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	app.setStyle("fusion");

	MainDialog s;

	return app.exec();
}
