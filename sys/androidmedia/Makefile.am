plugin_LTLIBRARIES = libgstandroidmedia.la

if USE_ANDROID_MEDIA_HYBRIS
 libgstandroidmedia_la_SOURCES = \
	gstamchybris.c \
	gstamcaudiodechybris.c \
	gstamcvideodechybris.c
else
 libgstandroidmedia_la_SOURCES = \
	gstahcsrc.c \
	gstahssrc.c \
	gstamcaudiodec.c \
	gstamc.c \
	gstamcsurface.c \
	gstamcsurfacetexture.c \
	gstamcvideodec.c \
	gstamcvideoenc.c \
	gst-android-graphics-imageformat.c \
	gst-android-hardware-camera.c \
	gst-android-hardware-sensor.c \
	gstjniutils.c
endif

noinst_HEADERS = \
	gstahcsrc.h \
	gstahssrc.h \
	gstamcaudiodec.h \
	gstamc-constants.h \
	gstamc.h \
	gstamcsurface.h \
	gstamcsurfacetexture.h \
	gstamcvideodec.h \
	gstamcvideoenc.h \
	gst-android-graphics-imageformat.h \
	gst-android-hardware-camera.h \
	gst-android-hardware-sensor.h \
	gstjniutils.h \
	gstsensors.h

libgstandroidmedia_la_CFLAGS = \
	$(GST_PLUGINS_BAD_CFLAGS) \
	$(GST_PLUGINS_BASE_CFLAGS) \
	$(GST_GL_CFLAGS) \
	$(GST_BASE_CFLAGS) \
	$(GST_CFLAGS) \
	$(UBUNTU_PLATFORM_CFLAGS) \
	$(ORC_CFLAGS) \
	-DGST_USE_UNSTABLE_API

libgstandroidmedia_la_LIBADD = \
	$(GST_PLUGINS_BASE_LIBS) \
	$(GST_PLUGIN_BAD_LIBS) \
	-lgstvideo-@GST_API_VERSION@ \
	-lgstaudio-@GST_API_VERSION@ \
	-lgstpbutils-@GST_API_VERSION@ \
	-lmedia \
	$(GST_GL_LIBS) \
	$(GST_BASE_LIBS) \
	$(GST_LIBS) \
	$(ORC_LIBS) \
	$(top_builddir)/gst-libs/gst/mir/libgstmiralloc-@GST_API_VERSION@.la
libgstandroidmedia_la_LDFLAGS = \
	$(GST_PLUGIN_LDFLAGS) \
	$(GST_BASE_LDFLAGS) \
	$(GST_PLUGINS_BASE_LDFLAGS)

if USE_ANDROID_MEDIA
androidmedia_java_classesdir = $(datadir)/gst-android/ndk-build/androidmedia/
androidmedia_java_classes_DATA = \
	org/freedesktop/gstreamer/androidmedia/GstAhcCallback.java \
	org/freedesktop/gstreamer/androidmedia/GstAhsCallback.java \
	org/freedesktop/gstreamer/androidmedia/GstAmcOnFrameAvailableListener.java
endif

# Make sure the .java files end up in the tarball
EXTRA_DIST = $(androidmedia_java_classes_DATA)
