/* GStreamer
 * Copyright (C) 2020 Intel Corporation
 *     Author: He Junyan <junyan.he@intel.com>
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

#ifndef __GST_MPEG2_PICTURE_H__
#define __GST_MPEG2_PICTURE_H__

#include <gst/codecs/codecs-prelude.h>
#include <gst/codecparsers/gstmpegvideoparser.h>

G_BEGIN_DECLS

#define GST_TYPE_MPEG2_PICTURE      (gst_mpeg2_picture_get_type())
#define GST_IS_MPEG2_PICTURE(obj)   (GST_IS_MINI_OBJECT_TYPE(obj, GST_TYPE_MPEG2_PICTURE))
#define GST_MPEG2_PICTURE(obj)      ((GstMpeg2Picture *)obj)
#define GST_MPEG2_PICTURE_CAST(obj) (GST_MPEG2_PICTURE(obj))

typedef struct _GstMpeg2Slice GstMpeg2Slice;

struct _GstMpeg2Slice
{
  /* The parameter set */
  GstMpegVideoQuantMatrixExt *quant_matrix;
  GstMpegVideoPictureHdr *pic_hdr;
  GstMpegVideoPictureExt *pic_ext;

  GstMpegVideoSliceHdr header;

  /* parsed video packet (doesn't take ownership of raw data) */
  GstMpegVideoPacket packet;
};

typedef struct _GstMpeg2Picture GstMpeg2Picture;

struct _GstMpeg2Picture
{
  /*< private >*/
  GstMiniObject parent;

  /* From GstVideoCodecFrame */
  guint32 system_frame_number;
  gboolean needed_for_output;
  /* For interlaced streams */
  GstMpeg2Picture *first_field;

  gint pic_order_cnt;
  gint tsn;
  GstMpegVideoPictureStructure structure;
  GstMpegVideoPictureType type;

  gpointer user_data;
  GDestroyNotify notify;
};

#define GST_MPEG2_PICTURE_IS_REF(picture) \
    (((GstMpeg2Picture *) picture)->type == GST_MPEG_VIDEO_PICTURE_TYPE_I || \
     ((GstMpeg2Picture *) picture)->type == GST_MPEG_VIDEO_PICTURE_TYPE_P)

GST_CODECS_API
GType gst_mpeg2_picture_get_type (void);

GST_CODECS_API
GstMpeg2Picture * gst_mpeg2_picture_new (void);

static inline GstMpeg2Picture *
gst_mpeg2_picture_ref (GstMpeg2Picture * picture)
{
  return (GstMpeg2Picture *) gst_mini_object_ref (GST_MINI_OBJECT_CAST (picture));
}

static inline void
gst_mpeg2_picture_unref (GstMpeg2Picture * picture)
{
  gst_mini_object_unref (GST_MINI_OBJECT_CAST (picture));
}

static inline gboolean
gst_mpeg2_picture_replace (GstMpeg2Picture ** old_picture,
    GstMpeg2Picture * new_picture)
{
  return gst_mini_object_replace ((GstMiniObject **) old_picture,
      (GstMiniObject *) new_picture);
}

static inline void
gst_mpeg2_picture_clear (GstMpeg2Picture ** picture)
{
  if (picture && *picture) {
    gst_mpeg2_picture_unref (*picture);
    *picture = NULL;
  }
}

GST_CODECS_API
void gst_mpeg2_picture_set_user_data (GstMpeg2Picture * picture,
                                      gpointer user_data,
                                      GDestroyNotify notify);

GST_CODECS_API
gpointer gst_mpeg2_picture_get_user_data (GstMpeg2Picture * picture);

typedef struct _GstMpeg2Dpb GstMpeg2Dpb;

GST_CODECS_API
GstMpeg2Dpb * gst_mpeg2_dpb_new       (void);

GST_CODECS_API
void gst_mpeg2_dpb_free               (GstMpeg2Dpb * dpb);

GST_CODECS_API
void gst_mpeg2_dpb_clear              (GstMpeg2Dpb * dpb);

GST_CODECS_API
void gst_mpeg2_dpb_add                (GstMpeg2Dpb * dpb,
                                       GstMpeg2Picture * picture);
GST_CODECS_API
GstMpeg2Picture * gst_mpeg2_dpb_bump  (GstMpeg2Dpb * dpb);

GST_CODECS_API
gboolean gst_mpeg2_dpb_need_bump      (GstMpeg2Dpb * dpb);

GST_CODECS_API
void gst_mpeg2_dpb_get_neighbours     (GstMpeg2Dpb * dpb,
                                       GstMpeg2Picture * picture,
                                       GstMpeg2Picture ** prev_picture_ptr,
                                       GstMpeg2Picture ** next_picture_ptr);

G_DEFINE_AUTOPTR_CLEANUP_FUNC(GstMpeg2Picture, gst_mpeg2_picture_unref)

G_END_DECLS

#endif /* __GST_MPEG2_PICTURE_H__ */