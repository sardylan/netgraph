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

gdImagePtr ngImageCreate(int x, int y)
{
    gdImagePtr ret;
    int color_bg;
    int color_white;

    ret = gdImageCreateTrueColor(x, y);
    color_bg = gdImageColorAllocate(ret, 0, 0, 0);
    gdImageColorTransparent(ret, color_bg);

    color_white = gdImageColorAllocateAlpha(img, 255, 255, 255, 64);

    gdImageFilledRectangle(img, 30, 10, img_x - (30+10), img_y - (10+10), color_white);

    return ret;
}