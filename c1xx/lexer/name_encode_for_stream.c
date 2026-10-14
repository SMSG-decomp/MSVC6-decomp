char * __cdecl name_encode_for_stream(char *out,byte *name)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  byte bVar4;
  byte *pbVar5;
  char *pcVar6;
  uint local_4;
  
  if (name == (byte *)0x0) {
    *out = '\0';
    return out;
  }
  bVar4 = *name;
  pcVar6 = out;
  if (bVar4 == 0) {
    *out = '\0';
    return out;
  }
  do {
    pbVar5 = name + 1;
    out = (char *)(uint)bVar4;
    if ((0x40 < bVar4) && (bVar4 < 0x5b)) {
      out = (char *)(uint)(byte)(bVar4 + 0x20);
    }
    pcVar3 = strchr("abcdefghijklmnopqrstuvwxyz0123456789$ :/._+-()\\",(int)out);
    if ((pcVar3 == (char *)0x0) || (pcVar3[0x30] == '\0')) {
      pcVar3 = strchr("abcdefghijklmnopqrstuvwxyz0123456789$ :/._+-()\\",0x24);
      if (pcVar3 == (char *)0x0) {
        cVar2 = '\0';
      }
      else {
        cVar2 = pcVar3[0x30];
      }
      *pcVar6 = cVar2;
      bVar1 = (bVar4 >> 4) + 0x61;
      name = (byte *)(uint)bVar1;
      if ((0x40 < bVar1) && (bVar1 < 0x5b)) {
        name = (byte *)(uint)(byte)((bVar4 >> 4) + 0x81);
      }
      pcVar3 = strchr("abcdefghijklmnopqrstuvwxyz0123456789$ :/._+-()\\",(int)name);
      if (pcVar3 == (char *)0x0) {
        cVar2 = '\0';
      }
      else {
        cVar2 = pcVar3[0x30];
      }
      pcVar6[1] = cVar2;
      bVar1 = (bVar4 & 0xf) + 0x61;
      pcVar6 = pcVar6 + 2;
      local_4 = (uint)bVar1;
      if ((0x40 < bVar1) && (bVar1 < 0x5b)) {
        local_4 = (uint)(byte)((bVar4 & 0xf) + 0x81);
      }
      pcVar3 = strchr("abcdefghijklmnopqrstuvwxyz0123456789$ :/._+-()\\",local_4);
      if (pcVar3 == (char *)0x0) {
        cVar2 = '\0';
      }
      else {
LAB_10488a2f:
        cVar2 = pcVar3[0x30];
      }
LAB_10488977:
      *pcVar6 = cVar2;
      pcVar6 = pcVar6 + 1;
    }
    else {
      *pcVar6 = pcVar3[0x30];
      pcVar6 = pcVar6 + 1;
      if (bVar4 == 0x24) {
        pcVar3 = strchr("abcdefghijklmnopqrstuvwxyz0123456789$ :/._+-()\\",0x24);
        if (pcVar3 != (char *)0x0) goto LAB_10488a2f;
        cVar2 = '\0';
        goto LAB_10488977;
      }
    }
    bVar4 = *pbVar5;
    name = pbVar5;
    if (bVar4 == 0) {
      *pcVar6 = '\0';
      return pcVar6;
    }
  } while( true );
}

