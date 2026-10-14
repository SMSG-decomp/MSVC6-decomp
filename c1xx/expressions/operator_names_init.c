void __cdecl operator_names_init(void)

{
  ushort *puVar1;
  c1_u32 cVar2;
  fe_name *pfVar3;
  c1_type *pcVar4;
  c1_type **ppcVar5;
  c1_type **ppcVar6;
  
  g_name_operator_arrow = name_intern_operator('S');
  g_name_operator_call = name_intern_operator('v');
  if ((char)g_builtin_operator_candidates[0].op != '\0') {
    ppcVar6 = &g_builtin_operator_candidates[0].left;
    do {
      pfVar3 = name_intern_operator((uchar)((c1_builtin_operator_row *)(ppcVar6 + -1))->op);
      ppcVar6[3] = (c1_type *)pfVar3;
      for (ppcVar5 = ppcVar6; ppcVar5 < ppcVar6 + 2; ppcVar5 = ppcVar5 + 1) {
        if (*(ushort *)ppcVar5 != 0) {
          pcVar4 = type_basic(*(ushort *)ppcVar5);
          *ppcVar5 = pcVar4;
        }
      }
      puVar1 = (ushort *)(ppcVar6 + 4);
      ppcVar6 = ppcVar6 + 5;
    } while ((char)*puVar1 != '\0');
  }
  g_compile_flags_cc = g_compile_flags_cc | 0x10;
  g_context_arena_index = 0;
  g_expr_arena_index = 0;
  g_tree_zero_constant = tree_new_int_constant(0);
  cVar2 = g_compile_flags_cc;
  g_compile_flags_cc = g_compile_flags_cc & 0xffffffef;
  if ((((g_compile_flags_c8 & 0x32000000) == 0) &&
      ((((g_compile_flags_c8 & 0x40000000) == 0 || ((cVar2 & 8) != 0)) ||
       ((g_compile_flags_c4 & 0x200) != 0)))) &&
     (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))) {
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if ((cVar2 & 1) != 0) {
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

