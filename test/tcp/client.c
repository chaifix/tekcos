#include "tekcos.h"

int main()
{
    tk_init();

    tk_TCPsocket * csk; 
    tk_IPaddress ip = { 
        tk_strtohl("127.0.0.1"), 
        6666
    };
    const char* str = "hello, tekcos\n";
    csk = tk_tcp_open(ip);
    if (csk)
    {
        int len = 0; 
        tk_tcp_send(csk, str, strlen(str), len);
    }
}