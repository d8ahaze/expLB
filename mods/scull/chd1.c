#include <linux/init.h>
#include <linux/module.h>

#include <linux/types.h>
#include <linux/kdev_t.h>

#ifndef SCULL_MAJOR
#define SCULL_MAJOR 0 /* dynamic major by default */
#endif
/* short int: 2 addresses (bytes), i.e. 16bit which enough since max is 12 */
short int scull_major = SCULL_MAJOR;
/* we have no 3 byte (24 bits) memory region (type) */
unsigned int scull_minor = 0;

#ifndef SCULL_NR_DEVS
#define SCULL_NR_DEVS 4 /* scull0 through scull3 */
#endif
unsigned char scull_nr_devs = SCULL_NR_DEVS;

extern int register_chrdev_region(dev_t, unsigned, const char *);
extern int alloc_chrdev_region(dev_t *, unsigned, unsigned, const char *);
extern void unregister_chrdev_region(dev_t, unsigned);

static int scull_init(void)
{
	dev_t dev = 0;
	int result;

	// block1	Su0UD.md#major-nums-dyn-alloc
	if (scull_major) {
		dev = MKDEV(scull_major, scull_minor);					// lines/e4e3c12566d13de60eacbea610b71e74d95bf3cd93ac971885f3bfc4ad065273
		result = register_chrdev_region(dev, scull_nr_devs, "scull");		// lines/eec4ef3cec7f52a2e0b2e575efa9f23b187230aff56f0ca2a0a2404141d12175
	} else {
		/* push major number of `scull' char device to /proc/devices */
		result = alloc_chrdev_region(&dev, scull_minor, scull_nr_devs,
				"scull");
		scull_major = MAJOR(dev);
		printk(KERN_ALERT "Scull major number: %d\n", scull_major);
	}
	if (result < 0) {
		printk(KERN_WARNING "scull: can't get major %d\n", scull_major);	// lines/
		return result;
	}

	return 0;
}

static void scull_exit(void)
{
	/* #alloc-free-dev-nums say that here I should free dev nums, but dev is
           var in scull_init func, so it no exists? */
	// unregister_chrdev_region
	printk(KERN_ALERT "Scull kernel module cleanup\n");
}

module_init(scull_init);
module_exit(scull_exit);

MODULE_LICENSE("GPL");
