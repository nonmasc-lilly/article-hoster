#include "../main.h"

#ifndef ERR_H
#define ERR_H

typedef int ERR;
typedef enum {
    E_SOCK_NO_INIT=0,
    E_SOCK_NO_BIND=1,
    E_SOCK_NO_LISTEN=2,
    E_SOCK_NO_ACCEPT=3
} SOCKERR;
static const char *SOCKERRMSG = "socket error stored in error code \n"
                         "\t(see SOCKERR defined in utils/err.h for more details)\n";

int assert(const int condition, const char *str, const int errcode);

#endif
