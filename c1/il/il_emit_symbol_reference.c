void __cdecl il_emit_symbol_reference(fe_il_buffer *buf,c1_symbol *sym,uint id)

{
  c1_symbol *sym_00;
  int iVar1;
  PB puVar2;
  byte bVar3;
  uint id_00;
  
  if ((sym->flags23 & 1) == 0) {
    il_buffer_put_id(buf,id);
    return;
  }
  sym_00 = sym_segment_record(sym);
  iVar1 = il_buffer_reserve(&buf->bytes,5);
  bVar3 = buf->open & (byte)iVar1 & 1;
  buf->open = bVar3;
  if (bVar3 != 0) {
    if ((int)(id | 0x200) < 0x8000) {
      *(short *)(buf->bytes).pbEnd = (short)(id | 0x200);
      puVar2 = (buf->bytes).pbEnd + 2;
    }
    else {
      *(uint *)(buf->bytes).pbEnd =
           (uint)((uint3)(id >> 8) & 0xffffc0 | 0x40) << 9 | id & 0x7fff | 0x200;
      puVar2 = (buf->bytes).pbEnd + 4;
    }
    (buf->bytes).pbEnd = puVar2;
  }
  if (g_c9il_mode == '\0') {
    if ((sym_00->key_ref & 0xfffffff8) != 0) {
      id_00 = sym_00->key_ref >> 3;
      goto LAB_10638989;
    }
    id_00 = il_symbol_key_assign(sym_00);
  }
  else {
    id_00 = sym_00->entity & 0xffffff;
  }
  if (g_c9il_mode != '\0') {
    il_buffer_put_id(buf,id_00);
    return;
  }
LAB_10638989:
  iVar1 = il_buffer_reserve(&buf->bytes,4);
  bVar3 = buf->open & (byte)iVar1 & 1;
  buf->open = bVar3;
  if (bVar3 == 0) {
    return;
  }
  bVar3 = (byte)id_00;
  if (id_00 < 0x3fff80) {
    if (0x3fff < id_00) {
      *(buf->bytes).pbEnd = bVar3 | 0xc0;
      puVar2 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar2;
      *puVar2 = (uchar)(id_00 >> 6);
      puVar2 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar2;
      *puVar2 = (uchar)(id_00 >> 0xe);
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      return;
    }
    *(buf->bytes).pbEnd = bVar3 & 0x3f | 0x80;
    puVar2 = (buf->bytes).pbEnd + 1;
    (buf->bytes).pbEnd = puVar2;
    *puVar2 = (uchar)(id_00 >> 6);
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    return;
  }
  *(buf->bytes).pbEnd = bVar3 + 0x80;
  (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
  return;
}

