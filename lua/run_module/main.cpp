// Lua 5.3.3
#include <iostream>

extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

using namespace std;



int main(int argc, char *argv[])
{

    lua_State *l = luaL_newstate();
    if(l != nullptr){
        luaL_openlibs(l);

       int ret = luaL_dofile(l,"/home/alexey/working/cpp-edu/lua/run_module/module.lua");
       if(ret > 0){
            cout << "lua exec error\n";
        }
        lua_getglobal(l,"f");
        lua_pcall(l, 0, 0, 0);
        lua_getglobal(l,"print_str");
        lua_pushstring(l,"lua print_str from cpp");
        lua_pcall(l, 1, 0, 0);

        lua_close(l);
    }

    return 0;
}
