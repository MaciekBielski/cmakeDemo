#include <stdio.h>

/* functions that has internal linkage attribute
 * must not be declared in header file
 */
//static void internal_hello();
void say_hello(const char* name);
//static void internal_goodbye();
void say_goodbye(const char* name);
