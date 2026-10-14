void __cdecl
il_emit_type_descriptor_fragment
          (uint type_flag_bits,c1_type *type,uint aggregate_size,uint descriptor)

{
  byte bVar1;
  uint descriptor_size;
  int iVar2;
  uint uVar3;
  
  descriptor_size = type_size_scalar(type);
  uVar3 = descriptor_size << 4;
  descriptor = uVar3 | 2;
  if ((type_flag_bits & 0x40) != 0) {
    descriptor = CONCAT22((short)(uVar3 >> 0x10),CONCAT11((char)(uVar3 >> 8),(char)descriptor)) |
                 0x1000;
  }
  if ((type_flag_bits & 0x20) != 0) {
    descriptor = descriptor | 0x2000;
  }
  if (((char)type->code < '\0') && ((type->flags & 0x100) != 0)) {
    il_emit_type_descriptor_fragment_2(descriptor,descriptor_size,2,aggregate_size);
    return;
  }
  if (0x7f < (ushort)descriptor) {
    if ((g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 2) &&
       (iVar2 = il_buffer_grow(&g_il_ex.bytes,2), iVar2 == 0)) {
      bVar1 = 0;
    }
    else {
      bVar1 = 1;
    }
    g_il_ex.open = g_il_ex.open & bVar1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.pbEnd = (byte)(descriptor >> 8) | 0x80;
      g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
    }
  }
  if ((g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 2) &&
     (iVar2 = il_buffer_grow(&g_il_ex.bytes,2), iVar2 == 0)) {
    bVar1 = 0;
  }
  else {
    bVar1 = 1;
  }
  g_il_ex.open = g_il_ex.open & bVar1;
  if (g_il_ex.open != 0) {
    *g_il_ex.bytes.pbEnd = (uchar)descriptor;
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
  }
  return;
}

