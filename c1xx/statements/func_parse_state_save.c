c1_parse_state * __fastcall func_parse_state_save(c1_parse_state *rec)

{
  c1_u8 cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *dst;
  uint *src;
  uint *dst_2;
  uint *dst_3;
  c1_u8 *src_2;
  
  rec->token_position = 0;
  rec->block_depth = g_block_depth;
  rec->il_block_level = g_il_block_level;
  rec->block_number = g_block_number;
  rec->member_function_class = g_member_function_class;
  rec->current_function = g_current_function;
  rec->tmpl_current_template = g_tmpl_current_template;
  rec->tmpl_current_instance = g_tmpl_current_instance;
  rec->tmpl_bound_scope = g_tmpl_bound_scope;
  rec->compile_flags_c4 = g_compile_flags_c4;
  rec->compile_flags_c8 = g_compile_flags_c8;
  rec->compile_flags_cc = g_compile_flags_cc;
  rec->compile_flags_d0 = g_compile_flags_d0;
  rec->prototype_scope_depth = g_prototype_scope_depth;
  rec->access_report_class = g_access_report_class;
  rec->access_report_vbase = (void *)g_access_report_via_virtual_base;
  rec->access_report_member = g_access_report_member;
  rec->access_report_base = g_access_report_base;
  rec->access_report_inherit_access = g_access_report_inherit_access;
  rec->access_report_member_access = g_access_report_access;
  cVar1 = access_get_special_member_context();
  rec->special_member_context = cVar1;
  rec->qualified_lookup_found_overloads = g_qualified_lookup_found_overloads;
  rec->byte_de316 = g_symbol_scope_level;
  rec->scope_restore_kind = 0;
  rec->decl_state = (c1_decl_state *)0x0;
  rec->paren_depth = g_paren_depth;
  rec->word_d2cd4 = g_list_cell_arena_saved;
  src_2 = g_arenas[8].cur;
  g_arenas[8].cur = g_arenas[8].cur + g_paren_depth * 0x24 + 0x24;
  if (g_arenas[8].end < g_arenas[8].cur) {
    arena_grow(g_arenas + 8);
  }
  rec->paren_declspecs = (c1xx_decl_specifiers *)src_2;
  src_2 = g_arenas[8].cur;
  g_arenas[8].cur = g_arenas[8].cur + g_paren_depth * 4 + 4;
  if (g_arenas[8].end < g_arenas[8].cur) {
    arena_grow(g_arenas + 8);
  }
  rec->pending_access = (c1_symbol **)src_2;
  src_2 = g_arenas[8].cur;
  g_arenas[8].cur = g_arenas[8].cur + (g_paren_depth + 4U & 0xfffffffc);
  if (g_arenas[8].end < g_arenas[8].cur) {
    arena_grow(g_arenas + 8);
  }
  rec->paren_flags = src_2;
  src_2 = g_arenas[8].cur;
  g_arenas[8].cur = g_arenas[8].cur + g_paren_depth * 4 + 4;
  if (g_arenas[8].end < g_arenas[8].cur) {
    arena_grow(g_arenas + 8);
  }
  rec->paren_arg_lists = (c1_arg_list **)src_2;
  rec->default_argument_parse_stack = g_default_argument_parse_stack;
  rec->word_d2190 = g_template_depth;
  if (-1 < g_paren_depth) {
    iVar6 = g_paren_depth * 0x24;
    iVar5 = g_paren_depth;
    do {
      iVar2 = iVar5 + -1;
      dst = (uint *)(g_paren_level_declspecs[0].spec + iVar6);
      dst_2 = (uint *)(rec->paren_declspecs->spec + iVar6);
      for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        *dst_2 = *dst;
        dst = dst + 1;
        dst_2 = dst_2 + 1;
      }
      iVar6 = iVar6 + -0x24;
      rec->pending_access[iVar5] = g_pending_access_check[iVar5];
      rec->paren_flags[iVar5] = g_paren_level_flags[iVar5];
      rec->paren_arg_lists[iVar5] = g_paren_level_arg_lists[iVar5];
      iVar5 = iVar2;
    } while (-1 < iVar2);
  }
  rec->pending_parameter_scope = g_pending_parameter_scope;
  rec->pending_function_word = g_pending_function_word;
  rec->function_parameter_scope = g_function_parameter_scope;
  rec->function_context_word = g_function_context_word;
  rec->class_depth = g_class_depth;
  rec->member_access_op = g_member_access_op;
  src_2 = g_arenas[8].cur;
  if ((uint)g_class_depth < 0x80000000) {
    g_arenas[8].cur = g_arenas[8].cur + g_class_depth * 0x20 + 0x20;
    if (g_arenas[8].end < g_arenas[8].cur) {
      arena_grow(g_arenas + 8);
    }
    rec->class_def_stack = (c1_class_def_entry *)src_2;
    if (-1 < g_class_depth) {
      iVar5 = g_class_depth + 1;
      iVar6 = g_class_depth << 5;
      do {
        iVar2 = iVar6 + -0x1e;
        iVar3 = iVar6 + -0x1e;
        iVar6 = iVar6 + -0x20;
        iVar5 = iVar5 + -1;
        src = (uint *)(g_class_def_stack[0].pad1e + iVar2);
        dst_3 = (uint *)(rec->class_def_stack->pad1e + iVar3);
        for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
          *dst_3 = *src;
          src = src + 1;
          dst_3 = dst_3 + 1;
        }
      } while (iVar5 != 0);
    }
  }
  rec->parse_block_record_depth = g_parse_block_record_depth;
  rec->sizeof_depth = g_sizeof_depth;
  return rec;
}

