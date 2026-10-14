char __fastcall tmpl_specialize_function(c1_tmpl_deduction *deduction)

{
  c1xx_token_cursor *cursor;
  c1_u16 cVar1;
  c1_symbol *pcVar2;
  c1_arg_list *pcVar3;
  c1_symbol *pcVar4;
  c1_deferred_action *pcVar5;
  char cVar6;
  void *pvVar7;
  byte *token_record;
  int iVar8;
  c1xx_token_stream *pcVar9;
  uint *src;
  c1_deferred_action *pcVar10;
  uint *dst;
  c1_parse_state *local_8;
  void *local_4;
  
  cVar6 = tmpl_check_deduced_arguments((uint *)deduction);
  if (cVar6 != '\0') {
    parse_context_push(&local_8);
    scope_push_instantiation_context(local_8);
    pvVar7 = tmpl_definition_table_lookup(deduction->tmpl);
    cVar1 = deduction->tmpl->scope_index;
    local_4 = pvVar7;
    if (cVar1 != 0) {
      pcVar2 = g_scope_vector->entries[(short)cVar1];
      if ((pcVar2->kind & 0x1f) == 0x19) {
        ns_enter_enclosing_namespaces(g_current_scope,pcVar2);
      }
      else {
        tmpl_push_member_class_context(pcVar2);
        g_class_def_stack[g_class_depth].flags =
             (deduction->tmpl->flags2 ^ g_class_def_stack[g_class_depth].flags) & 3 ^
             g_class_def_stack[g_class_depth].flags;
        if ((((pcVar2->detail).cls)->flags3e & 1) != 0) {
          g_tmpl_current_instance = pcVar2;
        }
        local_8->token_position = g_token_position;
      }
    }
    g_tmpl_bound_scope =
         tmpl_bind_arguments(deduction->tparams,deduction->args,deduction->tmpl,'\0','\0',0);
    scope_push_child(g_current_scope,(c1xx_scope *)g_tmpl_bound_scope);
    pcVar9 = (c1xx_token_stream *)g_arenas[4].cur;
    g_arenas[4].cur = g_arenas[4].cur + 0x38;
    if (g_arenas[4].end < g_arenas[4].cur) {
      arena_grow(g_arenas + 4);
    }
    iVar8 = g_token_position;
    if (pcVar9 == (c1xx_token_stream *)0x0) {
      pcVar9 = (c1xx_token_stream *)0x0;
    }
    else {
      cursor = (c1xx_token_cursor *)((int)pcVar9 + 0xc);
      *(int *)((int)pcVar9 + 4) = g_token_position;
      *(int *)((int)pcVar9 + 8) = iVar8;
      token_buffer_init(cursor,4);
      *(c1_u8 *)((int)pcVar9 + 0x30) = '\x04';
      *(c1_u8 *)((int)pcVar9 + 0x31) = '\0';
      *(c1_u8 *)((int)pcVar9 + 0x32) = '\0';
      *(c1_u8 *)((int)pcVar9 + 0x33) = '\0';
      *(undefined ***)pcVar9 = &PTR_token_stream_next_raw_104bc55c;
      *(c1_token_chunk **)((int)pcVar9 + 0x18) = cursor->chunk;
      *(undefined4 *)((int)pcVar9 + 0x1c) = *(undefined4 *)((int)pcVar9 + 0x10);
      *(undefined4 *)((int)pcVar9 + 0x20) = *(undefined4 *)((int)pcVar9 + 0x14);
      *(c1_token_chunk **)((int)pcVar9 + 0x24) = cursor->chunk;
      *(undefined4 *)((int)pcVar9 + 0x28) = *(undefined4 *)((int)pcVar9 + 0x10);
      *(undefined4 *)((int)pcVar9 + 0x2c) = *(undefined4 *)((int)pcVar9 + 0x14);
      *(byte *)((int)pcVar9 + 0x34) = *(byte *)((int)pcVar9 + 0x34) | 1;
    }
    (*pcVar9->vtbl->append)(pcVar9,(int)g_token_template_decl);
    g_yylval = (uint)pvVar7;
    if (g_token_arena_index == 0) {
      token_record = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      token_record = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (token_record == (byte *)0x0) {
      token_record = (byte *)0x0;
    }
    else {
      *token_record = 0xf3;
      src = &g_yylval;
      dst = (uint *)(token_record + 8);
      for (iVar8 = 10; pvVar7 = local_4, iVar8 != 0; iVar8 = iVar8 + -1) {
        *dst = *src;
        src = src + 1;
        dst = dst + 1;
      }
    }
    (*pcVar9->vtbl->append)(pcVar9,(int)token_record);
    token_list_clear_saved_state((int *)((int)pvVar7 + 0xc));
    (*pcVar9->vtbl->append)(pcVar9,(int)g_token_end_parse);
    token_source_push((c1_token_reader *)&g_token_position,pcVar9,4,1,(void *)0x0,&g_token_position)
    ;
    pcVar9 = g_token_source->stream;
    if ((pcVar9->flags & 2) == 0) {
      pcVar9->flags = pcVar9->flags | 2;
      (*pcVar9->vtbl->append)(pcVar9,g_token_end_of_stream);
    }
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffc;
    g_compile_flags_cc = g_compile_flags_cc | 0x40;
    g_compile_flags_c8 = g_compile_flags_c8 | 0x20000;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfd;
    decl_push_linkage_specification(0);
    iVar8 = parse_translation_unit();
    if (iVar8 == 0) {
      deduction->specialization = g_last_declared_symbol;
    }
    decl_pop_linkage_specification();
    pcVar10 = (c1_deferred_action *)g_arenas[5].cur;
    pcVar2 = deduction->specialization;
    if ((pcVar2 != (c1_symbol *)0x0) && ((pcVar2->flags3 & 4) == 0)) {
      deduction->pending_parameter_scope = g_pending_parameter_scope;
      deduction->pending_function_word = g_pending_function_word;
      symtab_1608_insert(pcVar2,g_tmpl_bound_scope->symbols);
      func_parse_state_pop((c1_u8 **)&local_8);
      return '\x01';
    }
    g_arenas[5].cur = g_arenas[5].cur + 0x14;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (pcVar10 == (c1_deferred_action *)0x0) {
      pcVar10 = (c1_deferred_action *)0x0;
    }
    else {
      pcVar3 = deduction->args;
      pcVar2 = deduction->specialization;
      pcVar4 = deduction->tmpl;
      *(c1_u8 *)((int)pcVar10 + 8) = '\0';
      *(c1_u8 *)((int)pcVar10 + 9) = '\0';
      *(c1_u8 *)((int)pcVar10 + 10) = '\0';
      *(c1_u8 *)((int)pcVar10 + 0xb) = '\0';
      *(c1_symbol **)((int)pcVar10 + 4) = pcVar4;
      *(c1_symbol **)((int)pcVar10 + 0xc) = pcVar2;
      *(c1_arg_list **)((int)pcVar10 + 0x10) = pcVar3;
      pcVar10->vtbl = &PTR_tmpl_deferred_report_c2893_104ceea4;
    }
    pcVar5 = pcVar10;
    if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
      g_deferred_actions_tail->next = pcVar10;
      pcVar5 = g_deferred_actions_head;
    }
    g_deferred_actions_head = pcVar5;
    g_deferred_actions_tail = pcVar10;
    deduction->flags = deduction->flags | 4;
    func_parse_state_pop((c1_u8 **)&local_8);
  }
  return '\0';
}

