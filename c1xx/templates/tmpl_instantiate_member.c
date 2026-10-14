void __cdecl
tmpl_instantiate_member
          (c1_symbol *tmpl,c1_symbol *instance,c1_symbol *tmpl_member,int *inst_args,
          c1_symbol *member)

{
  c1_scope_stack *pcVar1;
  c1xx_block_scope *pcVar2;
  c1_sym_list *head;
  void *pvVar3;
  void *pvVar4;
  c1_symbol *pcVar5;
  c1_sym_list *pcVar6;
  c1xx_block_scope *bound_scope;
  int *piVar7;
  c1_u8 *sub_tok;
  c1_u8 *sub_tok_2;
  c1_u8 *sub_tok_3;
  c1xx_token_stream *pcVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  c1_u8 *local_14;
  c1_list_cursor local_10;
  c1_list_cursor local_8;
  
  parse_context_push(&local_14);
  head = tmpl_lookup_parameter_list(tmpl_member);
  pvVar3 = tmpl_definition_table_lookup(tmpl_member);
  pvVar4 = symtab_1600_lookup(tmpl_member);
  g_tmpl_current_template = tmpl;
  g_tmpl_current_instance = instance;
  pcVar5 = tmpl_template_of_instance(instance);
  pcVar6 = tmpl_lookup_parameter_list(pcVar5);
  if (head == pcVar6) {
LAB_104436f2:
    pcVar6 = symtab_1608_lookup(instance);
    if (pcVar6 != (c1_sym_list *)0x0) {
      bound_scope = arena_alloc(g_arenas + 2,0x18);
      if (bound_scope == (c1xx_block_scope *)0x0) {
        g_tmpl_bound_scope = (c1xx_block_scope *)0x0;
      }
      else {
        scope_construct((c1xx_scope *)bound_scope,0xfa,(c1xx_scope *)0x0);
        bound_scope->symbols = pcVar6;
        bound_scope->vtbl = (c1xx_block_scope_vtbl *)&PTR_block_scope_has_entries_104bcac0;
        g_tmpl_bound_scope = bound_scope;
      }
      goto LAB_10443738;
    }
  }
  else {
    list_cursor_init_from_head(&local_8,head);
    list_cursor_init_from_head(&local_10,pcVar6);
    while (local_8.current != (void *)0x0) {
      if (local_10.current == (void *)0x0) {
        if (local_8.current != (void *)0x0) goto LAB_104b87d4;
        break;
      }
      iVar9 = tmpl_parameters_equal((int)local_8.current + -8,(int)local_10.current + -8);
      if ((char)iVar9 == '\0') goto LAB_104b87d4;
      class_member_iter_step(&local_8);
      class_member_iter_step(&local_10);
    }
    if (local_10.current == (void *)0x0) goto LAB_104436f2;
  }
LAB_104b87d4:
  g_tmpl_bound_scope = tmpl_bind_arguments(head,(c1_arg_list *)inst_args,pcVar5,'\0','\0',0);
LAB_10443738:
  if (g_token_stream_queues[2].top == (c1_token_source_frame *)0x0) {
    pcVar8 = arena_alloc(g_arenas,0x38);
    if (pcVar8 == (c1xx_token_stream *)0x0) {
      pcVar8 = (c1xx_token_stream *)0x0;
    }
    else {
      pcVar8 = token_stream_init(pcVar8,0,0);
    }
    token_source_push(g_token_stream_queues + 2,pcVar8,0,0,(void *)0x0,&g_token_position);
  }
  pcVar8 = (g_token_stream_queues[2].top)->stream;
  piVar7 = arena_alloc(g_arenas + 2,8);
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    *piVar7 = g_token_arena_index;
    piVar7[1] = (int)g_token_arena_stack;
  }
  g_token_arena_index = 2;
  g_token_arena_stack = piVar7;
  g_yylval = (uint)arena_alloc(g_arenas + 2,0x24);
  iVar9 = g_token_position;
  pcVar2 = g_tmpl_bound_scope;
  pcVar5 = g_tmpl_current_template;
  if ((undefined4 *)g_yylval == (undefined4 *)0x0) {
    g_yylval = 0;
  }
  else {
    *(c1_symbol **)(g_yylval + 0xc) = g_tmpl_current_instance;
    *(c1_symbol **)(g_yylval + 8) = pcVar5;
    *(undefined4 *)g_yylval = 0;
    *(undefined4 *)(g_yylval + 4) = 0;
    *(c1_symbol **)(g_yylval + 0x10) = member;
    *(c1xx_block_scope **)(g_yylval + 0x14) = pcVar2;
    *(undefined4 *)(g_yylval + 0x18) = 0;
    *(int *)(g_yylval + 0x1c) = iVar9;
    *(undefined4 *)(g_yylval + 0x20) = 0;
  }
  sub_tok = arena_or_pool_alloc(0x30,g_token_arena_index);
  if (sub_tok == (c1_u8 *)0x0) {
    sub_tok = (c1_u8 *)0x0;
  }
  else {
    *sub_tok = 0xca;
    puVar10 = &g_yylval;
    puVar11 = (uint *)(sub_tok + 8);
    for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
  }
  (*pcVar8->vtbl->append)(pcVar8,(int)sub_tok);
  g_yylval = (uint)pvVar3;
  if (g_token_arena_index == 0) {
    sub_tok_2 = pool_alloc_raw(&g_pool_default,0x30);
  }
  else {
    sub_tok_2 = arena_alloc(g_arenas + g_token_arena_index,0x30);
  }
  if (sub_tok_2 == (c1_u8 *)0x0) {
    sub_tok_2 = (c1_u8 *)0x0;
  }
  else {
    *sub_tok_2 = 0xf3;
    puVar10 = &g_yylval;
    puVar11 = (uint *)(sub_tok_2 + 8);
    for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
  }
  (*pcVar8->vtbl->append)(pcVar8,(int)sub_tok_2);
  token_list_clear_saved_state((int *)((int)pvVar3 + 0xc));
  if (pvVar4 == (void *)0x0) {
    (*pcVar8->vtbl->append)(pcVar8,(int)g_token_semicolon);
  }
  else {
    g_yylval = (uint)pvVar4;
    if (g_token_arena_index == 0) {
      sub_tok_3 = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      sub_tok_3 = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (sub_tok_3 == (c1_u8 *)0x0) {
      sub_tok_3 = (c1_u8 *)0x0;
    }
    else {
      *sub_tok_3 = 0xf3;
      puVar10 = &g_yylval;
      puVar11 = (uint *)(sub_tok_3 + 8);
      for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar11 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar11 = puVar11 + 1;
      }
    }
    (*pcVar8->vtbl->append)(pcVar8,(int)sub_tok_3);
    token_list_clear_saved_state((int *)((int)pvVar4 + 0xc));
  }
  (*pcVar8->vtbl->append)(pcVar8,(int)g_token_end_parse);
  pcVar1 = g_current_scope;
  g_token_arena_index = *g_token_arena_stack;
  g_token_arena_stack = (int *)g_token_arena_stack[1];
  g_current_scope->current = g_current_scope->global_scope;
  pcVar1->depth = '\0';
  pcVar1->qual_class = (c1_symbol *)0x0;
  pcVar1->access_op = '\x01';
  pcVar1->qualified = '\0';
  pcVar1->reported = '\0';
  pcVar1->keep_aliases = '\0';
  func_parse_state_pop(&local_14);
  return;
}

