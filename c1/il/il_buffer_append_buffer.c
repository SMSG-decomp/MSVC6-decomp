void __thiscall il_buffer_append_buffer(fe_il_buffer *src,fe_il_buffer *dst)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  PB puVar5;
  uchar *puVar6;
  
  puVar5 = (src->bytes).pbStart;
  uVar4 = (int)(src->bytes).pbEnd - (int)puVar5;
  if (uVar4 == 0) {
    return;
  }
  iVar1 = uVar4 + 1;
  if (iVar1 < 0) {
    bVar2 = 0;
  }
  else {
    if ((dst->bytes).pbStart + (dst->bytes).cbAlloc < (dst->bytes).pbEnd + iVar1) {
      iVar1 = il_buffer_grow(&dst->bytes,iVar1);
      bVar2 = 0;
      if (iVar1 == 0) goto LAB_1063aa2b;
    }
    bVar2 = 1;
  }
LAB_1063aa2b:
  bVar2 = dst->open & bVar2;
  dst->open = bVar2;
  if (bVar2 != 0) {
    puVar6 = (dst->bytes).pbEnd;
    for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)puVar6 = *(undefined4 *)puVar5;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
    }
    for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    (dst->bytes).pbEnd = (dst->bytes).pbEnd + uVar4;
  }
  (src->bytes).pbEnd = (src->bytes).pbStart;
  return;
}

