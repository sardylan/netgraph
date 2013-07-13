/*
 *
 * NetGraph
 * Copyright (C) 2013  Luca Cireddu (sardylan@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the
 * Free Software Foundation, Inc.
 * 51 Franklin Street, Fifth Floor
 * Boston, MA  02110-1301, USA.
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gd.h>

#include "netgraph.h"
#include "ui.h"
#include "cfg.h"
#include "imagefoo.h"

int main(int argc, char **argv)
{
    int ret;

    ret = 0;

    startup();

    if(ngCheckSystem() == 1) {
        fprintf(stderr, "OK\n");
        mainLoop();
    } else {
        fprintf(stderr, "ERROR\n");
        fprintf(stderr, "File /proc/net/dev doesn't exists!!!\n");
        ret = 1;
    }

    uiByeBye();

    return ret;
}

void startup()
{
    uiWelcome();
}

int ngCheckSystem()
{
    int ret;
    FILE *fd;

    ret = 0;

    fprintf(stderr, "Checking System... ");

    fd = fopen("/proc/net/dev", "r");

    if(fd != NULL) {
        fclose(fd);
        ret = 1;
    }

    return ret;
}

void mainLoop()
{
    gdImagePtr img;
    FILE *output;
    int img_x, img_y;

    img_x = NETGRAPH_CONFIG_IMAGE_X_DEFAULT;
    img_y = NETGRAPH_CONFIG_IMAGE_Y_DEFAULT;

    while(1) {
        printf("Loop\n");

        img = ngImageCreate(img_x, img_y);

        output = fopen(NETGRAPH_CONFIG_IMAGE_FILENAME_DEFAULT, "wb");

        gdImagePng(img, output);

        fclose(output);

        gdImageDestroy(img);

        sleep(NETGRAPH_CONFIG_REFRESH_DEFAULT);
    }
}
