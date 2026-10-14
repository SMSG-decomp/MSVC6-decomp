byte * __cdecl pp_quote_file_name(byte *dst,byte *name)

{
  byte bVar1;
  byte *pbVar2;
  
  bVar1 = *name;
  *dst = 0x22;
  pbVar2 = dst + 1;
  *pbVar2 = bVar1;
  do {
    if (bVar1 == 0) {
      *pbVar2 = 0x22;
      return pbVar2 + 1;
    }
    if (g_char_class[bVar1] == '\0') {
      pbVar2 = pbVar2 + 1;
      *pbVar2 = 0x5c;
    }
    else if (g_char_class[bVar1] == '#') {
      pbVar2 = pp_quote_file_name_fragment(pbVar2,name);
      return pbVar2;
    }
    bVar1 = name[1];
    name = name + 1;
    pbVar2 = pbVar2 + 1;
    *pbVar2 = bVar1;
  } while( true );
}

