/*
 * xHarbour 1.2.3 Intl. (SimpLex) (Build 20150518)
 * Generated C source code from <Puzzle.prg>
 * Command: Puzzle.prg /m /n /gc0 /es2 /iC:\Language\Fwh\Include;C:\Language\Sqllib\Include;C:\Language\xHarbour\Include;C:\Language\Borland\Include /iC:\Language\xHarbour\Include /q /oObj\Puzzle.c 
 * Created: 2021.08.24 12:42:29 (Borland C++ 5.8.2 (32-bit))
 */

#include "hbvmpub.h"
#include "hbinit.h"

#define __PRG_SOURCE__ "Puzzle.prg"

/* Forward declarations of all PRG defined Functions. */
HB_FUNC_INIT( INIT );
HB_FUNC( MAIN );
HB_FUNC_STATIC( MYPUZZLE );
HB_FUNC_STATIC( BUILDTIMER );
HB_FUNC_STATIC( EMBARALHA );
HB_FUNC_STATIC( CLIQUEBOTAO );
HB_FUNC_STATIC( VERECORD );
HB_FUNC_STATIC( RESOLVE );
HB_FUNC_STATIC( FIMDEJOGO );
HB_FUNC_EXIT( HALT );
HB_FUNC_STATIC( TIMETOSTR );
HB_FUNC_STATIC( MYSTUFF );
HB_FUNC_INITSTATICS();

/* Forward declarations of all externally defined Functions. */
/* Skipped DEFERRED call to: 'DIVERTCONSTRUCTORCALL' */
HB_FUNC_EXTERN( GETPROCADD );
HB_FUNC_EXTERN( TACTIVEX );
HB_FUNC_EXTERN( ERRORSYS );
HB_FUNC_EXTERN( SET );
HB_FUNC_EXTERN( __SETCENTURY );
HB_FUNC_EXTERN( TFONT );
HB_FUNC_EXTERN( TDIALOG );
HB_FUNC_EXTERN( TBUTTON );
HB_FUNC_EXTERN( TSAY );
HB_FUNC_EXTERN( TRANSFORM );
HB_FUNC_EXTERN( STRZERO );
HB_FUNC_EXTERN( SETKEY );
HB_FUNC_EXTERN( TTIMER );
HB_FUNC_EXTERN( HB_RANDOM );
HB_FUNC_EXTERN( SPACE );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( AT );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( MSGALERT );
HB_FUNC_EXTERN( LEN );
HB_FUNC_EXTERN( CREATEOBJECT );
HB_FUNC_EXTERN( MSGGET );
HB_FUNC_EXTERN( MSGINFO );
HB_FUNC_EXTERN( DATE );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( XBROWSE );
HB_FUNC_EXTERN( FREERESOURCES );
HB_FUNC_EXTERN( __MVRELEASE );
HB_FUNC_EXTERN( SYSREFRESH );
HB_FUNC_EXTERN( HB_GCALL );
HB_FUNC_EXTERN( POSTQUITMESSAGE );
HB_FUNC_EXTERN( __QUIT );
HB_FUNC_EXTERN( STUFF );

#undef HB_PRG_PCODE_VER
#define HB_PRG_PCODE_VER 10

