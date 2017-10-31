
# String operations

## `DL_Context_createString`
Create a string.
### C Specification
```
DL_String *
DL_Context_createString
    (
        DL_Context *context,
        const char *bytes,
        size_t numberOfBytes
    )
```
### Parameters
- `context` a pointer to the `DL_Context` object in which this operation is performed
- `bytes` a pointer to an array of `numberOfBytes` Bytes
- `numberOfBytes` the number of Bytes in the array pointed to by `bytes`
### Description
This function creates a `DL_String` object representing the specified Bytes in the specified context. A pointer to the `DL_String` object is returned.
### Errors
An error is raised in the specified context if this function fails.
#### Undefined behavior
- `context` is not a null pointer and does not point to a `DL_Context` object.



## `DL_String_getBytes`
Get the Bytes of a string.
### C Specification
```
const char *
DL_String_getBytes
    (
        DL_Context *context,
        DL_String *string
    )
```
### Description
This function gets the Bytes of a `DL_String` object. *It is undefined behaviour to modify the array. The lifetime of the array is the lifetime of the `DL_String` object.`*
### Errors
An error is raised in the specified context if this function fails.
### Undefined behaviour
- `context` is not a null pointer and does not point to a `DL_Context` object previously created by `DL_Context_create`.
- `string` is not null pointer and does not point to `DL_String` objects of the specified context.



## `DL_String_getNumberOfBytes`
Get the number of Bytes of a string.
### C Specification
```
size_t
DL_String_getNumberOfBytes
    (
        DL_Context *context,
        DL_String *string
    )
```
### Description
This function gets the number of Bytes of a `DL_String` object.
#### Errors
An error is raised in the specified context if this function fails.
#### Undefined behaviour
- `context` is not a null pointer and does not point to a `DL_Context` object previously created by `DL_Context_create`.
- `string` is not a null pointer and does not point to `DL_String` objects of the specified context.


## `DL_String_equal`
Compare strings for equality.
### C Specification
```
DL_Boolean
DL_String_equal
    (
        DL_Context *context,
        DL_String *first,
        DL_String *second
    )
```
### Parameters
- `context` a pointer to the `DL_Context` object in which this operation is performed
- `first` a pointer to the first `DL_String` object
- `second` a pointer to the second `DL_String` object
### Description
This function compares `DL_String` objects for equality.
`DL_True` is returned if both string objects are equal, `DL_False` is returned if they are not equal.
#### Errors
An error is raised in the specified context if this function fails.
#### Undefined behaviour
- `context` is not a null pointer and does not point to a `DL_Context` object previously created by `DL_Context_create`.
- `first` or `second` are not null pointers and do not point to `DL_String` objects of the specified context.



## `DL_String_concatenate`
*Concatenate strings.*
### C Specification
```
DL_String *
DL_String_concatenate
    (
        DL_Context *context,
        DL_String *x,
        DL_String *y
    )
```
### Parameters
- `context` a pointer to the `DL_Context` object in which this operation is performed
- `first` a pointer to the first `DL_String` object
- `second` a pointer to the second `DL_String` object
### Description
This function creates a `DL_String` object representing the concatenation of the first `DL_String` object with the second `DL_String` object.
A pointer to the `DL_String` object is returned.
#### Errors
An error is raised in the specified context if this function fails.
#### Undefined behaviour
- `context` is not a null pointer and does not point to a `DL_Context` object previously created by `DL_Context_create`.
- `first` or `second` are not null pointers and do not point to `DL_String` objects of the specified context.
