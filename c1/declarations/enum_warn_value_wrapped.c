longlong __cdecl enum_warn_value_wrapped(longlong value,void *name)

{
  if (value == 0x7fffffff) {
    diag_warning(1,0x154,name);
  }
  return value + 1;
}

