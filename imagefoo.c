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


#include <gd.h>

#include "imagefoo.h"
#include "cfg.h"

gdImagePtr ngImageCreate(int x, int y)
{
    gdImagePtr img;
    int i;
    int color_bg, color_black;
    int graph_y;
    int gray_value, color_gradient;
    int border_left, border_right, border_top, border_bottom;

    border_left = NETGRAPH_CONFIG_IMAGE_BORDER_LEFT_DEFAULT;
    border_right = NETGRAPH_CONFIG_IMAGE_BORDER_RIGHT_DEFAULT;
    border_top = NETGRAPH_CONFIG_IMAGE_BORDER_TOP_DEFAULT;
    border_bottom = NETGRAPH_CONFIG_IMAGE_BORDER_BOTTOM_DEFAULT;

    img = gdImageCreateTrueColor(x, y);
    color_bg = gdImageColorAllocate(img, 255, 255, 255);
    gdImageFill(img, 0, 0, color_bg);
    gdImageColorTransparent(img, color_bg);

    graph_y = y - border_top - border_bottom - 2;

    for(i=0; i<=graph_y; i++) {
        gray_value = (int) 225 - (200 * ((double) i/graph_y));
        color_gradient = gdImageColorAllocateAlpha(img, gray_value, gray_value, gray_value, 0);
        gdImageLine(img, border_left+1, border_top + 1 + i, x - border_right - 1, border_top + 1 + i, color_gradient);
    }

    color_black = gdImageColorAllocateAlpha(img, 0, 0, 0, 0);
    gdImageRectangle(img, border_left, border_top, x-border_right, y-border_bottom, color_black);

    return img;
}