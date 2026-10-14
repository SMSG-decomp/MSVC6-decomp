void __thiscall import_text_append(c1_il_buffer *src,c1_il_buffer *dst)

{
  int iVar1;
  uint uVar2;
  c1_il_buffer *pcVar3;
  uint uVar4;
  c1_u8 *pcVar5;
  
  pcVar5 = (src->bytes).start;
  uVar4 = (int)(src->bytes).cur - (int)pcVar5;
  if (uVar4 == 0) {
    return;
  }
  if (((pcVar5 != (c1_u8 *)0x0) && (-1 < (int)uVar4)) &&
     (((dst->bytes).cur + uVar4 <= (dst->bytes).start + (dst->bytes).size ||
      (iVar1 = il_buffer_grow(&dst->bytes,uVar4), iVar1 != 0)))) {
    pcVar3 = dst;
    if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
      pcVar3 = (c1_il_buffer *)(dst->bytes).cur;
    }
    if ((dst->bytes).start != (c1_u8 *)0x0) {
      (dst->bytes).cur = (dst->bytes).cur + uVar4;
    }
    for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      (pcVar3->bytes).start = *(c1_u8 **)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar3 = (c1_il_buffer *)&(pcVar3->bytes).cur;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(c1_u8 *)&(pcVar3->bytes).start = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar3 = (c1_il_buffer *)((int)&(pcVar3->bytes).start + 1);
    }
    (src->bytes).cur = (src->bytes).start;
    return;
  }
  diag_fatal_simple(0x3c);
}

