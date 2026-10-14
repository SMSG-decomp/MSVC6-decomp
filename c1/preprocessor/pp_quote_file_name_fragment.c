byte * __fastcall pp_quote_file_name_fragment(byte *dst,byte *name)

{
  byte bVar1;
  byte *pbVar2;
  byte *dst_00;
  byte *name_00;
  
  name_00 = name + 1;
  dst[1] = name[1];
  pbVar2 = dst + 1;
  do {
    while( true ) {
      bVar1 = name_00[1];
      name_00 = name_00 + 1;
      dst_00 = pbVar2 + 1;
      *dst_00 = bVar1;
      if (bVar1 == 0) {
        *dst_00 = 0x22;
        return pbVar2 + 2;
      }
      if (g_char_class[bVar1] != '\0') break;
      pbVar2 = pbVar2 + 2;
      *pbVar2 = 0x5c;
    }
    pbVar2 = dst_00;
  } while (g_char_class[bVar1] != '#');
  pbVar2 = pp_quote_file_name_fragment(dst_00,name_00);
  return pbVar2;
}

