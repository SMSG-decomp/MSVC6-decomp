c1_symbol * __cdecl sym_new_kind1_placeholder(fe_name *name)

{
  c1_type *pcVar1;
  c1_u8 *pcVar2;
  c1_type *pcVar3;
  c1_type *pcVar4;
  c1_symbol *pcVar5;
  c1_arena *pcVar6;
  uint uVar7;
  int unused;
  
  if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
       ((g_compile_flags_c8 & 0x10000000) != 0)) ||
      ((((g_compile_flags_c8 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
       ((g_compile_flags_c4 & 0x200) == 0)))) || (((byte)g_compile_flags_cc & 0x50) != 0)) {
    unused = 0;
    if ((void **)g_symbol_free_lists[g_symbol_size_class_table[1]] != (void **)0x0) {
      pcVar5 = sym_record_from_free_list_tail
                         (g_symbol_size_class_table[1],0,
                          (void **)g_symbol_free_lists[g_symbol_size_class_table[1]],name);
      return pcVar5;
    }
  }
  else {
    unused = 4;
  }
  pcVar6 = g_arenas + unused;
  uVar7 = g_symbol_size_table[1] + 3;
  pcVar5 = (c1_symbol *)pcVar6->cur;
  pcVar2 = g_arenas[unused].end;
  pcVar6->cur = &pcVar5->kind + (uVar7 & 0xfffffffc);
  if (pcVar2 < &pcVar5->kind + (uVar7 & 0xfffffffc)) {
    arena_grow(pcVar6);
  }
  if (pcVar5 == (c1_symbol *)0x0) {
    pcVar5 = (c1_symbol *)0x0;
  }
  else {
    pcVar5 = sym_init_kind(pcVar5,'\x01',name,unused);
  }
  pcVar6 = g_arenas + g_context_arena_index;
  pcVar3 = (c1_type *)pcVar6->cur;
  pcVar4 = (c1_type *)g_arenas[g_context_arena_index].end;
  pcVar1 = pcVar3 + 1;
  pcVar6->cur = (c1_u8 *)pcVar1;
  if (pcVar4 < pcVar1) {
    arena_grow(pcVar6);
  }
  pcVar5->type = pcVar3;
  (pcVar5->tail).fn.op_token = '\x01';
  return pcVar5;
}

