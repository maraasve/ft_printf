# 🎯 ft_printf

`ft_printf` is a custom implementation of the C `printf` function, created as part of the 42 curriculum. It supports formatted output for various data types, including characters, strings, integers, unsigned integers, hexadecimal, and pointers.

---

## 🛠️ Features

- Formatted output for characters (`%c`)
- Strings (`%s`)
- Signed integers (`%i` and `%d`)
- Unsigned integers (`%u`)
- Hexadecimal output in lowercase and uppercase (`%x` and `%X`)
- Pointer addresses (`%p`)
- Literal percent sign (`%%`)
- Supports variable argument lists using `va_list`

---

## 📦 How to Use

### 🧪 Build the library
To compile the static library:

```bash
make
```

### 🧹 Cleanup
Remove object files and build directories:

```bash
make clean
```

Remove everything, including libft.a:
```bash
make fclean
```

### Rebuild
Rebuild everything from scratch:
```bash
make re
```
