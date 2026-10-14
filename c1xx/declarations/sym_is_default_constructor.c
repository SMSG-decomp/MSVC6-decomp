c1_u8 __cdecl sym_is_default_constructor(c1_symbol *fn)

{
  return *(byte *)((int)&fn->tail + 8) >> 4 & 1;
}

