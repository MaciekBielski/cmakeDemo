#include <stdio.h>
#include "server.h"

/* before running this set LD_LIBRARY_PATH 
 * on that directory, that is only for testing
 */
int main(){
    puts("\nUSES release version\n\n");
    const char* test_name="alf";
    say_hello(test_name);
    say_goodbye(test_name);
}
