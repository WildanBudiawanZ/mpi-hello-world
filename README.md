# Installation, Configuration, and Hello MPI

Linux Mint 18.3 64-bit

Requirement:
1. C compiler
2. python 2.2 (or above)

### Install ``build-essential`` using

```
sudo apt-get install build-essential
```

### ``wget`` required MPICH version using


```
wget https://www.mpich.org/static/downloads/1.2.1/mpich2-1.2.1.tar.gz
```

### Install MPICH
```
tar xzvf mpich2-1.2.1.tar.gz
cd mpich2-1.4.1/
./configure
make
sudo make install
```

check the installation result using:
```mpich2version```

sample output:
```
MPICH2 Version:    	1.2.1
MPICH2 Release date:	Unknown, built on Thu Sep  2 15:08:58 WIB 2021
MPICH2 Device:    	ch3:nemesis
MPICH2 configure: 	
MPICH2 CC: 	gcc  -O2
MPICH2 CXX: 	c++  -O2
MPICH2 F77: 	 
MPICH2 F90:
```

### Config MPI MPD
```
cd $HOME
touch .mpd.conf
chmod 600 .mpd.conf
nano .mpd.conf
```

add following text to the ``.mpd.conf`` and save
```
MPD_SECRETWORD=12345
```

restart MPD service using
```
mpdboot
```

### Install Open MPI

install Open MPI
```
sudo apt-get install openmpi-bin
```
check Open MPI Installation
```
ompi_info
```

# Hello MPI

### Save ``hello_mpi.c`` in a directory
```
#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

	int numberOfProcessors;
	int rank;
	int namelen;
	char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc,&argv);
	printf("Hello MPI\r\n");

	MPI_Comm_size(MPI_COMM_WORLD,&numberOfProcessors);
	printf("Jumlah processor = %d\r\n", numberOfProcessors);

	MPI_Get_processor_name(processor_name, &namelen);
	printf("Nama Processor = %s\r\n", processor_name);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("Proses pada %d\r\n", rank);	

	MPI_Finalize();
	return 0;

}
```

### Compilation

select the directory and compile
```
mpicc hello_mpi.c -o hello_mpi -Wall
```

### Run MPI Apps
```
mpiexec -n 2 ./hello_mpi
```

``-n 2`` for running under 2 pocess, ``mpd &``for ``mpiexec`` failure tracing
