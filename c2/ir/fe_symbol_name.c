char * __fastcall fe_symbol_name(c2_fe_symbol *s,int undecorated)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  
  pcVar3 = s->name;
  if (pcVar3 == (char *)0x0) {
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\p2symtab.c",0x47e);
  }
  if (*pcVar3 == '?') {
    pcVar2 = undecorate_name(pcVar3,undecorated);
    if (*pcVar2 == '\0') {
      return pcVar3;
    }
  }
  else {
    if ((s->cls == '\x04') &&
       (((uVar5 = s->attrs & 0x1c, uVar5 == 0x10 || (uVar5 == 4)) || (uVar5 == 0x18)))) {
      uVar5 = 0xffffffff;
      pcVar3 = pcVar3 + 1;
      do {
        pcVar2 = pcVar3;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar2 = pcVar3 + 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar2;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar3 = pcVar2 + -uVar5;
      pcVar2 = g_il_name_buffer;
      for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar2 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar2 = pcVar2 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar2 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar2 = pcVar2 + 1;
      }
      pcVar3 = strchr(g_il_name_buffer,0x40);
      *pcVar3 = '\0';
      return g_il_name_buffer;
    }
    pcVar2 = pcVar3 + 1;
  }
  return pcVar2;
}

