#ifndef __CLRSCR_HPP__
#define __CLRSCR_HPP__

#ifdef NOTWIN
#define CLRSCR(); std::system("clear");
#endif // NOTWIN

#ifndef NOTWIN
#define CLRSCR(); std::system("cls");
#endif // NOTWIN

#endif // __CLRSCR_HPP__

