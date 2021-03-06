#define YY_parse_h_included

/*  A Bison++ parser, made from parser.y  */

 /* with Bison++ version bison++ Version 1.21-8, adapted from GNU bison by coetmeur@icdc.fr
  */


#line 1 "/emx/lib/bison.cc"
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* HEADER SECTION */
#if defined(SVR4)
#if defined(__cplusplus)
extern "C" {
void * alloca (unsigned int);       /* alloca.o ausgekoppelt aus flex++ */
};
#else
void * alloca (unsigned int);       /* alloca.o ausgekoppelt aus flex++ */
#endif
#endif

#if defined( _MSDOS ) || defined(MSDOS) || defined(__MSDOS__) 
#define __MSDOS_AND_ALIKE
#endif
#if defined(_WINDOWS) && defined(_MSC_VER)
#define __HAVE_NO_ALLOCA
#define __MSDOS_AND_ALIKE
#endif

#ifndef alloca
#if defined( __GNUC__)
#define alloca __builtin_alloca

#elif (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc)  || defined (__sgi) || defined (sun4)
#include <alloca.h>

#elif defined (__MSDOS_AND_ALIKE)
#include <malloc.h>
#ifndef __TURBOC__
/* MS C runtime lib */
#define alloca _alloca
#endif

#elif defined(_AIX)
#include <malloc.h>
#pragma alloca

#elif defined(__hpux)
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */

#endif /* not _AIX  not MSDOS, or __TURBOC__ or _AIX, not sparc.  */
#endif /* alloca not defined.  */
#ifdef c_plusplus
#ifndef __cplusplus
#define __cplusplus
#endif
#endif
#ifdef __cplusplus
#ifndef YY_USE_CLASS
#define YY_USE_CLASS
#endif
#else
#ifndef __STDC__
#define const
#endif
#endif
#include <stdio.h>
#include <malloc.h>   /* for error message handling in 'YY_parse_ERROR_VERBOSE' */
#define YYBISON 1  

/* #line 84 "/emx/lib/bison.cc" */
#line 96 "y.tab.c"
#line 24 "parser.y"

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include "rename.h"
#include "util.h"

#define do_binop(rv,op,a,b)		do {		\
	if (IDL_binop_chktypes (op, a, b))		\
		YYABORT;				\
	if (!(__IDL_flags & IDLF_NO_EVAL_CONST)) {	\
		rv = IDL_binop_eval (op, a, b);		\
		IDL_tree_free (a);			\
		IDL_tree_free (b);			\
		if (!rv) YYABORT;			\
	} else {					\
		rv = IDL_binop_new (op, a, b);		\
	}						\
} while (0)

#define do_unaryop(rv,op,a)		do {		\
	if (IDL_unaryop_chktypes (op, a))		\
		YYABORT;				\
	if (!(__IDL_flags & IDLF_NO_EVAL_CONST)) {	\
		rv = IDL_unaryop_eval (op, a);		\
		IDL_tree_free (a);			\
		if (!rv) YYABORT;			\
	} else {					\
		rv = IDL_unaryop_new (op, a);		\
	}						\
} while (0)

#define assign_props(tree,props)	do {		\
	if (__IDL_flags & IDLF_PROPERTIES)		\
		IDL_NODE_PROPERTIES (tree) = (props);	\
	else						\
		__IDL_free_properties (props);		\
} while (0)

extern int		yylex				(void);
static IDL_declspec_t	IDL_parse_declspec		(const char *strspec);
static int		IDL_binop_chktypes		(enum IDL_binop op,
							 IDL_tree a,
							 IDL_tree b);
static int		IDL_unaryop_chktypes		(enum IDL_unaryop op,
							 IDL_tree a);
static IDL_tree		IDL_binop_eval			(enum IDL_binop op,
							 IDL_tree a,
							 IDL_tree b);
static IDL_tree		IDL_unaryop_eval		(enum IDL_unaryop op,
							 IDL_tree a);
static IDL_tree		list_start			(IDL_tree a,
							 gboolean filter_null);
static IDL_tree		list_chain			(IDL_tree a,
							 IDL_tree b,
							 gboolean filter_null);
static IDL_tree		zlist_chain			(IDL_tree a,
							 IDL_tree b,
							 gboolean filter_null);
static int		do_token_error			(IDL_tree p,
							 const char *message,
							 gboolean prev);
static void		illegal_context_type_error	(IDL_tree p,
							 const char *what);
static void		illegal_type_error		(IDL_tree p,
							 const char *message);

#line 96 "parser.y"
typedef union {
	IDL_tree tree;
	struct {
		IDL_tree tree;
		gpointer data;
	} treedata;
	GHashTable *hash_table;
	char *str;
	gboolean boolean;
	IDL_declspec_t declspec;
	IDL_longlong_t integer;
	double floatp;
	enum IDL_unaryop unaryop;
	enum IDL_param_attr paramattr;
} yy_parse_stype;
#define YY_parse_STYPE yy_parse_stype

#line 84 "/emx/lib/bison.cc"
/* %{ and %header{ and %union, during decl */
#define YY_parse_BISON 1
#ifndef YY_parse_COMPATIBILITY
#ifndef YY_USE_CLASS
#define  YY_parse_COMPATIBILITY 1
#else
#define  YY_parse_COMPATIBILITY 0
#endif
#endif

#if YY_parse_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YYLTYPE
#ifndef YY_parse_LTYPE
#define YY_parse_LTYPE YYLTYPE
#endif
#endif
#ifdef YYSTYPE
#ifndef YY_parse_STYPE 
#define YY_parse_STYPE YYSTYPE
#endif
#endif
#ifdef YYDEBUG
#ifndef YY_parse_DEBUG
#define  YY_parse_DEBUG YYDEBUG
#endif
#endif
#ifdef YY_parse_STYPE
#ifndef yystype
#define yystype YY_parse_STYPE
#endif
#endif
/* use goto to be compatible */
#ifndef YY_parse_USE_GOTO
#define YY_parse_USE_GOTO 1
#endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_parse_USE_GOTO
#define YY_parse_USE_GOTO 0
#endif

#ifndef YY_parse_PURE

/* #line 128 "/emx/lib/bison.cc" */
#line 234 "y.tab.c"

#line 128 "/emx/lib/bison.cc"
/*  YY_parse_PURE */
#endif

/* section apres lecture def, avant lecture grammaire S2 */

/* #line 132 "/emx/lib/bison.cc" */
#line 243 "y.tab.c"

#line 132 "/emx/lib/bison.cc"
/* prefix */
#ifndef YY_parse_DEBUG

/* #line 134 "/emx/lib/bison.cc" */
#line 250 "y.tab.c"

#line 134 "/emx/lib/bison.cc"
/* YY_parse_DEBUG */
#endif


#ifndef YY_parse_LSP_NEEDED

/* #line 139 "/emx/lib/bison.cc" */
#line 260 "y.tab.c"

#line 139 "/emx/lib/bison.cc"
 /* YY_parse_LSP_NEEDED*/
#endif



/* DEFAULT LTYPE*/
#ifdef YY_parse_LSP_NEEDED
#ifndef YY_parse_LTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YY_parse_LTYPE yyltype
#endif
#endif
/* DEFAULT STYPE*/
      /* We used to use `unsigned long' as YY_parse_STYPE on MSDOS,
	 but it seems better to be consistent.
	 Most programs should declare their own type anyway.  */

#ifndef YY_parse_STYPE
#define YY_parse_STYPE int
#endif
/* DEFAULT MISCELANEOUS */
#ifndef YY_parse_PARSE
#define YY_parse_PARSE yyparse
#endif
#ifndef YY_parse_LEX
#define YY_parse_LEX yylex
#endif
#ifndef YY_parse_LVAL
#define YY_parse_LVAL yylval
#endif
#ifndef YY_parse_LLOC
#define YY_parse_LLOC yylloc
#endif
#ifndef YY_parse_CHAR
#define YY_parse_CHAR yychar
#endif
#ifndef YY_parse_NERRS
#define YY_parse_NERRS yynerrs
#endif
#ifndef YY_parse_DEBUG_FLAG
#define YY_parse_DEBUG_FLAG yydebug
#endif
#ifndef YY_parse_ERROR
#define YY_parse_ERROR yyerror
#endif
#ifndef YY_parse_PARSE_PARAM
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
#define YY_parse_PARSE_PARAM
#ifndef YY_parse_PARSE_PARAM_DEF
#define YY_parse_PARSE_PARAM_DEF
#endif
#endif
#endif
#endif
#ifndef YY_parse_PARSE_PARAM
#define YY_parse_PARSE_PARAM void
#endif
#endif
#if YY_parse_COMPATIBILITY != 0
/* backward compatibility */
#ifdef YY_parse_LTYPE
#ifndef YYLTYPE
#define YYLTYPE YY_parse_LTYPE
#else
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
#endif
#endif
#ifndef YYSTYPE
#define YYSTYPE YY_parse_STYPE
#else
/* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
#endif
#ifdef YY_parse_PURE
#ifndef YYPURE
#define YYPURE YY_parse_PURE
#endif
#endif
#ifdef YY_parse_DEBUG
#ifndef YYDEBUG
#define YYDEBUG YY_parse_DEBUG 
#endif
#endif
#ifndef YY_parse_ERROR_VERBOSE
#ifdef YYERROR_VERBOSE
#define YY_parse_ERROR_VERBOSE YYERROR_VERBOSE
#endif
#endif
#ifndef YY_parse_LSP_NEEDED
#ifdef YYLSP_NEEDED
#define YY_parse_LSP_NEEDED YYLSP_NEEDED
#endif
#endif
#endif
#ifndef YY_USE_CLASS
/* TOKEN C */

/* #line 247 "/emx/lib/bison.cc" */
#line 373 "y.tab.c"
#define	TOK_ANY	258
#define	TOK_ATTRIBUTE	259
#define	TOK_BOOLEAN	260
#define	TOK_CASE	261
#define	TOK_CHAR	262
#define	TOK_CONST	263
#define	TOK_CONTEXT	264
#define	TOK_DEFAULT	265
#define	TOK_DOUBLE	266
#define	TOK_ENUM	267
#define	TOK_EXCEPTION	268
#define	TOK_FALSE	269
#define	TOK_FIXED	270
#define	TOK_FLOAT	271
#define	TOK_IN	272
#define	TOK_INOUT	273
#define	TOK_INTERFACE	274
#define	TOK_LONG	275
#define	TOK_MODULE	276
#define	TOK_NATIVE	277
#define	TOK_NOSCRIPT	278
#define	TOK_OBJECT	279
#define	TOK_OCTET	280
#define	TOK_ONEWAY	281
#define	TOK_OP_SCOPE	282
#define	TOK_OP_SHL	283
#define	TOK_OP_SHR	284
#define	TOK_OUT	285
#define	TOK_RAISES	286
#define	TOK_READONLY	287
#define	TOK_SEQUENCE	288
#define	TOK_SHORT	289
#define	TOK_STRING	290
#define	TOK_STRUCT	291
#define	TOK_SWITCH	292
#define	TOK_TRUE	293
#define	TOK_TYPECODE	294
#define	TOK_TYPEDEF	295
#define	TOK_UNION	296
#define	TOK_UNSIGNED	297
#define	TOK_VARARGS	298
#define	TOK_VOID	299
#define	TOK_WCHAR	300
#define	TOK_WSTRING	301
#define	TOK_FLOATP	302
#define	TOK_INTEGER	303
#define	TOK_DECLSPEC	304
#define	TOK_PROP_KEY	305
#define	TOK_PROP_VALUE	306
#define	TOK_NATIVE_TYPE	307
#define	TOK_IDENT	308
#define	TOK_SQSTRING	309
#define	TOK_DQSTRING	310
#define	TOK_FIXEDP	311
#define	TOK_CODEFRAG	312


#line 247 "/emx/lib/bison.cc"
 /* #defines tokens */
#else
/* CLASS */
#ifndef YY_parse_CLASS
#define YY_parse_CLASS parse
#endif
#ifndef YY_parse_INHERIT
#define YY_parse_INHERIT
#endif
#ifndef YY_parse_MEMBERS
#define YY_parse_MEMBERS 
#endif
#ifndef YY_parse_LEX_BODY
#define YY_parse_LEX_BODY  
#endif
#ifndef YY_parse_ERROR_BODY
#define YY_parse_ERROR_BODY  
#endif
#ifndef YY_parse_CONSTRUCTOR_PARAM
#define YY_parse_CONSTRUCTOR_PARAM
#endif
#ifndef YY_parse_CONSTRUCTOR_CODE
#define YY_parse_CONSTRUCTOR_CODE
#endif
#ifndef YY_parse_CONSTRUCTOR_INIT
#define YY_parse_CONSTRUCTOR_INIT
#endif
/* choose between enum and const */
#ifndef YY_parse_USE_CONST_TOKEN
#define YY_parse_USE_CONST_TOKEN 0
/* yes enum is more compatible with flex,  */
/* so by default we use it */ 
#endif
#if YY_parse_USE_CONST_TOKEN != 0
#ifndef YY_parse_ENUM_TOKEN
#define YY_parse_ENUM_TOKEN yy_parse_enum_token
#endif
#endif

class YY_parse_CLASS YY_parse_INHERIT
{
public: 
#if YY_parse_USE_CONST_TOKEN != 0
/* static const int token ... */

/* #line 291 "/emx/lib/bison.cc" */
#line 478 "y.tab.c"
static const int TOK_ANY;
static const int TOK_ATTRIBUTE;
static const int TOK_BOOLEAN;
static const int TOK_CASE;
static const int TOK_CHAR;
static const int TOK_CONST;
static const int TOK_CONTEXT;
static const int TOK_DEFAULT;
static const int TOK_DOUBLE;
static const int TOK_ENUM;
static const int TOK_EXCEPTION;
static const int TOK_FALSE;
static const int TOK_FIXED;
static const int TOK_FLOAT;
static const int TOK_IN;
static const int TOK_INOUT;
static const int TOK_INTERFACE;
static const int TOK_LONG;
static const int TOK_MODULE;
static const int TOK_NATIVE;
static const int TOK_NOSCRIPT;
static const int TOK_OBJECT;
static const int TOK_OCTET;
static const int TOK_ONEWAY;
static const int TOK_OP_SCOPE;
static const int TOK_OP_SHL;
static const int TOK_OP_SHR;
static const int TOK_OUT;
static const int TOK_RAISES;
static const int TOK_READONLY;
static const int TOK_SEQUENCE;
static const int TOK_SHORT;
static const int TOK_STRING;
static const int TOK_STRUCT;
static const int TOK_SWITCH;
static const int TOK_TRUE;
static const int TOK_TYPECODE;
static const int TOK_TYPEDEF;
static const int TOK_UNION;
static const int TOK_UNSIGNED;
static const int TOK_VARARGS;
static const int TOK_VOID;
static const int TOK_WCHAR;
static const int TOK_WSTRING;
static const int TOK_FLOATP;
static const int TOK_INTEGER;
static const int TOK_DECLSPEC;
static const int TOK_PROP_KEY;
static const int TOK_PROP_VALUE;
static const int TOK_NATIVE_TYPE;
static const int TOK_IDENT;
static const int TOK_SQSTRING;
static const int TOK_DQSTRING;
static const int TOK_FIXEDP;
static const int TOK_CODEFRAG;


#line 291 "/emx/lib/bison.cc"
 /* decl const */
#else
enum YY_parse_ENUM_TOKEN { YY_parse_NULL_TOKEN=0

/* #line 294 "/emx/lib/bison.cc" */
#line 542 "y.tab.c"
	,TOK_ANY=258
	,TOK_ATTRIBUTE=259
	,TOK_BOOLEAN=260
	,TOK_CASE=261
	,TOK_CHAR=262
	,TOK_CONST=263
	,TOK_CONTEXT=264
	,TOK_DEFAULT=265
	,TOK_DOUBLE=266
	,TOK_ENUM=267
	,TOK_EXCEPTION=268
	,TOK_FALSE=269
	,TOK_FIXED=270
	,TOK_FLOAT=271
	,TOK_IN=272
	,TOK_INOUT=273
	,TOK_INTERFACE=274
	,TOK_LONG=275
	,TOK_MODULE=276
	,TOK_NATIVE=277
	,TOK_NOSCRIPT=278
	,TOK_OBJECT=279
	,TOK_OCTET=280
	,TOK_ONEWAY=281
	,TOK_OP_SCOPE=282
	,TOK_OP_SHL=283
	,TOK_OP_SHR=284
	,TOK_OUT=285
	,TOK_RAISES=286
	,TOK_READONLY=287
	,TOK_SEQUENCE=288
	,TOK_SHORT=289
	,TOK_STRING=290
	,TOK_STRUCT=291
	,TOK_SWITCH=292
	,TOK_TRUE=293
	,TOK_TYPECODE=294
	,TOK_TYPEDEF=295
	,TOK_UNION=296
	,TOK_UNSIGNED=297
	,TOK_VARARGS=298
	,TOK_VOID=299
	,TOK_WCHAR=300
	,TOK_WSTRING=301
	,TOK_FLOATP=302
	,TOK_INTEGER=303
	,TOK_DECLSPEC=304
	,TOK_PROP_KEY=305
	,TOK_PROP_VALUE=306
	,TOK_NATIVE_TYPE=307
	,TOK_IDENT=308
	,TOK_SQSTRING=309
	,TOK_DQSTRING=310
	,TOK_FIXEDP=311
	,TOK_CODEFRAG=312


#line 294 "/emx/lib/bison.cc"
 /* enum token */
     }; /* end of enum declaration */
#endif
public:
 int YY_parse_PARSE (YY_parse_PARSE_PARAM);
 virtual void YY_parse_ERROR(const char *msg) YY_parse_ERROR_BODY;
#ifdef YY_parse_PURE
#ifdef YY_parse_LSP_NEEDED
 virtual int  YY_parse_LEX (YY_parse_STYPE *YY_parse_LVAL,YY_parse_LTYPE *YY_parse_LLOC) YY_parse_LEX_BODY;
#else
 virtual int  YY_parse_LEX (YY_parse_STYPE *YY_parse_LVAL) YY_parse_LEX_BODY;
#endif
#else
 virtual int YY_parse_LEX() YY_parse_LEX_BODY;
 YY_parse_STYPE YY_parse_LVAL;
#ifdef YY_parse_LSP_NEEDED
 YY_parse_LTYPE YY_parse_LLOC;
#endif
 int   YY_parse_NERRS;
 int    YY_parse_CHAR;
#endif
#if YY_parse_DEBUG != 0
 int YY_parse_DEBUG_FLAG;   /*  nonzero means print parse trace     */
#endif
public:
 YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM);
