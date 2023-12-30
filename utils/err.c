#include "err.h"

int assert(const int condition, const char *str, const int errcode) {
    if(condition) return 0;
    writestr(2, str);
    _exit(errcode);
}
