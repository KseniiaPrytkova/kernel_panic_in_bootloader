#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module with null pointer dereference inside.");
MODULE_AUTHOR("Kseniia Prytkova");

static int __init hello_init(void)
{
	int *p;

	p = NULL;
	printk("Do you wanna know what an undefined behavior is?\n");
	printk("Ohh really?!\n");
	printk("%d\n", *p);
	return 0;
}

static void __exit hello_exit(void)
{
	printk("Goodbye, world\n");
}

module_init(hello_init);
module_exit(hello_exit);