#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#include <stdio.h>
#include <string.h>

int main ()
{
  //1. 受信するアドレスを構築する
  struct addrinfo hints;
  memset (&hints, 0, sizeof (hints));
  hints.ai_socktype = SOCK_DGRAM;

  struct addrinfo *bind_address;
  getaddrinfo ("localhost", "9002", &hints, &bind_address);


  //2. ソケットを作成する
  int  socket_listen;
  socket_listen = socket (bind_address->ai_family,
              bind_address->ai_socktype,
              bind_address->ai_protocol);
  if (socket_listen < 0)
  {
      fprintf (stderr, "socket() failed. (%d)\n", errno);
      return 1;
  }


  //3. ローカルアドレスをソケットにバインドする
  if (bind (socket_listen, bind_address->ai_addr, bind_address->ai_addrlen))
  {
      fprintf (stderr, "bind() failed. (%d)\n", errno);
      return 1;
  }
  freeaddrinfo (bind_address);


  //4. クライアントの接続を待つ
  while (1)
  {
      struct sockaddr_storage client_address;
      socklen_t client_len = sizeof (client_address);

      char read[4096];
      memset(read, 0, sizeof(read));
      int bytes_received = recvfrom (
                                    socket_listen, 
                                    read, 
                                    4096, 
                                    0,
                                    (struct sockaddr *) &client_address,
                                    &client_len);
      if (bytes_received < 1)
      {
        fprintf (stderr, "connection closed. (%d)\n", errno);
        return 1;
      }
      printf("receiving: %s", read);
  }

  //5. ソケットを閉じる
  close(socket_listen);
  printf ("Finished.\n");

  return 0;
}