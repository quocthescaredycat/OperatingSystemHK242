#ifndef CP_H
#define CP_H

#include "common.h"

int copy_from_userspace(struct pcb_t *caller, uint32_t memrg, char *buffer, size_t buffer_size);
int copy_to_userspace(struct pcb_t *caller, uint32_t memrg, char *buffer, size_t buffer_size);

#endif // CP_H
