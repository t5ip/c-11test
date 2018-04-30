#include <future>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

/* 
    Prints the stdin lines using  asynchronous or deferred launch policy.
    Control the mode using bAsync.
*/

int printline(const std::string &in)
{
    int i=3;
    while (0 < i)
    {
        i--;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "#" << std::endl;  
    }
    
    std::cout << in << std::endl;

    return 0;
}

int main()
{
    bool bAsync = true; // deferred if false

    std::string line;
    
    std::vector<std::future<int> > futures;
    while (std::getline(std::cin, line))
    {
        if (true == bAsync)
        {
            futures.push_back(std::async(std::launch::async,printline,line));
        }
        else
        {
            futures.push_back(std::async(printline,line));
        }
    }

    for (auto &e : futures)
    {
        e.get();
    }

    return 0;    
}
