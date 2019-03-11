/* hello_panic_world.c */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module to cause panic.");
MODULE_AUTHOR("Kseniia Prytkova");

static int __init hello_init(void)
{
	int var;
	int *p;

	var = 42;
	p = NULL;
	printk("Do you wanna know what an undefined behavior is?\n");
	//*var = *p;
	printk("%d\n", *p);
	return 0;
}

static void __exit hello_exit(void)
{
	printk("Goodbye, world\n");
}

module_init(hello_init);
module_exit(hello_exit);