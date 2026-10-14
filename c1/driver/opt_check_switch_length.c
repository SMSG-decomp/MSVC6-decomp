byte * __cdecl opt_check_switch_length(byte *s,byte *out,int size)

{
  c1_u8 cVar1;
  bool bVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  bVar2 = false;
  bVar3 = *s;
  while (bVar3 == 0x20) {
    pbVar4 = s + 1;
    s = s + 1;
    bVar3 = *pbVar4;
  }
  bVar3 = *s;
  pbVar4 = out;
  do {
    if ((bVar3 == 0) || (((bVar3 == 0x20 && (!bVar2)) || (out + size <= pbVar4)))) {
      if (out + size <= pbVar4) {
        diag_fatal(0x50,size);
      }
      *pbVar4 = 0;
      if (*s != 0) {
        s = s + 1;
      }
      return s;
    }
    cVar1 = g_char_class[bVar3];
    pbVar6 = s;
    if (cVar1 == '\0') {
      if (bVar3 == 0x3f) {
        *pbVar4 = 0x3f;
      }
      else {
        pbVar6 = s + 1;
        if (s[1] != 0x22) {
          *pbVar4 = 0x5c;
          bVar3 = *pbVar6;
          pbVar5 = pbVar4 + 1;
          if ((bVar3 != 0) && ((bVar3 != 0x20 || (bVar2)))) goto LAB_1063deab;
          goto LAB_1063deb4;
        }
        *pbVar4 = 0x22;
      }
LAB_1063dee4:
      pbVar5 = pbVar4 + 1;
    }
    else {
      if (cVar1 != '\x16') {
        *pbVar4 = bVar3;
        if (cVar1 == '#') {
          bVar3 = s[1];
LAB_1063deab:
          pbVar4 = pbVar4 + 1;
          *pbVar4 = bVar3;
          pbVar6 = s + 1;
        }
        goto LAB_1063dee4;
      }
      bVar2 = !bVar2;
      pbVar5 = pbVar4;
    }
LAB_1063deb4:
    bVar3 = pbVar6[1];
    s = pbVar6 + 1;
    pbVar4 = pbVar5;
  } while( true );
}

