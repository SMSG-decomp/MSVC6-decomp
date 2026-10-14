void __cdecl il_emit_type_descriptor(int op,c1_node *node,int mode)

{
  ushort uVar1;
  ushort uVar2;
  c1_type *type;
  byte bVar3;
  c1_type *pcVar4;
  int iVar5;
  uint uVar6;
  uint descriptor_size;
  uint aggregate_size;
  
  type = node->type;
  descriptor_size = 0;
  aggregate_size = 0;
  pcVar4 = type;
  if ((type->code & 0x8f) == 0x83) {
    pcVar4 = type_skip_arrays(type->base);
  }
  uVar1 = pcVar4->flags;
  uVar2 = type->code;
  bVar3 = (byte)uVar2;
  if ((char)bVar3 < '\0') {
    descriptor_size = 4;
    uVar6 = 3;
  }
  else if ((uVar2 & 0x110) == 0) {
    if ((bVar3 >> 5 & 1) == 0) {
      if ((uVar2 & 0x200) == 0) {
        if ((bVar3 >> 6 & 1) == 0) {
          if ((uVar2 & 0x400) == 0) {
            uVar6 = 0;
          }
          else {
            descriptor_size = 2;
            uVar6 = 2;
          }
        }
        else {
          uVar6 = 7;
        }
      }
      else {
        uVar6 = 6;
        if (op != 0x27) {
          aggregate_size = type_size_checked(type);
          descriptor_size = -(uint)(aggregate_size < 0x20) & aggregate_size;
        }
      }
    }
    else if (mode == 1) {
      uVar6 = 10;
      descriptor_size = 10;
    }
    else {
      uVar6 = 5;
      descriptor_size = type_size_scalar(type);
    }
  }
  else if ((uVar2 & 0x2000) == 0) {
    if ((((g_ms_extensions == '\0') && ((uVar2 & 0xfff) == 0x11)) && ((uVar2 & 0x1000) == 0)) &&
       (g_opt_J_unsigned_char != '\0')) {
      il_emit_type_descriptor_fragment(uVar1 & 0x3e0,type,aggregate_size,(uint)node);
      return;
    }
    uVar6 = 1;
    descriptor_size = type_size_scalar(type);
  }
  else {
    uVar6 = 2;
    descriptor_size = type_size_scalar(type);
  }
  node = (c1_node *)(descriptor_size << 4 | uVar6);
  if ((uVar1 & 0x40) != 0) {
    node = (c1_node *)((uint)node | 0x1000);
  }
  if ((uVar1 & 0x20) != 0) {
    node = (c1_node *)((uint)node | 0x2000);
  }
  if (((char)type->code < '\0') && ((type->flags & 0x100) != 0)) {
    il_emit_type_descriptor_fragment_2((uint)node,descriptor_size,(ushort)uVar6,aggregate_size);
    return;
  }
  if (0x7f < (ushort)node) {
    if ((g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 2) &&
       (iVar5 = il_buffer_grow(&g_il_ex.bytes,2), iVar5 == 0)) {
      bVar3 = 0;
    }
    else {
      bVar3 = 1;
    }
    g_il_ex.open = g_il_ex.open & bVar3;
    if (g_il_ex.open != 0) {
      *g_il_ex.bytes.pbEnd = (byte)((uint)node >> 8) | 0x80;
      g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
    }
  }
  if ((g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 2) &&
     (iVar5 = il_buffer_grow(&g_il_ex.bytes,2), iVar5 == 0)) {
    bVar3 = 0;
  }
  else {
    bVar3 = 1;
  }
  g_il_ex.open = g_il_ex.open & bVar3;
  if (g_il_ex.open != 0) {
    *g_il_ex.bytes.pbEnd = (uchar)node;
    g_il_ex.bytes.pbEnd = g_il_ex.bytes.pbEnd + 1;
  }
  if (((ushort)uVar6 == 6) && (descriptor_size == 0)) {
    if ((g_il_ex.bytes.pbStart + g_il_ex.bytes.cbAlloc < g_il_ex.bytes.pbEnd + 6) &&
       (iVar5 = il_buffer_grow(&g_il_ex.bytes,6), iVar5 == 0)) {
      bVar3 = 0;
    }
    else {
      bVar3 = 1;
    }
    g_il_ex.open = g_il_ex.open & bVar3;
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

