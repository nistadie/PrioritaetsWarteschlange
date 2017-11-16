/**************************************************************
* Macros für Cross-Plattform Kompatibilität.
* Autor: Heinz-Josef Eikerling, HS OS
* 22.10.2014: Fertigstellung
* To Do:
* - %
**************************************************************/

#ifndef ENVIRONMENT_H
#define	ENVIRONMENT_H


#ifdef __GNUC__
#include <stdio.h>
#define SPRINTF sprintf
#else
#ifdef _WIN32
#define SPRINTF sprintf_s
#else
#define SPRINTF sprintf
#endif
#endif

#endif	

