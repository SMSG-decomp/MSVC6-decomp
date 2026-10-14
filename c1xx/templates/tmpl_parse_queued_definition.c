void __cdecl tmpl_parse_queued_definition(c1_template_header_record *header)

{
  int iVar1;
  bool bVar2;
  c1xx_scope **ppcVar3;
  c1_scope_stack *pcVar4;
  byte bVar5;
  c1xx_warning_state *pcVar6;
  c1xx_warning_state *pcVar7;
  c1_decl_state *pcVar8;
  int iVar9;
  c1_u32 *state_dst;
  c1_tmpl_context_note context_note;
  
  if ((g_compile_flags_c4 & 0x20) != 0) {
    func_definition_end('\x01');
  }
  pcVar4 = g_current_scope;
  bVar2 = false;
  if (g_current_scope->current != g_current_scope->global_scope) {
    pcVar8 = arena_alloc(g_arenas + 8,0x1c);
    if (pcVar8 == (c1_decl_state *)0x0) {
      pcVar8 = (c1_decl_state *)0x0;
    }
    else {
      pcVar8 = decl_state_snapshot(pcVar8,pcVar4,pcVar4->saved,'\x01');
    }
    pcVar4->saved = pcVar8;
    pcVar4 = g_current_scope;
    bVar2 = true;
    ppcVar3 = &g_current_scope->global_scope;
    g_current_scope->depth = '\0';
    pcVar4->current = *ppcVar3;
    pcVar4->qual_class = (c1_symbol *)0x0;
    pcVar4->access_op = '\x01';
    pcVar4->qualified = '\0';
    pcVar4->reported = '\0';
    pcVar4->keep_aliases = '\0';
  }
  g_tmpl_current_template = header->tmpl;
  g_tmpl_current_instance = header->instance;
  g_tmpl_bound_scope = header->bound_scope;
  g_pending_parameter_scope = header->parameter_scope;
  g_pending_function_word = header->function_word;
  if (header->ns != (c1_symbol *)0x0) {
    ns_enter_enclosing_namespaces(g_current_scope,header->ns);
  }
  if (((g_tmpl_current_template != (c1_symbol *)0x0) && (g_tmpl_current_template->scope_index != 0))
     && ((g_scope_vector->entries[(short)g_tmpl_current_template->scope_index]->kind & 0x1f) == 0x19
        )) {
    ns_enter_enclosing_namespaces
              (g_current_scope,g_scope_vector->entries[(short)g_tmpl_current_template->scope_index])
    ;
  }
  if (g_tmpl_bound_scope != (c1xx_block_scope *)0x0) {
    scope_push_child(g_current_scope,(c1xx_scope *)g_tmpl_bound_scope);
    g_compile_flags_c8 = g_compile_flags_c8 | 0x40000000;
    g_compile_flags_cc = g_compile_flags_cc | 1;
  }
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffd;
  g_compile_flags_cc = g_compile_flags_cc | 2;
  if (g_browse_file != (char *)0x0) {
    (*g_il_emitter->vtbl->begin_module)();
  }
  iVar1 = g_linkage_stack[g_linkage_depth];
  if (iVar1 == 2) {
    decl_push_linkage_specification(0);
  }
  pcVar6 = header->warning_state;
  if (pcVar6 == (c1xx_warning_state *)0x0) {
    pcVar6 = symtab_160c_lookup(g_tmpl_current_template);
  }
  pcVar7 = arena_alloc(g_arenas + 2,0x3f4);
  if (pcVar7 == (c1xx_warning_state *)0x0) {
    pcVar7 = (c1xx_warning_state *)0x0;
  }
  else {
    pcVar7->saved = (c1_warning_record *)0x0;
    pcVar7->outer = g_warning_state;
    pcVar7->level = pcVar6->level;
    state_dst = (c1_u32 *)pcVar7;
    for (iVar9 = 0xfa; iVar9 != 0; iVar9 = iVar9 + -1) {
      *state_dst = *(c1_u32 *)pcVar6->state;
      pcVar6 = (c1xx_warning_state *)(pcVar6->state + 4);
      state_dst = state_dst + 1;
    }
  }
  if (g_tmpl_current_template == (c1_symbol *)0x0) {
    context_note.note = 0x18b1;
  }
  else {
    bVar5 = header->member->kind & 0x1f;
    if ((bVar5 == 7) || (context_note.note = 0x18b3, bVar5 == 8)) {
      context_note.note = 0x18b2;
    }
  }
  context_note.position = header->position;
  context_note.sym = header->member;
  context_note.vtbl = (c1_diag_note_vtbl *)&PTR_tmpl_context_note_104c4c40;
  g_warning_state = pcVar7;
  tmpl_pending_push(&context_note);
  parse_translation_unit();
  g_warning_state = g_warning_state->outer;
  if (iVar1 == 2) {
    decl_pop_linkage_specification();
  }
  if (g_browse_file != (char *)0x0) {
    (*g_il_emitter->vtbl->end_module)();
  }
  pcVar4 = g_current_scope;
  ppcVar3 = &g_current_scope->global_scope;
  g_current_scope->depth = '\0';
  pcVar4->current = *ppcVar3;
  pcVar4->qual_class = (c1_symbol *)0x0;
  pcVar4->access_op = '\x01';
  pcVar4->qualified = '\0';
  pcVar4->reported = '\0';
  pcVar4->keep_aliases = '\0';
  if (bVar2) {
    decl_state_restore(g_current_scope,'\x01');
    decl_state_pop(g_current_scope);
  }
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffcff;
  g_compile_flags_c8 = g_compile_flags_c8 & 0xbfffffff;
  g_compile_flags_cc = g_compile_flags_cc & 0xfffffffc;
  parse_external_declaration_end();
  context_note.vtbl = (c1_diag_note_vtbl *)&PTR_tmpl_context_note_104c4c40;
  tmpl_pending_pop();
  return;
}