public:
 YY_parse_MEMBERS 
};
/* other declare folow */
#if YY_parse_USE_CONST_TOKEN != 0

/* #line 325 "/emx/lib/bison.cc" */
#line 634 "y.tab.c"
const int YY_parse_CLASS::TOK_ANY=258;
const int YY_parse_CLASS::TOK_ATTRIBUTE=259;
const int YY_parse_CLASS::TOK_BOOLEAN=260;
const int YY_parse_CLASS::TOK_CASE=261;
const int YY_parse_CLASS::TOK_CHAR=262;
const int YY_parse_CLASS::TOK_CONST=263;
const int YY_parse_CLASS::TOK_CONTEXT=264;
const int YY_parse_CLASS::TOK_DEFAULT=265;
const int YY_parse_CLASS::TOK_DOUBLE=266;
const int YY_parse_CLASS::TOK_ENUM=267;
const int YY_parse_CLASS::TOK_EXCEPTION=268;
const int YY_parse_CLASS::TOK_FALSE=269;
const int YY_parse_CLASS::TOK_FIXED=270;
const int YY_parse_CLASS::TOK_FLOAT=271;
const int YY_parse_CLASS::TOK_IN=272;
const int YY_parse_CLASS::TOK_INOUT=273;
const int YY_parse_CLASS::TOK_INTERFACE=274;
const int YY_parse_CLASS::TOK_LONG=275;
const int YY_parse_CLASS::TOK_MODULE=276;
const int YY_parse_CLASS::TOK_NATIVE=277;
const int YY_parse_CLASS::TOK_NOSCRIPT=278;
const int YY_parse_CLASS::TOK_OBJECT=279;
const int YY_parse_CLASS::TOK_OCTET=280;
const int YY_parse_CLASS::TOK_ONEWAY=281;
const int YY_parse_CLASS::TOK_OP_SCOPE=282;
const int YY_parse_CLASS::TOK_OP_SHL=283;
const int YY_parse_CLASS::TOK_OP_SHR=284;
const int YY_parse_CLASS::TOK_OUT=285;
const int YY_parse_CLASS::TOK_RAISES=286;
const int YY_parse_CLASS::TOK_READONLY=287;
const int YY_parse_CLASS::TOK_SEQUENCE=288;
const int YY_parse_CLASS::TOK_SHORT=289;
const int YY_parse_CLASS::TOK_STRING=290;
const int YY_parse_CLASS::TOK_STRUCT=291;
const int YY_parse_CLASS::TOK_SWITCH=292;
const int YY_parse_CLASS::TOK_TRUE=293;
const int YY_parse_CLASS::TOK_TYPECODE=294;
const int YY_parse_CLASS::TOK_TYPEDEF=295;
const int YY_parse_CLASS::TOK_UNION=296;
const int YY_parse_CLASS::TOK_UNSIGNED=297;
const int YY_parse_CLASS::TOK_VARARGS=298;
const int YY_parse_CLASS::TOK_VOID=299;
const int YY_parse_CLASS::TOK_WCHAR=300;
const int YY_parse_CLASS::TOK_WSTRING=301;
const int YY_parse_CLASS::TOK_FLOATP=302;
const int YY_parse_CLASS::TOK_INTEGER=303;
const int YY_parse_CLASS::TOK_DECLSPEC=304;
const int YY_parse_CLASS::TOK_PROP_KEY=305;
const int YY_parse_CLASS::TOK_PROP_VALUE=306;
const int YY_parse_CLASS::TOK_NATIVE_TYPE=307;
const int YY_parse_CLASS::TOK_IDENT=308;
const int YY_parse_CLASS::TOK_SQSTRING=309;
const int YY_parse_CLASS::TOK_DQSTRING=310;
const int YY_parse_CLASS::TOK_FIXEDP=311;
const int YY_parse_CLASS::TOK_CODEFRAG=312;


#line 325 "/emx/lib/bison.cc"
 /* const YY_parse_CLASS::token */
#endif
/*apres const  */
YY_parse_CLASS::YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM) YY_parse_CONSTRUCTOR_INIT
{
#if YY_parse_DEBUG != 0
YY_parse_DEBUG_FLAG=0;
#endif
YY_parse_CONSTRUCTOR_CODE;
};
#endif

/* #line 336 "/emx/lib/bison.cc" */
#line 706 "y.tab.c"


#define	YYFINAL		396
#define	YYFLAG		-32768
#define	YYNTBASE	79

#define YYTRANSLATE(x) ((unsigned)(x) <= 312 ? yytranslate[x] : 226)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,    73,    68,     2,    63,
    64,    71,    69,    59,    70,     2,    72,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    62,    58,    75,
    65,    76,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    77,     2,    78,    67,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    60,    66,    61,    74,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57
};

#if YY_parse_DEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     3,     4,     6,     8,    11,    13,    14,    16,
    18,    19,    21,    24,    27,    30,    33,    36,    38,    40,
    42,    45,    46,    54,    56,    58,    60,    61,    62,    75,
    81,    82,    85,    87,    91,    93,    94,    97,   100,   103,
   106,   109,   112,   114,   116,   119,   123,   125,   127,   129,
   133,   134,   141,   144,   146,   148,   150,   152,   154,   156,
   158,   160,   161,   163,   164,   166,   167,   168,   178,   179,
   180,   194,   196,   198,   200,   202,   204,   206,   208,   211,
   215,   218,   220,   223,   227,   230,   233,   239,   242,   249,
   250,   253,   254,   256,   259,   260,   267,   269,   271,   273,
   275,   277,   279,   281,   283,   285,   287,   288,   290,   291,
   293,   296,   306,   307,   310,   312,   313,   315,   316,   319,
   324,   328,   330,   334,   335,   341,   343,   345,   347,   349,
   350,   352,   353,   355,   360,   365,   367,   369,   371,   373,
   375,   377,   379,   381,   383,   385,   387,   391,   393,   397,
   399,   403,   405,   409,   413,   415,   419,   423,   425,   429,
   433,   437,   440,   442,   444,   446,   448,   450,   452,   456,
   458,   460,   462,   464,   466,   468,   469,   477,   479,   481,
   484,   488,   490,   494,   496,   499,   503,   505,   507,   509,
   511,   513,   515,   517,   519,   521,   523,   525,   527,   529,
   536,   541,   543,   545,   548,   555,   557,   559,   561,   563,
   565,   567,   569,   571,   574,   576,   578,   580,   583,   586,
   590,   592,   594,   596,   598,   600,   602,   604,   609,   611,
   616,   618,   620,   624,   626,   628,   630,   632,   634,   638,
   641,   643,   646,   650,   653,   656,   661,   663,   667,   669,
   671,   673,   675,   676,   678,   680,   682,   684,   686,   690,
   692,   693,   695,   696,   697,   702,   704,   706,   708,   710,
   712,   714,   716,   719,   721,   724,   726
};

static const short yyrhs[] = {    -1,
    81,     0,     0,    81,     0,    86,     0,    81,    86,     0,
    58,     0,     0,    58,     0,    59,     0,     0,   164,     0,
    99,    82,     0,   121,    82,     0,   123,    82,     0,    91,
    82,     0,    88,    82,     0,   222,     0,    85,     0,    83,
     0,   213,    21,     0,     0,    87,   205,    89,    60,    80,
    61,   206,     0,   205,     0,    24,     0,    39,     0,     0,
     0,   213,   214,    19,    90,    92,   206,    94,    93,    60,
    96,    61,   206,     0,   213,   214,    19,    90,   206,     0,
     0,    62,    95,     0,   164,     0,    95,    84,   164,     0,
    97,     0,     0,    97,    98,     0,    99,    82,     0,   123,
    82,     0,   135,    82,     0,   127,    82,     0,   121,    82,
     0,   222,     0,    83,     0,   213,   100,     0,   214,    40,
   102,     0,   108,     0,   111,     0,   162,     0,   214,    22,
   195,     0,     0,   214,    22,   195,    63,   101,    52,     0,
   103,   193,     0,   104,     0,   105,     0,   169,     0,   170,
     0,   164,     0,   108,     0,   111,     0,   162,     0,     0,
   203,     0,     0,   204,     0,     0,     0,   214,    36,   109,
   107,    60,   110,   167,    61,   206,     0,     0,     0,   214,
    41,   112,   107,    37,    63,   114,    64,    60,   113,   115,
    61,   206,     0,   175,     0,   184,     0,   186,     0,   162,
     0,   164,     0,   116,     0,   117,     0,   116,   117,     0,
   119,   118,    82,     0,   103,   194,     0,   120,     0,   119,
   120,     0,     6,   151,    62,     0,    10,    62,     0,   213,
   122,     0,     8,   150,   203,    65,   151,     0,   213,   124,
     0,    13,   204,    60,   125,    61,   206,     0,     0,   125,
   168,     0,     0,    32,     0,   213,   128,     0,     0,   214,
   126,     4,   129,   130,   197,     0,   132,     0,    44,     0,
   171,     0,   105,     0,   169,     0,   191,     0,   192,     0,
   173,     0,   164,     0,   131,     0,     0,    23,     0,     0,
    26,     0,   213,   136,     0,   214,   133,   134,   137,   204,
   141,   206,   146,   147,     0,     0,   138,   132,     0,    44,
     0,     0,    43,     0,     0,    59,    43,     0,    63,   142,
   140,    64,     0,    63,   139,    64,     0,   143,     0,   142,
    84,   143,     0,     0,   214,   145,   144,   130,   195,     0,
    17,     0,    30,     0,    18,     0,   130,     0,     0,   148,
     0,     0,   149,     0,    31,    63,    95,    64,     0,     9,
    63,   211,    64,     0,   175,     0,   184,     0,   185,     0,
   186,     0,   172,     0,   191,     0,   192,     0,   174,     0,
   164,     0,   152,     0,   153,     0,   152,    66,   153,     0,
   154,     0,   153,    67,   154,     0,   155,     0,   154,    68,
   155,     0,   156,     0,   155,    29,   156,     0,   155,    28,
   156,     0,   157,     0,   156,    69,   157,     0,   156,    70,
   157,     0,   158,     0,   157,    71,   158,     0,   157,    72,
   158,     0,   157,    73,   158,     0,   159,   160,     0,   160,
     0,    70,     0,    69,     0,    74,     0,   164,     0,   161,
     0,    63,   151,    64,     0,   216,     0,   217,     0,   218,
     0,   219,     0,   220,     0,   221,     0,     0,   214,    12,
   163,   106,    60,   166,    61,     0,   165,     0,   208,     0,
    27,   210,     0,   165,    27,   202,     0,   203,     0,   166,
    84,   203,     0,   168,     0,   167,   168,     0,   103,   193,
    82,     0,   172,     0,   175,     0,   184,     0,   185,     0,
   186,     0,   187,     0,   188,     0,   189,     0,   190,     0,
   171,     0,   191,     0,   192,     0,   173,     0,    33,    75,
   104,    59,   212,    76,     0,    33,    75,   104,    76,     0,
    16,     0,    11,     0,    20,    11,     0,    15,    75,   212,
    59,   216,    76,     0,    15,     0,   176,     0,   180,     0,
   177,     0,   178,     0,   179,     0,    34,     0,    20,     0,
    20,    20,     0,   181,     0,   182,     0,   183,     0,    42,
    34,     0,    42,    20,     0,    42,    20,    20,     0,     7,
     0,    45,     0,     5,     0,    25,     0,     3,     0,    24,
     0,    39,     0,    35,    75,   212,    76,     0,    35,     0,
    46,    75,   212,    76,     0,    46,     0,   194,     0,   193,
    84,   194,     0,   195,     0,   196,     0,   203,     0,   198,
     0,   195,     0,   197,    84,   195,     0,   203,   199,     0,
   200,     0,   199,   200,     0,    77,   212,    78,     0,    77,
    78,     0,    50,    51,     0,   201,    59,    50,    51,     0,
    50,     0,   201,    59,    50,     0,    53,     0,   207,     0,
   207,     0,   209,     0,     0,   202,     0,   202,     0,   202,
     0,   202,     0,   217,     0,   211,    84,   217,     0,   151,
     0,     0,    49,     0,     0,     0,    77,   215,   201,    78,
     0,    48,     0,   223,     0,   225,     0,    56,     0,    47,
     0,    38,     0,    14,     0,   213,    57,     0,   224,     0,
   223,   224,     0,    55,     0,    54,     0
};

#endif

#if YY_parse_DEBUG != 0
static const short yyrline[] = { 0,
   287,   288,   291,   292,   295,   296,   299,   300,   306,   312,
   313,   319,   328,   329,   330,   331,   332,   333,   334,   335,
   338,   341,   350,   382,   383,   387,   393,   419,   425,   433,
   448,   449,   495,   496,   500,   503,   504,   507,   508,   509,
   510,   511,   512,   513,   516,   524,   537,   538,   539,   540,
   545,   554,   561,   564,   565,   568,   569,   570,   573,   574,
   575,   578,   582,   585,   589,   592,   594,   598,   607,   609,
   615,   624,   625,   626,   627,   628,   631,   634,   635,   638,
   642,   656,   657,   660,   661,   664,   672,   679,   687,   692,
   693,   696,   697,   700,   708,   713,   729,   730,   736,   738,
   741,   742,   743,   744,   745,   746,   752,   753,   756,   757,
   760,   768,   782,   783,   784,   787,   788,   791,   792,   795,
   802,   808,   809,   813,   817,   823,   824,   825,   826,   832,
   833,   836,   837,   840,   845,   850,   851,   852,   853,   854,
   855,   856,   857,   858,   861,   864,   865,   868,   869,   872,
   873,   876,   877,   878,   881,   882,   883,   886,   887,   888,
   889,   892,   893,   896,   897,   898,   901,   915,   916,   919,
   920,   921,   922,   923,   924,   927,   929,   937,   945,   946,
   947,   974,   975,   979,   980,   983,   998,   999,  1000,  1001,
  1002,  1003,  1004,  1005,  1006,  1009,  1010,  1011,  1012,  1015,
  1018,  1023,  1024,  1025,  1028,  1033,  1036,  1037,  1040,  1041,
  1042,  1045,  1048,  1051,  1054,  1055,  1056,  1059,  1062,  1065,
  1068,  1071,  1074,  1077,  1080,  1083,  1086,  1089,  1092,  1095,
  1098,  1101,  1102,  1106,  1107,  1110,  1113,  1116,  1117,  1121,
  1136,  1137,  1141,  1142,  1145,  1150,  1156,  1160,  1167,  1170,
  1178,  1190,  1206,  1216,  1252,  1268,  1291,  1308,  1309,  1313,
  1350,  1351,  1357,  1358,  1367,  1370,  1373,  1376,  1379,  1382,
  1385,  1386,  1389,  1397,  1398,  1406,  1413
};

