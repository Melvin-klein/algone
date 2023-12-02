# Handle errors

After each call to an Algone function, you should check whether an error has occurred.
You can handle errors through the functions [`ALG_HasError()`](/references/debug_and_error#alg_haserror), [`ALG_GetError()`](/references/debug_and_error#alg_geterror) and [`ALG_PrintError()`](/references/debug_and_error#alg_printerror).

## Print error

If you just want to print the error on the standard output stream, you can use the [`ALG_PrintError()`](/references/debug_and_error#alg_printerror) function.
For instance, if you use the [`ALG_CreateNetworkFromFile()`](/references/networks#alg_createnetworkfromfile) with a wrong `path`, you can handle errors by the following code :

```C
FILE *file = fopen("path/to/badly_formatted_file.model.alg", "r");
ALG_Network* n = ALG_CreateNetworkFromFile(file);

if (ALG_HasError()) {
    ALG_PrintError()
}
```

The function [`ALG_PrintError()`](/references/debug_and_error#alg_printerror) will print error on the standard output stream.

## Get error

If you want to be more precise when you handle errors, instead of using [`ALG_PrintError()`](/references/debug_and_error#alg_printerror) you can use [`ALG_GetError()`]().
This function returns an [`ALG_Error`](/references/debug_and_error#alg_error) struct that contains the error code and the error message.

For instance :

```C
// Create a network from a badly formatted file
FILE *file = fopen("path/to/badly_formatted_file.model.alg", "r");
ALG_Network* n = ALG_CreateNetworkFromFile(file);

// Handle the error
if (ALG_HasError()) {
    ALG_Error* e = ALG_GetError();
    
    if (e.code == ALG_INCOMPATIBLE_ERROR) {
        // do something ...
    }
}
```