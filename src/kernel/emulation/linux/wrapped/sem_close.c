#include "sem_close.h"
#include "../base.h"
#include "../errno.h"
#include <sys/errno.h>
#include <linux-syscalls/linux.h>
#include <elfcalls.h>

extern struct elf_calls* elfcalls(void);

long sys_sem_close(int sem)
{
#ifndef VARIANT_DYLD
	int ret;

	ret = elfcalls()->sem_close(sem);
	if (ret == -1)
		ret = -errno_linux_to_bsd(elfcalls()->get_errno());

	return ret;
#else
	return -ENOSYS;
#endif
}

