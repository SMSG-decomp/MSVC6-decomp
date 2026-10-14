int * __thiscall file_record_lookup_or_new(void *scope,char *file,uint hash)

{
  char cVar1;
  char *text;
  uint uVar2;
  fe_name *name;
  int *piVar3;
  uint uVar4;
  char *pcVar5;
  
  text = file;
  uVar4 = hash;
  if (hash == 0) {
    cVar1 = *file;
    file = (char *)CONCAT31(file._1_3_,cVar1);
    pcVar5 = text;
    while (pcVar5 = pcVar5 + 1, cVar1 != '\0') {
      cVar1 = *pcVar5;
      uVar4 = (uVar4 >> 4) + uVar4 * 4 + ((uint)file & 0xff);
      file._1_3_ = (undefined3)((uint)file >> 8);
      file = (char *)CONCAT31(file._1_3_,cVar1);
    }
    uVar2 = (int)pcVar5 - (int)text;
  }
  else {
    uVar2 = 0xffffffff;
    pcVar5 = file;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar2 = ~uVar2;
  }
  if (uVar2 - 1 < 0x101) {
    name = name_intern_hashed((c1_u8 *)text,uVar4,uVar2 - 1,(byte *)&file);
    if (((char)file != '\0') || (piVar3 = file_record_find(scope,(int)name), piVar3 == (int *)0x0))
    {
      piVar3 = (int *)g_arenas[0].cur;
      g_arenas[0].cur = g_arenas[0].cur + 0x18;
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        *piVar3 = (int)name;
        *(uchar *)((int)piVar3 + 4) = '\x15';
      }
      if (*(int *)((int)scope + 0x214) != 0) {
        piVar3[5] = *(int *)((int)scope + 0x214);
      }
      *(int **)((int)scope + 0x214) = piVar3;
    }
    return piVar3;
  }
  diag_fatal(0x51,text,0x100);
}

