int __thiscall il_buffer_grow(c1_byte_buffer *buf,int n)

{
  int iVar1;
  c1_u8 *new_start;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  c1_u8 *pcVar5;
  c1_u8 *pcVar6;
  
  iVar1 = (int)buf->size / 2;
  if (iVar1 < n + 0x1000) {
    iVar1 = n + 0x1000;
  }
  uVar4 = buf->size + 0xfff + iVar1 & 0xfffff000;
  new_start = __2_YAPAXI_Z(uVar4);
  if (new_start != (c1_u8 *)0x0) {
    buf->size = uVar4;
    uVar4 = (int)buf->cur - (int)buf->start;
    pcVar5 = buf->start;
    pcVar6 = new_start;
    for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar2 = uVar4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
    uVar3 = buf->size - uVar4;
    pcVar5 = new_start + uVar4;
    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      pcVar5[0] = '\0';
      pcVar5[1] = '\0';
      pcVar5[2] = '\0';
      pcVar5[3] = '\0';
      pcVar5 = pcVar5 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar5 = '\0';
      pcVar5 = pcVar5 + 1;
    }
    __3_YAXPAX_Z(buf->start);
    pcVar5 = buf->start;
    buf->start = new_start;
    buf->cur = new_start + uVar4;
    if ((pcVar5 != new_start) && (buf->on_move != (c1_il_buffer_move_fn)0x0)) {
      (*buf->on_move)(buf->move_ctx,pcVar5,new_start);
    }
    return 1;
  }
  return 0;
}

