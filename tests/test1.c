#include "log4c.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char* test_out;

void test_log(const char* command) {
    test_out = calloc(strlen(command), 1);
    strcpy(test_out, command);
}

int main(int argc, char **argv) {
    Log4CAPIContext ctx = { 
        .log_function = test_log
    };
    Log4CContextRef ctxRef = log4c_create_context(&ctx);
    log4c_context(ctxRef, "my message: %s", "passes");
    assert(strstr(test_out, "passes") != NULL);
}
