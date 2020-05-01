
/*program to use dump_stack and use init_module
*and cleanup_module, instead of module_init,
*module_exit
*/

#include <linux/version.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>


int init_module(void)
{
	printk("%s: module init\n",__func__);
	dump_stack();
	return 0;
}

void cleanup_module(void)
{
	printk("%s: module exit\n",__func__);
	dump_stack();
}



MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("LKM TO VERIFY DUMPSTACK AND USE INIT_MODULE, CLEANUP_MODULE");
MODULE_AUTHOR("Ganji Aravind");
