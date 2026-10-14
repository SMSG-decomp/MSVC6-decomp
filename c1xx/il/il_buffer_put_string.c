void __thiscall il_buffer_put_string(c1_il_buffer *buf,char *s)

{
  c1_u8 **ppcVar1;
  char cVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  c1_u8 *pcVar8;
  
  uVar5 = 0xffffffff;
  pcVar7 = s;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  iVar3 = uVar5 + 1;
  if (iVar3 < 0) {
    bVar4 = 0;
  }
  else {
    if ((buf->bytes).start + (buf->bytes).size < (buf->bytes).cur + iVar3) {
      iVar3 = il_buffer_grow(&buf->bytes,iVar3);
      if (iVar3 == 0) {
        bVar4 = 0;
        goto LAB_104280e3;
      }
    }
    bVar4 = 1;
  }
LAB_104280e3:
  bVar4 = buf->open & bVar4;
  buf->open = bVar4;
  if (bVar4 != 0) {
    pcVar8 = (buf->bytes).cur;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)s;
      s = s + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar6 = uVar5 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar8 = *s;
      s = s + 1;
      pcVar8 = pcVar8 + 1;
    }
    ppcVar1 = &(buf->bytes).cur;
    *ppcVar1 = *ppcVar1 + uVar5;
  }
  return;
}

