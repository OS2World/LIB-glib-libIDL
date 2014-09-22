# Makefile for building GLib for OS/2 with GCC
# Contributor: Henry Sobotka (sobotka@axess.com)
#              Peter Weilbacher (mozilla@Weilbacher.org)
#
# Usage:  set OS2KIT=VACPP if using VisualAge; otherwise defaults to GCC
#         make install
##############################################################################
# Change PREFIX below to wherever you want to install. The paths in
# setmozenv.cmd should be changed accordinly.

PREFIX  = $(GLIBIDL2)

BINDIR	= $(PREFIX)/bin
LIBDIR	= $(PREFIX)/lib
INCDIR	= $(PREFIX)/include
INSTALL	= cp

REPL_PREFIX = `echo '$${GLIBIDL2}'`

# Set to 1 for a debug build
DEBUG	=

THREAD_LIB = -lpthread
THREAD_INC = ..\include

SHELL := bash
EMPTY :=
SPACE := $(EMPTY) $(EMPTY)

# Toolkit options
ifeq ($(OS2KIT),VACPP)

  CC      = icc
  LINK    = ILink /O:
  FILTER  = cppfilt -q -B -P
  IMPLIB  = implib /nologo /noignorecase
  CFLAGS  = /Q /Gm /Gd /O3 /W2 /qlibansi /I. /DHAVE_CONFIG_H -DTCPV40HDRS -DBSD_SELECT -DXP_OS2
  DLLFLAG = /FREE /NOE /L /NOL /DLL /INC:_dllentry
  DBCFLAG = /Ti
  DBLFLAG = /DE
  DBGFLAG = /B"/DE"
  OS_LIBS =  so32dll.lib tcp32dll.lib
  EXEFLAG = /B"/ST:0x300000"
  HDREXT  = vacpp
  GLIB    = glib.lib
  OUTFL   = /Fe
  OBJSUF  = .obj
  LIBSUF  = .lib

else  # default to gcc

  OMFLIB  = 1
  CC      = gcc
  LINK    = gcc -o$(SPACE)
  FILTER  = emxexp
  IMPLIB  = emximp -o
  CFLAGS  = -Zcrtdll -Wall -s -O2 -I. -DHAVE_CONFIG_H -DXP_OS2
  DLLFLAG = -Zdll -Zmap -Zcrtdll
  DBCFLAG = -g
  DBLFLAG = -g
  DBGFLAG = -g
  EXEFLAG = -Zmap
  HDREXT  = gcc
  GLIB    = -lglib
  OUTFL   = -o$(SPACE)
  OBJSUF  = .o
ifeq ($(OMFLIB),1)
  LIBSUF  = .lib
  CFLAGS  += -Zomf
  EXEFLAG += -Zlinker /PM:VIO -Zlinker /Stack:0x300000
  DLLFLAG += -Zomf
else
  LIBSUF  = .a
endif
endif

ifeq ($(DEBUG),1)
  CFLAGS  += $(DBCFLAG)
  EXEFLAG += $(DBGFLAG)
  DLLFLAG += $(DBLFLAG)
endif

GLIB_VER = 1.2.10

HEADERS = glibconfig.h config.h # gmodule\gmoduleconf.h

DLLS = glib.dll # gmodule.dll gthread.dll gplugina.dll gpluginb.dll

TESTS = testglib.exe testgdate.exe testgdateparser.exe # testgmodule.exe testgthread.exe

glib_CSRCS = \
             garray.c      \
             gcache.c      \
             gcompletion.c \
             gdataset.c    \
             gdate.c       \
             gerror.c      \
             ghook.c       \
             ghash.c       \
             giochannel.c  \
             giounix.c     \
             glist.c       \
             gmain.c       \
             gmem.c        \
             gmessages.c   \
             gmutex.c      \
             gnode.c       \
             gprimes.c     \
             gslist.c      \
             gtimer.c      \
             gtree.c       \
             grel.c        \
             gstring.c     \
             gstrfuncs.c   \
             gscanner.c    \
             gutils.c      \
             $(NULL)

glib_OBJECTS = $(glib_CSRCS:.c=$(OBJSUF))

gmodule_OBJECTS = gmodule$(OBJSUF)

gthread_OBJECTS = gthread$(OBJSUF)

DEF_FILE = $(DLLS:.dll=.def)

# The rules
# =========

.PHONY:	clean

all: $(HEADERS) $(DLLS) $(TESTS)

# HEADERS
# ======
glibconfig.h: glibconfig.h.$(HDREXT)
	$(INSTALL) glibconfig.h.$(HDREXT) glibconfig.h

config.h: config.h.$(HDREXT)
	$(INSTALL) config.h.$(HDREXT) config.h

#gmodule\gmoduleconf.h: gmodule\gmoduleconf.h.$(HDREXT)
#	$(INSTALL) gmodule\gmoduleconf.h.$(HDREXT) gmodule\gmoduleconf.h

# OBJECTS
# =======

%$(OBJSUF): %.c
	$(CC) -c $(CFLAGS) -DGLIB_COMPILATION -DG_LOG_DOMAIN=g_log_domain_glib $< -o $@

gmodule$(OBJSUF): gmodule\gmodule.c gmodule\gmodule-win32.c
	$(CC) $(CFLAGS) -Igmodule -c -DG_LOG_DOMAIN=g_log_domain_gmodule gmodule\gmodule.c

