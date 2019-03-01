# kernel_panic_in_bootloader

## Let's be ready first. 
`i'm using Ubuntu 16.04 64-bit`; We need to install:
**1.** cross-toolchain for ARM (to build `ARM binaries` on x86 platform ([`cross-compilation`](https://en.wikipedia.org/wiki/Cross_compiler))):
```
$ sudo apt-get install gcc-arm-linux-gnueabi
```
**2.** [QEMU](https://wiki.qemu.org/Main_Page) for ARM architecture emulation:
```
$ sudo apt-get install qemu-system-arm
```
**3.** 'git' tool:
```
$ sudo apt-get install git
```
**4.** kernel build dependencies:
```
$ sudo apt-get install make bison flex libssl-dev
```

## task #1
> Build “Hello world” module, run it on QEMU. Try to dereference null pointer in the module and see results.
Add ability to change message by  trough module parameters (use MODULE_PARM_DESC() in your module).

First of all we need to download Linux Kernel sources and checkout on some release:
```
$ git clone git://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git
$ cd linux
$ git checkout -b v4.20 v4.20
```

and build Linux Kernel (to get `zImage`): 
```
$ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- multi_v7_defconfig
$ make -j4 ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- zImage
```
default zImage location is `arch/arm/boot/zImage`.