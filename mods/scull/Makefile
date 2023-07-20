# Lazy Set: 
# VAR = value
#
# Immediate Set:
# VAR := value
# 
# Lazy Set If Absent: set a value only if absent
# VAR ?= value
#
# Append
# VAR += value
LNX_BLD_DIR ?= /lib/modules/$(shell uname -r)/build
MOD_DIR ?= $(shell pwd)

# If we type make inside linux source dir then we use linux's Makefile in which
# created make's var which exported. Search `KERNELRELEASE' in linux's Makefile
# for details.
# ifneq (arg1, arg2) -- make syntax. In this case evaluate if not empty.
ifneq ($(KERNELRELEASE),)
	obj-m := cdd1.o
else
default:
	# stackoverflow.com/q/21177935
	# make -C $(LNX_BLD_DIR) M=$(MOD_DIR) tstmod1.i
	make -C $(LNX_BLD_DIR) M=$(MOD_DIR) modules EXTRA_CFLAGS='-save-temps'
clean:
	make -C $(LNX_BLD_DIR) M=$(MOD_DIR) clean
endif
