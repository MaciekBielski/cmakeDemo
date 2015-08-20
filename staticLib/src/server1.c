#include "server.h"

static void internal_hello(){
    puts("Hello from static library");
}

void say_hello(const char* nm){
    internal_hello();
    printf("Your name: %s \n",nm);
}

