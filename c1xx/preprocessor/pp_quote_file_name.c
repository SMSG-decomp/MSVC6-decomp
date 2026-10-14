byte * __cdecl pp_quote_file_name(byte *dst,byte *name)

{
  byte *pbVar1;
  byte bVar2;
  byte *pbVar3;
  
  bVar2 = *name;
  *dst = 0x22;
  pbVar3 = dst + 1;
  *pbVar3 = bVar2;
  while (bVar2 != 0) {
    if (g_char_class[bVar2] == '\0') {
      pbVar3 = pbVar3 + 1;
      *pbVar3 = 0x5c;
    }
    else if (g_char_class[bVar2] == '#') {
      pbVar1 = name + 1;
      name = name + 1;
      pbVar3 = pbVar3 + 1;
      *pbVar3 = *pbVar1;
    }
    bVar2 = name[1];
    name = name + 1;
    pbVar3 = pbVar3 + 1;
    *pbVar3 = bVar2;
  }
  *pbVar3 = 0x22;
  return pbVar3 + 1;
}

