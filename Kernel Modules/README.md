# Basic Kernel Module which prints string while loading and unloading.

## Usage

- Inject Module
```
make all
sudo insmod Varad.ko
lsmod
```
-------------------------
- Remove Module
```
suod rmmod Varad
make clean
lsmod
```
