byte * __cdecl decorate_name_operator_or_name(byte *out,c1_symbol *sym,uint codes)

{
  byte *pbVar1;
  byte bVar2;
  
  bVar2 = (byte)(codes >> 8);
  if (bVar2 == 0) {
    pbVar1 = (byte *)decorate_name_with_backreference((char *)out,(int)sym->name,0);
    return pbVar1;
  }
  *out = 0x3f;
  pbVar1 = out + 1;
  if ((codes & 0x8000) != 0) {
    *pbVar1 = 0x5f;
    pbVar1 = out + 2;
  }
  *pbVar1 = bVar2 & 0x7f;
  return pbVar1 + 1;
}

