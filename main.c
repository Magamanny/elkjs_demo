#include <stdio.h>
#include "elk.h"
// C function that adds two numbers. Will be called from JS
void log(char *txt) {
  printf("%s",txt);
}
int main()
{
    char mem[2000];
    struct js *js = js_create(mem, sizeof(mem));  // Create JS instance
    jsval_t v;
    printf("Hello JS\n");
    v = js_import(js, log, "vs");        // Import C function "sum"
    js_set(js, js_glob(js), "f", v);      // Under the name "f"

    v = js_eval(js, "f('ali\r\n');", ~0); // Call "f"
    printf("result: %s\n", js_str(js, v));   // result: 7
    // run loop
    v = js_eval(js,
        "let a = 0;"
        "while (a<100){"
        "f('no');"
        "a++;"
        "let t = 'aasd\r\n';"
        "f(t);"
        "}"
        "f('ok');",
        ~0);     // Execute JS code
    printf("result: %s\n", js_str(js, v));   // result: 7
    return 0;
}