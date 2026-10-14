void __cdecl tmpl_finish_class_template_declaration(c1_yy_value *head,c1xx_decl_specifiers *spec)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  c1_type *pcVar3;
  c1_symbol *tmpl;
  c1_class_record *pcVar4;
  c1_class_record *pcVar5;
  c1xx_token_stream *value;
  c1_symbol *pcVar6;
  int *piVar7;
  c1xx_hash_scope *pcVar8;
  int iVar9;
  uint uVar10;
  c1xx_warning_state *pcVar11;
  c1_u8 *pcVar12;
  bool bVar13;
  
  if (spec == (c1xx_decl_specifiers *)0x0) goto LAB_1044ffd3;
  pcVar3 = spec->type;
  if ((pcVar3->code & 0x100) != 0) {
    diag_error(0x3bf,(pcVar3->extra).cls);
    pcVar12 = &((pcVar3->extra).cls)->flags3;
    *pcVar12 = *pcVar12 | 4;
    goto LAB_1044ffd3;
  }
  if ((pcVar3->code & 0x200) == 0) goto LAB_1044ffd3;
  tmpl = (pcVar3->extra).cls;
  if (head->words[0] == 0) {
    diag_error(0x3e0,tmpl);
    tmpl->flags3 = tmpl->flags3 | 4;
  }
  else {
    tmpl->name->flags = tmpl->name->flags | 0x4000000;
    if ((((tmpl->detail).cls)->flags3f & 0x80) != 0) {
      diag_error(0x3dc);
      tmpl->flags3 = tmpl->flags3 | 4;
    }
    if ((g_compile_flags_c8 & 0x80000000) == 0) {
      if ((((tmpl->detail).cls)->flags3e & 8) == 0) {
        tmpl_check_parameter_lists_match(head->words[0],tmpl);
        if ((head->mods).based != (c1_arg_list *)0x0) {
          tmpl_merge_default_arguments((head->mods).based,tmpl);
        }
      }
    }
    else {
      tmpl_check_parameter_lists_match(head->words[0],tmpl);
      pcVar12 = g_arenas[0].cur;
      if ((g_tmpl_warning_state_snapshot == (int *)0x0) ||
         (g_tmpl_warning_state_snapshot[0xfa] != g_warning_state->level)) {
LAB_10450050:
        piVar7 = (int *)g_arenas[0].cur;
        g_arenas[0].cur = g_arenas[0].cur + 0x3ec;
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        pcVar11 = g_warning_state;
        if (pcVar12 == (c1_u8 *)0x0) {
          g_tmpl_warning_state_snapshot = (int *)0x0;
        }
        else {
          *(int *)(pcVar12 + 1000) = g_warning_state->level;
          for (iVar9 = 0xfa; g_tmpl_warning_state_snapshot = piVar7, iVar9 != 0; iVar9 = iVar9 + -1)
          {
            *(undefined4 *)pcVar12 = *(undefined4 *)pcVar11->state;
            pcVar11 = (c1xx_warning_state *)(pcVar11->state + 4);
            pcVar12 = pcVar12 + 4;
          }
        }
      }
      else {
        iVar9 = 0xfa;
        bVar13 = true;
        piVar7 = g_tmpl_warning_state_snapshot;
        pcVar11 = g_warning_state;
        do {
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          bVar13 = *piVar7 == *(int *)pcVar11->state;
          piVar7 = piVar7 + 1;
          pcVar11 = (c1xx_warning_state *)(pcVar11->state + 4);
        } while (bVar13);
        if (!bVar13) goto LAB_10450050;
      }
      tmpl_set_warning_state(tmpl,g_tmpl_warning_state_snapshot);
      ((tmpl->detail).cls)->unk38 = (c1_u16)g_pack_stack->top->packing;
      if ((head->mods).based != (c1_arg_list *)0x0) {
        tmpl_merge_default_arguments((head->mods).based,tmpl);
      }
      value = (c1xx_token_stream *)0x0;
      if (g_token_save_frame != (c1_token_source_frame *)0x0) {
        ppcVar1 = &g_token_save_frame->prev;
        value = g_token_save_frame->stream;
        g_token_record_position = g_token_save_frame->position;
        pp_Var2 = &g_token_save_frame->on_pop;
        g_token_save_frame = *ppcVar1;
        if (*pp_Var2 != (_func_193 *)0x0) {
          (**pp_Var2)();
        }
      }
      tmpl_check_class_redefinition(value,(int)tmpl);
      g_compile_flags_c8 = g_compile_flags_c8 & 0x7fffffff;
      if (((tmpl->flags3 & 4) == 0) &&
         (pcVar6 = tmpl_instantiate_generic_instance_untracked(tmpl), pcVar6 != (c1_symbol *)0x0)) {
        pcVar4 = (pcVar6->detail).cls;
        pcVar5 = (tmpl->detail).cls;
        pcVar5->member_count = pcVar4->member_count;
        pcVar5->sorted_members = pcVar4->sorted_members;
      }
      tmpl->flags2 = tmpl->flags2 | 4;
      ((tmpl->detail).cls)->flags3e = ((tmpl->detail).cls)->flags3e | 8;
    }
  }
  if (((tmpl != (c1_symbol *)0x0) && (tmpl->scope_index != 0)) &&
     (pcVar8 = scope_enclosing_namespace(g_current_scope,'\x01'), pcVar8 != (c1xx_hash_scope *)0x0))
  {
    ns_check_definition_scope(&tmpl->kind,(int)pcVar8->ns);
  }
LAB_1044ffd3:
  uVar10 = g_compile_flags_c8;
  if ((g_compile_flags_c8 & 0x80000000) != 0) {
    if (g_token_save_frame != (c1_token_source_frame *)0x0) {
      ppcVar1 = &g_token_save_frame->prev;
      g_token_record_position = g_token_save_frame->position;
      pp_Var2 = &g_token_save_frame->on_pop;
      g_token_save_frame = *ppcVar1;
      if (*pp_Var2 != (_func_193 *)0x0) {
        (**pp_Var2)();
      }
    }
    uVar10 = g_compile_flags_c8 & 0x7fffffff;
  }
  if (((uVar10 & 0x2000000) == 0) && (0 < g_template_depth)) {
    g_template_depth = g_template_depth + -1;
  }
  g_compile_flags_c8 = uVar10 & 0xfdffffff;
  if (((uVar10 & 0x30000000) == 0) &&
     (((((uVar10 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
       ((g_compile_flags_c4 & 0x200) != 0)) &&
      ((((byte)g_compile_flags_cc & 0x10) == 0 &&
       (((uVar10 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))))))) {
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if (((byte)g_compile_flags_cc & 1) != 0) {
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

