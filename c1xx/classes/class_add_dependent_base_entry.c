c1_symbol * __cdecl class_add_dependent_base_entry(int access,c1_u8 is_virtual,c1_symbol *base)

{
  char cVar1;
  c1_type *pcVar2;
  fe_name *name;
  uint *puVar3;
  c1_u8 *pcVar4;
  c1_class_record *pcVar5;
  c1_u32 cVar6;
  byte bVar7;
  c1_symbol *pcVar8;
  uint uVar9;
  c1_arena *a;
  int unused;
  c1_symbol *pcVar10;
  c1_u16 base_type_word;
  
  if (access == 0) {
    pcVar2 = (g_class_def_stack[g_class_depth].cls)->type;
    cVar1 = (char)pcVar2->code;
    while (cVar1 < '\0') {
      pcVar2 = pcVar2->base;
      cVar1 = (char)pcVar2->code;
    }
    access = (-(uint)((pcVar2->code & 0x20f) != 0x201) & 2) + 1;
  }
  pcVar2 = base->type;
  if ((((g_block_depth == '\0') || (-1 < g_class_depth)) || ((g_compile_flags_c8 & 0x10000000) != 0)
      ) || (((((g_compile_flags_c8 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
             ((g_compile_flags_c4 & 0x200) == 0)) || (((byte)g_compile_flags_cc & 0x50) != 0)))) {
    unused = 0;
  }
  else {
    unused = 4;
  }
  name = base->name;
  if ((unused == 0) &&
     (puVar3 = g_symbol_free_lists[g_symbol_size_class_table[0xf]], puVar3 != (uint *)0x0)) {
    pcVar8 = (c1_symbol *)(puVar3 + -2);
    g_symbol_free_lists[g_symbol_size_class_table[0xf]] = (uint *)puVar3[1];
    *puVar3 = 0;
    puVar3[1] = 0;
    cVar6 = g_symbol_size_table[0xf];
    pcVar10 = pcVar8;
    for (uVar9 = g_symbol_size_table[0xf] >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      pcVar10->kind = '\0';
      pcVar10->flags1 = '\0';
      pcVar10->flags2 = '\0';
      pcVar10->flags3 = '\0';
      pcVar10 = (c1_symbol *)&pcVar10->flags4;
    }
    for (uVar9 = cVar6 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      pcVar10->kind = '\0';
      pcVar10 = (c1_symbol *)&pcVar10->flags1;
    }
    *puVar3 = (uint)name;
    pcVar8->kind = pcVar8->kind & 0xef | 0xf;
    if (pcVar8 != (c1_symbol *)0x0) goto LAB_1046c582;
  }
  a = g_arenas + unused;
  uVar9 = g_symbol_size_table[0xf] + 3;
  pcVar8 = (c1_symbol *)a->cur;
  pcVar4 = g_arenas[unused].end;
  a->cur = &pcVar8->kind + (uVar9 & 0xfffffffc);
  if (pcVar4 < &pcVar8->kind + (uVar9 & 0xfffffffc)) {
    arena_grow(a);
  }
  if (pcVar8 == (c1_symbol *)0x0) {
    pcVar8 = (c1_symbol *)0x0;
  }
  else {
    pcVar8 = sym_init_kind(pcVar8,'\x0f',name,unused);
  }
LAB_1046c582:
  bVar7 = *(byte *)((int)&pcVar8->key_ref + 2);
  pcVar8->flags2 = (pcVar8->flags2 ^ (byte)access) & 3 ^ pcVar8->flags2;
  bVar7 = (bVar7 ^ is_virtual) & 1 ^ bVar7;
  *(byte *)((int)&pcVar8->key_ref + 2) = bVar7;
  base_type_word = *(c1_u16 *)&pcVar2->extra;
  *(byte *)((int)&pcVar8->key_ref + 2) = bVar7 | 2;
  *(c1_u16 *)&pcVar8->key_ref = base_type_word;
  pcVar5 = ((g_class_def_stack[g_class_depth].cls)->detail).cls;
  pcVar5->layout_flags3b = pcVar5->layout_flags3b | (is_virtual & 1) << 4;
  pcVar5 = ((g_class_def_stack[g_class_depth].cls)->detail).cls;
  pcVar5->layout_flags3c = pcVar5->layout_flags3c & 0xfe;
  pcVar8->type = (c1_type *)0x0;
  class_append_member(pcVar8);
  return pcVar8;
}

