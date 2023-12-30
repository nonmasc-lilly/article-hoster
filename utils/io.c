#include "io.h"

int writestr(int fd, const char *str) {
    int count;
    const char *strp;
    for(strp = str; *strp; strp++);
    count = (int)(strp-str);
    return write(fd, str, count);
}
