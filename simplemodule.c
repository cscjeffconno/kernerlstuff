/* sample misc device driver.
*
*
*/



#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h> 

MODULE_LICENSE("GPL");
MODULE_AUTHOR("csc");
MODULE_DESCRIPTION("simple device");

staic strcut file_operations sd_fops = {
 .open = NULL,
 .close = NULL,
 .read = NULL,
 .write = NULL,
 .llseck = noop_llseek 
 
};


static struct miscdevice mydev = {
 .minor = MISC_DYNAMIC_MINOR,
 .name = "simpledev",
 .fops = &sd_fops
 };

/* check init params here
*
*
*/

static int __init simpledev_init(void)
{
 printk(KERN_INFO "reverse device has been registered\n");    
 return 0;
} 

static void __exit simpledev_exit(void){    
 /* check this in demsg */
 printk(KERN_INFO "reverse device has been unregistered\n");
} 

module_init(reverse_init);
module_exit(reverse_exit);

 
