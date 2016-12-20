#include "../../tekcos.h"
#include <stdio.h>
int main()
{   
    tk_init();

    tk_TCPsocket* sk;
    tk_IPaddress ip = {
        0,
        6666
    }; 
    sk = tk_tcp_open(ip);

    tk_TCPsocket* csk; 
    while (1)
    {
        csk = tk_tcp_accept(sk);
        if (csk)
        {
            int len = 0;
            char buffer[2048] ;
            tk_tcp_recv(csk, buffer, 2048, &len);
            if (buffer)
            {
                printf((const char*)buffer);
            }
            tk_tcp_close(csk);
        }
    };

    return 0; 
}