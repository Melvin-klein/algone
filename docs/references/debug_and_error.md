## Functions

### `ALG_RaiseError`

**Prototype** : `void ALG_RaiseError(char message[], char file[], int line)`

**Description** : Print an error into the console.

**Parameters**

| Parameter | Type     | Description                          |
|-----------|----------|--------------------------------------|
| message   | `char[]` | The message to print.                |
| file      | `char[]` | The file that raise th error.        |
| line      | `int`    | The line number that raise the error |

**Mutations and return**

No mutation or return.

---

### `ALG_AssertMemoryAlloc`

**Prototype** : `void ALG_AssertMemoryAlloc(void* p, char file[], int line)`

**Description** : Check if manual memory allocation has worked.

**Parameters**

| Parameter | Type     | Description                          |
|-----------|----------|--------------------------------------|
| p         | `void*`  | The pointer to check.                |
| file      | `char[]` | The file that raise th error.        |
| line      | `int`    | The line number that raise the error |

**Mutations and return**

No mutation or return.