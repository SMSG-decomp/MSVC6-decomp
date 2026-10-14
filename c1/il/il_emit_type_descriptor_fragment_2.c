void __cdecl
il_emit_type_descriptor_fragment_2
          (uint descriptor,uint descriptor_size,ushort type_class,uint aggregate_size)

{
  byte bVar1;
  int iVar2;
  uchar uVar3;
  uint uStack0000001c;
  
  uStack0000001c = descriptor | 0x4000;
  if (0x7f < (ushort)((ushort)descriptor | 0x4000)) {
    if ((g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 2) &&
       (iVar2 = il_buffer_grow(&g_il_ex.bytes,2), iVar2 == 0)) {
      bVar1 = 0;
    }
    else {
      bVar1 = 1;
    }
    g_il_ex.open = g_il_ex.open & bVar1;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.pbEnd = (byte)(uStack0000001c >> 8) | 0x80;
      g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
    }
  }
  uVar3 = (uchar)uStack0000001c;
  if (g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 2) {
    iVar2 = il_buffer_grow(&g_il_ex.bytes,2);
    uVar3 = (uchar)uStack0000001c;
    if (iVar2 == 0) {
      bVar1 = 0;
      goto LAB_1061a0e0;
    }
  }
  bVar1 = 1;
LAB_1061a0e0:
  g_il_ex.open = g_il_ex.open & bVar1;
  if (g_il_ex.open != 0) {
    *g_il_ex.bytes.pbEnd = uVar3;
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
  }
  if ((type_class == 6) && (descriptor_size == 0)) {
    if ((g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 6) &&
       (iVar2 = il_buffer_grow(&g_il_ex.bytes,6), iVar2 == 0)) {
      bVar1 = 0;
    }
    else {
      bVar1 = 1;
    }
    g_il_ex.open = g_il_ex.open & bVar1;
    if (g_il_ex.open != 0) {
      if ((aggregate_size & 0xffffff80) == 0) {
        *g_il_ex.bytes.pbEnd = (uchar)aggregate_size;
        g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
        return;
      }
      *g_il_ex.bytes.pbEnd = 0x80;
      g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
      *(uint *)g_il_ex.bytes.pbEnd = aggregate_size;
      g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 4;
    }
  }
  return;
}

