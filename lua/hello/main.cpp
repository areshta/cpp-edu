// Lua 5.3.3
#include <iostream>

extern "C" {
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
}

using namespace std;

int LuaOutputToCpp(lua_State *luaVM) {
  string strSource = lua_tostring(luaVM, 1);
  cout << "from_lua: " << strSource << endl;
}

int main(int argc, char *argv[]) {

  lua_State *l = luaL_newstate();
  if (l != nullptr) {
    luaL_openlibs(l);
    // lua_register(l, "LuaOutputToCpp", LuaOutputToCpp);

    std::string tmpPath = "package.path = package.path .. "
                          "';/home/alexey/working/cpp-edu/lua/hello/?lua'";
    luaL_dostring(l, tmpPath.c_str());

    //    int ret =
    //        luaL_dofile(l,
    //        "/home/alexey/working/cpp-edu/lua/hello/script.lua");
    int ret =
        luaL_loadfile(l, "/home/alexey/working/cpp-edu/lua/hello/script.lua");
    if (ret > 0) {
      cout << "lua load error\n";
    }

    ret = lua_pcall(l, 0, LUA_MULTRET, 0);
    if (ret > 0) {
      cout << "lua exec error\n";
    }

    lua_getglobal(l, "print_str");
    lua_pushstring(l, "lua print_str from cpp");
    lua_pcall(l, 1, 1, 0);
    cout << lua_tostring(l, -1) << "\n";
    lua_pop(l, 1);

    lua_close(l);
  }

  return 0;
}
