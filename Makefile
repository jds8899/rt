#
# Created by gmakemake (Ubuntu Jul 25 2014) on Sat Feb 10 13:24:07 2018
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s .S
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.S.s:
		$(CPP) -o $*.s $<
.s.o:
		$(COMPILE.cc) $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

CC =		gcc
CXX =		g++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c
CPP = $(CPP) $(CPPFLAGS)
########## Flags from header.mak

CXXFLAGS = -g -gdwarf-2 -Wall -Wextra -Weffc++ -pedantic -std=c++17
LDFLAGS = -lSDL2

########## End of flags from header.mak


CPP_FILES =	camera.cpp color.cpp geo_obj.cpp main.cpp point.cpp triangle.cpp ray.cpp sphere.cpp vector.cpp world.cpp renderer.cpp intersect.cpp phong.cpp light.cpp illumination.cpp
C_FILES =
PS_FILES =
S_FILES =
H_FILES =
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES = main.o camera.o color.o geo_obj.o point.o triangle.o ray.o sphere.o vector.o world.o renderer.o intersect.o phong.o light.o illumination.o

#
# Main targets
#

all:	main

main:	main.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o main $(OBJFILES) $(LDFLAGS)

#
# Dependencies
#

main.o: camera.h color.h geo_obj.h point.h triangle.h ray.h sphere.h vector.h world.h renderer.h light.h
camera.o: point.h vector.h world.h camera.h
geo_obj.o: color.h ray.h intersect.h illumination.h
triangle.o: color.h point.h vector.h geo_obj.h intersect.h illumination.h
ray.o: point.h vector.h
sphere.o: color.h geo_obj.h point.h vector.h intersect.h illumination.h
world.o: geo_obj.h intersect.h light.h world.h
illumination.o: illumination.h intersect.h color.h
intersect.o: intersect.h point.h vector.h light.h ray.h
light.o: light.h color.h point.h
phong.o: phong.h intersect.h color.h illumination.h

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm -f $(OBJFILES) main

realclean: clean
