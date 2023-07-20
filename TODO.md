[The difference between char device and block device](lines/b18f33328e0f4b26d3a78e7e81b8d9e4427cc43da706e14fae25aebec7581862)

- [An Introduction to Device Drivers](M0Bah.md)

### 
- [Building and Running Modules](uMc0D.md)
- [x] [Setup development environemt](mods/setup/setup.md)
- [ ] [add kvm support](NONE)
- [ ] [Automate development environment setup](mods/setup/setup.sh)
- [ ] [Diff them to find the best one](NONE)
- [~] [brush unrelated stuff](mods/hello/hello.c)

### 

- [Char Drivers](Su0UD.md)
[ ] Understand `alloc/register_chdrdev_region` howToUse/howTheWorks
	- Create call
	[ ] (mods/scull/chd1.c#scull_init-DEF-b)
	- Create impl
[ ] Implement shell / C user prog for dynamic allocation of major numbers.
[ ] Understand what/how the `struct file_operations` is/works.
	- [zxc-ed src](types/file_operations.h)
	- [origin src](/linux/include/linux/fs.h#file_operations-tDEF)
	- [zxc-ed inf](Su0UD.md#file-operations)
	[ ] Create var to understand diff between `unlocked_ioctl` and `compat_ioctl`
		- [zxc-ed src](mods/scull/chd1.c#scull_fops-SET)
[ ] Idea: check if a file has not been used for long time, cache it drive from memory (check if this already implement (how))
	- [zxc-ed inf](Su0UD.md#d74c77bf5b4cc61372c8a1035f6185b03e9f614c389e9ad20357f61e3ad2aab0)
[x] Understand what/how the `struct file @ f_op` is/works.
	- [zxc-ed src](types/file.h#file-tDEF-f_op)
	[ ] Create var of this type according to you understanding and grasp details.
[ ] What does mean driver isn't notified (open of `file_operations`)?
	- [zxc-ed src](types/file_operations.h)
	- [origin src](/linux/include/linux/fs.h)
	- [zxc-ed inf](Su0UD.md#file_operations-DEF)

### 
- [The Linux Device Model](gK9vS.md)
