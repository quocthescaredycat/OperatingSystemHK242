# Simple Operating System Simulator

**Course**: Operating Systems (CO2018)  
**Institution**: Ho Chi Minh City University of Technology  
## Overview

This project implements a simplified OS, focusing on:
- **Multilevel Queue (MLQ) Scheduler**  
- **Paging-Based Virtual Memory Management**  
- **System Call Interface** (`killall`)  
- **Synchronization Mechanisms** for multi-processor safety

Goal: The objective of this assignment is the simulation of major components in a simple operating system,
for example, scheduler, synchronization, related operations of physical memory and virtual memory.
Content: In detail, students will practice with three major modules: scheduler, synchronization, mechanism
of memory allocation from virtual-to-physical memory.
• scheduler
• synchronization
• the operations of mem-allocation from virtual-to-physical
Besides, students will practice the design and implementation of Simple Operating System programming
interface via system call.
Result: After this assignment, students can understand partly the principle of a simple OS. They can
understand and draw the role of OS key modules.
---

## Project Structure
├── include/ # Header files (.h)
├── src/ # Source files (.c)
│ ├ scheduler/ # sched.c, queue.c, etc.
│ ├ memory/ # mm-vm.c, mm-memphy.c, etc.
│ └ syscall/ # sys_xxxhandler.c
├── input/ # Sample configs & process descriptions
├── output/ # Reference outputs for verification
├── Makefile # Build script
├── report.pdf # Detailed project report
└── README.md # You are here
## Prerequisites

- GCC or compatible C compiler  
- GNU make  

---
## Build

```bash
make all
./os <input_file>
```
eg. ./os os_syscall
Note: This analysis represents findings based on standardized testing environments and common use cases. Individual results may vary based on specific hardware configurations, software requirements, and organizational needs.

## 📄 License
This report is provided for informational and educational purposes. Please refer to the full document for detailed citation and usage guidelines.
