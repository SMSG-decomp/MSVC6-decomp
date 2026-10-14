void __fastcall func_parse_state_restore(c1_parse_state *rec)

{
  c1xx_scope **ppcVar1;
  c1_scope_stack *pcVar2;
  uint uVar3;
  int iVar4;
  c1_line_map_row *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint *src_declspecs;
  c1_class_def_entry *pcVar9;
  c1_u8 *pcVar10;
  uint *dst_class_def;
  
  uVar3 = (rec->compile_flags_c4 ^ g_compile_flags_c4) & 0x20 ^ rec->compile_flags_c4;
  rec->compile_flags_c4 = uVar3;
  if ((rec->current_function == (c1_symbol *)0x0) && ((uVar3 & 0x20) == 0)) {
    rec->compile_flags_c4 = uVar3 & 0xfffdffff;
  }
  pcVar2 = g_current_scope;
  if (rec->scope_restore_kind == 1) {
    ppcVar1 = &g_current_scope->global_scope;
    g_current_scope->depth = '\0';
    pcVar2->current = *ppcVar1;
    pcVar2->qual_class = (c1_symbol *)0x0;
    pcVar2->access_op = '\x01';
    pcVar2->qualified = '\0';
    pcVar2->reported = '\0';
    pcVar2->keep_aliases = '\0';
  }
  else if (rec->scope_restore_kind == 2) {
    decl_state_unwind_to(g_current_scope,rec->decl_state);
  }
  g_block_depth = rec->block_depth;
  g_il_block_level = rec->il_block_level;
  g_block_number = rec->block_number;
  g_member_function_class = rec->member_function_class;
  g_current_function = rec->current_function;
  g_tmpl_current_template = rec->tmpl_current_template;
  g_tmpl_current_instance = rec->tmpl_current_instance;
  g_tmpl_bound_scope = rec->tmpl_bound_scope;
  g_compile_flags_c4 = rec->compile_flags_c4;
  g_compile_flags_c8 = rec->compile_flags_c8;
  g_compile_flags_cc = rec->compile_flags_cc;
  g_compile_flags_d0 = rec->compile_flags_d0;
  g_prototype_scope_depth = rec->prototype_scope_depth;
  g_access_report_class = rec->access_report_class;
  g_access_report_via_virtual_base = (int)rec->access_report_vbase;
  g_access_report_member = rec->access_report_member;
  g_access_report_base = rec->access_report_base;
  g_access_report_inherit_access = rec->access_report_inherit_access;
  g_access_report_access = rec->access_report_member_access;
  g_paren_depth = rec->paren_depth;
  g_parse_block_record_depth = rec->parse_block_record_depth;
  g_sizeof_depth = rec->sizeof_depth;
  g_qualified_lookup_found_overloads = rec->qualified_lookup_found_overloads;
  g_symbol_scope_level = rec->byte_de316;
  g_list_cell_arena_saved = rec->word_d2cd4;
  g_default_argument_parse_stack = rec->default_argument_parse_stack;
  g_template_depth = rec->word_d2190;
  access_set_special_member_context(rec->special_member_context);
  if (-1 < g_paren_depth) {
    iVar8 = g_paren_depth * 0x24;
    iVar7 = g_paren_depth;
    do {
      iVar4 = iVar7 + -1;
      src_declspecs = (uint *)(rec->paren_declspecs->spec + iVar8);
      pcVar10 = g_paren_level_declspecs[0].spec + iVar8;
      for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(uint *)pcVar10 = *src_declspecs;
        src_declspecs = src_declspecs + 1;
        pcVar10 = pcVar10 + 4;
      }
      iVar8 = iVar8 + -0x24;
      g_pending_access_check[iVar7] = rec->pending_access[iVar7];
      g_paren_level_flags[iVar7] = rec->paren_flags[iVar7];
      g_paren_level_arg_lists[iVar7] = rec->paren_arg_lists[iVar7];
      iVar7 = iVar4;
    } while (-1 < iVar4);
  }
  g_pending_parameter_scope = rec->pending_parameter_scope;
  g_pending_function_word = rec->pending_function_word;
  g_function_parameter_scope = rec->function_parameter_scope;
  g_function_context_word = rec->function_context_word;
  g_class_depth = rec->class_depth;
  iVar7 = rec->class_depth;
  while (iVar7 != -1) {
    pcVar9 = rec->class_def_stack + rec->class_depth;
    dst_class_def = (uint *)(g_class_def_stack + rec->class_depth);
    for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
      *dst_class_def = (uint)pcVar9->cls;
      pcVar9 = (c1_class_def_entry *)&pcVar9->unk04;
      dst_class_def = dst_class_def + 1;
    }
    iVar7 = rec->class_depth + -1;
    rec->class_depth = iVar7;
  }
  g_member_access_op = rec->member_access_op;
  if (g_line_map_cached_row.position == rec->token_position) {
    pcVar5 = &g_line_map_cached_row;
  }
  else {
    pcVar5 = pp_line_map_find_entry(&g_line_map,rec->token_position);
  }
  if (pcVar5->file != (fe_file_record *)0x0) {
    g_token_position = rec->token_position;
  }
  if (((((g_compile_flags_c8 & 0x32000000) == 0) &&
       ((((g_compile_flags_c8 & 0x40000000) == 0 || ((g_compile_flags_cc & 8) != 0)) ||
        ((g_compile_flags_c4 & 0x200) != 0)))) && ((g_compile_flags_cc & 0x10) == 0)) &&
     (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))) {
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if ((g_compile_flags_cc & 1) != 0) {
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