static const char * const yytname[] = {   "$","error","$illegal.","TOK_ANY",
"TOK_ATTRIBUTE","TOK_BOOLEAN","TOK_CASE","TOK_CHAR","TOK_CONST","TOK_CONTEXT",
"TOK_DEFAULT","TOK_DOUBLE","TOK_ENUM","TOK_EXCEPTION","TOK_FALSE","TOK_FIXED",
"TOK_FLOAT","TOK_IN","TOK_INOUT","TOK_INTERFACE","TOK_LONG","TOK_MODULE","TOK_NATIVE",
"TOK_NOSCRIPT","TOK_OBJECT","TOK_OCTET","TOK_ONEWAY","TOK_OP_SCOPE","TOK_OP_SHL",
"TOK_OP_SHR","TOK_OUT","TOK_RAISES","TOK_READONLY","TOK_SEQUENCE","TOK_SHORT",
"TOK_STRING","TOK_STRUCT","TOK_SWITCH","TOK_TRUE","TOK_TYPECODE","TOK_TYPEDEF",
"TOK_UNION","TOK_UNSIGNED","TOK_VARARGS","TOK_VOID","TOK_WCHAR","TOK_WSTRING",
"TOK_FLOATP","TOK_INTEGER","TOK_DECLSPEC","TOK_PROP_KEY","TOK_PROP_VALUE","TOK_NATIVE_TYPE",
"TOK_IDENT","TOK_SQSTRING","TOK_DQSTRING","TOK_FIXEDP","TOK_CODEFRAG","';'",
"','","'{'","'}'","':'","'('","')'","'='","'|'","'^'","'&'","'+'","'-'","'*'",
"'/'","'%'","'~'","'<'","'>'","'['","']'","specification","z_definition_list",
"definition_list","check_semicolon","useless_semicolon","check_comma","illegal_ident",
"definition","module_declspec","module","@1","interface_catch_ident","interface",
"@2","@3","z_inheritance","scoped_name_list","interface_body","export_list",
"export","type_dcl","type_dcl_def","@4","type_declarator","type_spec","simple_type_spec",
"constr_type_spec","z_new_ident_catch","z_new_scope_catch","struct_type","@5",
"@6","union_type","@7","@8","switch_type_spec","switch_body","case_stmt_list",
"case_stmt","element_spec","case_label_list","case_label","const_dcl","const_dcl_def",
"except_dcl","except_dcl_def","member_zlist","is_readonly","attr_dcl","attr_dcl_def",
"@9","param_type_spec","op_param_type_spec_illegal","op_param_type_spec","is_noscript",
"is_oneway","op_dcl","op_dcl_def","op_type_spec","@10","is_varargs","is_cvarargs",
"parameter_dcls","param_dcl_list","param_dcl","@11","param_attribute","is_raises_expr",
"is_context_expr","raises_expr","context_expr","const_type","const_exp","or_expr",
"xor_expr","and_expr","shift_expr","add_expr","mult_expr","unary_expr","unary_op",
"primary_expr","literal","enum_type","@12","scoped_name","ns_scoped_name","enumerator_list",
"member_list","member","base_type_spec","template_type_spec","sequence_type",
"floating_pt_type","fixed_pt_type","fixed_pt_const_type","integer_type","signed_int",
"signed_short_int","signed_long_int","signed_longlong_int","unsigned_int","unsigned_short_int",
"unsigned_long_int","unsigned_longlong_int","char_type","wide_char_type","boolean_type",
"octet_type","any_type","object_type","typecode_type","string_type","wide_string_type",
"declarator_list","declarator","simple_declarator","complex_declarator","simple_declarator_list",
"array_declarator","fixed_array_size_list","fixed_array_size","prop_hash","ident",
"new_ident","new_scope","new_or_prev_scope","pop_scope","ns_new_ident","ns_prev_ident",
"cur_ns_new_or_prev_ident","ns_global_ident","string_lit_list","positive_int_const",
"z_declspec","z_props","@13","integer_lit","string_lit","char_lit","fixed_pt_lit",
"floating_pt_lit","boolean_lit","codefrag","dqstring_cat","dqstring","sqstring",
""
};
#endif

static const short yyr1[] = {     0,
    79,    79,    80,    80,    81,    81,    82,    82,    83,    84,
    84,    85,    86,    86,    86,    86,    86,    86,    86,    86,
    87,    89,    88,    90,    90,    90,    92,    93,    91,    91,
    94,    94,    95,    95,    96,    97,    97,    98,    98,    98,
    98,    98,    98,    98,    99,   100,   100,   100,   100,   100,
   101,   100,   102,   103,   103,   104,   104,   104,   105,   105,
   105,   106,   106,   107,   107,   109,   110,   108,   112,   113,
   111,   114,   114,   114,   114,   114,   115,   116,   116,   117,
   118,   119,   119,   120,   120,   121,   122,   123,   124,   125,
   125,   126,   126,   127,   129,   128,   130,   130,   131,   131,
   132,   132,   132,   132,   132,   132,   133,   133,   134,   134,
   135,   136,   138,   137,   137,   139,   139,   140,   140,   141,
   141,   142,   142,   144,   143,   145,   145,   145,   145,   146,
   146,   147,   147,   148,   149,   150,   150,   150,   150,   150,
   150,   150,   150,   150,   151,   152,   152,   153,   153,   154,
   154,   155,   155,   155,   156,   156,   156,   157,   157,   157,
   157,   158,   158,   159,   159,   159,   160,   160,   160,   161,
   161,   161,   161,   161,   161,   163,   162,   164,   165,   165,
   165,   166,   166,   167,   167,   168,   169,   169,   169,   169,
   169,   169,   169,   169,   169,   170,   170,   170,   170,   171,
   171,   172,   172,   172,   173,   174,   175,   175,   176,   176,
   176,   177,   178,   179,   180,   180,   180,   181,   182,   183,
   184,   185,   186,   187,   188,   189,   190,   191,   191,   192,
   192,   193,   193,   194,   194,   195,   196,   197,   197,   198,
   199,   199,   200,   200,   201,   201,   201,   201,   202,   203,
   204,   205,   206,   207,   208,   209,   210,   211,   211,   212,
   213,   213,   214,   215,   214,   216,   217,   218,   219,   220,
   221,   221,   222,   223,   223,   224,   225
};

static const short yyr2[] = {     0,
     0,     1,     0,     1,     1,     2,     1,     0,     1,     1,
     0,     1,     2,     2,     2,     2,     2,     1,     1,     1,
     2,     0,     7,     1,     1,     1,     0,     0,    12,     5,
     0,     2,     1,     3,     1,     0,     2,     2,     2,     2,
     2,     2,     1,     1,     2,     3,     1,     1,     1,     3,
     0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
     1,     0,     1,     0,     1,     0,     0,     9,     0,     0,
    13,     1,     1,     1,     1,     1,     1,     1,     2,     3,
     2,     1,     2,     3,     2,     2,     5,     2,     6,     0,
     2,     0,     1,     2,     0,     6,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     0,     1,     0,     1,
     2,     9,     0,     2,     1,     0,     1,     0,     2,     4,
     3,     1,     3,     0,     5,     1,     1,     1,     1,     0,
     1,     0,     1,     4,     4,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
     3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
     3,     2,     1,     1,     1,     1,     1,     1,     3,     1,
     1,     1,     1,     1,     1,     0,     7,     1,     1,     2,
     3,     1,     3,     1,     2,     3,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     6,
     4,     1,     1,     2,     6,     1,     1,     1,     1,     1,
     1,     1,     1,     2,     1,     1,     1,     2,     2,     3,
     1,     1,     1,     1,     1,     1,     1,     4,     1,     4,
     1,     1,     3,     1,     1,     1,     1,     1,     3,     2,
     1,     2,     3,     2,     2,     4,     1,     3,     1,     1,
     1,     1,     0,     1,     1,     1,     1,     1,     3,     1,
     0,     1,     0,     0,     4,     1,     1,     1,     1,     1,
     1,     1,     2,     1,     2,     1,     1
};

static const short yydefact[] = {   261,
     0,   262,   249,     9,   261,    20,    19,     5,     0,     8,
     8,     8,     8,     8,    12,   178,   255,   179,   263,    18,
   257,   180,     6,   256,    22,   252,     7,    17,    16,    13,
    14,    15,     0,     0,     0,    21,   273,   264,    45,    47,
    48,    86,    88,    49,     0,     0,   181,   223,   221,   203,
   206,   202,   213,   212,   229,     0,   222,   231,     0,   144,
   140,   143,   136,   207,   209,   210,   211,   208,   215,   216,
   217,   137,   138,   139,   141,   142,   254,     0,   251,     0,
   176,     0,     0,    66,   263,    69,   261,   204,   214,     0,
   219,   218,     0,     0,   250,    90,   247,     0,    62,    25,
    26,   253,    24,    50,   236,    64,   225,     0,   226,   224,
     0,   227,    46,     0,    54,    55,    59,    60,    61,    58,
    56,    57,   196,   187,   199,   188,   189,   190,   191,   192,
   193,   194,   195,   197,   198,     0,    64,     0,   261,   272,
   271,   270,   266,   277,   276,   269,     0,   165,   164,   166,
   260,   145,   146,   148,   150,   152,   155,   158,     0,   163,
   168,   167,     0,   170,   171,   172,   173,   174,   175,   267,
   274,   268,   220,     0,     0,   263,   245,     0,   265,     0,
    63,   253,    30,    51,     0,    65,     0,     0,    53,   232,
   234,   235,   237,   236,     0,   253,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   162,   228,   275,
   230,    87,   253,     0,    91,   248,     0,    31,     0,    67,
     0,     0,    10,     0,     0,   240,   241,     0,    23,   169,
   147,   149,   151,   154,   153,   156,   157,   159,   160,   161,
    89,     8,   246,    11,   182,     0,    28,    52,   263,     0,
     0,   201,   233,   244,     0,   242,   263,   186,   177,     0,
    11,    33,     0,   263,   184,     0,     0,   243,   213,     0,
    75,    76,    72,    73,    74,     0,   183,     0,    36,   253,
   185,   205,   200,     0,    34,     0,   261,    68,    70,   253,
    44,    37,     8,     8,     8,     8,     8,   263,    43,     0,
    29,    38,    42,    39,    41,    40,    94,   111,   107,     0,
     0,     0,    77,    78,   263,    82,   108,    93,     0,   109,
     0,    85,   253,    79,     0,     8,    83,    95,   110,   113,
    84,    71,    81,    80,   263,   115,     0,   263,    98,   100,
     0,   106,    97,   105,   101,    99,   104,   102,   103,     0,
   114,   238,    96,   263,   253,     0,   117,     0,    11,   122,
   263,   130,   239,   121,    10,   263,     0,   126,   128,   127,
   129,   124,     0,   132,   131,   119,   123,   120,   263,     0,
     0,   112,   133,     0,    11,     0,   125,   134,    11,   258,
   135,     0,   259,     0,     0,     0
};

static const short yydefgoto[] = {   394,
   138,     5,    28,     6,   224,     7,     8,     9,    10,    46,
   102,    11,   182,   263,   247,   261,   286,   287,   292,    12,
    39,   219,   113,   214,   115,   116,   180,   185,   117,   106,
   249,   118,   137,   300,   270,   312,   313,   314,   326,   315,
   316,    13,    42,    14,    43,   176,   319,   296,   307,   335,
   341,   342,   343,   320,   330,   297,   308,   337,   338,   358,
   367,   355,   359,   360,   379,   372,   374,   382,   375,   383,
    59,   151,   152,   153,   154,   155,   156,   157,   158,   159,
   160,   161,   119,    99,   162,    16,   244,   264,   215,   121,
   122,   123,   124,   125,    62,   126,    64,    65,    66,    67,
    68,    69,    70,    71,   127,   128,   129,   130,   131,   132,
   133,   134,   135,   189,   190,   191,   192,   353,   193,   226,
   227,    98,    17,   105,   186,    25,   183,    95,    18,    26,
    22,   389,   163,    19,   136,    80,   164,   165,   166,   167,
   168,   169,    20,   170,   171,   172
};

static const short yypact[] = {    46,
     9,-32768,-32768,-32768,    59,-32768,-32768,-32768,     9,    17,
    17,    17,    17,    17,-32768,    87,-32768,-32768,    20,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,     9,   660,     9,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    49,    67,-32768,-32768,-32768,-32768,
-32768,-32768,    43,-32768,   -46,    22,-32768,    86,     9,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   116,-32768,   137,
-32768,    72,     9,-32768,   538,-32768,   119,-32768,-32768,   582,
   169,-32768,   582,   126,-32768,-32768,   142,   -29,     9,-32768,
-32768,   124,-32768,   135,-32768,     9,-32768,   133,-32768,-32768,
   136,-32768,-32768,     9,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    82,     9,   153,   146,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   582,-32768,-32768,-32768,
-32768,   160,   161,   164,   115,   -18,    79,-32768,   101,-32768,
-32768,-32768,   158,-32768,-32768,-32768,-32768,-32768,-32768,   182,
-32768,-32768,-32768,   168,   582,   399,-32768,   189,-32768,   188,
-32768,-32768,-32768,-32768,   206,-32768,   582,   639,    71,-32768,
-32768,-32768,-32768,   190,   231,-32768,   205,   582,   582,   582,
   582,   582,   582,   582,   582,   582,   582,-32768,-32768,-32768,
-32768,-32768,-32768,     9,-32768,   221,     9,   211,   223,-32768,
   217,     8,-32768,     9,   547,   190,-32768,   214,-32768,-32768,
   161,   164,   115,   -18,   -18,    79,    79,-32768,-32768,-32768,
-32768,   163,-32768,   120,-32768,    12,-32768,-32768,   538,   230,
   582,-32768,-32768,-32768,   201,-32768,    30,-32768,-32768,     9,
   191,-32768,   220,   446,-32768,   209,   210,-32768,   262,   224,
-32768,-32768,-32768,-32768,-32768,   275,-32768,    12,-32768,-32768,
-32768,-32768,-32768,   232,-32768,   229,   117,-32768,-32768,-32768,
-32768,-32768,    17,    17,    17,    17,    17,    23,-32768,   152,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   213,   582,
   237,   242,   152,-32768,   354,-32768,-32768,-32768,   287,   267,
   244,-32768,-32768,-32768,     9,    17,-32768,-32768,-32768,   264,
-32768,-32768,-32768,-32768,   493,-32768,     9,   538,-32768,-32768,
     9,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   247,
-32768,-32768,    71,    10,-32768,     9,-32768,   248,    74,-32768,
   185,   282,-32768,-32768,   271,   238,   252,-32768,-32768,-32768,
-32768,-32768,   255,   310,-32768,-32768,-32768,-32768,   493,    12,
   257,-32768,-32768,     9,    78,   182,-32768,-32768,   110,-32768,
-32768,   182,-32768,   322,   323,-32768
};

static const short yypgoto[] = {-32768,
-32768,   239,     1,    38,  -218,-32768,    14,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   -51,-32768,-32768,-32768,    44,
-32768,-32768,-32768,   -68,   144,  -291,-32768,   196,     2,-32768,
-32768,     3,-32768,-32768,-32768,-32768,-32768,    21,-32768,-32768,
    24,    48,-32768,    55,-32768,-32768,-32768,-32768,-32768,-32768,
  -260,-32768,     0,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   -23,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,  -127,-32768,   147,   148,   150,    63,    57,    51,-32768,
   192,-32768,   -15,-32768,     6,-32768,-32768,-32768,  -133,  -269,
-32768,  -259,   318,  -232,-32768,   -24,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,   -16,   319,   -11,-32768,-32768,-32768,
-32768,   -33,   -31,   140,  -199,   -67,-32768,-32768,-32768,-32768,
   130,-32768,    -1,   -54,   -26,   276,  -158,   -28,-32768,-32768,
-32768,-32768,   -66,    75,   -17,-32768,   113,  -252,-32768,-32768,
-32768,-32768,    81,-32768,   202,-32768
};


#define	YYLAST		713


static const short yytable[] = {    21,
    75,    45,    76,    44,    94,    15,    79,    24,    78,    63,
    15,    29,    30,    31,    32,   104,   114,    72,    23,   197,
    40,    41,    74,   218,   253,   260,   174,    34,    90,   178,
    34,    47,    35,    77,    48,    35,    49,   229,     1,    60,
    36,    91,   278,   340,   181,    -1,   340,   212,   179,   269,
   203,   204,   357,    88,   241,    92,     1,    77,    -2,   194,
    81,     3,    89,    54,     3,   345,   251,    82,   345,   340,
    83,    56,     1,  -116,    27,   346,    37,    79,   346,    37,
    24,    77,     3,   252,    84,     1,    38,   340,    85,    86,
   120,   345,    15,    81,     2,   100,    38,    77,     3,    38,
   371,   346,   347,     4,    77,   347,    38,     2,    79,   345,
   101,     3,    77,    33,   140,   265,     4,    84,   384,   346,
   221,   288,    86,   -11,     3,   333,    87,     1,   347,   223,
   281,   301,   365,   390,   356,    77,   223,  -118,   141,   393,
   366,   388,   201,   202,    15,     1,   347,   142,   143,   205,
   206,   207,    23,     3,   144,   145,   146,   310,   255,   194,
    93,   311,   245,   147,   332,     2,   278,     2,   223,   194,
   392,     3,     1,   391,     4,    96,     4,   -35,   223,    -3,
   259,   120,   321,   -27,   267,   -27,    97,   107,   173,    48,
   175,    49,   177,   120,     2,    50,   362,   184,     3,   108,
    52,   368,   369,     4,    53,   277,    -4,   187,   109,   110,
   188,     1,    77,   196,   370,    77,   -92,   111,    54,    55,
    27,   223,    77,   112,    81,   198,    56,   199,   339,    57,
    58,   200,   273,   209,    83,   317,   145,     3,   216,   276,
   274,   271,   258,   211,   318,   275,   325,   217,    84,   223,
   -32,   262,    85,    86,   120,   238,   239,   240,    77,   236,
   237,    38,   272,   234,   235,   220,   225,   228,   230,   120,
   194,   243,   246,   352,   248,   250,   257,   143,   268,   279,
   309,    89,    44,   285,   282,   283,    81,   284,   363,   290,
   328,   289,   329,   302,   303,   304,   305,   306,   322,    40,
    41,   348,   323,   349,   348,   331,   349,   336,    79,   354,
   350,   364,   373,   376,    38,   378,   387,   380,   381,   386,
   120,   395,   396,    77,   291,   139,   334,   348,   385,   349,
   293,   222,   195,   324,   294,    77,   361,   351,   327,    77,
   344,   295,   377,   344,   231,   348,   232,   349,   361,   233,
   208,    61,    73,   242,    77,   256,   107,   103,    48,   310,
    49,   298,   266,   311,    50,     0,   344,   299,   108,    52,
     0,   210,     0,    53,     0,     0,     0,   109,   110,     0,
     1,     0,    77,     0,   344,   262,   111,    54,    55,     0,
     0,     0,   112,     0,     0,    56,     0,     0,    57,    58,
     0,   107,     0,    48,     0,    49,     3,     0,     0,    50,
     0,     0,     0,   108,    52,     0,     0,     0,    53,     0,
     0,     0,   109,   110,     0,     1,     0,     0,     0,     0,
    38,   111,    54,    55,     0,     0,     0,   112,     0,     0,
    56,     0,     0,    57,    58,     0,     0,     0,   107,     0,
    48,     3,    49,     0,     0,     0,    50,     0,     0,   213,
   108,    52,     0,     0,     0,    53,     0,     0,     0,   109,
   110,     0,     1,     0,     0,    38,     0,     0,   111,    54,
    55,     0,     0,     0,   112,     0,     0,    56,     0,     0,
    57,    58,     0,     0,     0,   107,     0,    48,     3,    49,
     0,     0,     0,    50,     0,     0,   280,   108,    52,     0,
     0,     0,    53,     0,     0,     0,   109,   110,     0,     1,
     0,     0,    38,     0,     0,   111,    54,    55,     0,     0,
     0,   112,     0,     0,    56,     0,   339,    57,    58,     0,
   107,     0,    48,     0,    49,     3,     0,     0,    50,     0,
     0,     0,   108,    52,     0,     0,     0,    53,     0,     0,
   140,   109,   110,     0,     1,     0,     0,     0,     0,    38,
   111,    54,    55,     1,     0,     0,   112,     0,     0,    56,
     0,     0,    57,    58,   141,     0,     0,     0,     0,     0,
     3,     0,     0,   142,   143,   140,     0,     0,     0,     3,
   144,   145,   146,     0,     0,     0,     0,     0,     1,   147,
     0,     0,     0,     0,    38,   148,   149,     0,     0,   141,
   150,     0,     0,     0,   254,     0,     0,     0,   142,   143,
     0,     0,     0,     0,     3,   144,   145,   146,     0,     0,
     0,   107,     0,    48,   147,    49,     0,     0,     0,    50,
   148,   149,     0,   108,    52,   150,     0,     0,    53,     0,
     0,     0,   109,   110,    48,     1,    49,     0,     0,     0,
    50,   111,    54,    55,    51,    52,     0,   112,     0,    53,
    56,     0,     0,    57,    58,     0,     1,     0,     0,     0,
     0,     3,     0,    54,    55,     0,     0,     0,     0,     0,
     0,    56,     0,     0,    57,    58,     0,     0,     0,     0,
     0,     0,     3
};

