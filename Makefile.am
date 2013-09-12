lib_LTLIBRARIES = libcpfig.la

libcpfig_la_SOURCES = arc.cpp arc.h arrow.cpp arrow.h attributes.cpp \
attributes.h box.cpp box.h coordinate3d.cpp coordinate3d.h coordinate.cpp \
coordinate.h diametercircle.cpp diametercircle.h diameterellipse.cpp \
diameterellipse.h ellipse.cpp ellipse.h fig.h figure.cpp figure.h \
matrix.cpp matrix.h object3dcontainer.cpp object3dcontainer.h object3d.cpp \
object3d.h object.cpp object.h polygon3d.cpp polygon3d.h polygon.cpp \
polygon.h polyline3d.cpp polyline3d.h polyline.cpp polyline.h \
radiiellipse.cpp radiiellipse.h radiuscircle.cpp radiuscircle.h \
rotation3dmatrix.cpp rotation3dmatrix.h scale3dmatrix.cpp scale3dmatrix.h \
splinecoordinate.cpp splinecoordinate.h spline.cpp spline.h text3d.cpp \
text3d.h text.cpp text.h

library_includedir=$(includedir)/cpfig

library_include_HEADERS = arc.h arrow.h attributes.h box.h coordinate3d.h \
coordinate.h diametercircle.h diameterellipse.h ellipse.h fig.h figure.h \
matrix.h object3dcontainer.h object3d.h object.h polygon3d.h polygon.h \
polyline3d.h polyline.h radiiellipse.h radiuscircle.h rotation3dmatrix.h \
scale3dmatrix.h splinecoordinate.h spline.h text3d.h text.h

EXTRA_DIST = examples doxygen.config

dist-hook:
	rm -rf `find $(distdir)/examples -name CVS`

#if MDOXYGEN
#doc:
#	doxygen doxygen.config
#endif
