package.path = '/home/alexey/working/cpp-edu/lua/run_module/?.lua;' .. package.path
require("const")

function f()
    print("f()")
    print("VERSION ", _VER)
end

function print_str(str)
    print(str)
end