#include "hbapi.h"

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_PUZZLE )
{ "DIVERTCONSTRUCTORCALL", {HB_FS_PUBLIC | HB_FS_DEFERRED}, {NULL}, NULL },
{ "GETPROCADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( GETPROCADD )}, NULL },
{ "TACTIVEX", {HB_FS_PUBLIC}, {HB_FUNCNAME( TACTIVEX )}, NULL },
{ "ERRORSYS", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORSYS )}, NULL },
{ "INIT$", {HB_FS_INIT | HB_FS_LOCAL}, {HB_INIT_FUNCNAME( INIT )}, &ModuleFakeDyn },
{ "SET", {HB_FS_PUBLIC}, {HB_FUNCNAME( SET )}, NULL },
{ "__SETCENTURY", {HB_FS_PUBLIC}, {HB_FUNCNAME( __SETCENTURY )}, NULL },
{ "MAIN", {HB_FS_PUBLIC | HB_FS_LOCAL | HB_FS_FIRST}, {HB_FUNCNAME( MAIN )}, &ModuleFakeDyn },
{ "MYPUZZLE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( MYPUZZLE )}, &ModuleFakeDyn },
{ "NEW", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TFONT", {HB_FS_PUBLIC}, {HB_FUNCNAME( TFONT )}, NULL },
{ "TDIALOG", {HB_FS_PUBLIC}, {HB_FUNCNAME( TDIALOG )}, NULL },
{ "REDEFINE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TBUTTON", {HB_FS_PUBLIC}, {HB_FUNCNAME( TBUTTON )}, NULL },
{ "CLIQUEBOTAO", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( CLIQUEBOTAO )}, &ModuleFakeDyn },
{ "EMBARALHA", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( EMBARALHA )}, &ModuleFakeDyn },
{ "FONT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "END", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "TSAY", {HB_FS_PUBLIC}, {HB_FUNCNAME( TSAY )}, NULL },
{ "TRANSFORM", {HB_FS_PUBLIC}, {HB_FUNCNAME( TRANSFORM )}, NULL },
{ "STRZERO", {HB_FS_PUBLIC}, {HB_FUNCNAME( STRZERO )}, NULL },
{ "SETKEY", {HB_FS_PUBLIC}, {HB_FUNCNAME( SETKEY )}, NULL },
{ "MYSTUFF", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( MYSTUFF )}, &ModuleFakeDyn },
{ "RESOLVE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( RESOLVE )}, &ModuleFakeDyn },
{ "ACTIVATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "BLCLICKED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "BMOVED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "BPAINTED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_LHELPICON", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "BRCLICKED", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "BUILDTIMER", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( BUILDTIMER )}, &ModuleFakeDyn },
{ "TTIMER", {HB_FS_PUBLIC}, {HB_FUNCNAME( TTIMER )}, NULL },
{ "REFRESH", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "HB_RANDOM", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_RANDOM )}, NULL },
{ "SPACE", {HB_FS_PUBLIC}, {HB_FUNCNAME( SPACE )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "AT", {HB_FS_PUBLIC}, {HB_FUNCNAME( AT )}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "SETTEXT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "OERR", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "DEACTIVATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "MSGALERT", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGALERT )}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "GETTEXT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "FIMDEJOGO", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( FIMDEJOGO )}, &ModuleFakeDyn },
{ "VERECORD", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( VERECORD )}, &ModuleFakeDyn },
{ "CREATEOBJECT", {HB_FS_PUBLIC}, {HB_FUNCNAME( CREATEOBJECT )}, NULL },
{ "MSGGET", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGGET )}, NULL },
{ "OPEN", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "EOF", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "MSGINFO", {HB_FS_PUBLIC}, {HB_FUNCNAME( MSGINFO )}, NULL },
{ "ADDNEW", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "_VALUE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "FIELDS", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "DATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( DATE )}, NULL },
{ "TIMETOSTR", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( TIMETOSTR )}, &ModuleFakeDyn },
{ "UPDATE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "VALUE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "MOVENEXT", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "CLOSE", {HB_FS_PUBLIC}, {NULL}, NULL },
{ "XBROWSE", {HB_FS_PUBLIC}, {HB_FUNCNAME( XBROWSE )}, NULL },
{ "HALT$", {HB_FS_EXIT | HB_FS_LOCAL}, {HB_EXIT_FUNCNAME( HALT )}, &ModuleFakeDyn },
{ "FREERESOURCES", {HB_FS_PUBLIC}, {HB_FUNCNAME( FREERESOURCES )}, NULL },
{ "__MVRELEASE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __MVRELEASE )}, NULL },
{ "SYSREFRESH", {HB_FS_PUBLIC}, {HB_FUNCNAME( SYSREFRESH )}, NULL },
{ "HB_GCALL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_GCALL )}, NULL },
{ "POSTQUITMESSAGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( POSTQUITMESSAGE )}, NULL },
{ "__QUIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( __QUIT )}, NULL },
{ "STUFF", {HB_FS_PUBLIC}, {HB_FUNCNAME( STUFF )}, NULL },
{ "(_INITSTATICS00006)", {HB_FS_INITEXIT}, {hb_INITSTATICS}, &ModuleFakeDyn }
HB_INIT_SYMBOLS_END( hb_vm_SymbolInit_PUZZLE )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_PUZZLE
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_PUZZLE )
   #include "hbiniseg.h"
#endif

HB_FUNC_INIT( INIT )
{
   static const BYTE pcode[] =
   {
	133,27,0,108,5,100,92,5,93,171,7,20,2,134,
	1,108,6,100,106,3,79,78,0,20,1,134,2,108,
	5,100,92,4,108,6,100,12,0,28,17,106,11,100,
	100,47,109,109,47,121,121,121,121,0,25,13,106,9,
	100,100,47,109,109,47,121,121,0,20,2,134,3,108,
	5,100,92,11,106,3,79,78,0,20,2,134,5,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC( MAIN )
{
   static const BYTE pcode[] =
   {
	13,2,0,133,36,0,92,2,3,1,0,80,1,134,
	2,108,8,100,20,0,134,4,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( MYPUZZLE )
{
   static const BYTE pcode[] =
   {
	13,1,0,116,70,0,133,45,0,48,9,0,108,10,
	100,12,0,106,6,65,114,105,97,108,0,92,14,92,
	12,100,120,100,100,100,100,100,100,100,100,100,100,100,
	100,112,17,80,1,134,2,9,82,5,0,134,3,121,
	82,6,0,134,5,48,9,0,108,11,100,12,0,100,
	100,100,100,100,106,10,68,73,65,76,79,71,95,48,
	49,0,100,9,100,106,4,66,47,87,0,100,100,100,
	9,100,95,1,100,100,100,9,100,106,5,111,68,108,
	103,0,112,22,82,1,0,134,7,48,12,0,108,13,
	100,12,0,93,161,15,89,23,0,1,0,0,0,108,
	14,100,93,161,15,92,2,92,5,4,2,0,12,2,
	6,103,1,0,100,100,9,100,100,100,9,112,10,104,
	2,0,122,2,134,8,48,12,0,108,13,100,12,0,
	93,162,15,89,24,0,1,0,0,0,108,14,100,93,
	162,15,122,92,3,92,6,4,3,0,12,2,6,103,
	1,0,100,100,9,100,100,100,9,112,10,104,2,0,
	92,2,2,134,9,48,12,0,108,13,100,12,0,93,
	163,15,89,25,0,1,0,0,0,108,14,100,93,163,
	15,92,2,92,4,92,7,4,3,0,12,2,6,103,
	1,0,100,100,9,100,100,100,9,112,10,104,2,0,
	92,3,2,134,10,48,12,0,108,13,100,12,0,93,
	164,15,89,23,0,1,0,0,0,108,14,100,93,164,
	15,92,3,92,8,4,2,0,12,2,6,103,1,0,
	100,100,9,100,100,100,9,112,10,104,2,0,92,4,
	2,134,12,48,12,0,108,13,100,12,0,93,165,15,
	89,24,0,1,0,0,0,108,14,100,93,165,15,122,
	92,6,92,9,4,3,0,12,2,6,103,1,0,100,
	100,9,100,100,100,9,112,10,104,2,0,92,5,2,
	134,13,48,12,0,108,13,100,12,0,93,166,15,89,
	27,0,1,0,0,0,108,14,100,93,166,15,92,2,
	92,5,92,7,92,10,4,4,0,12,2,6,103,1,
	0,100,100,9,100,100,100,9,112,10,104,2,0,92,
	6,2,134,14,48,12,0,108,13,100,12,0,93,167,
	15,89,27,0,1,0,0,0,108,14,100,93,167,15,
	92,3,92,6,92,8,92,11,4,4,0,12,2,6,
	103,1,0,100,100,9,100,100,100,9,112,10,104,2,
	0,92,7,2,134,15,48,12,0,108,13,100,12,0,
	93,168,15,89,25,0,1,0,0,0,108,14,100,93,
	168,15,92,4,92,7,92,12,4,3,0,12,2,6,
	103,1,0,100,100,9,100,100,100,9,112,10,104,2,
	0,92,8,2,134,17,48,12,0,108,13,100,12,0,
	93,169,15,89,25,0,1,0,0,0,108,14,100,93,
	169,15,92,5,92,10,92,13,4,3,0,12,2,6,
	103,1,0,100,100,9,100,100,100,9,112,10,104,2,
	0,92,9,2,134,18,48,12,0,108,13,100,12,0,
	93,170,15,89,27,0,1,0,0,0,108,14,100,93,
	170,15,92,6,92,9,92,11,92,14,4,4,0,12,
	2,6,103,1,0,100,100,9,100,100,100,9,112,10,
	104,2,0,92,10,2,134,19,48,12,0,108,13,100,
	12,0,93,171,15,89,27,0,1,0,0,0,108,14,
	100,93,171,15,92,7,92,10,92,12,92,15,4,4,
	0,12,2,6,103,1,0,100,100,9,100,100,100,9,
	112,10,104,2,0,92,11,2,134,20,48,12,0,108,
	13,100,12,0,93,172,15,89,25,0,1,0,0,0,
	108,14,100,93,172,15,92,8,92,11,92,16,4,3,
	0,12,2,6,103,1,0,100,100,9,100,100,100,9,
	112,10,104,2,0,92,12,2,134,22,48,12,0,108,
	13,100,12,0,93,173,15,89,23,0,1,0,0,0,
	108,14,100,93,173,15,92,9,92,14,4,2,0,12,
	2,6,103,1,0,100,100,9,100,100,100,9,112,10,
	104,2,0,92,13,2,134,23,48,12,0,108,13,100,
	12,0,93,174,15,89,25,0,1,0,0,0,108,14,
	100,93,174,15,92,10,92,13,92,15,4,3,0,12,
	2,6,103,1,0,100,100,9,100,100,100,9,112,10,
	104,2,0,92,14,2,134,24,48,12,0,108,13,100,
	12,0,93,175,15,89,25,0,1,0,0,0,108,14,
	100,93,175,15,92,11,92,14,92,16,4,3,0,12,
	2,6,103,1,0,100,100,9,100,100,100,9,112,10,
	104,2,0,92,15,2,134,25,48,12,0,108,13,100,
	12,0,93,176,15,89,23,0,1,0,0,0,108,14,
	100,93,176,15,92,12,92,15,4,2,0,12,2,6,
	103,1,0,100,100,9,100,100,100,9,112,10,104,2,
	0,92,16,2,134,28,48,12,0,108,13,100,12,0,
	93,177,15,89,13,0,1,0,0,0,108,15,100,12,
	0,6,103,1,0,100,100,9,89,12,0,1,0,0,
	0,103,5,0,68,6,100,100,9,112,10,21,80,1,
	21,83,16,0,104,2,0,92,17,2,134,29,48,12,
	0,108,13,100,12,0,93,178,15,89,16,0,1,0,
	0,0,48,17,0,103,1,0,112,0,6,103,1,0,
	100,100,9,100,100,100,9,112,10,21,80,1,21,83,
	16,0,104,2,0,92,18,2,134,31,48,12,0,108,
	18,100,12,0,93,180,15,89,31,0,1,0,0,0,
	108,19,100,108,20,100,103,6,0,92,5,12,2,106,
	6,57,57,58,57,57,0,12,2,6,103,1,0,100,
	100,100,9,100,9,9,112,10,82,3,0,134,33,108,
	21,100,92,113,89,13,0,1,0,0,0,108,22,100,
	12,0,6,20,2,134,35,108,21,100,92,121,89,13,
	0,1,0,0,0,108,23,100,12,0,6,20,2,134,
	37,48,24,0,103,1,0,48,25,0,103,1,0,112,
	0,48,26,0,103,1,0,112,0,48,27,0,103,1,
	0,112,0,120,100,100,89,17,0,1,0,0,0,48,
	28,0,103,1,0,9,112,1,6,48,29,0,103,1,
	0,112,0,100,100,100,112,11,73,134,40,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( BUILDTIMER )
{
   static const BYTE pcode[] =
   {
	116,70,0,133,90,0,48,9,0,108,31,100,12,0,
	93,232,3,89,23,0,1,0,0,0,103,6,0,23,
	82,6,0,48,32,0,103,3,0,112,0,6,103,1,
	0,112,3,82,4,0,134,1,48,24,0,103,4,0,
	112,0,73,134,3,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( EMBARALHA )
{
   static const BYTE pcode[] =
   {
	13,6,0,116,70,0,133,96,0,4,0,0,80,1,
	134,5,127,2,1,0,0,134,6,126,5,1,0,134,
	7,95,5,92,16,34,28,98,134,8,108,33,100,121,
	92,18,12,2,80,4,134,9,9,95,4,122,16,28,
	8,73,95,4,92,16,34,28,220,134,10,95,4,92,
	16,5,28,11,108,34,100,92,2,12,1,25,11,108,
	35,100,95,4,92,2,12,2,80,3,134,11,108,36,
	100,95,3,95,2,12,2,121,5,28,23,134,12,95,
	3,167,2,134,13,108,37,100,95,1,95,3,20,2,
	134,14,173,5,25,153,134,19,126,5,1,0,95,5,
	92,16,34,28,63,134,20,48,38,0,103,2,0,95,
	5,1,95,1,95,5,1,106,3,49,54,0,5,28,
	11,108,34,100,92,2,12,1,25,7,95,1,95,5,
	1,112,1,73,134,21,48,32,0,103,2,0,95,5,
	1,112,0,73,134,22,173,5,25,190,134,24,120,82,
	5,0,162,15,0,0,134,26,108,30,100,20,0,163,
	22,0,0,164,18,0,0,83,39,0,134,28,48,40,
	0,103,4,0,112,0,73,165,166,134,32,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( CLIQUEBOTAO )
{
   static const BYTE pcode[] =
   {
	13,3,2,116,70,0,133,132,0,9,80,5,134,2,
	103,5,0,31,62,134,3,108,41,100,106,36,67,108,
	105,113,117,101,32,101,109,32,39,73,110,105,99,105,
	97,114,39,32,112,97,114,97,32,99,111,109,101,231,
	97,114,46,46,46,0,106,8,65,84,69,78,199,195,
	79,0,20,2,134,4,100,110,7,134,7,126,3,1,
	0,95,3,108,42,100,95,2,12,1,34,28,47,134,
	8,95,2,95,3,1,80,4,134,9,48,43,0,103,
	2,0,95,4,1,112,0,108,34,100,92,2,12,1,
	5,28,9,134,10,120,80,5,25,8,134,13,173,3,
	25,201,134,15,95,5,31,65,134,16,108,41,100,106,
	39,77,111,118,105,109,101,110,116,111,32,105,110,118,
	225,108,105,100,111,46,46,46,32,84,101,110,116,101,
	32,111,117,116,114,97,32,118,101,122,33,0,106,8,
	65,84,69,78,199,195,79,0,20,2,134,17,9,110,
	7,134,21,48,38,0,103,2,0,95,4,1,48,43,
	0,103,2,0,95,1,128,96,240,1,112,0,112,1,
	73,134,22,48,32,0,103,2,0,95,4,1,112,0,
	73,134,24,48,38,0,103,2,0,95,1,128,96,240,
	1,108,34,100,92,2,12,1,112,1,73,134,25,48,
	32,0,103,2,0,95,1,128,96,240,1,112,0,73,
	134,27,108,44,100,12,0,28,92,134,28,108,41,100,
	106,20,80,85,90,90,76,69,32,110,111,32,116,101,
	109,112,111,32,100,101,32,0,108,19,100,103,6,0,
	106,9,64,82,32,57,57,58,57,57,0,12,2,72,
	106,9,80,65,82,65,66,201,78,83,0,20,2,134,
	30,48,40,0,103,4,0,112,0,73,134,31,9,82,
	5,0,134,33,108,45,100,20,0,134,34,121,82,6,
	0,134,38,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( VERECORD )
{
   static const BYTE pcode[] =
   {
	13,7,0,116,70,0,133,173,0,108,46,100,106,17,
	65,68,79,68,66,46,67,111,110,110,101,99,116,105,
	111,110,0,12,1,80,1,134,1,108,46,100,106,16,
	65,68,79,68,66,46,82,101,99,111,114,100,115,101,
	116,0,12,1,80,2,134,3,4,0,0,80,6,134,
	6,108,34,100,92,20,12,1,21,80,5,80,4,134,
	7,108,47,100,106,18,73,110,102,111,114,109,101,32,
	115,101,117,32,110,111,109,101,58,0,95,4,96,5,
	0,12,3,31,7,134,8,100,110,7,134,11,48,48,
	0,95,1,106,75,80,114,111,118,105,100,101,114,61,
	77,105,99,114,111,115,111,102,116,46,74,101,116,46,
	79,76,69,68,66,46,52,46,48,59,68,97,116,97,
	32,83,111,117,114,99,101,61,68,58,92,83,105,115,
	116,101,109,97,115,92,80,117,122,122,108,101,92,80,
	117,122,122,108,101,46,109,100,98,0,112,1,73,134,
	12,127,3,55,0,83,69,76,69,67,84,32,68,97,
	116,97,44,32,78,111,109,101,44,32,84,101,109,112,
	111,32,70,82,79,77,32,82,101,103,105,115,116,114,
	111,115,32,79,82,68,69,82,32,66,89,32,116,101,
	109,112,111,0,134,13,48,48,0,95,2,95,3,95,
	1,92,2,92,3,112,4,73,134,15,48,49,0,95,
	2,112,0,29,140,0,134,16,108,50,100,106,13,78,
	111,118,111,32,114,101,99,111,114,100,33,0,106,9,
	80,97,114,97,98,233,110,115,0,20,2,134,17,48,
	51,0,95,2,112,0,73,134,19,48,52,0,48,53,
	0,95,2,106,5,68,97,116,97,0,112,1,108,54,
	100,12,0,112,1,73,134,20,48,52,0,48,53,0,
	95,2,106,5,78,111,109,101,0,112,1,95,5,112,
	1,73,134,21,48,52,0,48,53,0,95,2,106,6,
	84,101,109,112,111,0,112,1,108,55,100,103,6,0,
	12,1,112,1,73,134,22,48,56,0,95,2,112,0,
	73,25,105,134,24,4,0,0,80,6,134,25,48,49,
	0,95,2,112,0,31,87,134,28,108,37,100,95,6,
	48,57,0,48,53,0,95,2,112,0,106,5,68,97,
	116,97,0,1,112,0,48,57,0,48,53,0,95,2,
	112,0,106,5,78,111,109,101,0,1,112,0,48,57,
	0,48,53,0,95,2,112,0,106,6,84,101,109,112,
	111,0,1,112,0,4,3,0,20,2,134,29,48,58,
	0,95,2,112,0,73,25,162,134,33,108,59,100,95,
	6,12,1,32,203,0,134,34,48,51,0,95,2,112,
	0,73,134,36,48,52,0,48,53,0,95,2,106,5,
	68,97,116,97,0,112,1,108,54,100,12,0,112,1,
	73,134,37,48,52,0,48,53,0,95,2,106,5,78,
	111,109,101,0,112,1,95,5,112,1,73,134,38,48,
	52,0,48,53,0,95,2,106,6,84,101,109,112,111,
	0,112,1,108,55,100,103,6,0,12,1,112,1,73,
	134,39,48,56,0,95,2,112,0,73,134,40,48,60,
	0,95,2,112,0,73,134,42,127,3,55,0,83,69,
	76,69,67,84,32,68,97,116,97,44,32,78,111,109,
	101,44,32,84,101,109,112,111,32,70,82,79,77,32,
	82,101,103,105,115,116,114,111,115,32,79,82,68,69,
	82,32,66,89,32,116,101,109,112,111,0,134,43,48,
	48,0,95,2,95,3,95,1,92,2,92,3,112,4,
	73,134,45,108,61,100,95,6,20,1,134,48,48,60,
	0,95,2,112,0,73,134,49,48,60,0,95,1,112,
	0,73,134,51,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( RESOLVE )
{
   static const BYTE pcode[] =
   {
	13,1,0,116,70,0,133,229,0,126,1,1,0,95,
	1,92,15,34,28,45,134,1,48,38,0,103,2,0,
	95,1,1,108,35,100,95,1,92,2,12,2,112,1,
	73,134,2,48,32,0,103,2,0,95,1,1,112,0,
	73,134,3,173,1,25,208,134,4,48,38,0,103,2,
	0,92,16,1,106,2,32,0,112,1,73,134,5,48,
	32,0,103,2,0,92,16,1,112,0,73,134,6,108,
	41,100,106,20,80,85,90,90,76,69,32,110,111,32,
	116,101,109,112,111,32,100,101,32,0,108,55,100,103,
	6,0,12,1,72,106,9,80,65,82,65,66,201,78,
	83,0,20,2,134,8,48,40,0,103,4,0,112,0,
	73,134,9,9,82,5,0,134,11,108,45,100,20,0,
	134,12,121,82,6,0,134,15,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( FIMDEJOGO )
{
   static const BYTE pcode[] =
   {
	13,2,0,116,70,0,133,248,0,120,80,2,134,2,
	126,1,1,0,95,1,92,15,34,28,40,134,3,48,
	43,0,103,2,0,95,1,1,112,0,108,35,100,95,
	1,92,2,12,2,69,28,9,134,4,9,80,2,25,
	8,134,7,173,1,25,213,134,9,95,2,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_EXIT( HALT )
{
   static const BYTE pcode[] =
   {
	116,70,0,133,5,1,48,17,0,103,1,0,112,0,
	73,134,2,108,63,100,20,0,134,3,108,64,100,106,
	2,42,0,120,20,2,134,5,108,65,100,20,0,134,
	8,108,66,100,120,20,1,134,10,108,67,100,121,20,
	1,134,12,108,68,100,20,0,134,14,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( TIMETOSTR )
{
   static const BYTE pcode[] =
   {
	13,4,1,133,25,1,126,3,0,0,134,1,126,4,
	0,0,134,2,95,1,80,2,134,3,127,5,1,0,
	0,134,5,95,2,92,59,15,28,14,134,6,173,3,
	134,7,125,2,196,255,25,237,134,10,95,3,92,59,
	15,28,14,134,11,173,4,134,12,125,3,196,255,25,
	237,134,15,95,4,121,15,28,47,134,16,108,35,100,
	95,4,92,2,12,2,106,2,58,0,72,108,20,100,
	95,3,92,2,12,2,72,106,2,58,0,72,108,20,
	100,95,2,92,2,12,2,72,80,5,25,60,134,18,
	95,3,121,15,28,32,134,19,108,35,100,95,3,92,
	2,12,2,106,2,58,0,72,108,20,100,95,2,92,
	2,12,2,72,80,5,25,22,134,21,106,4,48,48,
	58,0,108,20,100,95,2,92,2,12,2,72,80,5,
	134,25,95,5,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( MYSTUFF )
{
   static const BYTE pcode[] =
   {
	13,2,0,133,54,1,127,1,69,0,83,69,76,69,
	67,84,32,42,32,70,82,79,77,32,116,97,98,101,
	108,97,32,87,72,69,82,69,32,105,100,32,61,32,
	58,112,73,100,32,65,78,68,32,110,117,109,32,61,
	32,58,112,78,117,109,32,65,78,68,32,100,97,116,
	97,32,61,32,58,112,68,116,0,134,1,108,36,100,
	106,5,58,112,73,100,0,95,1,12,2,80,2,134,
	3,108,69,100,95,1,95,2,108,42,100,106,5,58,
	112,73,100,0,12,1,106,2,120,0,12,4,80,1,
	134,4,108,36,100,106,6,58,112,78,117,109,0,95,
	1,12,2,80,2,134,5,108,69,100,95,1,95,2,
	108,42,100,106,6,58,112,78,117,109,0,12,1,106,
	2,121,0,12,4,80,1,134,8,100,110,7
   };

   hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
   static const BYTE pcode[] =
   {
	117,70,0,6,0,116,70,0,92,18,3,1,0,82,
	2,0,7
   };

   hb_vmExecute( pcode, symbols );
}

