int __thiscall array_save(c1xx_pdb_array *array,c1_byte_buffer *buf)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  c1_u32 *out;
  uint *cursor;
  c1_u32 *out_2;
  uint *cursor_2;
  
  cursor_2 = &array->count;
  if ((cursor_2 == (uint *)0x0) ||
     ((buf->start + buf->size < buf->cur + 4 && (iVar1 = il_buffer_grow(buf,4), iVar1 == 0)))) {
    return 0;
  }
  out = (c1_u32 *)buf;
  if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
    out = (c1_u32 *)buf->cur;
  }
  if (buf->start != (c1_u8 *)0x0) {
    buf->cur = buf->cur + 4;
  }
  *out = *cursor_2;
  uVar3 = *cursor_2;
  if (uVar3 != 0) {
    cursor = array->data;
    iVar1 = uVar3 * 4;
    if (cursor == (c1_u32 *)0x0) {
      return 0;
    }
    if (iVar1 < 0) {
      return 0;
    }
    if ((buf->start + buf->size < buf->cur + iVar1) &&
       (iVar2 = il_buffer_grow(buf,iVar1), iVar2 == 0)) {
      return 0;
    }
    out_2 = (c1_u32 *)buf;
    if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
      out_2 = (c1_u32 *)buf->cur;
    }
    if (buf->start != (c1_u8 *)0x0) {
      buf->cur = buf->cur + iVar1;
    }
    for (uVar3 = uVar3 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
      ((c1_byte_buffer *)out_2)->start = (c1_u8 *)*cursor;
      cursor = cursor + 1;
      out_2 = (c1_u32 *)&((c1_byte_buffer *)out_2)->cur;
    }
    for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(char *)out_2 = (char)*cursor;
      cursor = (uint *)((int)cursor + 1);
      out_2 = (c1_u32 *)((int)out_2 + 1);
    }
  }
  return 1;
}

