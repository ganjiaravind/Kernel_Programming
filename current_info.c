#include <linux/init.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <asm/current.h>


static __init int current_init(void)
{
	pr_info("%s: in function\n", __func__);
	pr_info("Caller process name: %s\n",current->comm);
	pr_info("Caller Pid is %u\n", current->pid);
	pr_info("stack start address is %p\n", current->stack);

	return 0;
}

static __exit void current_exit(void)
{
	pr_info("Caller process name: %s\n",current->comm);
	pr_info("Caller Pid is %u\n", current->pid);
	return;
}


module_init(current_init);
module_exit(current_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("LKM: Current task info");
