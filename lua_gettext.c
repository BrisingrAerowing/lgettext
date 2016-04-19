/*
 * $Id: lua_gettext.c,v 1.15 2005/09/01 20:08:35 cpressey Exp $
 */

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#if 1
#include <libintl.h>
#include <locale.h>
#else
#include "libintl.h"
#endif

#ifndef LC_PAPER
#define LC_PAPER (-1)
#endif
#ifndef LC_NAME
#define LC_NAME (-1)
#endif
#ifndef LC_ADDRESS
#define LC_ADDRESS (-1)
#endif
#ifndef LC_TELEPHONE
#define LC_TELEPHONE (-1)
#endif
#ifndef LC_MEASUREMENT
#define LC_MEASUREMENT (-1)
#endif
#ifndef LC_IDENTIFICATION
#define LC_IDENTIFICATION (-1)
#endif

extern int _nl_msg_cat_cntr;

/*** Prototypes ***/

LUA_API int luaopen_lgettext(lua_State *);

/*** Globals ***/

const char *package = "";
const char *locale_dir = "";

/*** Methods ***/

static int
lua_gettext_init(lua_State *L __unused)
{
	setlocale(LC_ALL, "");
	bindtextdomain(package, locale_dir);
	textdomain(package);

	return(0);
}

static int
lua_gettext_set_package(lua_State *L)
{
	package = luaL_checkstring(L, 1);

	return(0);
}

static int
lua_gettext_set_locale_dir(lua_State *L)
{
	locale_dir = luaL_checkstring(L, 1);

	return(0);
}

static int
lua_gettext_gettext(lua_State *L)
{
	lua_pushstring(L, gettext(luaL_checkstring(L, 1)));

	return(1);
}

static int lua_gettext_dgettext(lua_State *L)
{
    
    lua_pushstring(L, dgettext(luaL_checkstring(L, 1), luaL_checkstring(L, 2)));
    
    return (1);
    
}

static int lua_gettext_dcgettext(lua_State *L)
{
    lua_pushstring(L, dcgettext(luaL_checkstring(L, 1), luaL_checkstring(L, 2), luaL_checkinteger(L, 3)));
    
    return (1);
}

static int lua_gettext_ngettext(lua_State *L)
{
    lua_pushstring(L, ngettext(luaL_checkstring(L, 1), luaL_checkstring(L, 2), luaL_checkinteger(L, 3)));
    
    return (1);
}

static int lua_gettext_dngettext(lua_State *L)
{
    lua_pushstring(L, dngettext(luaL_checkstring(L, 1), luaL_checkstring(L, 2), luaL_checkstring(L, 3), luaL_checkinteger(L, 4)));
    
    return (1);
}

static int lua_gettext_dcngettext(lua_State *L)
{
    lua_pushstring(L, dcngettext(luaL_checkstring(L, 1), luaL_checkstring(L, 2), luaL_checkstring(L, 3), luaL_checkinteger(L, 4), luaL_checkinteger(L, 5)));
    
    return (1);
}

static int
lua_gettext_notify_change(lua_State *L __unused)
{
	++_nl_msg_cat_cntr;

	return(0);
}

/**** Binding Tables ****/

const luaL_Reg gettext_methods[] = {
	{"init",		lua_gettext_init },
	{"set_package",		lua_gettext_set_package },
	{"set_locale_dir",	lua_gettext_set_locale_dir },
	{"gettext",		lua_gettext_gettext },
    {"dgettext",    lua_gettext_dgettext },
    {"dcgettext",   lua_gettext_dcgettext },
    {"ngettext",    lua_gettext_ngettext },
    {"dngettext",   lua_gettext_dngettext },
    {"dcngettext",  lua_gettext_dcngettext },
	{"notify_change",	lua_gettext_notify_change },

	{0, 0}
};

#define lua_setconst(name, index) {lua_pushnumber(L, name); lua_setfield(L, index, #name);}

/*** REGISTER ***/

LUA_API int
luaopen_lgettext(lua_State *L)
{
	lua_newtable(L);
    luaL_setfuncs(L, gettext_methods, 0);
    lua_setconst(LC_COLLATE, -2);
    lua_setconst(LC_CTYPE, -2);
    lua_setconst(LC_MONETARY, -2);
    lua_setconst(LC_NUMERIC, -2);
    lua_setconst(LC_TIME, -2);
    lua_setconst(LC_MESSAGES, -2);
    lua_setconst(LC_PAPER, -2);
    lua_setconst(LC_NAME, -2);
    lua_setconst(LC_ADDRESS, -2);
    lua_setconst(LC_TELEPHONE, -2);
    lua_setconst(LC_MEASUREMENT, -2);
    lua_setconst(LC_IDENTIFICATION, -2);
    
	return(1);
}
