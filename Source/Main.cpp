#include "Main.hpp"

int main()
{
    auto* engine = new Engine;
    engine->Init();
    engine->Run();
    engine->End();
    delete engine;

}