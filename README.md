# mpi-hello-world

Config MPI:

Linux Mint 18.3 64-bit

Requirement:
1. C compiler
2. python 2.2 (or above)


First step, install ``build-essential`` using

```
sudo apt-get install build-essential
```

then, ``wget`` required MPICH version using


```
wget https://www.mpich.org/static/downloads/1.2.1/mpich2-1.2.1.tar.gz
```

```
tar xzvf mpich2-1.2.1.tar.gz
cd mpich2-1.4.1/
./configure
make
sudo make install
```
