c1_u8 __cdecl sym_is_copy_constructor(c1_symbol *fn)

{
  return *(byte *)((int)&fn->tail + 8) >> 5 & 1;
}

