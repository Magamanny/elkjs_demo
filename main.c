#include <stdio.h>
#include "elk.h"
int main()
{
    char mem[200];
    struct js *js = js_create(mem, sizeof(mem));  // Create JS instance
    printf("Hello JS\n");
    jsval_t v = js_eval(js, "1 + 2 * 3", ~0);     // Execute JS code
    printf("result: %s\n", js_str(js, v));        // result: 7
    return 0;
}