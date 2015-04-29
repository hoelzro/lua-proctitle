#include <lua.h>
#include <lauxlib.h>
#include <string.h>

static char **
find_argv(lua_State *L)
{
    extern char *__progname;

    return &__progname;
}

static int
set_proctitle(lua_State *L)
{
    const char *title = luaL_checkstring(L, 1);
    char **argv = find_argv(L);

    // XXX no length check
    strcpy(argv[0], title);

    return 0;
}

int
luaopen_proctitle(lua_State *L)
{
    lua_pushcfunction(L, set_proctitle);
    return 1;
}
