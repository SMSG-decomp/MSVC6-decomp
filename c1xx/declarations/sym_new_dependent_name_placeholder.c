c1_symbol * __cdecl sym_new_dependent_name_placeholder(fe_name *name,char is_type)

{
  c1_u32 cVar1;
  c1_symbol *pcVar2;
  c1_type *pcVar3;
  uint uVar4;
  int unused;
  c1_symbol *pcVar5;
  c1_type local_10;
  uint *free_cell;
  
  if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
       ((g_compile_flags_c8 & 0x10000000) != 0)) ||
      ((((g_compile_flags_c8 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
       ((g_compile_flags_c4 & 0x200) == 0)))) || (((byte)g_compile_flags_cc & 0x50) != 0)) {
    unused = 0;
    free_cell = g_symbol_free_lists[g_symbol_size_class_table[0x18]];
    if (free_cell != (uint *)0x0) {
      pcVar2 = (c1_symbol *)(free_cell + -2);
      g_symbol_free_lists[g_symbol_size_class_table[0x18]] = (uint *)free_cell[1];
      *free_cell = 0;
      free_cell[1] = 0;
      cVar1 = g_symbol_size_table[0x18];
      pcVar5 = pcVar2;
      for (uVar4 = g_symbol_size_table[0x18] >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        pcVar5->kind = '\0';
        pcVar5->flags1 = '\0';
        pcVar5->flags2 = '\0';
        pcVar5->flags3 = '\0';
        pcVar5 = (c1_symbol *)&pcVar5->flags4;
      }
      for (uVar4 = cVar1 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        pcVar5->kind = '\0';
        pcVar5 = (c1_symbol *)&pcVar5->flags1;
      }
      *free_cell = (uint)name;
      pcVar2->kind = pcVar2->kind & 0xf8 | 0x18;
      if (pcVar2 != (c1_symbol *)0x0) goto LAB_1047bbdf;
    }
  }
  else {
    unused = 4;
  }
  pcVar2 = arena_alloc(g_arenas + unused,g_symbol_size_table[0x18] + 3 & 0xfffffffc);
  if (pcVar2 == (c1_symbol *)0x0) {
    pcVar2 = (c1_symbol *)0x0;
  }
  else {
    pcVar2 = sym_init_kind(pcVar2,'\x18',name,unused);
  }
LAB_1047bbdf:
  g_dependent_name_count = g_dependent_name_count + 1;
  local_10.extra =
       (c1_type_extra)
       (int)(short)((ushort)(byte)g_template_depth << 8 | (ushort)g_dependent_name_count);
  local_10.base = (c1_type *)0x0;
  local_10.debug_index = 0;
  local_10.code = 0x802;
  local_10.flags = 0;
  pcVar3 = type_intern(&local_10);
  pcVar2->type = pcVar3;
  if (is_type != '\0') {
    pcVar2->flags2 = pcVar2->flags2 | 0x10;
    name->flags = name->flags | 0x20000;
  }
  return pcVar2;
}

