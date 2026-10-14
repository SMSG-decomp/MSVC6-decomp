int __thiscall array16_save(c1_idb_region_array *array,c1_byte_buffer *buf)

{
  c1_u32 *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  c1_u32 *dst;
  uint *elements;
  c1_u32 *dst_2;
  
  pcVar1 = &array->count;
  if ((pcVar1 == (c1_u32 *)0x0) ||
     ((buf->start + buf->size < buf->cur + 4 && (iVar3 = il_buffer_grow(buf,4), iVar3 == 0)))) {
    return 0;
  }
  dst = (c1_u32 *)buf;
  if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
    dst = (c1_u32 *)buf->cur;
  }
  if (buf->start != (c1_u8 *)0x0) {
    buf->cur = buf->cur + 4;
  }
  *dst = *pcVar1;
  uVar2 = *pcVar1;
  if (uVar2 != 0) {
    elements = &array->data->signature;
    iVar3 = uVar2 * 0x10;
    if ((c1_idb_region *)elements == (c1_idb_region *)0x0) {
      return 0;
    }
    if (iVar3 < 0) {
      return 0;
    }
    if ((buf->start + buf->size < buf->cur + iVar3) &&
       (iVar4 = il_buffer_grow(buf,iVar3), iVar4 == 0)) {
      return 0;
    }
    dst_2 = (c1_u32 *)buf;
    if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
      dst_2 = (c1_u32 *)buf->cur;
    }
    if (buf->start != (c1_u8 *)0x0) {
      buf->cur = buf->cur + iVar3;
    }
    for (iVar3 = (uVar2 & 0xfffffff) << 2; iVar3 != 0; iVar3 = iVar3 + -1) {
      ((c1_byte_buffer *)dst_2)->start = (c1_u8 *)((c1_idb_region *)elements)->signature;
      elements = (uint *)&((c1_idb_region *)elements)->length;
      dst_2 = (c1_u32 *)&((c1_byte_buffer *)dst_2)->cur;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(char *)dst_2 = (char)*elements;
      elements = (uint *)((int)elements + 1);
      dst_2 = (c1_u32 *)((int)dst_2 + 1);
    }
  }
  return 1;
}

