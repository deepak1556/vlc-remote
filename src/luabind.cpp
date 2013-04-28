#include <iostream>

extern "C"{
#include "include/lua.h"
#include "include/lualib.h"
#include "include/lauxlib.h"
}

lua_State *L;

int main(int argc, char *argv[]){
  for(int n=1;n<argc;++n){
    const char* file = argv[n];

    L = lua_open();
    luaL_openlibs(L); 

    //    lua_register(L, "" , );

    int s = luaL_loadfile(L,file);
    if(s==0)
      lua_pcall(L,0,LUA_MULTRET,0);

    lua_close(L);
  }
  return 0;
}

