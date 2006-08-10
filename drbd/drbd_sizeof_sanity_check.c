#include <linux/drbd.h>
#include <linux/kernel.h>

#define COMPILETIME_ASSERT(x) \
	switch(0) { case 0:; case (x):; }
#define SZO(type,size) \
void __assert_sizeof_ ##type ## _eq_ ##size(void) { COMPILETIME_ASSERT(sizeof(struct type) == (size)); } \
void __assert_sizeof_ ##type ## _modulo_8_eq_0(void) { COMPILETIME_ASSERT(sizeof(struct type) % 8 == 0); }

SZO(disk_config,	 32)
SZO(net_config,		456)
SZO(syncer_config,	 16)
SZO(ioctl_disk_config,	 40)
SZO(ioctl_net_config,	464)
SZO(ioctl_syncer_config, 24)
SZO(ioctl_wait,		 16)
SZO(ioctl_get_config,	576)
SZO(ioctl_get_uuids,     48)

