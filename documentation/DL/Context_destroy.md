# `DL_Context_destroy`
*Destroy a context.*

## C Specification
```
void
DL_Context_destroy
    (
        DL_Context *context
    )
```

### Parameters
- `context`: a pointer to a `DL_Context` object previously created by a call to `DL_Context_create`

### Description
This function destroys a `DL_Context` object.

The parameter `context` expects a pointer to a `DL_Context` object previously created by `DL_Context_create`.
The `DL_Context` context object is destroyed.

### Undefined behaviour
If `context` is not a null pointer and does not point to a `DL_Context` object previously created by `DL_Context_create`, the behavior of this function is undefined.
