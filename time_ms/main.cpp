#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

int main()
{
    std::chrono::time_point<std::chrono::system_clock> now = 
        std::chrono::system_clock::now();

    auto duration = now.time_since_epoch();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    auto sec = std::chrono::duration_cast<std::chrono::seconds>(duration).count();
    auto mscount = ms - sec*1000L;

    auto time = std::time(nullptr);
    auto ltime = std::localtime(&time);
    std::ostringstream utcTimeStream;
    utcTimeStream << std::put_time(ltime, "%FT%T.") << std::setfill('0') << std::setw(3) << mscount<< std::put_time(ltime, "%z");
    std::cout << utcTimeStream.str() << std::endl; 

    return 0;
}
