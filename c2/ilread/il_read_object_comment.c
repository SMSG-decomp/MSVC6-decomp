void __fastcall il_read_object_comment(int kind)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  char local_200 [512];
  
  if (kind == 7) {
    iVar6 = il_read_byte();
    iVar8 = (int)(char)iVar6;
    pcVar4 = arena_alloc(1,iVar8 + 1);
    *pcVar4 = (char)iVar6;
    pcVar2 = pcVar4;
    if (iVar8 != 0) {
      do {
        iVar6 = il_read_byte();
        iVar8 = iVar8 + -1;
        pcVar2[1] = (char)iVar6;
        pcVar2 = pcVar2 + 1;
      } while (iVar8 != 0);
      add_comment_record(7,(int)pcVar4);
      return;
    }
  }
  else {
    il_read_string(local_200,0x200);
    pcVar2 = arena_strdup(local_200,1);
    pcVar4 = pcVar2;
    if ((kind == 4) && (pcVar3 = strchr(pcVar2,0x20), pcVar3 != (char *)0x0)) {
      uVar5 = 0xffffffff;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      pcVar4 = arena_alloc(1,~uVar5 + 2);
      uVar5 = 0xffffffff;
      do {
        pcVar3 = pcVar2;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar3 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar3;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      *pcVar4 = '\"';
      iVar6 = -1;
      pcVar4[1] = '\0';
      pcVar2 = pcVar4;
      do {
        pcVar9 = pcVar2;
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        pcVar9 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar9;
      } while (cVar1 != '\0');
      pcVar2 = pcVar3 + -uVar5;
      pcVar3 = pcVar9 + -1;
      for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar2;
        pcVar2 = pcVar2 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar3 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      }
      uVar5 = 0xffffffff;
      pcVar2 = "\"";
      do {
        pcVar3 = pcVar2;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar3 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar3;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      iVar6 = -1;
      pcVar2 = pcVar4;
      do {
        pcVar9 = pcVar2;
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        pcVar9 = pcVar2 + 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar9;
      } while (cVar1 != '\0');
      pcVar2 = pcVar3 + -uVar5;
      pcVar3 = pcVar9 + -1;
      for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar2;
        pcVar2 = pcVar2 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar3 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        pcVar3 = pcVar3 + 1;
      }
    }
  }
  add_comment_record(kind,(int)pcVar4);
  return;
}

