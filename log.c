/**
 * Ext2read
 * File: log.c
 **/
/**
 * Copyright (C) 2005 by Manish Regmi   (regmi dot manish at gmail.com)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the
 * Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 **/

#include <stdio.h>
#include <stdarg.h>

static FILE *logfile = 0;
static char buff[4096];

int log_init()
{
    logfile = fopen("ext2explorelog.log", "w+");
    if(!logfile)
        return -1;
    return 0;
}

int ext2explore_log(const char *msg, ...)
{
    va_list ap;

    va_start(ap, msg);
    vsnprintf(buff, 4096, msg, ap);
    va_end(ap);

    fprintf(logfile, "%s", buff);
    fflush(logfile);
    return 0;
}

void log_exit()
{
    fclose(logfile);
}
