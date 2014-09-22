# Makefile for building libIDL for OS2 with GCC
# Contributor: Henry Sobotka (sobotka@axess.com)
#              Peter Weilbacher (mozilla@Weilbacher.org)
#
# Usage:  set OS2KIT=VACPP if using VisualAge; otherwise defaults to GCC
#         make install
##############################################################################
# Change PREFIX below to wherever you want to install. The paths in
# setmozenv.cmd should be changed accordinly.

PREFIX  = $(GLIBIDL2)

BINDIR  = $(PREFIX)/bin
LIBDIR  = $(PREFIX)/lib
INCDIR  = $(PREFIX)/include
INSTALL = cp
# GLib location
GLIB_INCLUDES = -I$(PREFIX)/include
GLIB_LIBPATH = $(PREFIX)/lib

REPL_PREFIX = `echo '$${GLIBIDL2}'`

# Set to 1 for a debug build
DEBUG	=

# libIDL dll version
LIBIDL_REALVER = 0.6.5
LIBIDL_LIBVER = 0.6
SHELL := bash
EMPTY :=
SPACE := $(EMPTY) $(EMPTY)

# Toolkit options
ifeq ($(OS2KIT),VACPP)

  CC      = icc
  LINK    = ILink
  FILTER  = cppfilt -q -B -P
  IMPLIB  = implib /nologo /noignorecase
  CFLAGS  = /Q /Gm /Gd /Ti+ /W2 /O3 /qlibansi /I. /DHAVE_CONFIG_H /DTCPV40HDRS /DBSD_SELECT /DXP_OS2
  DLLFLAG = /FREE /DEF /NOE /L /NOL /DLL /M /INC:_dllentry
  OS_LIBS =  so32dll.lib tcp32dll.lib
  DBCFLAG = /Ti
  DBLFLAG = /DE
  HDREXT  = vacpp
  GLIB    = v:/mozports/glib/glib-1.2.1/lib-vacpp/glib.lib
  LIBIDL  = libIDL.lib
  OBJFL	  = /Fo
  OUTFL   = /Fe
  LOUTFL  = /O:

else  # default to gcc

  CC      = gcc
  LINK    = gcc
  FILTER  = emxexp
  IMPLIB  = emximp -o
  CFLAGS  = -Zcrtdll -Wall -Zomf -s -O2 -I. -DHAVE_CONFIG_H -DXP_OS2
  DLLFLAG = -Zdll -Zmap -Zomf -Zcrtdll
  EXEFLAG = -Zmap -Zlinker /PM:VIO
  DBCFLAG = -g
  DBLFLAG = -g
  HDREXT  = gcc
  GLIB    = -lglib
  LIBIDL  = -llibIDL
  OBJFL   = -o$(SPACE)
  OUTFL   = $(OBJFL)
  LOUTFL  = $(OBJFL)
  LDFLAGS = -L$(GLIB_LIBPATH) $(LDOPT)
endif

ifeq ($(DEBUG),1)
  CFLAGS  += $(DBCFLAG)
  EXEFLAG += $(DBGFLAG)
  DLLFLAG += $(DBLFLAG)
endif

CFLAGS += -I. $(GLIB_INCLUDES) -DXP_OS2 -DYY_MAIN=0

libIDL_CSRCS = \
               parser.c \
               lexer.c  \
               ns.c     \
               util.c

libIDL_OBJECTS = $(libIDL_CSRCS:.c=.obj)

DLLS = libIDL.dll

DEF_FILE = $(DLLS:.dll=.def)

.PHONY:	clean

all:   libIDL.dll tstidl.exe


%.obj: %.c
	$(CC) $(CFLAGS) -c -DPACKAGE=\"libIDL\" -DLIBIDL_LIBRARY_VERSION=\"$(LIBIDL_REALVER)\" -DHAVE_CPP_PIPE_STDIN=1 -DCPP_PROGRAM="\"notsupported\"" -DYYTEXT_POINTER=1 -DSTDC_HEADERS=1 -DHAVE_STDDEF_H=1 -DYYDEBUG=1 -DIDL_LIBRARY -DG_LOG_DOMAIN=\"libIDL\" $< $(OBJFL)$@

libIDL.dll: $(libIDL_OBJECTS) $(DEF_FILE)
	$(LINK) $(DLLFLAG) $(LOUTFL)$@ $(libIDL_OBJECTS) $(LDFLAGS) $(GLIB) $(DEF_FILE)
	$(IMPLIB) libIDL.lib $(DEF_FILE)

tstidl.exe: libIDL.dll tstidl.obj
	$(CC) $(CFLAGS) $(OUTFL)tstidl.exe tstidl.obj $(LIBIDL) $(GLIB) $(LDFLAGS) $(EXEFLAG)

$(DEF_FILE): $(libIDL_OBJECTS)
	rm -f $@
	@cmd /C "echo LIBRARY libIDL INITINSTANCE TERMINSTANCE >$(DEF_FILE)"
	@cmd /C "echo PROTMODE >>$(DEF_FILE)"
	@cmd /C "echo CODE    LOADONCALL MOVEABLE DISCARDABLE >>$(DEF_FILE)"
	@cmd /C "echo DATA    PRELOAD MOVEABLE MULTIPLE NONSHARED >>$(DEF_FILE)"	
	@cmd /C "echo EXPORTS >>$(DEF_FILE)"
	$(FILTER) $(libIDL_OBJECTS) >> $(DEF_FILE)

install: all
	@if test ! -d $(BINDIR); then mkdir -p $(BINDIR); fi
	$(INSTALL) *.exe $(BINDIR)
	sed -e "s%@LIBIDL_LIBRARY_VERSION@%$(LIBIDL_REALVER)%g" \
	    -e "s%@prefix@%$(REPL_PREFIX)%g" \
	   libIDL-config.in > $(BINDIR)/libIDL-config
	@if test ! -d $(LIBDIR); then mkdir -p $(LIBDIR); fi
	$(INSTALL) *.lib $(LIBDIR)
	$(INSTALL) *.dll $(LIBDIR)
	@if test ! -d $(INCDIR); then mkdir -p $(INCDIR); fi
	@if test ! -d $(INCDIR)/libIDL; then mkdir -p $(INCDIR)/libIDL; fi
	$(INSTALL) IDL.h $(INCDIR)/libIDL

clean:
	rm -f *.exe *.obj *.dll *.lib *.map *.def
