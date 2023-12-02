## Errors

### `ALG_Error`

**Type** : Structure

**Description** : A representation of an error.

| Variable | Type            | Accessibility | Description                                                                                                       |
|----------|-----------------|---------------|-------------------------------------------------------------------------------------------------------------------|
| message  | `char*`         | Read/Write    | The error message.                                                                                                |
| code     | `ALG_ErrorCode` | Read/Write    | An array that describe matrix size. First value is the number of rows. The second value is the number of columns. |
| len      | `size_t`        | Read/Write    | The error message length.                                                                                         |          
| file     | `char*`         | Read/Write    | The file where the occurred.                                                                                      |
| line     | `int`           | Read/Write    | The line where the error occurred.                                                                                |
| hasError | `bool`          | Read/Write    | Set to true if the struct if filled.                                                                              |

---

### `ALG_HasError()`

**Prototype** : `bool ALG_HasError()`

**Description** : Returns `true` if an error has occurred.

**Mutations and return** :

| Case   | Name | Type   | Description               |
|--------|------|--------|---------------------------|
| Return |      | `bool` | True if an error occurred |

---

### `ALG_GetError()`

**Prototype** : `ALG_Error* ALG_GetError();`

**Description** : Retrieves the error if it has occurred.

**Mutations and return**

| Case   | Name | Type         | Description                                        |
|--------|------|--------------|----------------------------------------------------|
| Return |      | `ALG_Error*` | Returns the error struct containing current error. |

---

### `ALG_PrintError()`

**Prototype** : `ALG_Error* ALG_PrintError();`

**Description** : Print the error on the standard output stream.

**Mutations and return** :

No mutations or return.

---

### `ALG_SetError()`

**Type** : Function

**Prototype** : `void ALG_SetError(int errorCode, const char *errorMessage, char *file, int line)`

**Description** : Fill an [`ALG_Error`]() struct in the global error variable.

**Parameters**

| Parameter    | Type                | Description                               |
|--------------|---------------------|-------------------------------------------|
| errorCode    | [`ALG_ErrorCode`]() | The code of the error.                    |
| errorMessage | `const char`        | A string that contains the error message. |
| file         | `char*`             | The file name where the error occurred.   |
| line         | `int`               | The line where the error occurred.        | 

**Mutations and return**

No mutations or return.