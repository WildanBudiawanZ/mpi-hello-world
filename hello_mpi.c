#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

	int numberOfProcessors;
	int rank;
	int namelen;
	char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc,&argv);
	printf("Hello MPI test test test\r\n");

	MPI_Comm_size(MPI_COMM_WORLD,&numberOfProcessors);
	printf("Jumlah processor = %d\r\n", numberOfProcessors);

	MPI_Get_processor_name(processor_name, &namelen);
	printf("Nama Processor = %s\r\n", processor_name);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("Proses pada %d\r\n", rank);	

	MPI_Finalize();
	return 0;

}
