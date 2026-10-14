int __cdecl type_chain_is_cv_qualified(c1_type *t)

{
  byte code_lo;
  
  while( true ) {
    code_lo = (byte)t->code;
    if (((code_lo & 0x8f) != 0x83) && ((code_lo & 0x83) != 0x81)) break;
    t = t->base;
  }
  return (uint)((t->flags & 0x60) != 0);
}

