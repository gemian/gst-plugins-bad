/* GStreamer openaptx audio plugin
 *
 * Copyright (C) 2020 Igor V. Kovalenko <igor.v.kovalenko@gmail.com>
 * Copyright (C) 2020 Thomas Weißschuh <thomas@t-8ch.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "openaptx-plugin.h"
#include "gstopenaptxdec.h"
#include "gstopenaptxenc.h"

static gboolean
plugin_init (GstPlugin * plugin)
{
  gst_element_register (plugin, "openaptxdec", GST_RANK_NONE,
      GST_TYPE_OPENAPTX_DEC);
  gst_element_register (plugin, "openaptxenc", GST_RANK_NONE,
      GST_TYPE_OPENAPTX_ENC);
  return TRUE;
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    openaptx,
    "Open Source implementation of Audio Processing Technology codec (aptX)",
    plugin_init, VERSION, GST_LICENSE, GST_PACKAGE_NAME, GST_PACKAGE_ORIGIN);
