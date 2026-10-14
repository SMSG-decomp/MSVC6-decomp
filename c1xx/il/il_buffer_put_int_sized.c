void __cdecl il_buffer_put_int_sized(uint *value,int size,c1_il_buffer *buf)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint *puVar5;
  ushort *puVar6;
  int iVar7;
  
  if (size != 2) {
    if (size != 4) {
      iVar3 = il_buffer_reserve(&buf->bytes,size + 2);
      bVar4 = buf->open & (byte)iVar3 & 1;
      buf->open = bVar4;
      if (bVar4 == 0) {
        return;
      }
      uVar2 = value[1];
      if ((((int)uVar2 < 1) && ((((int)uVar2 < 0 || (*value < 0x80)) && (-2 < (int)uVar2)))) &&
         ((uVar2 < 0x80000000 || (0xffffff80 < *value)))) {
        *(buf->bytes).cur = (c1_u8)*value;
        (buf->bytes).cur = (buf->bytes).cur + 1;
        return;
      }
      iVar3 = 0;
      *(buf->bytes).cur = 0x80;
      (buf->bytes).cur = (buf->bytes).cur + 1;
      if (size < 1) {
        return;
      }
      do {
        iVar7 = iVar3 >> 2;
        iVar3 = iVar3 + 4;
        *(uint *)(buf->bytes).cur = value[iVar7];
        (buf->bytes).cur = (buf->bytes).cur + 4;
      } while (iVar3 < size);
      return;
    }
    uVar2 = *value;
    iVar3 = il_buffer_reserve(&buf->bytes,6);
    bVar4 = buf->open & (byte)iVar3 & 1;
    buf->open = bVar4;
    if (bVar4 == 0) {
      return;
    }
    if ((uVar2 & 0xffffff80) != 0) {
      *(buf->bytes).cur = 0x80;
      puVar5 = (uint *)((buf->bytes).cur + 1);
      (buf->bytes).cur = (c1_u8 *)puVar5;
      *puVar5 = uVar2;
      (buf->bytes).cur = (buf->bytes).cur + 4;
      return;
    }
    *(buf->bytes).cur = (c1_u8)uVar2;
    (buf->bytes).cur = (buf->bytes).cur + 1;
    return;
  }
  uVar1 = (ushort)*value;
  if ((buf->bytes).start + (buf->bytes).size < (buf->bytes).cur + 4) {
    iVar3 = il_buffer_grow(&buf->bytes,4);
    bVar4 = 0;
    if (iVar3 == 0) goto LAB_1047e90c;
  }
  bVar4 = 1;
LAB_1047e90c:
  bVar4 = buf->open & bVar4;
  buf->open = bVar4;
  if (bVar4 == 0) {
    return;
  }
  if ((uVar1 & 0xff80) != 0) {
    *(buf->bytes).cur = 0x80;
    puVar6 = (ushort *)((buf->bytes).cur + 1);
    (buf->bytes).cur = (c1_u8 *)puVar6;
    *puVar6 = uVar1;
    (buf->bytes).cur = (buf->bytes).cur + 2;
    return;
  }
  *(buf->bytes).cur = (c1_u8)uVar1;
  (buf->bytes).cur = (buf->bytes).cur + 1;
  return;
}

