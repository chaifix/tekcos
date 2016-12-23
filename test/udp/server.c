#include "../../tekcos.h"
#include <stdio.h>
int main()
{
#ifdef _WIN32
    tk_init(); 
#endif
    tk_UDPsocket* sk = tk_udp_open(6666);
    tk_UDPpack p;
    tk_UDPpack confirm;
    confirm.data = "i got it\n";
    confirm.len = 9;
    while (1)
    {
        tk_udp_recvfrom(sk, &p);
        printf("ip address: %s\n port number: %d\n data:\n %s\n", 
            tk_hltostr(p.ip.host), 
            p.ip.port, 
            p.data);
        confirm.ip = p.ip;
        tk_udp_sendto(sk, &confirm);
    }
    tk_udp_close(sk);
}