static const short yycheck[] = {     1,
    34,    19,    34,    19,    59,     0,    35,     9,    35,    34,
     5,    11,    12,    13,    14,    83,    85,    34,     5,   147,
    19,    19,    34,   182,   224,   244,    93,     8,    75,    59,
     8,    33,    13,    35,     5,    13,     7,   196,    27,    34,
    21,    20,   261,   335,    99,     0,   338,   175,    78,    20,
    69,    70,    43,    11,   213,    34,    27,    59,     0,   114,
    12,    53,    20,    34,    53,   335,    59,    19,   338,   361,
    22,    42,    27,    64,    58,   335,    57,   106,   338,    57,
    82,    83,    53,    76,    36,    27,    77,   379,    40,    41,
    85,   361,    87,    12,    49,    24,    77,    99,    53,    77,
   361,   361,   335,    58,   106,   338,    77,    49,   137,   379,
    39,    53,   114,    27,    14,   249,    58,    36,   379,   379,
   187,   280,    41,    53,    53,   325,    60,    27,   361,    59,
   264,   290,    59,   386,   353,   137,    59,    64,    38,   392,
   359,    64,    28,    29,   139,    27,   379,    47,    48,    71,
    72,    73,   139,    53,    54,    55,    56,     6,   225,   214,
    75,    10,   217,    63,   323,    49,   385,    49,    59,   224,
   389,    53,    27,    64,    58,    60,    58,    61,    59,    61,
    61,   176,   310,    60,   251,    62,    50,     3,    20,     5,
    65,     7,    51,   188,    49,    11,   355,    63,    53,    15,
    16,    17,    18,    58,    20,   260,    61,    75,    24,    25,
    75,    27,   214,    61,    30,   217,     4,    33,    34,    35,
    58,    59,   224,    39,    12,    66,    42,    67,    44,    45,
    46,    68,   257,    76,    22,    23,    55,    53,    50,   257,
   257,   257,   242,    76,    32,   257,   315,    60,    36,    59,
    60,   246,    40,    41,   249,   205,   206,   207,   260,   203,
   204,    77,   257,   201,   202,    60,    77,    37,    64,   264,
   325,    51,    62,   341,    52,    59,    63,    48,    78,    60,
   298,    20,   298,   278,    76,    76,    12,    64,   356,    61,
     4,    60,    26,   293,   294,   295,   296,   297,    62,   298,
   298,   335,    61,   335,   338,    62,   338,    44,   337,    63,
   337,    64,    31,    43,    77,    64,   384,    63,     9,    63,
   315,     0,     0,   325,   287,    87,   326,   361,   380,   361,
   287,   188,   137,   313,   287,   337,   354,   338,   315,   341,
   335,   287,   366,   338,   198,   379,   199,   379,   366,   200,
   159,    34,    34,   214,   356,   226,     3,    82,     5,     6,
     7,   287,   250,    10,    11,    -1,   361,   287,    15,    16,
    -1,   170,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,
    27,    -1,   384,    -1,   379,   380,    33,    34,    35,    -1,
    -1,    -1,    39,    -1,    -1,    42,    -1,    -1,    45,    46,
    -1,     3,    -1,     5,    -1,     7,    53,    -1,    -1,    11,
    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    20,    -1,
    -1,    -1,    24,    25,    -1,    27,    -1,    -1,    -1,    -1,
    77,    33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,
    42,    -1,    -1,    45,    46,    -1,    -1,    -1,     3,    -1,
     5,    53,     7,    -1,    -1,    -1,    11,    -1,    -1,    61,
    15,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,
    25,    -1,    27,    -1,    -1,    77,    -1,    -1,    33,    34,
    35,    -1,    -1,    -1,    39,    -1,    -1,    42,    -1,    -1,
    45,    46,    -1,    -1,    -1,     3,    -1,     5,    53,     7,
    -1,    -1,    -1,    11,    -1,    -1,    61,    15,    16,    -1,
    -1,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,    27,
    -1,    -1,    77,    -1,    -1,    33,    34,    35,    -1,    -1,
    -1,    39,    -1,    -1,    42,    -1,    44,    45,    46,    -1,
     3,    -1,     5,    -1,     7,    53,    -1,    -1,    11,    -1,
    -1,    -1,    15,    16,    -1,    -1,    -1,    20,    -1,    -1,
    14,    24,    25,    -1,    27,    -1,    -1,    -1,    -1,    77,
    33,    34,    35,    27,    -1,    -1,    39,    -1,    -1,    42,
    -1,    -1,    45,    46,    38,    -1,    -1,    -1,    -1,    -1,
    53,    -1,    -1,    47,    48,    14,    -1,    -1,    -1,    53,
    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    27,    63,
    -1,    -1,    -1,    -1,    77,    69,    70,    -1,    -1,    38,
    74,    -1,    -1,    -1,    78,    -1,    -1,    -1,    47,    48,
    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,    -1,
    -1,     3,    -1,     5,    63,     7,    -1,    -1,    -1,    11,
    69,    70,    -1,    15,    16,    74,    -1,    -1,    20,    -1,
    -1,    -1,    24,    25,     5,    27,     7,    -1,    -1,    -1,
    11,    33,    34,    35,    15,    16,    -1,    39,    -1,    20,
    42,    -1,    -1,    45,    46,    -1,    27,    -1,    -1,    -1,
    -1,    53,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
    -1,    42,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
    -1,    -1,    53
};

#line 336 "/emx/lib/bison.cc"
 /* fattrs + tables */

/* parser code folow  */


/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: dollar marks section change
   the next  is replaced by the list of actions, each action
   as one case of the switch.  */ 

#if YY_parse_USE_GOTO != 0
/* 
 SUPRESSION OF GOTO : on some C++ compiler (sun c++)
  the goto is strictly forbidden if any constructor/destructor
  is used in the whole function (very stupid isn't it ?)
 so goto are to be replaced with a 'while/switch/case construct'
 here are the macro to keep some apparent compatibility
*/
#define YYGOTO(lb) {yy_gotostate=lb;continue;}
#define YYBEGINGOTO  enum yy_labels yy_gotostate=yygotostart; \
                     for(;;) switch(yy_gotostate) { case yygotostart: {
#define YYLABEL(lb) } case lb: {
#define YYENDGOTO } } 
#define YYBEGINDECLARELABEL enum yy_labels {yygotostart
#define YYDECLARELABEL(lb) ,lb
#define YYENDDECLARELABEL  };
#else
/* macro to keep goto */
#define YYGOTO(lb) goto lb
#define YYBEGINGOTO 
#define YYLABEL(lb) lb:
#define YYENDGOTO
#define YYBEGINDECLARELABEL 
#define YYDECLARELABEL(lb)
#define YYENDDECLARELABEL 
#endif
/* LABEL DECLARATION */
YYBEGINDECLARELABEL
  YYDECLARELABEL(yynewstate)
  YYDECLARELABEL(yybackup)
/* YYDECLARELABEL(yyresume) */
  YYDECLARELABEL(yydefault)
  YYDECLARELABEL(yyreduce)
  YYDECLARELABEL(yyerrlab)   /* here on detecting error */
  YYDECLARELABEL(yyerrlab1)   /* here on error raised explicitly by an action */
  YYDECLARELABEL(yyerrdefault)  /* current state does not do anything special for the error token. */
  YYDECLARELABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */
  YYDECLARELABEL(yyerrhandle)  
YYENDDECLARELABEL
/* ALLOCA SIMULATION */
/* __HAVE_NO_ALLOCA */
#ifdef __HAVE_NO_ALLOCA
int __alloca_free_ptr(char *ptr,char *ref)
{if(ptr!=ref) free(ptr);
 return 0;}

#define __ALLOCA_alloca(size) malloc(size)
#define __ALLOCA_free(ptr,ref) __alloca_free_ptr((char *)ptr,(char *)ref)

#ifdef YY_parse_LSP_NEEDED
#define __ALLOCA_return(num) \
            return( __ALLOCA_free(yyss,yyssa)+\
		    __ALLOCA_free(yyvs,yyvsa)+\
		    __ALLOCA_free(yyls,yylsa)+\
		   (num))
#else
#define __ALLOCA_return(num) \
            return( __ALLOCA_free(yyss,yyssa)+\
		    __ALLOCA_free(yyvs,yyvsa)+\
		   (num))
#endif
#else
#define __ALLOCA_return(num) return(num)
#define __ALLOCA_alloca(size) alloca(size)
#define __ALLOCA_free(ptr,ref) 
#endif

/* ENDALLOCA SIMULATION */

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (YY_parse_CHAR = YYEMPTY)
#define YYEMPTY         -2
#define YYEOF           0
#define YYACCEPT        __ALLOCA_return(0)
#define YYABORT         __ALLOCA_return(1)
#define YYERROR         YYGOTO(yyerrlab1)
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL          YYGOTO(yyerrlab)
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do                                                              \
  if (YY_parse_CHAR == YYEMPTY && yylen == 1)                               \
    { YY_parse_CHAR = (token), YY_parse_LVAL = (value);                 \
      yychar1 = YYTRANSLATE (YY_parse_CHAR);                                \
      YYPOPSTACK;                                               \
      YYGOTO(yybackup);                                            \
    }                                                           \
  else                                                          \
    { YY_parse_ERROR ("syntax error: cannot back up"); YYERROR; }   \
while (0)

#define YYTERROR        1
#define YYERRCODE       256

#ifndef YY_parse_PURE
/* UNPURE */
#define YYLEX           YY_parse_LEX()
#ifndef YY_USE_CLASS
/* If nonreentrant, and not class , generate the variables here */
int     YY_parse_CHAR;                      /*  the lookahead symbol        */
YY_parse_STYPE      YY_parse_LVAL;              /*  the semantic value of the */
				/*  lookahead symbol    */
int YY_parse_NERRS;                 /*  number of parse errors so far */
#ifdef YY_parse_LSP_NEEDED
YY_parse_LTYPE YY_parse_LLOC;   /*  location data for the lookahead     */
			/*  symbol                              */
#endif
#endif


#else
/* PURE */
#ifdef YY_parse_LSP_NEEDED
#define YYLEX           YY_parse_LEX(&YY_parse_LVAL, &YY_parse_LLOC)
#else
#define YYLEX           YY_parse_LEX(&YY_parse_LVAL)
#endif
#endif
#ifndef YY_USE_CLASS
#if YY_parse_DEBUG != 0
int YY_parse_DEBUG_FLAG;                    /*  nonzero means print parse trace     */
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif
#endif



/*  YYINITDEPTH indicates the initial size of the parser's stacks       */

#ifndef YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif


#if __GNUC__ > 1                /* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)       __builtin_memcpy(TO,FROM,COUNT)
#else                           /* not GNU C or C++ */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */

#ifdef __cplusplus
static void __yy_bcopy (char *from, char *to, int count)
#else
#ifdef __STDC__
static void __yy_bcopy (char *from, char *to, int count)
#else
static void __yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
#endif
#endif
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}
#endif

int
#ifdef YY_USE_CLASS
 YY_parse_CLASS::
#endif
     YY_parse_PARSE(YY_parse_PARSE_PARAM)
#ifndef __STDC__
#ifndef __cplusplus
#ifndef YY_USE_CLASS
/* parameter definition without protypes */
YY_parse_PARSE_PARAM_DEF
#endif
#endif
#endif
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YY_parse_STYPE *yyvsp;
  int yyerrstatus;      /*  number of tokens to shift before error messages enabled */
  int yychar1=0;          /*  lookahead token as an internal (translated) token number */

  short yyssa[YYINITDEPTH];     /*  the state stack                     */
  YY_parse_STYPE yyvsa[YYINITDEPTH];        /*  the semantic value stack            */

  short *yyss = yyssa;          /*  refer to the stacks thru separate pointers */
  YY_parse_STYPE *yyvs = yyvsa;     /*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YY_parse_LSP_NEEDED
  YY_parse_LTYPE yylsa[YYINITDEPTH];        /*  the location stack                  */
  YY_parse_LTYPE *yyls = yylsa;
  YY_parse_LTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YY_parse_PURE
  int YY_parse_CHAR;
  YY_parse_STYPE YY_parse_LVAL;
  int YY_parse_NERRS;
#ifdef YY_parse_LSP_NEEDED
  YY_parse_LTYPE YY_parse_LLOC;
#endif
#endif

  YY_parse_STYPE yyval;             /*  the variable used to return         */
				/*  semantic values from the action     */
				/*  routines                            */

  int yylen;
/* start loop, in which YYGOTO may be used. */
YYBEGINGOTO

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    fprintf(stderr, "Starting parse\n");
#endif
  yystate = 0;
  yyerrstatus = 0;
  YY_parse_NERRS = 0;
  YY_parse_CHAR = YYEMPTY;          /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YY_parse_LSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
YYLABEL(yynewstate)

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YY_parse_STYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YY_parse_LSP_NEEDED
      YY_parse_LTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YY_parse_LSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YY_parse_LSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  YY_parse_ERROR("parser stack overflow");
	  __ALLOCA_return(2);
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) __ALLOCA_alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      __ALLOCA_free(yyss1,yyssa);
      yyvs = (YY_parse_STYPE *) __ALLOCA_alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
      __ALLOCA_free(yyvs1,yyvsa);
