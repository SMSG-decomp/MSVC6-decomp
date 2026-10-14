c1_type * __fastcall type_skip_arrays(c1_type *t)

{
  byte bVar1;
  
  bVar1 = (byte)t->code;
  while ((bVar1 & 0x8f) == 0x83) {
    t = t->base;
    bVar1 = (byte)t->code;
  }
  return t;
}

