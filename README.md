# Introduction to Binary Exploitation

## Table of Contents
- [What is Binary Exploitation?](#what-is-binary-exploitation)
- [Basic Linux Commands for Pwn Journey](#basic-linux-commands-for-pwn-journey)
- [Example C Program](#example-c-program)
- [Fundamental Concepts Before Diving Into Binary Exploitation](#fundamental-concepts-before-diving-into-binary-exploitation)
- [Programs vs Processes](#programs-vs-processes)
- [Registers and Assembly Basics](#registers-and-assembly-basics)
- [ELF (Executable and Linkable Format)](#elf-executable-and-linkable-format)
- [Memory Regions: Stack vs Heap](#memory-regions-stack-vs-heap)
- [Introduction to Buffer Overflow](#introduction-to-buffer-overflow)
- [Ret2Win](#ret2win)
- [Syscalls](#syscalls)
- [Binary Protections](#binary-protections)
- [Conclusion](#conclusion)
- [Credits](#credits)

---

## What is Binary Exploitation?
Binary exploitation is the art of taking control over a binary file and manipulating it based on specific inputs.  
We mainly work at a low level, targeting binaries running on a **Linux** operating system.

---

## Basic Linux Commands for Pwn Journey
Commands you’ll frequently use:
- `ls`
- `cat`
- `nc`

You operate inside a **shell** (terminal). In most pwn challenges, the goal is to **pop a shell** (gain remote access).

---

## Example C Program

```c
int vuln() {
    system("/bin/sh");
}

int main() {
    vuln();
    return 0;
}
```

**Goal:**  
Execute the `system("/bin/sh")` command to gain a shell.

---

## Fundamental Concepts Before Diving Into Binary Exploitation

When working with remote binaries:
- You reverse engineer **compiled binaries** (not source code).
- You exploit memory structures and low-level CPU instructions.

You will often connect to distant servers and exploit binaries remotely.

---

## Programs vs Processes

- **Program**:  
  A program is a **passive** collection of instructions stored on disk (like a `.c` file or an ELF binary). It **is not running** — it's just code waiting to be executed.

- **Process**:  
  A process is an **active** instance of a program. Once you run a program, it becomes a process that lives in memory, has its own address space, and can interact with the system and other processes.

**Summary:**  
> A program is like a recipe, while a process is the cooking in action.

---

## Registers and Assembly Basics

Assembly was invented by **Kathleen Booth** in 1947.

**General Purpose Registers:**
- `rax`, `rbx`, `rcx`, `rdx`
- `rsi`, `rdi`
- `r8`, `r9`, `r10`, `r11`
- `r12`, `r13`, `r14`, `r15`

**Special Purpose Registers:**
- `rbp`: Base pointer (bottom of the stack frame)
- `rsp`: Stack pointer (top of the stack frame)
- `rip`: Instruction pointer (next instruction to be executed)

Each function executed creates a stack frame, and the current function is always at the top of the stack.

---

## ELF (Executable and Linkable Format)

Important sections in an ELF file:
- **`.text`** — executable code
- **`.bss`** — uninitialized data
- **`.data`** — initialized data

Reading and understanding ELF files is crucial.

---

## Memory Regions: Stack vs Heap

- **Stack:**  
  Static memory allocation; local variables, function calls.
- **Heap:**  
  Dynamic memory allocation (`malloc`, `calloc`, `realloc`).

Heap exploitation is more advanced, but important.

---

## Introduction to Buffer Overflow

Example C vulnerable code:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char buf[16];
    printf("binary exploitation\n");
    gets(buf);
    return 0;
}
```

**Explanation:**  
- `buf` is a 16-byte buffer.
- `gets(buf)` is dangerous because it allows writing beyond the buffer size, leading to **buffer overflow**.

Buffer overflow happens when data spills over into adjacent memory, potentially overwriting important control structures like return addresses.

---

## Ret2Win

After causing an overflow, you can redirect execution flow to a "winning" function — a technique called **ret2win** (Return to Win).

---

## Syscalls

**Syscalls** are system calls for interacting with the kernel, such as:
- `exit()`
- `execve()`
- `read()`
- `write()`

Understanding syscalls is vital for advanced exploitation.

---

## Binary Protections

When analyzing a binary, check for these protections:

| Protection | Description |
|:-----------|:------------|
| **PIE** (Position Independent Executable) | Randomizes memory addresses making it harder to predict the location of code. |
| **RELRO** (Relocation Read-Only) | Protects GOT (Global Offset Table) from being overwritten. |
| **NX** (Non-Executable Stack) | Prevents the execution of code on the stack to hinder exploits. |
| **Stack Canaries** | Protects against stack-based buffer overflows by inserting a canary value. |
| **Stripped Binaries** | Removes symbol information to make reverse engineering harder. |

**Checking Protections:**
Use tools like `checksec` to determine the protections enabled on a binary.

---

## Conclusion

Binary exploitation teaches:
- In-depth knowledge of **computer architecture** and **low-level programming**.
- How memory, CPU, and operating systems interact.
- Unique skills that stand out in **CTF competitions** and **cybersecurity fields**.

Stay curious and keep learning! 🚀

---

## Credits

- Written by: **[Your Name]**
- GitHub: [your-github-username](https://github.com/your-github-username)
- Date: *April 2025*

---

# 🌟 Bonus: Pro Tips
- Add a **License** section (MIT, Apache, etc.).
- Use real **images/diagrams** with `draw.io` or `excalidraw`.
- Add a **Resources** section linking to tutorials, books, and tools.
- Insert GitHub badges for extra style.

