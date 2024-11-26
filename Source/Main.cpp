#include "Main.hpp"

int main()
{
    auto engine* = new Engine;
    engine->Innit();
    engine->Run();
    engine->End();
    delete engine;

}