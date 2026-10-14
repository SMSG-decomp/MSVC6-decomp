void __cdecl parse_context_reset(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  c1_u32 cVar4;
  int iVar5;
  char *paren_flag;
  uint *level;
  uint *word;
  
  if (-1 < g_paren_depth) {
    paren_flag = (char *)(g_paren_level_flags + g_paren_depth);
    level = (uint *)(g_paren_level_declspecs + g_paren_depth);
    do {
      g_pending_access_check[g_paren_depth] = (c1_symbol *)0x0;
      g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
      *paren_flag = 0;
      g_paren_depth = g_paren_depth + -1;
      paren_flag = paren_flag + -1;
      word = level;
      for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
        *word = 0;
        word = word + 1;
      }
      level = level + -9;
    } while (-1 < g_paren_depth);
  }
  cVar4 = g_compile_flags_cc;
  uVar3 = g_compile_flags_c8;
  uVar2 = g_compile_flags_c4;
  g_class_depth = -1;
  g_list_cell_arena_saved = -1;
  g_paren_depth = 0;
  uVar1 = g_compile_flags_c8 & 0x30000000;
  g_sizeof_depth = 0;
  g_block_depth = '\0';
  g_prototype_scope_depth = 0;
  g_current_function = (c1_symbol *)0x0;
  g_parse_block_record_depth = 0;
  g_compile_flags_cc = g_compile_flags_cc & 0xffbfffff;
  g_compile_flags_c8 = g_compile_flags_c8 & 0xfcffffef;
  g_compile_flags_c4 = g_compile_flags_c4 & 0xe7e5fff8 | 0x40000000;
  if ((((uVar1 == 0) &&
       ((((uVar3 & 0x40000000) == 0 || ((cVar4 & 8) != 0)) || ((uVar2 & 0x200) != 0)))) &&
      ((cVar4 & 0x10) == 0)) && (((uVar3 & 0x4000000) == 0 || ((uVar2 & 0x8000) != 0)))) {
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if ((cVar4 & 1) != 0) {
      g_context_arena_index = 4;
      g_expr_arena_index = 4;
      return;
    }
  }
  else {
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
  }
  return;
}

