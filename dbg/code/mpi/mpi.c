#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <mpi.h>

#define MAXLINE 20
#define ECHO 42

int main(int argc, char **argv)
{
	int me, n, p;
	MPI_Status status;
	char line[MAXLINE];

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	MPI_Comm_rank(MPI_COMM_WORLD, &me);

	/* astept hello-uri de la cei cu rang mai mic */
	n = me;
	while (n){
		MPI_Recv(line, MAXLINE, MPI_CHAR, MPI_ANY_SOURCE, ECHO, MPI_COMM_WORLD, &status);
		printf("%d: Primit mesaj <%s> de la %d.\n", me, line, status.MPI_SOURCE);
		n--;
	}

	/* trimit hello-uri la ceilalți */
	n = p - me - 1;
	while (n){
		sprintf(line, "Hello from %d.", me);
		MPI_Send(line, strlen(line)+1, MPI_CHAR, n + me, ECHO, MPI_COMM_WORLD);
		n--;
	}

	MPI_Finalize();
	return 0;
}
