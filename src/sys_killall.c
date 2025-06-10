/*
 * Copyright (C) 2025 pdnguyen of HCMC University of Technology VNU-HCM
 */

/* Sierra release
 * Source Code License Grant: The authors hereby grant to Licensee
 * personal permission to use and modify the Licensed Source Code
 * for the sole purpose of studying while attending the course CO2018.
 */

 #include "common.h"
 #include "syscall.h"
 #include "stdio.h"
 #include "libmem.h"
 
#include "queue.h"  
#include <string.h> 
int __sys_killall(struct pcb_t *caller, struct sc_regs* regs)
{
    char proc_name[100];
    uint32_t data;
    uint32_t memrg = regs->a1;

    int i = 0;
    data = 0;
    while(data != -1){
        libread(caller, memrg, i, &data);
        proc_name[i]= data;
        printf("Data %d: %d\n",i ,data);
        if(data == -1) proc_name[i]='\0';
        i++;
    }
    printf("The procname retrieved from memregionid %d is \"%s\"\n", memrg, proc_name);

    struct queue_t *running_list = caller->running_list;
    struct queue_t temp_queue = {0}; 
    int idx = 0;

    while (!empty(running_list)) 
    {
        struct pcb_t *proc = dequeue(running_list);
        char *name = strrchr(proc->path, '/');
        if (!name) name = strrchr(proc->path, '\\');
        if (name) name++;
        
        if (strcmp(proc->path, proc_name) == 0) 
        {
            if (proc->pid == caller->pid) continue; 
            libfree(proc, idx);
        }
        else enqueue(&temp_queue, proc);
        idx++;
    }

    while (!empty(&temp_queue)) 
    {
        struct pcb_t *proc = dequeue(&temp_queue);
        enqueue(running_list, proc);
    }
     
    return 0;
}
 