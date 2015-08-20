#include "server.h"

/* soname lib<NAME>.so.<VERSION_NB>
 * realname lib<NAME>.so.<VERSION_NB>.<MINOR_NB>[.<RELEASE_NB>]
 * when requesting a library compiler uses lib<NAME>.so
 *
 * ldconfig examines files in specific locations and creates
 * sonames- symbolic link to the real name and sets up the cache (/etc/ld.so.cache)
 *
 * linker name is symbolic link to the latest soname (recommended) or latest real name.
 * set LD_LIBRARY_PATH for testing purposes or copy libraries
 * to standard location
 *
 * /usr/lib- libraries that are part of the system
 * /lib- libraries needed during startup i.e (PAM modules in /lib/security)
 * /usr/local/lib- libraries that are not part of the system
 * if library calls program that can only be called by the library it should be 
 * placed in /usr/local/libexec (/usr/libexec for distribution)
 */
static void internal_goodbye(){
    puts("DEV:Goodbye from shared lib");
}

void say_goodbye(const char* name){
    puts("===============\n");
    internal_goodbye();
}
