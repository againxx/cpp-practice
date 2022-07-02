#include <uv.h>

static uv_loop_t* loop;
static uv_process_options_t options;

int main() {
    loop = uv_default_loop();
    char* args[3];
    args[0] = "sleep";
    args[1] = "100";
    args[2] = NULL;
    return 0;
}
