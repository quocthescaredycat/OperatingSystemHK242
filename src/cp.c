#include "cp.h"
#include "common.h"
#include "mm.h"
#include "stdio.h"
#include "queue.h"  
#include <string.h>
int copy_from_userspace(struct pcb_t *caller, uint32_t memrg, char *buffer, size_t buffer_size)
{
    if (caller == NULL || buffer == NULL || buffer_size == 0)
        return -1;

    struct vm_rg_struct *src_region = get_symrg_byid(caller->mm, memrg);
    if (src_region == NULL)
        return -1;

    BYTE byte;
    size_t i = 0;

    while (i < buffer_size - 1)
    {
        uint32_t vaddr = src_region->rg_start + i;
        int fpn = -1;
        struct queue_t *running_list = caller->running_list;
        struct queue_t temp_queue = {0}; 
        while(!empty(running_list))
        {
            struct pcb_t *p = dequeue(running_list);
            enqueue(&temp_queue, p);

            uint32_t pgn = vaddr / PAGING_PAGESZ; 
            if (p && PAGING_PAGE_PRESENT(p->mm->pgd[pgn]))
            {
                fpn = PAGING_PTE_FPN(p->mm->pgd[pgn]);
                break;
            }
        }
        while (!empty(&temp_queue)) 
        {
            struct pcb_t *proc = dequeue(&temp_queue);
            enqueue(running_list, proc);
        }

        if (fpn == -1)
        {
            return -1;
        }

        int offset = vaddr % PAGING_PAGESZ;
        int phyaddr = fpn * PAGING_PAGESZ + offset;

        if (MEMPHY_read(caller->mram, phyaddr, &byte) != 0)
            return -1;

        buffer[i++] = byte;

        if (byte == (BYTE)-1)
        {
            buffer[i - 1] = '\0';
            break;
        }
    }

    buffer[i] = '\0';
    return (int)i;
}