#ifdef YY_parse_LSP_NEEDED
      yyls = (YY_parse_LTYPE *) __ALLOCA_alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
      __ALLOCA_free(yyls1,yylsa);
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YY_parse_LSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  YYGOTO(yybackup);
YYLABEL(yybackup)

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* YYLABEL(yyresume) */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yydefault);

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (YY_parse_CHAR == YYEMPTY)
    {
#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	fprintf(stderr, "Reading a token: ");
#endif
      YY_parse_CHAR = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (YY_parse_CHAR <= 0)           /* This means end of input. */
    {
      yychar1 = 0;
      YY_parse_CHAR = YYEOF;                /* Don't call YYLEX any more */

#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(YY_parse_CHAR);

#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	{
	  fprintf (stderr, "Next token is %d (%s", YY_parse_CHAR, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, YY_parse_CHAR, YY_parse_LVAL);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    YYGOTO(yydefault);

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrlab);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrlab);

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    fprintf(stderr, "Shifting token %d (%s), ", YY_parse_CHAR, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (YY_parse_CHAR != YYEOF)
    YY_parse_CHAR = YYEMPTY;

  *++yyvsp = YY_parse_LVAL;
#ifdef YY_parse_LSP_NEEDED
  *++yylsp = YY_parse_LLOC;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  YYGOTO(yynewstate);

/* Do the default action for the current state.  */
YYLABEL(yydefault)

  yyn = yydefact[yystate];
  if (yyn == 0)
    YYGOTO(yyerrlab);

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
YYLABEL(yyreduce)
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


/* #line 822 "/emx/lib/bison.cc" */
#line 1760 "y.tab.c"

  switch (yyn) {

case 1:
#line 287 "parser.y"
{ yyerror ("Empty file"); YYABORT; ;
    break;}
case 2:
#line 288 "parser.y"
{ __IDL_root = yyvsp[0].tree; ;
    break;}
case 3:
#line 291 "parser.y"
{ yyval.tree = NULL; ;
    break;}
case 5:
#line 295 "parser.y"
{ yyval.tree = list_start (yyvsp[0].tree, TRUE); ;
    break;}
case 6:
#line 296 "parser.y"
{ yyval.tree = list_chain (yyvsp[-1].tree, yyvsp[0].tree, TRUE); ;
    break;}
case 8:
#line 300 "parser.y"
{
	if (do_token_error (yyvsp[0].tree, "Missing semicolon after", TRUE))
		YYABORT;
;
    break;}
case 9:
#line 306 "parser.y"
{
	yyerror ("Dangling semicolon has no effect");
	yyval.tree = NULL;
;
    break;}
case 11:
#line 313 "parser.y"
{
	if (do_token_error (yyvsp[0].tree, "Missing comma after", TRUE))
		YYABORT;
;
    break;}
case 12:
#line 319 "parser.y"
{
	if (IDL_NODE_UP (yyvsp[0].tree))
	    do_token_error (IDL_NODE_UP (yyvsp[0].tree), "Illegal context for", FALSE);
	else
		yyerror ("Illegal context for identifier");
	YYABORT;
;
    break;}
case 22:
#line 342 "parser.y"
{
	if (IDL_NODE_UP (yyvsp[0].tree) != NULL &&
	    IDL_NODE_TYPE (IDL_NODE_UP (yyvsp[0].tree)) != IDLN_MODULE) {
		yyerror ("Module definition conflicts");
		do_token_error (IDL_NODE_UP (yyvsp[0].tree), "with", FALSE);
		YYABORT;
	}
;
    break;}
case 23:
#line 351 "parser.y"
{
	IDL_tree module;

	if (yyvsp[-2].tree == NULL) {
		yyerrorv ("Empty module declaration `%s' is not legal IDL",
			  IDL_IDENT (yyvsp[-5].tree).str);
		module = NULL;
	}

	if (__IDL_flags & IDLF_COMBINE_REOPENED_MODULES) {
		if (IDL_NODE_UP (yyvsp[-5].tree) == NULL)
			module = IDL_module_new (yyvsp[-5].tree, yyvsp[-2].tree);
		else {
			module = IDL_NODE_UP (yyvsp[-5].tree);
			IDL_MODULE (module).definition_list =
				IDL_list_concat (IDL_MODULE (module).definition_list, yyvsp[-2].tree);
			module = NULL;
		}
	} else
		module = IDL_module_new (yyvsp[-5].tree, yyvsp[-2].tree);

	yyval.tree = module;
	if (yyval.tree) {
		IDL_NODE_DECLSPEC (yyval.tree) = yyvsp[-6].declspec;	
		if (__IDL_inhibits > 0)
			IDL_NODE_DECLSPEC (yyval.tree) |= IDLF_DECLSPEC_EXIST |
				IDLF_DECLSPEC_INHIBIT;
	}
;
    break;}
case 25:
#line 383 "parser.y"
{
	yyerror ("Interfaces cannot be named `Object'");
	YYABORT;
;
    break;}
case 26:
#line 387 "parser.y"
{
	yyerror ("Interfaces cannot be named `TypeCode'");
	YYABORT;
;
    break;}
case 27:
#line 396 "parser.y"
{
	assert (yyvsp[0].tree != NULL);
	assert (IDL_NODE_TYPE (yyvsp[0].tree) == IDLN_IDENT);
	assert (IDL_IDENT_TO_NS (yyvsp[0].tree) != NULL);
	assert (IDL_NODE_TYPE (IDL_IDENT_TO_NS (yyvsp[0].tree)) == IDLN_GENTREE);

	if (IDL_NODE_UP (yyvsp[0].tree) != NULL &&
	    IDL_NODE_TYPE (IDL_NODE_UP (yyvsp[0].tree)) != IDLN_INTERFACE &&
	    IDL_NODE_TYPE (IDL_NODE_UP (yyvsp[0].tree)) != IDLN_FORWARD_DCL) {
		yyerrorl ("Interface definition conflicts",
			  __IDL_prev_token_line - __IDL_cur_token_line);
		do_token_error (IDL_NODE_UP (yyvsp[0].tree), "with", FALSE);
		YYABORT;
	} else if (IDL_NODE_UP (yyvsp[0].tree) != NULL &&
		   IDL_NODE_TYPE (IDL_NODE_UP (yyvsp[0].tree)) != IDLN_FORWARD_DCL) {
		yyerrorv ("Cannot redeclare interface `%s'", IDL_IDENT (yyvsp[0].tree).str);
		IDL_tree_error (yyvsp[0].tree, "Previous declaration of interface `%s'", IDL_IDENT (yyvsp[0].tree).str);
		YYABORT;
	} else if (IDL_NODE_UP (yyvsp[0].tree) != NULL &&
		   IDL_NODE_TYPE (IDL_NODE_UP (yyvsp[0].tree)) == IDLN_FORWARD_DCL)
		__IDL_assign_this_location (yyvsp[0].tree, __IDL_cur_filename, __IDL_cur_line);
;
    break;}
case 28:
#line 419 "parser.y"
{
	IDL_GENTREE (IDL_IDENT_TO_NS (yyvsp[-3].tree))._import = yyvsp[0].tree;
	IDL_ns_push_scope (__IDL_root_ns, IDL_IDENT_TO_NS (yyvsp[-3].tree));
	if (IDL_ns_check_for_ambiguous_inheritance (yyvsp[-3].tree, yyvsp[0].tree))
		__IDL_is_okay = FALSE;
;
    break;}
case 29:
#line 426 "parser.y"
{
 	yyval.tree = IDL_interface_new (yyvsp[-8].tree, yyvsp[-5].tree, yyvsp[-2].tree);
	IDL_NODE_DECLSPEC (yyval.tree) = yyvsp[-11].declspec;
	if (__IDL_inhibits > 0)
		IDL_NODE_DECLSPEC (yyval.tree) |= IDLF_DECLSPEC_EXIST | IDLF_DECLSPEC_INHIBIT;
	assign_props (IDL_INTERFACE (yyval.tree).ident, yyvsp[-10].hash_table);
;
    break;}
case 30:
#line 437 "parser.y"
{
	if (yyvsp[-3].hash_table) yywarningv (IDL_WARNING1,
			    "Ignoring properties for forward declaration `%s'",
			    IDL_IDENT (yyvsp[-1].tree).str);
	yyval.tree = IDL_forward_dcl_new (yyvsp[-1].tree);
	IDL_NODE_DECLSPEC (yyval.tree) = yyvsp[-4].declspec;
	if (__IDL_inhibits > 0)
		IDL_NODE_DECLSPEC (yyval.tree) |= IDLF_DECLSPEC_EXIST | IDLF_DECLSPEC_INHIBIT;
;
    break;}
case 31:
#line 448 "parser.y"
{ yyval.tree = NULL; ;
    break;}
case 32:
#line 449 "parser.y"
{
	GHashTable *table = g_hash_table_new (g_direct_hash, g_direct_equal);
	gboolean die = FALSE;
	IDL_tree p = yyvsp[0].tree;

	assert (IDL_NODE_TYPE (p) == IDLN_LIST);
	for (; p != NULL && !die; p = IDL_LIST (p).next) {
		assert (IDL_LIST (p).data != NULL);
		assert (IDL_NODE_TYPE (IDL_LIST (p).data) == IDLN_IDENT);

		if (g_hash_table_lookup_extended (table, IDL_LIST (p).data, NULL, NULL)) {
			char *s = IDL_ns_ident_to_qstring (IDL_LIST (p).data, "::", 0);
			yyerrorv ("Cannot inherit from interface `%s' more than once", s);
			g_free (s);
			die = TRUE;
			break;
		} else
			g_hash_table_insert (table, IDL_LIST (p).data, NULL);

		if (IDL_NODE_TYPE (IDL_NODE_UP (IDL_LIST (p).data)) == IDLN_FORWARD_DCL) {
			char *s = IDL_ns_ident_to_qstring (IDL_LIST (p).data, "::", 0);
			yyerrorv ("Incomplete definition of interface `%s'", s);
			IDL_tree_error (IDL_LIST (p).data,
					"Previous forward declaration of `%s'", s);
			g_free (s);
			die = TRUE;
		}
		else if (IDL_NODE_TYPE (IDL_NODE_UP (IDL_LIST (p).data)) != IDLN_INTERFACE) {
			char *s = IDL_ns_ident_to_qstring (IDL_LIST (p).data, "::", 0);
			yyerrorv ("`%s' is not an interface", s);
			IDL_tree_error (IDL_LIST (p).data,
					"Previous declaration of `%s'", s);
			g_free (s);
			die = TRUE;
		}
	}

	g_hash_table_destroy (table);

	if (die)
		YYABORT;

	yyval.tree = yyvsp[0].tree;
;
    break;}
case 33:
#line 495 "parser.y"
{ yyval.tree = list_start (yyvsp[0].tree, TRUE); ;
    break;}
case 34:
#line 497 "parser.y"
{ yyval.tree = list_chain (yyvsp[-2].tree, yyvsp[0].tree, TRUE); ;
    break;}
case 36:
#line 503 "parser.y"
{ yyval.tree = NULL; ;
    break;}
case 37:
#line 504 "parser.y"
{ yyval.tree = zlist_chain (yyvsp[-1].tree, yyvsp[0].tree, TRUE); ;
    break;}
case 45:
#line 516 "parser.y"
{
	yyval.tree = yyvsp[0].tree;
	IDL_NODE_DECLSPEC (yyval.tree) = yyvsp[-1].declspec;
	if (__IDL_inhibits > 0)
 		IDL_NODE_DECLSPEC (yyval.tree) |= IDLF_DECLSPEC_EXIST | IDLF_DECLSPEC_INHIBIT;
;
    break;}
case 46:
#line 525 "parser.y"
{
	IDL_tree_node node;
	IDL_tree p, dcl;

	yyval.tree = yyvsp[0].tree;
	node.properties = yyvsp[-2].hash_table;
	for (p = IDL_TYPE_DCL (yyvsp[0].tree).dcls; p; p = IDL_LIST (p).next) {
		dcl = IDL_LIST (p).data;
		IDL_tree_properties_copy (&node, dcl);
	}
	__IDL_free_properties (node.properties);
;
    break;}
case 50:
#line 541 "parser.y"
{
	yyval.tree = IDL_native_new (yyvsp[0].tree);
	assign_props (IDL_NATIVE (yyval.tree).ident, yyvsp[-2].hash_table);
;
    break;}
case 51:
#line 546 "parser.y"
{
	/* Enable native type scanning */
	if (__IDL_flags & IDLF_XPIDL)
		__IDL_flagsi |= IDLFP_NATIVE;
	else {
		yyerror ("Native syntax not enabled");
		YYABORT;
	}
;
    break;}
case 52:
#line 554 "parser.y"
{
	yyval.tree = IDL_native_new (yyvsp[-3].tree);
	IDL_NATIVE (yyval.tree).user_type = yyvsp[0].str;
	assign_props (IDL_NATIVE (yyval.tree).ident, yyvsp[-5].hash_table);
;
    break;}
case 53:
#line 561 "parser.y"
{ yyval.tree = IDL_type_dcl_new (yyvsp[-1].tree, yyvsp[0].tree); ;
    break;}
case 62:
#line 578 "parser.y"
{
	yyerrorv ("Missing identifier in %s definition", yyvsp[0].str);
	YYABORT;
;
    break;}
case 64:
#line 585 "parser.y"
{
	yyerrorv ("Missing identifier in %s definition", yyvsp[0].str);
	YYABORT;
;
    break;}
case 66:
#line 593 "parser.y"
{ yyval.str = "struct"; ;
    break;}
case 67:
#line 594 "parser.y"
{
	g_hash_table_insert (__IDL_structunion_ht, yyvsp[-1].tree, yyvsp[-1].tree);
	yyval.tree = IDL_type_struct_new (yyvsp[-1].tree, NULL);
;
    break;}
case 68:
#line 598 "parser.y"
{
	g_hash_table_remove (__IDL_structunion_ht, yyvsp[-5].tree);
	yyval.tree = yyvsp[-3].tree;
	__IDL_assign_up_node (yyval.tree, yyvsp[-2].tree);
	IDL_TYPE_STRUCT (yyval.tree).member_list = yyvsp[-2].tree;
	assign_props (IDL_TYPE_STRUCT (yyval.tree).ident, yyvsp[-8].hash_table);
;
    break;}
case 69:
#line 608 "parser.y"
{ yyval.str = "union"; ;
    break;}
case 70:
#line 611 "parser.y"
{
	g_hash_table_insert (__IDL_structunion_ht, yyvsp[-5].tree, yyvsp[-5].tree);
	yyval.tree = IDL_type_union_new (yyvsp[-5].tree, yyvsp[-2].tree, NULL);
;
    break;}
case 71:
#line 615 "parser.y"
{
	g_hash_table_remove (__IDL_structunion_ht, yyvsp[-9].tree);
	yyval.tree = yyvsp[-3].tree;
	__IDL_assign_up_node (yyval.tree, yyvsp[-2].tree);
	IDL_TYPE_UNION (yyval.tree).switch_body = yyvsp[-2].tree;
	assign_props (IDL_TYPE_UNION (yyval.tree).ident, yyvsp[-12].hash_table);
;
    break;}
case 78:
#line 634 "parser.y"
{ yyval.tree = list_start (yyvsp[0].tree, TRUE); ;
    break;}
case 79:
#line 635 "parser.y"
{ yyval.tree = list_chain (yyvsp[-1].tree, yyvsp[0].tree, TRUE); ;
    break;}
case 80:
#line 639 "parser.y"
{ yyval.tree = IDL_case_stmt_new (yyvsp[-2].tree, yyvsp[-1].tree); ;
    break;}
case 81:
#line 642 "parser.y"
{
	char *s;

	yyval.tree = IDL_member_new (yyvsp[-1].tree, list_start (yyvsp[0].tree, TRUE));
	if (IDL_NODE_TYPE (yyvsp[-1].tree) == IDLN_IDENT &&
	    g_hash_table_lookup (__IDL_structunion_ht, yyvsp[-1].tree)) {
		s = IDL_ns_ident_to_qstring (yyvsp[0].tree, "::", 0);
		yyerrorv ("Member `%s'", s);
		do_token_error (IDL_NODE_UP (yyvsp[-1].tree), "recurses", TRUE);
		g_free (s);
	}
;
    break;}
case 82:
#line 656 "parser.y"
{ yyval.tree = list_start (yyvsp[0].tree, FALSE); ;
    break;}
case 83:
#line 657 "parser.y"
{ yyval.tree = list_chain (yyvsp[-1].tree, yyvsp[0].tree, FALSE); ;
    break;}
case 84:
#line 660 "parser.y"
{ yyval.tree = yyvsp[-1].tree; ;
    break;}
case 85:
#line 661 "parser.y"
{ yyval.tree = NULL; ;
    break;}
case 86:
#line 664 "parser.y"
{
	yyval.tree = yyvsp[0].tree;
	IDL_NODE_DECLSPEC (yyval.tree) = yyvsp[-1].declspec;
	if (__IDL_inhibits > 0)
 		IDL_NODE_DECLSPEC (yyval.tree) |= IDLF_DECLSPEC_EXIST | IDLF_DECLSPEC_INHIBIT;
;
    break;}
case 87:
#line 673 "parser.y"
{
	yyval.tree = IDL_const_dcl_new (yyvsp[-3].tree, yyvsp[-2].tree, yyvsp[0].tree);
	/* Should probably do some type checking here... */
;
    break;}
case 88:
#line 679 "parser.y"
{
	yyval.tree = yyvsp[0].tree;
	IDL_NODE_DECLSPEC (yyval.tree) = yyvsp[-1].declspec;
	if (__IDL_inhibits > 0)
 		IDL_NODE_DECLSPEC (yyval.tree) |= IDLF_DECLSPEC_EXIST | IDLF_DECLSPEC_INHIBIT;
;
    break;}
case 89:
#line 689 "parser.y"
{ yyval.tree = IDL_except_dcl_new (yyvsp[-4].tree, yyvsp[-2].tree); ;
    break;}
case 90:
#line 692 "parser.y"
{ yyval.tree = NULL; ;
    break;}
case 91:
#line 693 "parser.y"
{ yyval.tree = zlist_chain (yyvsp[-1].tree, yyvsp[0].tree, TRUE); ;
    break;}
case 92:
#line 696 "parser.y"
{ yyval.boolean = FALSE; ;
    break;}
case 93:
#line 697 "parser.y"
{ yyval.boolean = TRUE; ;
    break;}
case 94:
#line 700 "parser.y"
{
	yyval.tree = yyvsp[0].tree;
	IDL_NODE_DECLSPEC (yyval.tree) = yyvsp[-1].declspec;
	if (__IDL_inhibits > 0)
 		IDL_NODE_DECLSPEC (yyval.tree) |= IDLF_DECLSPEC_EXIST | IDLF_DECLSPEC_INHIBIT;
;
    break;}
case 95:
#line 711 "parser.y"
{ yyval.str = "attribute"; ;
    break;}
case 96:
#line 713 "parser.y"
{
	IDL_tree_node node;
	IDL_tree p, dcl;

	yyval.tree = IDL_attr_dcl_new (yyvsp[-4].boolean, yyvsp[-1].tree, yyvsp[0].tree);
	node.properties = yyvsp[-5].hash_table;
	for (p = yyvsp[0].tree; p; p = IDL_LIST (p).next) {
		dcl = IDL_LIST (p).data;
		IDL_tree_properties_copy (&node, dcl);
	}
	__IDL_free_properties (node.properties);
	if (__IDL_inhibits > 0)
 		IDL_NODE_DECLSPEC (yyval.tree) |= IDLF_DECLSPEC_EXIST | IDLF_DECLSPEC_INHIBIT;
;
    break;}
case 98:
#line 730 "parser.y"
{
	yyerrorv ("Illegal type `void' for %s", yyvsp[-1].str);
	yyval.tree = NULL;
;
    break;}
case 106:
#line 746 "parser.y"
{
	illegal_context_type_error (yyvsp[0].tree, yyvsp[-1].str);
	yyval.tree = yyvsp[0].tree;
;
    break;}
case 107:
#line 752 "parser.y"
{ yyval.boolean = FALSE; ;
    break;}
case 108:
#line 753 "parser.y"
{ yyval.boolean = TRUE; ;
    break;}
case 109:
#line 756 "parser.y"
{ yyval.boolean = FALSE; ;
    break;}
case 110:
#line 757 "parser.y"
{ yyval.boolean = TRUE; ;
    break;}
case 111:
#line 760 "parser.y"
{
	yyval.tree = yyvsp[0].tree;
	IDL_NODE_DECLSPEC (yyval.tree) = yyvsp[-1].declspec;
	if (__IDL_inhibits > 0)
 		IDL_NODE_DECLSPEC (yyval.tree) |= IDLF_DECLSPEC_EXIST | IDLF_DECLSPEC_INHIBIT;
;
    break;}
case 112:
#line 774 "parser.y"
{
	yyval.tree = IDL_op_dcl_new (yyvsp[-6].boolean, yyvsp[-5].tree, yyvsp[-4].tree, yyvsp[-3].treedata.tree, yyvsp[-1].tree, yyvsp[0].tree);
	IDL_OP_DCL (yyval.tree).f_noscript = yyvsp[-7].boolean;
	IDL_OP_DCL (yyval.tree).f_varargs = GPOINTER_TO_INT (yyvsp[-3].treedata.data);
	assign_props (IDL_OP_DCL (yyval.tree).ident, yyvsp[-8].hash_table);
;
    break;}
case 113:
#line 782 "parser.y"
{ yyval.str = "operation return value"; ;
    break;}
case 114:
#line 783 "parser.y"
{ yyval.tree = yyvsp[0].tree; ;
    break;}
case 115:
#line 784 "parser.y"
{ yyval.tree = NULL; ;
    break;}
case 116:
#line 787 "parser.y"
{ yyval.boolean = FALSE; ;
    break;}
case 117:
#line 788 "parser.y"
{ yyval.boolean = TRUE; ;
    break;}
case 118:
#line 791 "parser.y"
{ yyval.boolean = FALSE; ;
    break;}
case 119:
#line 792 "parser.y"
{ yyval.boolean = TRUE; ;
    break;}
case 120:
#line 798 "parser.y"
{
	yyval.treedata.tree = yyvsp[-2].tree;
	yyval.treedata.data = GINT_TO_POINTER (yyvsp[-1].boolean);
;
    break;}
case 121:
#line 802 "parser.y"
{
	yyval.treedata.tree = NULL;
	yyval.treedata.data = GINT_TO_POINTER (yyvsp[-1].boolean);
;
    break;}
case 122:
#line 808 "parser.y"
{ yyval.tree = list_start (yyvsp[0].tree, TRUE); ;
    break;}
case 123:
#line 810 "parser.y"
{ yyval.tree = list_chain (yyvsp[-2].tree, yyvsp[0].tree, TRUE); ;
    break;}
case 124:
#line 815 "parser.y"
{ yyval.str = "parameter"; ;
    break;}
case 125:
#line 817 "parser.y"
{
	yyval.tree = IDL_param_dcl_new (yyvsp[-3].paramattr, yyvsp[-1].tree, yyvsp[0].tree);
	assign_props (IDL_PARAM_DCL (yyval.tree).simple_declarator, yyvsp[-4].hash_table);
;
    break;}
case 126:
#line 823 "parser.y"
{ yyval.paramattr = IDL_PARAM_IN; ;
    break;}
case 127:
#line 824 "parser.y"
{ yyval.paramattr = IDL_PARAM_OUT; ;
    break;}
case 128:
#line 825 "parser.y"
{ yyval.paramattr = IDL_PARAM_INOUT; ;
    break;}
case 129:
#line 826 "parser.y"
{
	yyerrorv ("Missing direction attribute (in, out, inout) before parameter");
	IDL_tree_free (yyvsp[0].tree);
;
    break;}
case 130:
#line 832 "parser.y"
{ yyval.tree = NULL; ;
    break;}
case 132:
#line 836 "parser.y"
{ yyval.tree = NULL; ;
    break;}
case 134:
#line 842 "parser.y"
{ yyval.tree = yyvsp[-1].tree; ;
    break;}
case 135:
#line 847 "parser.y"
{ yyval.tree = yyvsp[-1].tree; ;
    break;}
case 147:
#line 865 "parser.y"
{ do_binop (yyval.tree, IDL_BINOP_OR, yyvsp[-2].tree, yyvsp[0].tree); ;
    break;}
case 149:
#line 869 "parser.y"
{ do_binop (yyval.tree, IDL_BINOP_XOR, yyvsp[-2].tree, yyvsp[0].tree); ;
    break;}
case 151:
#line 873 "parser.y"
{ do_binop (yyval.tree, IDL_BINOP_AND, yyvsp[-2].tree, yyvsp[0].tree); ;
    break;}
case 153:
#line 877 "parser.y"
{ do_binop (yyval.tree, IDL_BINOP_SHR, yyvsp[-2].tree, yyvsp[0].tree); ;
    break;}
case 154:
#line 878 "parser.y"
{ do_binop (yyval.tree, IDL_BINOP_SHL, yyvsp[-2].tree, yyvsp[0].tree); ;
    break;}
case 156:
#line 882 "parser.y"
{ do_binop (yyval.tree, IDL_BINOP_ADD, yyvsp[-2].tree, yyvsp[0].tree); ;
    break;}
case 157:
#line 883 "parser.y"
{ do_binop (yyval.tree, IDL_BINOP_SUB, yyvsp[-2].tree, yyvsp[0].tree); ;
    break;}
case 159:
#line 887 "parser.y"
{ do_binop (yyval.tree, IDL_BINOP_MULT, yyvsp[-2].tree, yyvsp[0].tree); ;
    break;}
case 160:
#line 888 "parser.y"
{ do_binop (yyval.tree, IDL_BINOP_DIV, yyvsp[-2].tree, yyvsp[0].tree); ;
    break;}
case 161:
#line 889 "parser.y"
{ do_binop (yyval.tree, IDL_BINOP_MOD, yyvsp[-2].tree, yyvsp[0].tree); ;
    break;}
case 162:
#line 892 "parser.y"
{ do_unaryop (yyval.tree, yyvsp[-1].unaryop, yyvsp[0].tree); ;
    break;}
case 164:
#line 896 "parser.y"
{ yyval.unaryop = IDL_UNARYOP_MINUS; ;
    break;}
case 165:
#line 897 "parser.y"
{ yyval.unaryop = IDL_UNARYOP_PLUS; ;
    break;}
case 166:
#line 898 "parser.y"
{ yyval.unaryop = IDL_UNARYOP_COMPLEMENT; ;
    break;}
case 167:
#line 901 "parser.y"
{
	IDL_tree p, literal;
	
	assert (IDL_NODE_TYPE (yyvsp[0].tree) == IDLN_IDENT);

	p = IDL_NODE_UP (yyvsp[0].tree);
	
	if ((literal = IDL_resolve_const_exp (yyvsp[0].tree, IDLN_ANY))) {
		++IDL_NODE_REFS (literal);
		yyval.tree = literal;
		IDL_tree_free (yyvsp[0].tree);
	} else
		yyval.tree = yyvsp[0].tree;
;
    break;}
case 169:
#line 916 "parser.y"
{ yyval.tree = yyvsp[-1].tree; ;
    break;}
case 176:
#line 928 "parser.y"
{ yyval.str = "enum"; ;
    break;}
case 177:
#line 931 "parser.y"
{
	yyval.tree = IDL_type_enum_new (yyvsp[-3].tree, yyvsp[-1].tree);
	assign_props (IDL_TYPE_ENUM (yyval.tree).ident, yyvsp[-6].hash_table);
;
    break;}
case 178:
#line 937 "parser.y"
{
	assert (yyvsp[0].tree != NULL);
	assert (IDL_NODE_TYPE (yyvsp[0].tree) == IDLN_GENTREE);
	assert (IDL_NODE_TYPE (IDL_GENTREE (yyvsp[0].tree).data) == IDLN_IDENT);
	yyval.tree = IDL_GENTREE (yyvsp[0].tree).data;
;
    break;}
case 180:
#line 946 "parser.y"
{ yyval.tree = yyvsp[0].tree; ;
    break;}
case 181:
#line 948 "parser.y"
{
	IDL_tree p;

	assert (IDL_NODE_TYPE (yyvsp[-2].tree) == IDLN_GENTREE);
	assert (IDL_NODE_TYPE (yyvsp[0].tree) == IDLN_IDENT);

#ifdef YYDEBUG
	if (yydebug)
		printf ("looking in %s\n", IDL_IDENT (IDL_GENTREE (yyvsp[-2].tree).data).str);
#endif

	if ((p = IDL_ns_lookup_this_scope (__IDL_root_ns, yyvsp[-2].tree, yyvsp[0].tree, NULL)) == NULL) {
#ifdef YYDEBUG
		if (yydebug)
			printf ("'%s'\n", IDL_IDENT (yyvsp[0].tree).str);
#endif
		yyerrorv ("`%s' undeclared identifier", IDL_IDENT (yyvsp[0].tree).str);
		IDL_tree_free (yyvsp[0].tree);
		YYABORT;
	}
	IDL_tree_free (yyvsp[0].tree);
	++IDL_NODE_REFS (IDL_GENTREE (p).data);
	yyval.tree = p;
;
    break;}
case 182:
#line 974 "parser.y"
{ yyval.tree = list_start (yyvsp[0].tree, TRUE); ;
    break;}
case 183:
#line 976 "parser.y"
{ yyval.tree = list_chain (yyvsp[-2].tree, yyvsp[0].tree, TRUE); ;
    break;}
case 184:
#line 979 "parser.y"
{ yyval.tree = list_start (yyvsp[0].tree, TRUE); ;
    break;}
case 185:
#line 980 "parser.y"
{ yyval.tree = list_chain (yyvsp[-1].tree, yyvsp[0].tree, TRUE); ;
    break;}
case 186:
#line 984 "parser.y"
{
	char *s;

	yyval.tree = IDL_member_new (yyvsp[-2].tree, yyvsp[-1].tree);
	if (IDL_NODE_TYPE (yyvsp[-2].tree) == IDLN_IDENT &&
	    g_hash_table_lookup (__IDL_structunion_ht, yyvsp[-2].tree)) {
		s = IDL_ns_ident_to_qstring (IDL_LIST (yyvsp[-1].tree).data, "::", 0);
		yyerrorv ("Member `%s'", s);
		do_token_error (IDL_NODE_UP (yyvsp[-2].tree), "recurses", TRUE);
		g_free (s);
	}
;
    break;}
case 200:
#line 1017 "parser.y"
{ yyval.tree = IDL_type_sequence_new (yyvsp[-3].tree, yyvsp[-1].tree); ;
    break;}
case 201:
#line 1020 "parser.y"
{ yyval.tree = IDL_type_sequence_new (yyvsp[-1].tree, NULL); ;
    break;}
case 202:
#line 1023 "parser.y"
{ yyval.tree = IDL_type_float_new (IDL_FLOAT_TYPE_FLOAT); ;
    break;}
case 203:
#line 1024 "parser.y"
{ yyval.tree = IDL_type_float_new (IDL_FLOAT_TYPE_DOUBLE); ;
    break;}
case 204:
#line 1025 "parser.y"
{ yyval.tree = IDL_type_float_new (IDL_FLOAT_TYPE_LONGDOUBLE); ;
    break;}
case 205:
#line 1030 "parser.y"
{ yyval.tree = IDL_type_fixed_new (yyvsp[-3].tree, yyvsp[-1].tree); ;
    break;}
case 206:
#line 1033 "parser.y"
{ yyval.tree = IDL_type_fixed_new (NULL, NULL); ;
    break;}
case 207:
#line 1036 "parser.y"
{ yyval.tree = IDL_type_integer_new (TRUE, yyvsp[0].integer); ;
    break;}
case 208:
#line 1037 "parser.y"
{ yyval.tree = IDL_type_integer_new (FALSE, yyvsp[0].integer); ;
    break;}
case 209:
#line 1040 "parser.y"
{ yyval.integer = IDL_INTEGER_TYPE_SHORT; ;
    break;}
case 210:
#line 1041 "parser.y"
{ yyval.integer = IDL_INTEGER_TYPE_LONG; ;
    break;}
case 211:
#line 1042 "parser.y"
{ yyval.integer = IDL_INTEGER_TYPE_LONGLONG; ;
    break;}
case 215:
#line 1054 "parser.y"
{ yyval.integer = IDL_INTEGER_TYPE_SHORT; ;
    break;}
case 216:
#line 1055 "parser.y"
{ yyval.integer = IDL_INTEGER_TYPE_LONG; ;
    break;}
case 217:
#line 1056 "parser.y"
{ yyval.integer = IDL_INTEGER_TYPE_LONGLONG; ;
    break;}
case 221:
#line 1068 "parser.y"
{ yyval.tree = IDL_type_char_new (); ;
    break;}
case 222:
#line 1071 "parser.y"
{ yyval.tree = IDL_type_wide_char_new (); ;
    break;}
case 223:
#line 1074 "parser.y"
{ yyval.tree = IDL_type_boolean_new (); ;
    break;}
case 224:
#line 1077 "parser.y"
{ yyval.tree = IDL_type_octet_new (); ;
    break;}
case 225:
#line 1080 "parser.y"
{ yyval.tree = IDL_type_any_new (); ;
    break;}
case 226:
#line 1083 "parser.y"
{ yyval.tree = IDL_type_object_new (); ;
    break;}
case 227:
#line 1086 "parser.y"
{ yyval.tree = IDL_type_typecode_new (); ;
    break;}
case 228:
#line 1091 "parser.y"
{ yyval.tree = IDL_type_string_new (yyvsp[-1].tree); ;
    break;}
case 229:
#line 1092 "parser.y"
{ yyval.tree = IDL_type_string_new (NULL); ;
    break;}
case 230:
#line 1097 "parser.y"
{ yyval.tree = IDL_type_wide_string_new (yyvsp[-1].tree); ;
    break;}
case 231:
#line 1098 "parser.y"
{ yyval.tree = IDL_type_wide_string_new (NULL); ;
    break;}
case 232:
#line 1101 "parser.y"
{ yyval.tree = list_start (yyvsp[0].tree, TRUE); ;
    break;}
case 233:
#line 1103 "parser.y"
{ yyval.tree = list_chain (yyvsp[-2].tree, yyvsp[0].tree, TRUE); ;
    break;}
case 238:
#line 1116 "parser.y"
{ yyval.tree = list_start (yyvsp[0].tree, TRUE); ;
    break;}
case 239:
#line 1118 "parser.y"
{ yyval.tree = list_chain (yyvsp[-2].tree, yyvsp[0].tree, TRUE); ;
    break;}
case 240:
#line 1122 "parser.y"
{
	IDL_tree p;
	int i;

	yyval.tree = IDL_type_array_new (yyvsp[-1].tree, yyvsp[0].tree);
	for (i = 1, p = yyvsp[0].tree; p; ++i, p = IDL_LIST (p).next)
		if (!IDL_LIST (p).data) {
			char *s = IDL_ns_ident_to_qstring (yyvsp[-1].tree, "::", 0);
			yyerrorv ("Missing value in dimension %d of array `%s'", i, s);
			g_free (s);
		}
;
    break;}
case 241:
#line 1136 "parser.y"
{ yyval.tree = list_start (yyvsp[0].tree, FALSE); ;
    break;}
case 242:
#line 1138 "parser.y"
{ yyval.tree = list_chain (yyvsp[-1].tree, yyvsp[0].tree, FALSE); ;
    break;}
case 243:
#line 1141 "parser.y"
{ yyval.tree = yyvsp[-1].tree; ;
    break;}
case 244:
#line 1142 "parser.y"
{ yyval.tree = NULL; ;
    break;}
case 245:
#line 1146 "parser.y"
{
	yyval.hash_table = g_hash_table_new (IDL_strcase_hash, IDL_strcase_equal);
	g_hash_table_insert (yyval.hash_table, yyvsp[-1].str, yyvsp[0].str);
;
    break;}
case 246:
#line 1152 "parser.y"
{
	yyval.hash_table = yyvsp[-3].hash_table;
	g_hash_table_insert (yyval.hash_table, yyvsp[-1].str, yyvsp[0].str);
;
    break;}
case 247:
#line 1156 "parser.y"
{
	yyval.hash_table = g_hash_table_new (IDL_strcase_hash, IDL_strcase_equal);
	g_hash_table_insert (yyval.hash_table, yyvsp[0].str, g_strdup (""));
;
    break;}
case 248:
#line 1161 "parser.y"
{
	yyval.hash_table = yyvsp[-2].hash_table;
	g_hash_table_insert (yyval.hash_table, yyvsp[0].str, g_strdup (""));
;
    break;}
case 249:
#line 1167 "parser.y"
{ yyval.tree = IDL_ident_new (yyvsp[0].str); ;
    break;}
case 250:
#line 1170 "parser.y"
{
	assert (yyvsp[0].tree != NULL);
	assert (IDL_NODE_TYPE (yyvsp[0].tree) == IDLN_GENTREE);
	assert (IDL_NODE_TYPE (IDL_GENTREE (yyvsp[0].tree).data) == IDLN_IDENT);
	yyval.tree = IDL_GENTREE (yyvsp[0].tree).data;
;
    break;}
case 251:
#line 1178 "parser.y"
{
	IDL_ns_push_scope (__IDL_root_ns, yyvsp[0].tree);
#ifdef YYDEBUG
	if (yydebug)
		printf ("entering new/prev scope of %s\n", 
		       IDL_IDENT (IDL_GENTREE (IDL_NS (__IDL_root_ns).current).data).str);
#endif
	assert (IDL_NODE_TYPE (IDL_GENTREE (yyvsp[0].tree).data) == IDLN_IDENT);
	yyval.tree = IDL_GENTREE (yyvsp[0].tree).data;
;
    break;}
case 252:
#line 1190 "parser.y"
{
	IDL_ns_push_scope (__IDL_root_ns, yyvsp[0].tree);
	assert (IDL_NS (__IDL_root_ns).current != NULL);
	assert (IDL_NODE_TYPE (IDL_NS (__IDL_root_ns).current) == IDLN_GENTREE);
	assert (IDL_GENTREE (IDL_NS (__IDL_root_ns).current).data != NULL);
	assert (IDL_NODE_TYPE (IDL_GENTREE (IDL_NS (__IDL_root_ns).current).data) == IDLN_IDENT);
#ifdef YYDEBUG
	if (yydebug)
		printf ("entering new/prev scope of %s\n", 
		       IDL_IDENT (IDL_GENTREE (IDL_NS (__IDL_root_ns).current).data).str);
#endif
	assert (IDL_NODE_TYPE (IDL_GENTREE (yyvsp[0].tree).data) == IDLN_IDENT);
	yyval.tree = IDL_GENTREE (yyvsp[0].tree).data;
;
    break;}
case 253:
#line 1206 "parser.y"
{
#ifdef YYDEBUG
	if (yydebug)
		printf ("scope to parent of %s\n", 
		       IDL_IDENT (IDL_GENTREE (IDL_NS (__IDL_root_ns).current).data).str);
#endif
	IDL_ns_pop_scope (__IDL_root_ns);
;
    break;}
case 254:
#line 1216 "parser.y"
{
	IDL_tree p;

	if ((p = IDL_ns_place_new (__IDL_root_ns, yyvsp[0].tree)) == NULL) {
		IDL_tree q;
		int i;

		p = IDL_ns_lookup_cur_scope (__IDL_root_ns, yyvsp[0].tree, NULL);

		for (i = 0, q = IDL_GENTREE (p).data;
		     q && (IDL_NODE_TYPE (q) == IDLN_IDENT ||
			   IDL_NODE_TYPE (q) == IDLN_LIST) && i < 4;
		     ++i)
			if (IDL_NODE_UP (q))
				q = IDL_NODE_UP (q);

		if (q) {
			IDL_tree_error (yyvsp[0].tree, "`%s' conflicts", IDL_IDENT (yyvsp[0].tree).str);
			do_token_error (q, "with", FALSE);
		} else
			yyerrorv ("`%s' duplicate identifier", IDL_IDENT (yyvsp[0].tree).str);

		IDL_tree_free (yyvsp[0].tree);
		YYABORT;
	}
	assert (IDL_IDENT (yyvsp[0].tree)._ns_ref == p);
	++IDL_NODE_REFS (IDL_GENTREE (p).data);
	if (__IDL_new_ident_comments != NULL) {
		assert (IDL_IDENT (yyvsp[0].tree).comments == NULL);
		IDL_IDENT (yyvsp[0].tree).comments = __IDL_new_ident_comments;
		__IDL_new_ident_comments = NULL;
	}
	yyval.tree = p;
;
    break;}
case 255:
#line 1252 "parser.y"
{
	IDL_tree p;

	if ((p = IDL_ns_resolve_ident (__IDL_root_ns, yyvsp[0].tree)) == NULL) {
		yyerrorv ("`%s' undeclared identifier", IDL_IDENT (yyvsp[0].tree).str);
		IDL_tree_free (yyvsp[0].tree);
		YYABORT;
	}
	IDL_tree_free (yyvsp[0].tree);
	assert (IDL_GENTREE (p).data != NULL);
	assert (IDL_IDENT (IDL_GENTREE (p).data)._ns_ref == p);
	++IDL_NODE_REFS (IDL_GENTREE (p).data);
	yyval.tree = p;
;
    break;}
case 256:
#line 1269 "parser.y"
{
	IDL_tree p;

	if ((p = IDL_ns_lookup_cur_scope (__IDL_root_ns, yyvsp[0].tree, NULL)) == NULL) {
		p = IDL_ns_place_new (__IDL_root_ns, yyvsp[0].tree);
		assert (p != NULL);
		assert (IDL_IDENT (yyvsp[0].tree)._ns_ref == p);
		if (__IDL_new_ident_comments != NULL) {
			assert (IDL_IDENT (yyvsp[0].tree).comments == NULL);
			IDL_IDENT (yyvsp[0].tree).comments = __IDL_new_ident_comments;
			__IDL_new_ident_comments = NULL;
		}
	} else {
		IDL_tree_free (yyvsp[0].tree);
		assert (IDL_GENTREE (p).data != NULL);
		assert (IDL_IDENT (IDL_GENTREE (p).data)._ns_ref == p);
	}
	++IDL_NODE_REFS (IDL_GENTREE (p).data);
	yyval.tree = p;
;
    break;}
case 257:
#line 1291 "parser.y"
{
	IDL_tree p;

	if ((p = IDL_ns_lookup_this_scope (
		__IDL_root_ns,IDL_NS (__IDL_root_ns).file, yyvsp[0].tree, NULL)) == NULL) {
		yyerrorv ("`%s' undeclared identifier", IDL_IDENT (yyvsp[0].tree).str);
		IDL_tree_free (yyvsp[0].tree);
		YYABORT;
	}
	IDL_tree_free (yyvsp[0].tree);
	assert (IDL_GENTREE (p).data != NULL);
	assert (IDL_IDENT (IDL_GENTREE (p).data)._ns_ref == p);
	++IDL_NODE_REFS (IDL_GENTREE (p).data);
	yyval.tree = p;
;
    break;}
case 258:
#line 1308 "parser.y"
{ yyval.tree = list_start (yyvsp[0].tree, TRUE); ;
    break;}
case 259:
#line 1310 "parser.y"
{ yyval.tree = list_chain (yyvsp[-2].tree, yyvsp[0].tree, TRUE); ;
    break;}
case 260:
#line 1313 "parser.y"
{
	IDL_tree literal, ident = NULL;
	IDL_longlong_t value = 0;

	if ((literal = IDL_resolve_const_exp (yyvsp[0].tree, IDLN_INTEGER))) {
		assert (IDL_NODE_TYPE (literal) == IDLN_INTEGER);
		value = IDL_INTEGER (literal).value;
		IDL_tree_free (yyvsp[0].tree);
	}

	if (literal && IDL_NODE_UP (literal) &&
	    IDL_NODE_TYPE (IDL_NODE_UP (literal)) == IDLN_CONST_DCL)
		ident = IDL_CONST_DCL (IDL_NODE_UP (literal)).ident;
	
	if (literal == NULL) {
		if (!(__IDL_flags & IDLF_NO_EVAL_CONST))
			yyerror ("Could not resolve constant expression");
		yyval.tree = yyvsp[0].tree;
	} else if (value == 0) {
		yyerror ("Zero array size is illegal");
		if (ident)
			IDL_tree_error (ident, "From constant declared here");
		yyval.tree = NULL;
	} else if (value < 0) {
		yywarningv (IDL_WARNING1, "Cannot use negative value %"
			    IDL_LL "d, using %" IDL_LL "d",
			   value, -value);
		if (ident)
			IDL_tree_warning (ident,
					  IDL_WARNING1, "From constant declared here");
		yyval.tree = IDL_integer_new (-value);
	}
	else
		yyval.tree = IDL_integer_new (value);
;
    break;}
case 261:
#line 1350 "parser.y"
{ yyval.declspec = 0; ;
    break;}
case 262:
#line 1351 "parser.y"
{
	yyval.declspec = IDL_parse_declspec (yyvsp[0].str);
	g_free (yyvsp[0].str);
;
    break;}
case 263:
#line 1357 "parser.y"
{ yyval.hash_table = NULL; ;
    break;}
case 264:
#line 1358 "parser.y"
{
	/* Enable property scanning */
	if (__IDL_flags & IDLF_PROPERTIES)
		__IDL_flagsi |= IDLFP_PROPERTIES;
	else {
		yyerror ("Property syntax not enabled");
		YYABORT;
	}
;
    break;}
case 265:
#line 1367 "parser.y"
{ yyval.hash_table = yyvsp[-1].hash_table; ;
    break;}
case 266:
#line 1370 "parser.y"
{ yyval.tree = IDL_integer_new (yyvsp[0].integer); ;
    break;}
case 267:
#line 1373 "parser.y"
{ yyval.tree = IDL_string_new (yyvsp[0].str); ;
    break;}
case 268:
#line 1376 "parser.y"
{ yyval.tree = IDL_char_new (yyvsp[0].str); ;
    break;}
case 269:
#line 1379 "parser.y"
{ yyval.tree = IDL_fixed_new (yyvsp[0].str); ;
    break;}
case 270:
#line 1382 "parser.y"
{ yyval.tree = IDL_float_new (yyvsp[0].floatp); ;
    break;}
case 271:
#line 1385 "parser.y"
{ yyval.tree = IDL_boolean_new (TRUE); ;
    break;}
case 272:
#line 1386 "parser.y"
{ yyval.tree = IDL_boolean_new (FALSE); ;
    break;}
case 273:
#line 1389 "parser.y"
{
	yyval.tree = yyvsp[0].tree;
	IDL_NODE_DECLSPEC (yyval.tree) = yyvsp[-1].declspec;	
	if (__IDL_inhibits > 0)
		IDL_NODE_DECLSPEC (yyval.tree) |= IDLF_DECLSPEC_EXIST | IDLF_DECLSPEC_INHIBIT;
;
    break;}
case 275:
#line 1398 "parser.y"
{
	char *catstr = g_malloc (strlen (yyvsp[-1].str) + strlen (yyvsp[0].str) + 1);
	strcpy (catstr, yyvsp[-1].str); g_free (yyvsp[-1].str);
	strcat (catstr, yyvsp[0].str); g_free (yyvsp[0].str);
	yyval.str = catstr;
;
    break;}
case 276:
#line 1406 "parser.y"
{
	char *s = IDL_do_escapes (yyvsp[0].str);
	g_free (yyvsp[0].str);
	yyval.str = s;
;
    break;}
case 277:
#line 1413 "parser.y"
{
	char *s = IDL_do_escapes (yyvsp[0].str);
	g_free (yyvsp[0].str);
	yyval.str = s;
;
    break;}
}

#line 822 "/emx/lib/bison.cc"
   /* the action file gets copied in in place of this dollarsign  */
  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YY_parse_LSP_NEEDED
  yylsp -= yylen;
#endif

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YY_parse_LSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = YY_parse_LLOC.first_line;
      yylsp->first_column = YY_parse_LLOC.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  YYGOTO(yynewstate);

YYLABEL(yyerrlab)   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++YY_parse_NERRS;

#ifdef YY_parse_ERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      YY_parse_ERROR(msg);
	      free(msg);
	    }
	  else
	    YY_parse_ERROR ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YY_parse_ERROR_VERBOSE */
	YY_parse_ERROR("parse error");
    }

  YYGOTO(yyerrlab1);
