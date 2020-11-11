// Used for all kernel modules
#include<linux/kernel.h>

// Used for the module functionality
#include<linux/module.h>

#include<linux/init.h>
#include<linux/moduleparam.h>
#include<linux/stat.h>

#define AUTHOR "Varad Lanke"
#define DESC "Demo Kernel module of lanke company"

MODULE_LICENSE("GPL");

MODULE_AUTHOR(AUTHOR);

MODULE_DESCRIPTION(DESC);

int no = 11;

module_param(no,int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

// Gets called when module gets loaded
int start(void)
{
	// Function to print in the kernel log file
	printk(KERN_INFO "[INFO] Varad Kernel Module loaded %d\n",no);
	return(0);
}

// Gets called when module gets unloaded
void end(void)
{
	printk(KERN_INFO "[INFO] Varad Kernel Module unloaded\n");
}

// macros | Register the name of callback functions
module_init(start);
module_exit(end);