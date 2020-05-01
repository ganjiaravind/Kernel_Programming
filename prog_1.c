/*
*  This is Basic kernel module
*/

#include<linux/init.h>
#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/moduleparam.h>


static __init int start_init(void)
{
	pr_info("%s: function loaded\n",__func__);
	return 0;
}

static __exit void start_exit(void)
{
	pr_info("%s: function unloaded\n",__func__);
	return;
}


module_init(start_init);
module_exit(start_exit);
MODULE_LICENSE("GPL");