YYLABEL(yyerrlab1)   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (YY_parse_CHAR == YYEOF)
	YYABORT;

#if YY_parse_DEBUG != 0
      if (YY_parse_DEBUG_FLAG)
	fprintf(stderr, "Discarding token %d (%s).\n", YY_parse_CHAR, yytname[yychar1]);
#endif

      YY_parse_CHAR = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;              /* Each real token shifted decrements this */

  YYGOTO(yyerrhandle);

YYLABEL(yyerrdefault)  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) YYGOTO(yydefault);
#endif

YYLABEL(yyerrpop)   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YY_parse_LSP_NEEDED
  yylsp--;
#endif

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

YYLABEL(yyerrhandle)

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    YYGOTO(yyerrdefault);

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    YYGOTO(yyerrdefault);

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	YYGOTO(yyerrpop);
      yyn = -yyn;
      YYGOTO(yyreduce);
    }
  else if (yyn == 0)
    YYGOTO(yyerrpop);

  if (yyn == YYFINAL)
    YYACCEPT;

#if YY_parse_DEBUG != 0
  if (YY_parse_DEBUG_FLAG)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = YY_parse_LVAL;
#ifdef YY_parse_LSP_NEEDED
  *++yylsp = YY_parse_LLOC;
#endif

  yystate = yyn;
  YYGOTO(yynewstate);
