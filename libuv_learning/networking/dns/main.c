#include <stdio.h>
#include <uv.h>

static uv_loop_t* loop;

void on_resolved(uv_getaddrinfo_t* resolver, int status, struct addrinfo* res) {
    if (status < 0) {
        fprintf(stderr, "getaddrinfo callback error %s\n", uv_err_name(status));
    }

    char addr[17] = { '\0' };
    uv_ip4_name((struct sockaddr_in*)res->ai_addr, addr, 16);
    printf("%s\n", addr);
    uv_freeaddrinfo(res);
}

int main() {
    loop = uv_default_loop();
    struct addrinfo hints;
    hints.ai_family = PF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = 0;

    uv_getaddrinfo_t resolver;
    printf("baidu.com is ...");
    int r = uv_getaddrinfo(loop, &resolver, on_resolved, "baidu.com", "443", &hints);

    if (r) {
        fprintf(stderr, "getaddrinfo call error %s\n", uv_err_name(r));
        return 1;
    }

    return uv_run(loop, UV_RUN_DEFAULT);
}
