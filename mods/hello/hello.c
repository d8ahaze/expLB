#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

static int v1 __initdata = 3;

/* void -- required, else error: function declaration isn't a prototype */
static int f3(void) {
  pr_info("f3 adr: %p\n", f3);
  return 0;
}

static int __init f1(void) {
  printk(KERN_ALERT "Hello, world\n");
  pr_info("v1: %d\n", v1);
  pr_info("v1 adr: %p\n", &v1);
  pr_info("f1 adr: %p\n", f1);
  f3();
  return 0;
}

static void __exit f2(void) {
  f3();
  pr_info("f2 adr: %p\n", f2);
  printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(f1);
module_exit(f2);

MODULE_LICENSE("GPL");
