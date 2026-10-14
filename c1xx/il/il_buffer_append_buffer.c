void __thiscall il_buffer_append_buffer(c1_il_buffer *src,c1_il_buffer *dst)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  c1_u8 *pcVar5;
  c1_u8 *pcVar6;
  
  pcVar5 = (src->bytes).start;
  uVar4 = (int)(src->bytes).cur - (int)pcVar5;
  if (uVar4 == 0) {
    return;
  }
  iVar1 = uVar4 + 1;
  if (iVar1 < 0) {
    bVar2 = 0;
  }
  else {
    if ((dst->bytes).start + (dst->bytes).size < (dst->bytes).cur + iVar1) {
      iVar1 = il_buffer_grow(&dst->bytes,iVar1);
      bVar2 = 0;
      if (iVar1 == 0) goto LAB_1047e883;
    }
    bVar2 = 1;
  }
LAB_1047e883:
  bVar2 = dst->open & bVar2;
  dst->open = bVar2;
  if (bVar2 != 0) {
    pcVar6 = (dst->bytes).cur;
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
    (dst->bytes).cur = (dst->bytes).cur + uVar4;
  }
  (src->bytes).cur = (src->bytes).start;
  return;
}

