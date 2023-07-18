*Setting up the development environment for Linux kernel modules*
---

# Location of initramfs

In common case: `mkdir -pv /usr/src/initramfs/busybox`
```sh
$ cd /busybox; realpath .
/src1/PEi5B
$ mkdir /dst1/PEi5B/usr2
$ ln -s /dst1/PEi5B/usr2
$ cd usr2
```

# Structure of initramfs
$ mkdir -pv {bin,sbin,etc,proc,sys,usr/{bin,sbin}}
-a, --archive		same as -dR --preserve=all
-d			same as -P --preserve=links
-P, --no-dereference	never follow symbolic links in SOURCE
-L, --dereference	always follow symbolic links in SOURCE
--preserve[=ATTR_LIST]	preserve the specified attributes
why we save no dereference links, cpio it does?
$ cp -av /busybox/usr1/* .

# Create the initial process

/busybox/usr2/init:
```sh
#!/bin/sh

mount -t proc none /proc
mount -t sysfs none /sys
mount -t debugfs none /sys/kernel/debug
mount -t devtmpfs none /dev

b1: mount -o ro /dev/sdxN /mnt/root; b2: zxc;

echo -e "\nBoot took $(cut -d' ' -f1 /proc/uptime) seconds\n"

a1: setsid /bin/cttyhack /bin/sh;	a2: exec /bin/sh;	b11: exec switch_root /mnt/root /sbin/init
```

/busybox/usr2/init:
```sh
a21: chmod 755 init;	a22: chmod +x init;
```

# cpio

```sh
# print just file after file (recursively (like ls -AilvR) and not dereference links)
# in dir `.' without any delimiters (by fact null character ('\0') is delimiter)
a1: find . -print0 | \;			a2: find . | \;
a11: cpio --null -ov --format=newc | \;	a22: cpio -H newc -o > /busybox/usr2.cpio
a111: gzip -9 > /busybox/usr2.cpio.gz;	a222: cat usr2.cpio | gzip > usr2.cpio.igz
```

# Execute QEMU

```
qemu-system-x86_64	\
-kernel /linux/arch/x86_64/boot/bzImage # should: /linux/bldN/arch/*/boot/bzImage \
-initrd /busybox/usr2.cpio.gz	\
-nographic -append "console=ttyS0" -enable-kvm
```

[r1](https://mgalgs.io/2015/05/16/how-to-build-a-custom-linux-kernel-for-qemu-2015-edition.html)
[r2](https://github.com/grossamos/homepage/blob/02859fc0b98c4137c9e16433669f43d9ea3f5e2e/content/articles/kenel_development_setup_with_qemu.md)
[r3](mudongliang.github.io/2017/09/12/how-to-build-a-custom-linux-kernel-for-qemu.html)
