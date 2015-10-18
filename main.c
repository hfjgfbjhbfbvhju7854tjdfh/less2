#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main () {

int sock;
int listener;
char buf [1024];
int bytes_read;
struct sockaddr_in addr;

listener = socket (AF_INET, SOCK_STREAM, 0);
if (listener < 0) {
   printf("Wrong socket\n");
   exit (1);
}

addr.sin_family = AF_INET;
addr.sin_port = htons(10000);
addr.sin_addr.s_addr = htonl(INADDR_ANY);
if (bind (listener, (struct sockaddr*) &addr, sizeof(addr)) ) {
  printf ("Wrong is bind\n");
  exit (1);
}

listen (listener, 1);

while (1) {

  sock  = accept (listener, NULL, NULL);
  if (sock<0) { 
    printf ("Wrong is sock\n");
    exit (1);
   }

   
   while (1) {
     bytes_read = recv (sock, buf, 1024, 0);
     if (bytes_read <=0 ) break;
     printf ("%s\n", buf);
     send (sock, buf, bytes_read, 0);
   }
   
   close(sock);

}


return 0;
}
 
