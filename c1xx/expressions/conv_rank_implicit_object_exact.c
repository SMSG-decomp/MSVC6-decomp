void __fastcall conv_rank_implicit_object_exact(c1_conversion *conv)

{
  byte bVar1;
  
  bVar1 = conv->flags4e;
  if ((bVar1 & 0x20) != 0) {
    conv->flags4e = bVar1 & 0xdf;
    if ((bVar1 & 2) != 0) {
      conv->rank = 1;
      return;
    }
    conv->rank = 0;
  }
  return;
}

