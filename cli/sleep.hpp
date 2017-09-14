#ifndef __SLEEP_HPP__

#ifndef NOTWIN
#include <windows.h>
#endif // NOTWIN

#ifdef NOTWIN
#include <unistd.h>
#endif // NOTWIN

void SLEEP(int);

#endif // __SLEEP_HPP__

