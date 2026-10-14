char * __cdecl decorate_array_dims(char *out,c1_type *type)

{
  byte bVar1;
  c1_type *pcVar2;
  char *out_00;
  byte *pbVar3;
  uint n;
  
  n = 0;
  bVar1 = (byte)type->code;
  pcVar2 = type;
  while ((bVar1 & 0x8f) == 0x83) {
    pcVar2 = pcVar2->base;
    n = n + 1;
    bVar1 = (byte)pcVar2->code;
  }
  out_00 = decorate_number(out,n);
  pcVar2 = type;
  for (; n != 0; n = n - 1) {
    out_00 = decorate_number(out_00,(type->extra).count);
    type = type->base;
    pcVar2 = pcVar2->base;
  }
  if ((-1 < (char)pcVar2->code) && ((pcVar2->flags & 0x3e0) != 0)) {
    pbVar3 = decorate_pointer_target(out_00,pcVar2,2);
    return (char *)pbVar3;
  }
  pbVar3 = decorate_pointer_target(out_00,pcVar2,0);
  return (char *)pbVar3;
}

