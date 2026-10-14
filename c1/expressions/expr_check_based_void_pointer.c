c1_type * __cdecl expr_check_based_void_pointer(c1_type *type)

{
  if ((type->flags & 0x18) == 8) {
    diag_error(0xd6);
  }
  return type->base;
}

