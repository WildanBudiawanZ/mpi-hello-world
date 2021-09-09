# Installation, Configuration, and Hello World MPI

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
cek Open MPI
```
ompi_info
```
