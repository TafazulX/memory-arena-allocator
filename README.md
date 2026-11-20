# Memory Arena Allocator in C

A simple memory arena allocator implemented from scratch in C.

This project explores manual memory management, pointer arithmetic, memory alignment, and efficient memory reuse.

## Features

- Initialize a memory arena with a specified capacity.
- Allocate memory from a pre-allocated memory block.
- Support aligned memory allocation.
- Track used and available memory.
- Reset the arena to reuse its allocated memory without requesting a new block.

## How It Works

The allocator reserves one large block of memory using `malloc()`.

Instead of requesting memory from the operating system for every allocation, it manages allocations inside this existing block.

It tracks memory usage using three fields:

- `memoryBegin` — starting address of the arena.
- `memorySize` — total capacity of the arena.
- `memoryUsed` — amount of memory currently used.

### Alignment

The allocator supports aligned memory allocation by calculating the padding required to reach the requested alignment boundary.

For example, an allocation requiring 8-byte alignment must begin at an address divisible by 8.

### Reset

The `resetArena()` function sets the memory usage counter back to zero, allowing the arena to be reused without allocating another memory block.

**Note:** Resetting the arena does not erase its contents.

## Project Structure

```text
memory-arena-allocator/
└── main.c
```

## Compilation

Using GCC:

```bash
gcc main.c -o arena
```

Run:

```bash
./arena
```

On Windows:

```bash
arena.exe
```

## Concepts Explored

- Dynamic memory allocation
- Pointers and pointer arithmetic
- `size_t` and `uintptr_t`
- Memory alignment and padding
- Structs
- Manual memory management

## About

Built as a hands-on systems programming project to understand how memory allocation works internally.

**Language:** C