gthread$(OBJSUF): gthread\gthread.c gthread\gthread-nspr.c
	$(CC) $(CFLAGS) -I$(PTHREAD_INC) -DG_LOG_DOMAIN=\"GThread\" -c gthread\gthread.c

gplugina$(OBJSUF): gmodule\libgplugin_a.c
	$(CC) $(CFLAGS) -Igmodule -c gmodule\libgplugin_a.c

gpluginb$(OBJSUF): gmodule\libgplugin_b.c
	$(CC) $(CFLAGS) -Igmodule -c gmodule\libgplugin_b.c


# DLLS
# ====
glib.dll: $(glib_OBJECTS) $(DEF_FILE)
	$(LINK)$@ $(DLLFLAG) $(glib_OBJECTS) $(OS_LIBS) $(DEF_FILE)
	$(IMPLIB) glib$(LIBSUF) $(DEF_FILE)

gmodule.dll: $(gmodule_OBJECTS) $(DEF_FILE)
	$(CC) $(CFLAGS) -o gmodule.dll $(gmodule_OBJECTS) glib$(LIBSUF) $(DLLFLAG) $(LDFLAGS) $(DEF_FILE)
	$(IMPLIB) gmodule$(LIBSUF) $(DEF_FILE)

gthread.dll: $(gthread_OBJECTS) $(DEF_FILE)
	$(CC) $(CFLAGS) -o gthread.dll $(gthread_OBJECTS) glib$(LIBSUF) $(DLLFLAG) $(THREAD_LIB) $(LDFLAGS) $(DEF_FILE)
	$(IMPLIB) gthread$(LIBSUF) $(DEF_FILE)

gplugina.dll: gplugin_a$(OBJSUF) $(DEF_FILE)
	$(CC) $(CFLAGS) gplugin_a$(OBJSUF) glib$(LIBSUF) gmodule$(LIBSUF) $(DLLFLAG) $(LDFLAGS) $(DEF_FILE)
	$(IMPLIB) gplugina$(LIBSUF) $(DEF_FILE)

gpluginb.dll: gplugin_b$(OBJSUF) $(DEF_FILE)
	$(CC) $(CFLAGS) gplugin_b$(OBJSUF) glib$(LIBSUF) gmodule$(LIBSUF) $(DLLFLAG) $(LDFLAGS) $(DEF_FILE)
	$(IMPLIB) gpluginb$(LIBSUF) $(DEF_FILE)



# TESTS
# =====
testglib.exe: testglib.c glib.dll
	$(CC) $(CFLAGS) $(OUTFL)testglib.exe testglib.c $(LDFLAGS) $(EXEFLAG) $(GLIB)

testgdate.exe: testgdate.c glib.dll
	$(CC) $(CFLAGS) $(OUTFL)testgdate.exe testgdate.c $(LDFLAGS) $(EXEFLAG) $(GLIB)

testgdateparser.exe: testgdateparser.c glib.dll
	$(CC) $(CFLAGS) $(OUTFL)testgdateparser.exe testgdateparser.c $(LDFLAGS) $(EXEFLAG) $(GLIB)

testgmodule.exe: gmodule.dll gmodule\testgmodule.c gplugina.dll gpluginb.dll glib.dll
	$(CC) $(CFLAGS) $(OUTFL)testgmodule.exe gmodule\testgmodule.c glib$(LIBSUF) gmodule$(LIBSUF) $(LDFLAGS)

testgthread.exe: gthread.dll gthread\testgthread.c glib.dll
	$(CC) $(CFLAGS)  $(OUTFL)testgthread.exe gthread\testgthread.c glib$(LIBSUF) gthread$(LIBSUF) $(THREAD_LIB) $(LDFLAGS)


# .def files
$(DEF_FILE): $(glib_OBJECTS)
	rm -f $@
	@cmd /C "echo LIBRARY glib INITINSTANCE TERMINSTANCE >$(DEF_FILE)"
	@cmd /C "echo PROTMODE >>$(DEF_FILE)"
	@cmd /C "echo CODE    LOADONCALL MOVEABLE DISCARDABLE >>$(DEF_FILE)"
	@cmd /C "echo DATA    PRELOAD MOVEABLE MULTIPLE NONSHARED >>$(DEF_FILE)"	
	@cmd /C "echo EXPORTS >>$(DEF_FILE)"
	$(FILTER) $(glib_OBJECTS) >> $(DEF_FILE)

install: all
	@if test ! -d $(BINDIR); then mkdir -p $(BINDIR); fi
	$(INSTALL) *.exe $(BINDIR)
	sed -e "s%@GLIB_VERSION@%1.2.10%g" \
	    -e "s%@prefix@%$(REPL_PREFIX)%g" \
	   glib-config.in > $(BINDIR)/glib-config
	@if test ! -d $(LIBDIR); then mkdir -p $(LIBDIR); fi
	$(INSTALL) *.dll $(LIBDIR)
	$(INSTALL) *$(LIBSUF) $(LIBDIR)
	@if test ! -d $(INCDIR); then mkdir -p $(INCDIR); fi
	$(INSTALL) glib*.h $(INCDIR)

clean:
	rm -f config.h glibconfig.h
#	rm -f gmodule\gmoduleconf.h
	rm -f *.exe *$(OBJSUF) *.dll *$(LIBSUF) *.map *.def

showomf:
	@echo $(OMFLIB)
