c1_symbol * __cdecl class_append_base_entry(int access,c1_u8 is_virtual,c1_symbol *base)

{
  c1_u8 *pcVar1;
  byte bVar2;
  fe_name *name;
  uint *puVar3;
  c1_class_record *pcVar4;
  c1_type *pcVar5;
  c1_u32 cVar6;
  char cVar7;
  c1_symbol *pcVar8;
  uint uVar9;
  int unused;
  c1_symbol *pcVar10;
  
  if (access == 0) {
    pcVar5 = (g_class_def_stack[g_class_depth].cls)->type;
    cVar7 = (char)pcVar5->code;
    while (cVar7 < '\0') {
      pcVar5 = pcVar5->base;
      cVar7 = (char)pcVar5->code;
    }
    access = (-(uint)((pcVar5->code & 0x20f) != 0x201) & 2) + 1;
  }
  if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
       ((g_compile_flags_c8 & 0x10000000) != 0)) ||
      ((((g_compile_flags_c8 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
       ((g_compile_flags_c4 & 0x200) == 0)))) || (((byte)g_compile_flags_cc & 0x50) != 0)) {
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
    if (pcVar8 != (c1_symbol *)0x0) goto LAB_10439439;
  }
  pcVar8 = arena_alloc(g_arenas + unused,g_symbol_size_table[0xf] + 3 & 0xfffffffc);
  if (pcVar8 == (c1_symbol *)0x0) {
    pcVar8 = (c1_symbol *)0x0;
  }
  else {
    pcVar8 = sym_init_kind(pcVar8,'\x0f',name,unused);
  }
LAB_10439439:
  base->name->flags = base->name->flags | 0x40000;
  bVar2 = *(byte *)((int)&pcVar8->key_ref + 2);
  pcVar8->flags2 = (pcVar8->flags2 ^ (byte)access) & 3 ^ pcVar8->flags2;
  *(byte *)((int)&pcVar8->key_ref + 2) = (bVar2 ^ is_virtual) & 1 ^ bVar2;
  *(c1_u16 *)&pcVar8->key_ref = ((base->detail).cls)->scope_index;
  if ((((base->detail).cls)->flags3f & 2) != 0) {
    pcVar1 = &(((g_class_def_stack[g_class_depth].cls)->detail).cls)->flags3f;
    *pcVar1 = *pcVar1 | 4;
  }
  if ((is_virtual == '\0') && ((((base->detail).cls)->layout_flags3b & 0x10) == 0)) {
    cVar7 = '\0';
  }
  else {
    cVar7 = '\x01';
  }
  pcVar4 = ((g_class_def_stack[g_class_depth].cls)->detail).cls;
  pcVar4->layout_flags3b = pcVar4->layout_flags3b | cVar7 << 4;
  pcVar4 = ((g_class_def_stack[g_class_depth].cls)->detail).cls;
  pcVar4->layout_flags3c = pcVar4->layout_flags3c & 0xfe;
  pcVar8->type = (c1_type *)0x0;
  class_append_member(pcVar8);
  if ((g_browse_file != (char *)0x0) &&
     (((g_block_depth == '\0' || (g_opt_FR_browse != 0)) &&
      (((g_class_def_stack[g_class_depth].cls)->flags3 & 1) == 0)))) {
    (*g_il_emitter->vtbl->record_c)((int)pcVar8);
  }
  return pcVar8;
}

