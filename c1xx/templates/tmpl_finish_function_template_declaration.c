void __cdecl tmpl_finish_function_template_declaration(c1_yy_value *head,c1_symbol *fn)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  c1_declarator *pcVar3;
  c1_sym_list *head_00;
  c1_symbol *key;
  c1_declarator *pcVar4;
  c1_decl_record *pcVar5;
  c1_list_cursor local_10;
  c1_list_cursor local_8;
  
  if (fn == (c1_symbol *)0x0) goto LAB_1044fbd2;
  fn->name->flags = fn->name->flags | 0x8000000;
  fn->flags3 = fn->flags3 | 1;
  g_pending_access_check[g_paren_depth] = (c1_symbol *)0x0;
  if (g_tmpl_definition_tail_tokens != (c1xx_token_stream *)0x0) {
    if ((fn->flags2 & 4) == 0) {
      fn->flags2 = fn->flags2 | 4;
    }
    else {
      diag_error(0x3e3,fn);
      fn->flags3 = fn->flags3 | 4;
    }
  }
  if (((fn->kind & 0x1f) == 8) && (g_class_depth < 0)) {
    key = g_scope_vector->entries[(short)fn->scope_index];
    if ((((key->detail).cls)->flags3f & 0x80) != 0) {
      key = tmpl_template_of_instance(key);
    }
    if ((((key->detail).cls)->flags3e & 2) != 0) {
      pcVar4 = tmpl_lookup_parameter_list(key);
      pcVar3 = head->declarator;
      if (pcVar4 != pcVar3) {
        if (pcVar4 == (c1_declarator *)0x0) {
          pcVar5 = (c1_decl_record *)0x0;
        }
        else {
          pcVar5 = pcVar4->decl;
        }
        list_cursor_init(&local_10,pcVar5);
        if (pcVar3 == (c1_declarator *)0x0) {
          pcVar5 = (c1_decl_record *)0x0;
        }
        else {
          pcVar5 = pcVar3->decl;
        }
        list_cursor_init(&local_8,pcVar5);
        while (local_10.current != (int *)0x0) {
          if (local_8.current == (int *)0x0) {
            if (local_10.current != (int *)0x0) goto LAB_1044fb9a;
            break;
          }
          if ((*(int *)local_10.current != *(int *)local_8.current) ||
             (*(int *)((int)local_10.current + 0xc) != *(int *)((int)local_8.current + 0xc)))
          goto LAB_1044fb9a;
          class_member_iter_step(&local_10);
          class_member_iter_step(&local_8);
        }
        if (local_8.current != (int *)0x0) goto LAB_1044fb9a;
      }
      head_00 = head->template_params;
      if (head_00 != (c1_sym_list *)0x0) {
        list_cursor_init_from_head(&local_8,head_00);
        while (local_8.current != (int *)0x0) {
          sym_recycle_record((c1_symbol *)((int)local_8.current + -8));
          class_member_iter_step(&local_8);
        }
        if (head_00->arena == 0) {
          head_00->head = (c1_sym_link *)g_list_cell_free_list;
          g_list_cell_free_list = head_00;
        }
      }
      head->ptr = pcVar4;
    }
  }
LAB_1044fb9a:
  if ((g_compile_flags_cc & 0x100000) == 0) {
    tmpl_record_definition
              (fn,head->template_params,g_tmpl_definition_tokens,g_tmpl_definition_tail_tokens);
  }
  else {
    tmpl_set_parameter_list(head->template_params,fn);
  }
  if ((-1 < g_class_depth) && ((*(byte *)((int)&fn->tail + 9) & 0x20) != 0)) {
    if ((fn->flags21 & 2) != 0) {
      diag_error(0x382,fn);
      fn->flags3 = fn->flags3 | 4;
    }
    if ((fn->flags1 & 0x20) == 0x20) {
      diag_error(0x381,fn);
      fn->flags3 = fn->flags3 | 4;
    }
  }
LAB_1044fbd2:
  g_compile_flags_cc = g_compile_flags_cc & 0xffdfffff;
  g_tmpl_definition_tail_tokens = (c1xx_token_stream *)0x0;
  g_tmpl_definition_tokens = (c1xx_token_stream *)0x0;
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
    g_compile_flags_c8 = g_compile_flags_c8 & 0x7fffffff;
  }
  g_compile_flags_cc = g_compile_flags_cc & 0xffffffdf;
  g_compile_flags_c8 = g_compile_flags_c8 & 0xfdffffff;
  tmpl_close_parameter_scope();
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

