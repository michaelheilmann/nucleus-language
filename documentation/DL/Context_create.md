# `DL_Context_create`
*Create a context.*

## C Specification
```
DL_Status
DL_Context_create
    (
        DL_Context **context
    )
```

## Parameters
- `context` a pointer to a `DL_Context *` variable

## Description
This function creates a `DL_Context` object.

If this function succeeds, `*context` is assigned a pointer to a new `DL_Context` object and `DL_Status_Success` is returned.
Otherwise a non-zero status code is returned. In particular, if `context` is a null pointer `DL_Status_InvalidArgument` is returned and if an allocation failed `DL_Status_AllocationFailed` is returned.

## Undefined behavior
If `context` is not a null pointer and does not point to a `DL_Context *` variable, the behavior of this function is undefined.
