// Lua 5.3.3
#include <iostream>
#include <string>
#include <thread>
#include <memory>

extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

using namespace std;
using threadP = shared_ptr<thread>;

threadP run(const string& path)
{
    auto execFun = [path](){

        lua_State *L = luaL_newstate();
        if(L != nullptr){
            luaL_openlibs(L);
            cout << "started\n";
            int ret = luaL_dofile(L,path.c_str());
            if(ret > 0){
                cout << "lua exec error\n";
            }
            cout << "ended\n";
            lua_close(L);
        }
    };

    threadP thr = std::make_shared<thread>(execFun);
    return thr;
}

int main(int argc, char *argv[])
{
    auto threadP1 = run("/home/alexey/working/cpp-edu/lua/hello_async/s1.lua");

    threadP1->join();


    return 0;
}
