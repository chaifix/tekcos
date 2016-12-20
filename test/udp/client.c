#include "tekcos.h"
#include <stdio.h>

int main()
{
    tk_init(); 
    tk_UDPsocket* sk = tk_udp_open(7777); 
    const char* str = "hello, tekcos\n";
    tk_UDPpack pack = {
        {
            tk_strtohl("127.0.0.1"),
            6666
        },
        strlen(str),
        str,
    };
    // send 3 package
    for (int i = 0; i < 3 ;i++)
        tk_udp_sendto(sk, &pack);
    tk_UDPpack p; 
    while (1)
    {
        tk_udp_recvfrom(sk, &p); 
        printf(p.data);
    }
    tk_udp_close(sk);
}