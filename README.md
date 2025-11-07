# ft_printf — Custom implementation of the printf function

![Typewriter](assets/typewriter.png)

A recreation of the C standard library’s `printf` function.  
This project is part of the **42 curriculum** and focuses on mastering **variadic functions**, **format parsing**, and **modular code organization**.

---

## Overview

`ft_printf` reproduces the behavior of the original `printf` function from `<stdio.h>`, allowing formatted output to `stdout`.  
It handles various format specifiers, flags, and conversion types while ensuring clean and maintainable C code.

---

## Project Structure

> [!NOTE]
> This project builds upon my [libft](https://github.com/danyarwx/42-libft) library.

```
42-ft_printf/
├── include/
│   ├── ft_printf.h           # Header for printf project
│   └── libft.h               # Reused from libft (for helper functions)
├── libft/
│   ├── ft_*.c                # Core libft functions (reused)
│   └── Makefile
├── src/
│   ├── ft_printf.c           # Main printf logic and format parsing
│   ├── ft_put_chars.c        # Character and string output functions
│   ├── ft_put_hex.c          # Hexadecimal conversion
│   ├── ft_put_nbr.c          # Decimal and integer printing
│   ├── ft_put_ptr.c          # Pointer printing (0x... format)
│   └── ft_put_unbr.c         # Unsigned integer printing
└── Makefile                  # Builds libft and ft_printf into one library
```

---

## Supported Conversions

| Specifier | Output |
|------------|---------|
| `%c` | Character |
| `%s` | String |
| `%p` | Pointer address (in hexadecimal) |
| `%d` | Signed decimal integer |
| `%i` | Signed decimal integer (identical to `%d`) |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hexadecimal integer (lowercase) |
| `%X` | Unsigned hexadecimal integer (uppercase) |
| `%%` | Literal percent sign |

---

## Build & Usage

> [!IMPORTANT]
> Only the `ft_printf/` folder is required to compile and use the library.  
> The `assets/` folder and `README.md` are for documentation only.

### 1. Clone and build

```bash
git clone https://github.com/danyarwx/42-ft_printf.git
cd ft_printf/
make
```

This generates `libftprintf.a`, a static library combining **libft** and **ft_printf**.

### 2. Compile your test program

```bash
gcc main.c -L. -lftprintf -I include
./a.out
```

> **Include the header:**
> ```c
> #include "ft_printf.h"
> ```

---

## Implementation Highlights

- Built using **variadic functions** (`stdarg.h`)
- Modular design: each type handled by a dedicated function
- Reuses foundational utilities from **libft**
- Manages buffers and length tracking manually
- Fully norm-compliant and memory-safe

---

## Example Usage

```c
#include "ft_printf.h"

int main(void)
{
    int num = 42;
    char *str = "Hello, 42!";

    ft_printf("Number: %d\n", num);
    ft_printf("Hex: %x\n", num);
    ft_printf("String: %s\n", str);
    ft_printf("Pointer: %p\n", str);
}
```

**Expected Output:**
```
Number: 42
Hex: 2a
String: Hello, 42!
Pointer: 0x7ffeefbff5b0
```

---

## Makefile Targets

| Command | Description |
|----------|--------------|
| `make` | Build the library (`libftprintf.a`) |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and static library |
| `make re` | Rebuild everything from scratch |

---

## License

This repository is part of the **42 curriculum**.  
You are free to reference or reuse it for educational purposes, provided you credit appropriately.
