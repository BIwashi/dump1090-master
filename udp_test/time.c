#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>
int main(int argc, char **argv)
{
    struct tm tm;

    // 接続情報を渡す用-----------------
    char *ipadd = "0.0.0.0";
    unsigned short p = 30000;

    if (argc > 1)
    {
        if (argc > 3)
        {
            printf("Usage: <ip-addr> <port> \n");
            return -1;
        }
        ipadd = argv[1];
        p = atoi(argv[2]);
    }
    // 終わり--------------------------

    char *
        dayofweek[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t t = time(NULL);
    localtime_r(&t, &tm);
    printf("%s %hu %04d-%02d/%02d-%s-%02d:%02d:%02d\n",
           ipadd, p, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
           dayofweek[tm.tm_wday], tm.tm_hour, tm.tm_min, tm.tm_sec);
    return 0;
}