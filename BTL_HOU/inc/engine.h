#ifndef ENGINE
#define ENGINE

#include "common.h"
#include "AppController.h"


using namespace std;

class Engine{
public:
    Engine();
    ~Engine();
    void start_application();

private:
    Controller ctl;
};

#endif
