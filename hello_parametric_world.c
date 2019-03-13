#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module with an answer to life");
MODULE_AUTHOR("Kseniia Prytkova");

static int answer = 42;
module_param(answer, int, 0644);
MODULE_PARM_DESC(answer, "Answer to the Ultimate Question of Life, the Universe, and Everything");

static int __init hello_init(void)
{
	printk(KERN_INFO "hello_parametric_world module being loaded.\n");
    printk(KERN_INFO "Initial answer = %d.\n", answer);
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "hello_parametric_world module being unloaded.\n");
}

module_init(hello_init);
module_exit(hello_exit);