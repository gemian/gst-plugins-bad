lib_LTLIBRARIES = libgstmiralloc-@GST_API_VERSION@.la

libgstmiralloc_@GST_API_VERSION@_la_SOURCES = mirallocator.c gstmircontext.c

libgstmiralloc_@GST_API_VERSION@includedir = \
	$(includedir)/gstreamer-@GST_API_VERSION@/gst/mir

libgstmiralloc_@GST_API_VERSION@include_HEADERS = mirallocator.h gstmircontext.h

libgstmiralloc_@GST_API_VERSION@_la_CFLAGS = \
	$(GST_PLUGINS_BAD_CFLAGS) \
	$(GST_CFLAGS) \
	$(MIR_CFLAGS)

libgstmiralloc_@GST_API_VERSION@_la_LIBADD = \
	-lgstvideo-@GST_API_VERSION@ \
	$(GST_BASE_LIBS) \
	$(GST_LIBS) \
	$(MIR_LIBS)
	-lmedia

libgstmiralloc_@GST_API_VERSION@_la_LDFLAGS = \
	$(GST_LIB_LDFLAGS) \
	$(GST_ALL_LDFLAGS) \
	$(GST_LT_LDFLAGS)
