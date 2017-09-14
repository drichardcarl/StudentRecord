#include "sleep.hpp"

void SLEEP(int ms){
#ifndef NOTWIN
    Sleep(ms);
#endif
#ifdef NOTWIN
    usleep(ms * 1000);   // usleep takes sleep time in us (1 millionth of a second)
#endif
}
