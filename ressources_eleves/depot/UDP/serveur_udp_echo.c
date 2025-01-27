#include "udp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char** argv) {
	traiter_commande(/*A COMPLETER*/, argv[0], "<port>\nmauvais nombre d'arguments");
	traiter_commande(/*A COMPLETER*/, argv[0], "<port>\n<port> est un port non réservé");

//----------------prototype socket

int socket(int domain, int type, int protocol);

int close(int sock);

int bind(int sock, const struct sockaddr *address, socklen_t
addr_len);

ssize_t sendto(int sock, const void *buf, size_t len, int flags,
const struct sockaddr *dest_addr, socklen_t addr_len);
ssize_t recvfrom(int sock, void *buf, size_t len, int flags,
struct sockaddr *src_addr, socklen_t *addr_len);



int sock ;
sock = socket(AF_INET, SOCK_DGRAM, 0);

if (sock == -1){
	printf(« Echec creation socket\n »);
	exit(1);}
	
//--------------------Bind
...
struct sockaddr_in addr_srv ;
...
// on initialise la structure d'adresse en la remplissant de '0'
bzero(&addr_srv, sizeof(addr_srv));
// on initialise la structure d'adresse avec les valeurs souhaitées
addr_srv.sin_family = AF_INET ;
addr_srv.sin_port = htons(5896) ;
addr_srv.sin_addr.s_addr = htonl(INADDR_ANY) ;
// on appelle la fonction (on suppose que « sock » est initialisée)
if (bind (sock, (struct sockaddr*) &addr_srv, sizeof(addr_srv)) == -1) {
printf(« Echec attachement\n ») ;
exit(1) ;
}

//--------------------envoi

...
struct sockaddr_in dest_addr ;
...
// on définit le message à envoyer
char* msg = "coucou";

// on initialise la structure d'adresse
bzero(&dest_addr, sizeof(dest_addr));

// on initialise la structure d'adresse avec les valeurs souhaitées
dest_addr.sin_family = AF_INET ;
dest_addr.sin_port = htons(5896) ;
inet_aton("192.168.1.3", &dest_addr .sin_addr) ;

// on appelle la fonction (on suppose que « sock » est initialisée)
if (sendto (sock, msg, strlen(msg), 0,
(struct sockaddr*) &dest_addr, sizeof(dest_addr)) == -1) {
printf("Echec envoi\n") ;
exit(1) ;
}

//------------------reception

...
struct sockaddr_in src_addr ;
socklen_t addr_len ;
...
// on définit un tableau de réception
char buf[32] ;

// on appelle la fonction (on suppose que « sock » est initialisée)
addr_len = sizeof(src_addr) ;
if (recvfrom (sock, buf, sizeof(buf), 0,
(struct sockaddr*) &src_addr, &addr_len) == -1) {
printf(« Echec réception\n ») ;
exit(1) ;
}

//----------------fermeture du socket
close(sock);


	exit(0);
}


