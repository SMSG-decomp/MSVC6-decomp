void __cdecl class_append_alignment_member(int size)

{
  uint *puVar1;
  c1_u8 *pcVar2;
  void *name;
  c1_u32 cVar3;
  c1_symbol *pcVar4;
  c1_arena *a;
  uint uVar5;
  int unused;
  c1_symbol *pcVar6;
  
  name = g_name_alignment_member;
  if ((((g_block_depth == '\0') || (-1 < g_class_depth)) || ((g_compile_flags_c8 & 0x10000000) != 0)
      ) || (((((g_compile_flags_c8 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
             ((g_compile_flags_c4 & 0x200) == 0)) || (((byte)g_compile_flags_cc & 0x50) != 0)))) {
    unused = 0;
  }
  else {
    unused = 4;
  }
  if ((unused == 0) &&
     (puVar1 = g_symbol_free_lists[g_symbol_size_class_table[3]], puVar1 != (uint *)0x0)) {
    g_symbol_free_lists[g_symbol_size_class_table[3]] = (uint *)puVar1[1];
    pcVar4 = (c1_symbol *)(puVar1 + -2);
    *puVar1 = 0;
    puVar1[1] = 0;
    cVar3 = g_symbol_size_table[3];
    pcVar6 = pcVar4;
    for (uVar5 = g_symbol_size_table[3] >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      pcVar6->kind = '\0';
      pcVar6->flags1 = '\0';
      pcVar6->flags2 = '\0';
      pcVar6->flags3 = '\0';
      pcVar6 = (c1_symbol *)&pcVar6->flags4;
    }
    for (uVar5 = cVar3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      pcVar6->kind = '\0';
      pcVar6 = (c1_symbol *)&pcVar6->flags1;
    }
    *puVar1 = (uint)name;
    pcVar4->kind = pcVar4->kind & 0xe3 | 3;
    if (pcVar4 != (c1_symbol *)0x0) goto LAB_10438a34;
  }
  a = g_arenas + unused;
  uVar5 = g_symbol_size_table[3] + 3;
  pcVar4 = (c1_symbol *)a->cur;
  pcVar2 = g_arenas[unused].end;
  a->cur = &pcVar4->kind + (uVar5 & 0xfffffffc);
  if (pcVar2 < &pcVar4->kind + (uVar5 & 0xfffffffc)) {
    arena_grow(a);
  }
  if (pcVar4 == (c1_symbol *)0x0) {
    pcVar4 = (c1_symbol *)0x0;
  }
  else {
    pcVar4 = sym_init_kind(pcVar4,'\x03',name,unused);
  }
LAB_10438a34:
  pcVar4->flags3 = pcVar4->flags3 | 1;
  (pcVar4->detail).value = size;
  class_append_member(pcVar4);
  g_class_def_stack[g_class_depth].offset = g_class_def_stack[g_class_depth].offset + size;
  return;
}