/* end loop, in which YYGOTO may be used. */
  YYENDGOTO
}

/* END */

/* #line 1021 "/emx/lib/bison.cc" */
#line 3198 "y.tab.c"
#line 1420 "parser.y"


static const char *IDL_ns_get_cur_prefix (IDL_ns ns)
{
	IDL_tree p;

	p = IDL_NS (ns).current;

	assert (p != NULL);

	while (p && !IDL_GENTREE (p)._cur_prefix)
		p = IDL_NODE_UP (p);

	return p ? IDL_GENTREE (p)._cur_prefix : NULL;
}

gchar *IDL_ns_ident_make_repo_id (IDL_ns ns, IDL_tree p,
				  const char *p_prefix, int *major, int *minor)
{
	GString *s = g_string_new (NULL);
	const char *prefix;
	char *q;

	assert (p != NULL);
	
	if (IDL_NODE_TYPE (p) == IDLN_IDENT)
		p = IDL_IDENT_TO_NS (p);

	assert (p != NULL);

	prefix = p_prefix ? p_prefix : IDL_ns_get_cur_prefix (ns);

	q = IDL_ns_ident_to_qstring (p, "/", 0);
	g_string_sprintf (s, "IDL:%s%s%s:%d.%d",
			  prefix ? prefix : "",
			  prefix && *prefix ? "/" : "",
			  q,
			  major ? *major : 1,
			  minor ? *minor : 0);
	g_free (q);

	q = s->str;
	g_string_free (s, FALSE);

	return q;
}

static const char *get_name_token (const char *s, char **tok)
{
	const char *begin = s;
	int state = 0;

	if (!s)
		return NULL;

	while (isspace (*s)) ++s;
	
	while (1) switch (state) {
	case 0:		/* Unknown */
		if (*s == ':')
			state = 1;
		else if (isalnum (*s) || *s == '_') {
			begin = s;
			state = 2;
		} else
			return NULL;
		break;
	case 1:		/* Scope */
		if (strncmp (s, "::", 2) == 0) {
			char *r = g_malloc (3);
			strcpy (r, "::");
			*tok = r;
			return s + 2;
		} else	/* Invalid */
			return NULL;
		break;
	case 2:
		if (isalnum (*s) || *s == '_')
			++s;
		else {
			char *r = g_malloc (s - begin + 1);
			strncpy (r, begin, s - begin + 1);
			r[s - begin] = 0;
			*tok = r;
			return s;
		}
		break;
	}
}

static IDL_tree IDL_ns_pragma_parse_name (IDL_ns ns, const char *s)
{
	IDL_tree p = IDL_NS (ns).current;
	int start = 1;
	char *tok;

	while (p && *s && (s = get_name_token (s, &tok))) {
		if (tok == NULL)
			return NULL;
		if (strcmp (tok, "::") == 0) {
			if (start) {
				/* Globally scoped */
				p = IDL_NS (ns).file;
			}
			g_free (tok);
		} else {
			IDL_tree ident = IDL_ident_new (tok);
			p = IDL_ns_lookup_this_scope (__IDL_root_ns, p, ident, NULL);
			IDL_tree_free (ident);
		}
		start = 0;
	}
	
	return p;
}

