#include <linux/init.h>
#include <linux/module.h>
#include <linux/workqueue.h>
#include <linux/slab.h>

struct workqueue_struct *wq;

struct work_data {
	struct work_struct work;
	int data;
};

static void worktest_handler(struct work_struct *work)
{
	struct work_data *data = (struct work_data *)work;
	kfree(data);
	pr_info("%s: function called\n", __func__);
}

static int __init wqtest_init(void)
{
	struct work_data *data = NULL;

	pr_info("%s: function loaded\n", __func__);
	wq = create_workqueue("wq_test");
	if (!wq) {
		pr_err("failed to create worker queue\n");
		return -EFAULT;
	}
	data = (struct work_data *)kmalloc(sizeof(*data), GFP_KERNEL);
	if (!data) {
		pr_err("failed to allocate memory\n");
		return -ENOMEM;
	}
	INIT_WORK(&data->work, worktest_handler);
	queue_work(wq, &data->work);

	pr_info("test worker queue has been queued\n");

	return 0;
}

static void __exit wqtest_exit(void)
{
	pr_info("%s: function \n",__func__);
	flush_workqueue(wq);
	destroy_workqueue(wq);
}


module_init(wqtest_init);
module_exit(wqtest_exit);
MODULE_LICENSE("GPL");
