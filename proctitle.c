/*
 * Copyright (c) 2015 Rob Hoelz <rob AT SIGN hoelz.ro>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
*/

#include <lua.h>
#include <lauxlib.h>
#include <string.h>

static char *
find_argv0(lua_State *L)
{
    extern char *__progname;

    return __progname;
}

static int
set_proctitle(lua_State *L)
{
    const char *title = luaL_checkstring(L, 1);
    char *argv0 = find_argv0(L);

    // XXX no length check
    strcpy(argv0, title);

    return 0;
}

int
luaopen_proctitle(lua_State *L)
{
    lua_pushcfunction(L, set_proctitle);
    return 1;
}