void IDL_ns_ID (IDL_ns ns, const char *s)
{
	char name[1024], id[1024];
	IDL_tree p, ident;
	int n;

	n = sscanf (s, "%1023s \"%1023s\"", name, id);
	if (n < 2 && __IDL_is_parsing) {
		yywarning (IDL_WARNING1, "Malformed pragma ID");
		return;
	}
	if (id[strlen (id) - 1] == '"')
		id[strlen (id) - 1] = 0;

	p = IDL_ns_pragma_parse_name (__IDL_root_ns, name);
	if (!p && __IDL_is_parsing) {
		yywarningv (IDL_WARNING1, "Unknown identifier `%s' in pragma ID", name);
		return;
	}

	/* We have resolved the identifier, so assign the repo id */
	assert (IDL_NODE_TYPE (p) == IDLN_GENTREE);
	assert (IDL_GENTREE (p).data != NULL);
	assert (IDL_NODE_TYPE (IDL_GENTREE (p).data) == IDLN_IDENT);
	ident = IDL_GENTREE (p).data;

	if (IDL_IDENT_REPO_ID (ident) != NULL)
		g_free (IDL_IDENT_REPO_ID (ident));

	IDL_IDENT_REPO_ID (ident) = g_strdup (id);
}

void IDL_ns_version (IDL_ns ns, const char *s)
{
	char name[1024];
	int n, major, minor;
	IDL_tree p, ident;

	n = sscanf (s, "%1023s %u %u", name, &major, &minor);
	if (n < 3 && __IDL_is_parsing) {
		yywarning (IDL_WARNING1, "Malformed pragma version");
		return;
	}

	p = IDL_ns_pragma_parse_name (__IDL_root_ns, name);
	if (!p && __IDL_is_parsing) {
		yywarningv (IDL_WARNING1, "Unknown identifier `%s' in pragma version", name);
		return;
	}

	/* We have resolved the identifier, so assign the repo id */
	assert (IDL_NODE_TYPE (p) == IDLN_GENTREE);
	assert (IDL_GENTREE (p).data != NULL);
	assert (IDL_NODE_TYPE (IDL_GENTREE (p).data) == IDLN_IDENT);
	ident = IDL_GENTREE (p).data;

	if (IDL_IDENT_REPO_ID (ident) != NULL) {
		char *v = strrchr (IDL_IDENT_REPO_ID (ident), ':');
		if (v) {
			GString *s;

			*v = 0;
			s = g_string_new (NULL);
			g_string_sprintf (s, "%s:%d.%d",
					  IDL_IDENT_REPO_ID (ident), major, minor);
			g_free (IDL_IDENT_REPO_ID (ident));
			IDL_IDENT_REPO_ID (ident) = s->str;
			g_string_free (s, FALSE);
		} else if (__IDL_is_parsing)
			yywarningv (IDL_WARNING1, "Cannot find RepositoryID OMG IDL version in ID `%s'",
				    IDL_IDENT_REPO_ID (ident));
	} else
		IDL_IDENT_REPO_ID (ident) =
			IDL_ns_ident_make_repo_id (
				__IDL_root_ns, p, NULL, &major, &minor);
}

int IDL_inhibit_get (void)
{
	g_return_val_if_fail (__IDL_is_parsing, -1);

	return __IDL_inhibits;
}

void IDL_inhibit_push (void)
{
	g_return_if_fail (__IDL_is_parsing);

	++__IDL_inhibits;
}

void IDL_inhibit_pop (void)
{
	g_return_if_fail (__IDL_is_parsing);

	if (--__IDL_inhibits < 0)
		__IDL_inhibits = 0;
}

static void IDL_inhibit (IDL_ns ns, const char *s)
{
	if (g_strcasecmp ("push", s) == 0)
		IDL_inhibit_push ();
	else if (g_strcasecmp ("pop", s) == 0)
		IDL_inhibit_pop ();
}

void __IDL_do_pragma (const char *s)
{
	int n;
	char directive[256];

	g_return_if_fail (__IDL_is_parsing);
	g_return_if_fail (s != NULL);

	if (sscanf (s, "%255s%n", directive, &n) < 1)
		return;
	s += n;
	while (isspace (*s)) ++s;

	if (strcmp (directive, "prefix") == 0)
		IDL_ns_prefix (__IDL_root_ns, s);
	else if (strcmp (directive, "ID") == 0)
		IDL_ns_ID (__IDL_root_ns, s);
	else if (strcmp (directive, "version") == 0)
		IDL_ns_version (__IDL_root_ns, s);
	else if (strcmp (directive, "inhibit") == 0)
		IDL_inhibit (__IDL_root_ns, s);
}

static IDL_declspec_t IDL_parse_declspec (const char *strspec)
{
	IDL_declspec_t flags = IDLF_DECLSPEC_EXIST;

	if (strspec == NULL)
		return flags;

	if (strcmp (strspec, "inhibit") == 0)
		flags |= IDLF_DECLSPEC_INHIBIT;
	else if (__IDL_is_parsing)
		yywarningv (IDL_WARNING1, "Ignoring unknown declspec `%s'", strspec);

	return flags;
}

void IDL_file_set (const char *filename, int line)
{
	IDL_fileinfo *fi;
	char *orig;

	g_return_if_fail (__IDL_is_parsing);

	if (filename) {
		__IDL_cur_filename = g_strdup (filename);

		if (
#ifdef HAVE_CPP_PIPE_STDIN
			!strlen (__IDL_cur_filename)
#else
			__IDL_tmp_filename &&
			!strcmp (__IDL_cur_filename, __IDL_tmp_filename)
#endif
			) {
			g_free (__IDL_cur_filename);
			__IDL_cur_filename = g_strdup (__IDL_real_filename);
		}

		if (g_hash_table_lookup_extended (__IDL_filename_hash, __IDL_cur_filename,
						  (gpointer) &orig, (gpointer) &fi)) {
			g_free (__IDL_cur_filename);
			__IDL_cur_filename = orig;
			__IDL_cur_fileinfo = fi;
		} else {
			fi = g_new0 (IDL_fileinfo, 1);
			__IDL_cur_fileinfo = fi;
			g_hash_table_insert (__IDL_filename_hash, __IDL_cur_filename, fi);
		}
	}

	if (__IDL_cur_line > 0)
		__IDL_cur_line = line;
}

void IDL_file_get (const char **filename, int *line)
{
	g_return_if_fail (__IDL_is_parsing);

	if (filename)
		*filename = __IDL_cur_filename;

	if (line)
		*line = __IDL_cur_line;
}

static int do_token_error (IDL_tree p, const char *message, gboolean prev)
{
	int dienow;
	char *what = NULL, *who = NULL;

	assert (p != NULL);

	dienow = IDL_tree_get_node_info (p, &what, &who);

	assert (what != NULL);
	
	if (who && *who)
		IDL_tree_error (p, "%s %s `%s'", message, what, who);
	else
		IDL_tree_error (p, "%s %s", message, what);
	
	return dienow;
}

static void illegal_context_type_error (IDL_tree p, const char *what)
{
	GString *s = g_string_new (NULL);

	g_string_sprintf (s, "Illegal type `%%s' for %s", what);
	illegal_type_error (p, s->str);
	g_string_free (s, TRUE);
}

static void illegal_type_error (IDL_tree p, const char *message)
{
	GString *s;

	s = IDL_tree_to_IDL_string (p, NULL, IDLF_OUTPUT_NO_NEWLINES);
	yyerrorv (message, s->str);
	g_string_free (s, TRUE);
}

static IDL_tree list_start (IDL_tree a, gboolean filter_null)
{
	IDL_tree p;

	if (!a && filter_null)
		return NULL;

	p = IDL_list_new (a);

	return p;
}

static IDL_tree list_chain (IDL_tree a, IDL_tree b, gboolean filter_null)
{
	IDL_tree p;

	if (filter_null) {
		if (!b)
			return a;
		if (!a)
			return list_start (b, filter_null);
	}

	p = IDL_list_new (b);
	a = IDL_list_concat (a, p);

	return a;
}

static IDL_tree zlist_chain (IDL_tree a, IDL_tree b, gboolean filter_null)
{
	if (a == NULL)
		return list_start (b, filter_null);
	else
		return list_chain (a, b, filter_null);
}

static int IDL_binop_chktypes (enum IDL_binop op, IDL_tree a, IDL_tree b)
{
	if (IDL_NODE_TYPE (a) != IDLN_BINOP &&
	    IDL_NODE_TYPE (b) != IDLN_BINOP &&
	    IDL_NODE_TYPE (a) != IDLN_UNARYOP &&
	    IDL_NODE_TYPE (b) != IDLN_UNARYOP &&
	    IDL_NODE_TYPE (a) != IDL_NODE_TYPE (b)) {
		yyerror ("Invalid mix of types in constant expression");
		return -1;
	}

	switch (op) {
	case IDL_BINOP_MULT:
	case IDL_BINOP_DIV:
	case IDL_BINOP_ADD:
	case IDL_BINOP_SUB:
		break;

	case IDL_BINOP_MOD:
	case IDL_BINOP_SHR:
	case IDL_BINOP_SHL:
	case IDL_BINOP_AND:
	case IDL_BINOP_OR:
	case IDL_BINOP_XOR:
		if ((IDL_NODE_TYPE (a) != IDLN_INTEGER ||
		     IDL_NODE_TYPE (b) != IDLN_INTEGER) &&
		    !(IDL_NODE_TYPE (a) == IDLN_BINOP ||
		      IDL_NODE_TYPE (b) == IDLN_BINOP ||
		      IDL_NODE_TYPE (a) == IDLN_UNARYOP ||
		      IDL_NODE_TYPE (b) == IDLN_UNARYOP)) {
			yyerror ("Invalid operation on non-integer value");
			return -1;
		}
		break;
	}

	return 0;
}

static int IDL_unaryop_chktypes (enum IDL_unaryop op, IDL_tree a)
{
	switch (op) {
	case IDL_UNARYOP_PLUS:
	case IDL_UNARYOP_MINUS:
		break;

	case IDL_UNARYOP_COMPLEMENT:
		if (IDL_NODE_TYPE (a) != IDLN_INTEGER &&
		    !(IDL_NODE_TYPE (a) == IDLN_BINOP ||
		      IDL_NODE_TYPE (a) == IDLN_UNARYOP)) {
			yyerror ("Operand to complement must be integer");
			return -1;
		}
		break;
	}

	return 0;
}

static IDL_tree IDL_binop_eval_integer (enum IDL_binop op, IDL_tree a, IDL_tree b)
{
	IDL_tree p = NULL;

	assert (IDL_NODE_TYPE (a) == IDLN_INTEGER);

	switch (op) {
	case IDL_BINOP_MULT:
		p = IDL_integer_new (IDL_INTEGER (a).value * IDL_INTEGER (b).value);
		break;

	case IDL_BINOP_DIV:
		if (IDL_INTEGER (b).value == 0) {
			yyerror ("Divide by zero in constant expression");
			return NULL;
		}
		p = IDL_integer_new (IDL_INTEGER (a).value / IDL_INTEGER (b).value);
		break;

	case IDL_BINOP_ADD:
		p = IDL_integer_new (IDL_INTEGER (a).value + IDL_INTEGER (b).value);
		break;

	case IDL_BINOP_SUB:
		p = IDL_integer_new (IDL_INTEGER (a).value - IDL_INTEGER (b).value);
		break;

	case IDL_BINOP_MOD:
		if (IDL_INTEGER (b).value == 0) {
			yyerror ("Modulo by zero in constant expression");
			return NULL;
		}
		p = IDL_integer_new (IDL_INTEGER (a).value % IDL_INTEGER (b).value);
		break;

	case IDL_BINOP_SHR:
		p = IDL_integer_new (IDL_INTEGER (a).value >> IDL_INTEGER (b).value);
		break;

	case IDL_BINOP_SHL:
		p = IDL_integer_new (IDL_INTEGER (a).value << IDL_INTEGER (b).value);
		break;

	case IDL_BINOP_AND:
		p = IDL_integer_new (IDL_INTEGER (a).value & IDL_INTEGER (b).value);
		break;

	case IDL_BINOP_OR:
		p = IDL_integer_new (IDL_INTEGER (a).value | IDL_INTEGER (b).value);
		break;

	case IDL_BINOP_XOR:
		p = IDL_integer_new (IDL_INTEGER (a).value ^ IDL_INTEGER (b).value);
		break;
	}

	return p;
}

static IDL_tree IDL_binop_eval_float (enum IDL_binop op, IDL_tree a, IDL_tree b)
{
	IDL_tree p = NULL;

	assert (IDL_NODE_TYPE (a) == IDLN_FLOAT);

	switch (op) {
	case IDL_BINOP_MULT:
		p = IDL_float_new (IDL_FLOAT (a).value * IDL_FLOAT (b).value);
		break;

	case IDL_BINOP_DIV:
		if (IDL_FLOAT (b).value == 0.0) {
			yyerror ("Divide by zero in constant expression");
			return NULL;
		}
		p = IDL_float_new (IDL_FLOAT (a).value / IDL_FLOAT (b).value);
		break;

	case IDL_BINOP_ADD:
		p = IDL_float_new (IDL_FLOAT (a).value + IDL_FLOAT (b).value);
		break;

	case IDL_BINOP_SUB:
		p = IDL_float_new (IDL_FLOAT (a).value - IDL_FLOAT (b).value);
		break;

	default:
		break;
	}

	return p;
}

static IDL_tree IDL_binop_eval (enum IDL_binop op, IDL_tree a, IDL_tree b)
{
	assert (IDL_NODE_TYPE (a) == IDL_NODE_TYPE (b));

	switch (IDL_NODE_TYPE (a)) {
	case IDLN_INTEGER: return IDL_binop_eval_integer (op, a, b);
	case IDLN_FLOAT: return IDL_binop_eval_float (op, a, b);
	default: return NULL;
	}
}

static IDL_tree IDL_unaryop_eval_integer (enum IDL_unaryop op, IDL_tree a)
{
	IDL_tree p = NULL;

	assert (IDL_NODE_TYPE (a) == IDLN_INTEGER);

	switch (op) {
	case IDL_UNARYOP_PLUS:
		p = IDL_integer_new (IDL_INTEGER (a).value);
		break;

	case IDL_UNARYOP_MINUS:
		p = IDL_integer_new (-IDL_INTEGER (a).value);
		break;

	case IDL_UNARYOP_COMPLEMENT:
		p = IDL_integer_new (~IDL_INTEGER (a).value);
		break;
	}
       
	return p;
}

static IDL_tree IDL_unaryop_eval_fixed (enum IDL_unaryop op, IDL_tree a)
{
	IDL_tree p = NULL;

	assert (IDL_NODE_TYPE (a) == IDLN_FIXED);

	switch (op) {
	case IDL_UNARYOP_PLUS:
		p = IDL_fixed_new (IDL_FIXED (a).value);
		break;

	default:
		break;
	}
       
	return p;
}

static IDL_tree IDL_unaryop_eval_float (enum IDL_unaryop op, IDL_tree a)
{
	IDL_tree p = NULL;

	assert (IDL_NODE_TYPE (a) == IDLN_FLOAT);

	switch (op) {
	case IDL_UNARYOP_PLUS:
		p = IDL_float_new (IDL_FLOAT (a).value);
		break;

	case IDL_UNARYOP_MINUS:
		p = IDL_float_new (-IDL_FLOAT (a).value);
		break;

	default:
		break;
	}
       
	return p;
}

static IDL_tree IDL_unaryop_eval (enum IDL_unaryop op, IDL_tree a)
{
	switch (IDL_NODE_TYPE (a)) {
	case IDLN_INTEGER: return IDL_unaryop_eval_integer (op, a);
	case IDLN_FIXED: return IDL_unaryop_eval_fixed (op, a);
	case IDLN_FLOAT: return IDL_unaryop_eval_float (op, a);
	default: return NULL;
	}
}

IDL_tree IDL_resolve_const_exp (IDL_tree p, IDL_tree_type type)
{
	gboolean resolved_value = FALSE, die = FALSE;
	gboolean wrong_type = FALSE;

	while (!resolved_value && !die) {
		if (IDL_NODE_TYPE (p) == IDLN_IDENT) {
			IDL_tree q = IDL_NODE_UP (p);
			
			assert (q != NULL);
			if (IDL_NODE_UP (q) &&
			    IDL_NODE_TYPE (IDL_NODE_UP (q)) == IDLN_TYPE_ENUM) {
				p = q;
				die = TRUE;
				break;
			} else if (IDL_NODE_TYPE (q) != IDLN_CONST_DCL) {
				p = q;
				wrong_type = TRUE;
				die = TRUE;
			} else
 				p = IDL_CONST_DCL (q).const_exp;
		}
		
		if (p == NULL ||
		    IDL_NODE_TYPE (p) == IDLN_BINOP ||
		    IDL_NODE_TYPE (p) == IDLN_UNARYOP) {
			die = TRUE;
			continue;
		}
		
		resolved_value = IDL_NODE_IS_LITERAL (p);
	}

	if (resolved_value &&
	    type != IDLN_ANY &&
	    IDL_NODE_TYPE (p) != type)
		wrong_type = TRUE;
	
	if (wrong_type) {
		yyerror ("Invalid type for constant");
		IDL_tree_error (p, "Previous resolved type declaration");
		return NULL;
	}

	return resolved_value ? p : NULL;
}

void IDL_queue_new_ident_comment (const char *str)
{
	g_return_if_fail (str != NULL);

	__IDL_new_ident_comments = g_slist_append (__IDL_new_ident_comments, g_strdup (str));
}

/*
 * Local variables:
 * mode: C
 * c-basic-offset: 8
 * tab-width: 8
 * indent-tabs-mode: t
 * End:
 */
