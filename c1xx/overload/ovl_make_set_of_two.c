byte * __cdecl ovl_make_set_of_two(c1_symbol *sym,c1_symbol *sym2)

{
  fe_name *name;
  byte *pbVar1;
  c1_keyed_list *pcVar2;
  c1_type *list;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  c1_arena *a;
  c1_symbol *sym_00;
  
  tree_list_arena_set(5);
  sym_00 = sym2;
  pcVar2 = tree_new_list_cell((c1_keyed_list *)0x0,0,sym);
  list = (c1_type *)tree_new_list_cell((c1_keyed_list *)0x0,(int)pcVar2->head,sym_00);
  tree_list_arena_restore();
  if (((g_block_depth != '\0') && (g_class_depth < 0)) && ((g_compile_flags_c8 & 0x10000000) == 0))
  {
    if ((((g_compile_flags_c8 & 0x40000000) != 0) && (((byte)g_compile_flags_cc & 8) == 0)) &&
       ((g_compile_flags_c4 & 0x200) == 0)) {
      pbVar3 = sym_alloc_record_fragment(sym2,list,sym,list);
      return pbVar3;
    }
    if (((byte)g_compile_flags_cc & 0x50) == 0) {
      iVar5 = 4;
      goto LAB_1041c7ac;
    }
  }
  iVar5 = 0;
LAB_1041c7ac:
  name = sym2->name;
  if (iVar5 == 0) {
    if ((void **)g_symbol_free_lists[g_symbol_size_class_table[0x12]] != (void **)0x0) {
      pbVar3 = sym_record_from_free_list_tail_2
                         (g_symbol_size_class_table[0x12],0,
                          (void **)g_symbol_free_lists[g_symbol_size_class_table[0x12]],name,list);
      return pbVar3;
    }
  }
  a = g_arenas + iVar5;
  uVar4 = g_symbol_size_table[0x12] + 3;
  pbVar3 = a->cur;
  pbVar1 = g_arenas[iVar5].end;
  a->cur = pbVar3 + (uVar4 & 0xfffffffc);
  if (pbVar1 < pbVar3 + (uVar4 & 0xfffffffc)) {
    arena_grow(a);
  }
  if (pbVar3 != (byte *)0x0) {
    *pbVar3 = *pbVar3 & 0xf2 | 0x12;
    if (pbVar3 + 8 != (byte *)0x0) {
      *(fe_name **)(pbVar3 + 8) = name;
      pbVar3[0xc] = 0;
      pbVar3[0xd] = 0;
      pbVar3[0xe] = 0;
      pbVar3[0xf] = 0;
    }
    *(c1_type **)(pbVar3 + 0x14) = list;
    return pbVar3;
  }
  pcRam00000014 = list;
  return (byte *)0x0;
}

