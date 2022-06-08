#include <stdio.h>
#include "elk.h"
// C function that adds two numbers. Will be called from JS
int sum(int a, int b) {
  return a + b;
}
int main()
{
    char mem[200];
    struct js *js = js_create(mem, sizeof(mem));  // Create JS instance
    jsval_t v;
    printf("Hello JS\n");
    v = js_import(js, sum, "iii");        // Import C function "sum"
    js_set(js, js_glob(js), "f", v);      // Under the name "f"

    v = js_eval(js, "f(4,3);", ~0); // Call "f"
    printf("result: %s\n", js_str(js, v));   // result: 7
    // run loop
    v = js_eval(js,
    "let a=0;"
    "while(a<100)"
    "a++;"
    "let text = a.toString();"
    "log(text);"
    , ~0);     // Execute JS code
    return 0;
}