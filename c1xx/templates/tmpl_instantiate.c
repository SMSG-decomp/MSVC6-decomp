void __cdecl tmpl_instantiate(c1_symbol *tmpl,c1_symbol *instance)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  byte bVar3;
  c1_u16 cVar4;
  c1_class_instance_cell *pcVar5;
  c1_sym_link *pcVar6;
  c1_u8 *pcVar7;
  c1_class_instance_cell **ppcVar8;
  int iVar9;
  int *piVar10;
  c1_sym_list *params;
  c1_arg_list *args;
  c1xx_token_stream *pcVar11;
  byte *instance_token;
  int tmpl_pack;
  c1_class_instance_cell *cell;
  c1_deferred_action *pcVar12;
  uint *puVar13;
  char *pcVar14;
  byte bVar15;
  int iVar16;
  c1xx_warning_state *pcVar17;
  uint *puVar18;
  uint *state_dst;
  bool bVar19;
  c1_parse_state *pcStack_20;
  c1_deferred_action *pcStack_1c;
  c1_deferred_action *pcStack_18;
  int iStack_14;
  void **ctx_vtbl;
  int iStack_c;
  c1_symbol *pcStack_8;
  uint ctx_note;
  
  if ((((tmpl != (c1_symbol *)0x0) && ((tmpl->flags3 & 4) == 0)) && (instance != (c1_symbol *)0x0))
     && ((instance->flags3 & 4) == 0)) {
    iVar9 = (*g_idb->vtbl->idb_note_first_use)(g_idb);
    if (iVar9 == 0) {
      diag_fatal(0x49,".\\template.cpp",0x156b);
    }
    iStack_c = g_token_position;
    pcStack_8 = instance;
    ctx_note = 0x18b0;
    ctx_vtbl = &PTR_tmpl_context_note_104c4c40;
    tmpl_pending_push(&ctx_vtbl);
    piVar10 = symtab_1600_lookup(tmpl);
    params = tmpl_lookup_parameter_list(tmpl);
    args = symtab_15f4_lookup(instance);
    (**(code **)(*piVar10 + 0x14))();
    pcVar11 = arena_alloc(g_arenas + 1,0x38);
    if (pcVar11 == (c1xx_token_stream *)0x0) {
      pcVar11 = (c1xx_token_stream *)0x0;
    }
    else {
      pcVar11->start_position = piVar10[1];
      pcVar11->position = piVar10[2];
      (pcVar11->first).chunk = (c1_token_chunk *)piVar10[3];
      (pcVar11->first).index = piVar10[4];
      (pcVar11->first).arena = piVar10[5];
      (pcVar11->read).chunk = (c1_token_chunk *)piVar10[6];
      (pcVar11->read).index = piVar10[7];
      (pcVar11->read).arena = piVar10[8];
      (pcVar11->write).chunk = (c1_token_chunk *)piVar10[9];
      (pcVar11->write).index = piVar10[10];
      (pcVar11->write).arena = piVar10[0xb];
      pcVar11->arena = piVar10[0xc];
      bVar15 = (pcVar11->flags ^ *(byte *)(piVar10 + 0xd)) & 1 ^ pcVar11->flags;
      pcVar11->flags = bVar15;
      bVar3 = *(byte *)(piVar10 + 0xd);
      pcVar11->vtbl = (c1xx_token_stream_vtbl *)&PTR_token_stream_next_raw_104bc55c;
      pcVar11->flags = (bVar15 ^ bVar3) & 2 ^ bVar15;
    }
    token_source_push((c1_token_reader *)&g_token_position,pcVar11,1,0,(void *)0x0,&g_token_position
                     );
    pcVar11 = g_token_source->stream;
    if ((pcVar11->flags & 2) == 0) {
      pcVar11->flags = pcVar11->flags | 2;
      (*pcVar11->vtbl->append)(pcVar11,g_token_end_of_stream);
    }
    parse_context_push(&pcStack_20);
    bVar19 = 1 < g_block_depth;
    scope_push_instantiation_context(pcStack_20);
    g_access_report_class = (c1_symbol *)0x0;
    g_access_report_via_virtual_base = 0;
    g_access_report_member = 0;
    g_access_report_base = (c1_symbol *)0x0;
    g_access_report_inherit_access = '\0';
    g_access_report_access = '\0';
    access_set_special_member_context('\0');
    if (g_browse_file != (char *)0x0) {
      (*g_il_emitter->vtbl->begin_instantiation)((int)(piVar10 + 1));
      (*g_il_emitter->vtbl->begin_module)();
    }
    g_tmpl_current_instance = instance;
    g_tmpl_current_template = tmpl;
    if ((((instance->detail).cls)->flags3f & 0x80) == 0) {
      g_tmpl_bound_scope = tmpl_bind_arguments(params,args,tmpl,bVar19,'\0',0);
      symtab_1608_insert(instance,g_tmpl_bound_scope->symbols);
    }
    deferred_body_list_push(&g_deferred_member_bodies);
    g_compile_flags_cc = g_compile_flags_cc & 0xffeffffd | 8;
    g_compile_flags_c8 = g_compile_flags_c8 & 0x4ffffeff | 0x40000000;
    g_compile_flags_c4 = g_compile_flags_c4 & 0x7bf5fff8;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xd5;
    if ((((instance->detail).cls)->flags3f & 0x80) != 0) {
      g_compile_flags_cc = g_compile_flags_cc | 0x100000;
    }
    pcVar11 = arena_alloc(g_arenas + 3,0x38);
    if (pcVar11 == (c1xx_token_stream *)0x0) {
      pcVar11 = (c1xx_token_stream *)0x0;
    }
    else {
      pcVar11 = token_stream_init(pcVar11,3,0);
    }
    token_source_push((c1_token_reader *)&g_token_record_position,pcVar11,3,0,(void *)0x0,
                      &g_token_position);
    (*g_token_save_frame->stream->vtbl->append)
              (g_token_save_frame->stream,(int)g_token_template_defn);
    g_yylval_spec_type_sym = instance;
    g_yylval_spec_insert_fn = (void *)0x0;
    g_yylval_spec_type = sym_type_of(instance);
    if (g_token_arena_index == 0) {
      instance_token = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      instance_token = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if (instance_token == (byte *)0x0) {
      instance_token = (byte *)0x0;
    }
    else {
      *instance_token = 0x22;
      puVar13 = &g_yylval;
      puVar18 = (uint *)(instance_token + 8);
      for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar18 = *puVar13;
        puVar13 = puVar13 + 1;
        puVar18 = puVar18 + 1;
      }
    }
    (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)instance_token);
    if (g_token_save_frame == (c1_token_source_frame *)0x0) {
      pcVar11 = (c1xx_token_stream *)0x0;
    }
    else {
      ppcVar1 = &g_token_save_frame->prev;
      pcVar11 = g_token_save_frame->stream;
      g_token_record_position = g_token_save_frame->position;
      pp_Var2 = &g_token_save_frame->on_pop;
      g_token_save_frame = *ppcVar1;
      if (*pp_Var2 != (_func_193 *)0x0) {
        (**pp_Var2)();
      }
    }
    token_source_push((c1_token_reader *)&g_token_position,pcVar11,3,1,(void *)0x0,&g_token_position
                     );
    pcVar11 = g_token_source->stream;
    if ((pcVar11->flags & 2) == 0) {
      pcVar11->flags = pcVar11->flags | 2;
      (*pcVar11->vtbl->append)(pcVar11,g_token_end_of_stream);
    }
    ((instance->detail).cls)->flags3e = ((instance->detail).cls)->flags3e | 4;
    if (g_browse_file != (char *)0x0) {
      (*g_il_emitter->vtbl->end_instantiation)();
    }
    tmpl_pack = (int)((tmpl->detail).cls)->unk38;
    bVar19 = tmpl_pack != g_pack_stack->top->packing;
    if (bVar19) {
      pragma_pack_push(tmpl_pack,0);
    }
    pcVar7 = g_arenas[0].cur;
    if ((((instance->detail).cls)->flags3f & 0x80) == 0) {
      if (g_class_template_instances == (c1_class_instance_cell **)0x0) {
        g_arenas[0].cur = g_arenas[0].cur + 4;
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        if (pcVar7 == (c1_u8 *)0x0) {
          g_class_template_instances = (c1_class_instance_cell **)0x0;
        }
        else {
          pcVar7[0] = '\0';
          pcVar7[1] = '\0';
          pcVar7[2] = '\0';
          pcVar7[3] = '\0';
          g_class_template_instances = (c1_class_instance_cell **)pcVar7;
        }
      }
      ppcVar8 = g_class_template_instances;
      cell = arena_alloc(g_arenas,0xc);
      if (cell == (c1_class_instance_cell *)0x0) {
        cell = (c1_class_instance_cell *)0x0;
      }
      else {
        pcVar5 = *ppcVar8;
        cell->instance = instance;
        cell->bodies = (void *)0x0;
        cell->next = pcVar5;
      }
      *ppcVar8 = cell;
    }
    pcVar12 = g_deferred_actions_head;
    pcStack_1c = (c1_deferred_action *)0x0;
    pcStack_18 = (c1_deferred_action *)0x0;
    iStack_14 = 0;
    if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
      iStack_14 = g_tmpl_deduction_depth;
      pcStack_18 = g_deferred_actions_tail;
      g_deferred_actions_tail = (c1_deferred_action *)0x0;
      g_deferred_actions_head = (c1_deferred_action *)0x0;
      pcStack_1c = pcVar12;
    }
    pcVar6 = params->head;
    if ((pcVar6[-1].position & 0x1f) == 0x16) {
      cVar4 = ((pcVar6->type).alias)->class_index;
    }
    else {
      pcVar14 = tree_find_template_parameter_use((char *)pcVar6[2].next);
      cVar4 = *(c1_u16 *)(pcVar14 + 0x10);
    }
    g_template_depth = (int)(short)cVar4 >> 8;
    iVar9 = g_linkage_stack[g_linkage_depth];
    if (iVar9 == 2) {
      decl_push_linkage_specification(0);
    }
    puVar13 = symtab_160c_lookup(tmpl);
    pcVar17 = (c1xx_warning_state *)g_arenas[2].cur;
    g_arenas[2].cur = g_arenas[2].cur + 0x3f4;
    if (g_arenas[2].end < g_arenas[2].cur) {
      arena_grow(g_arenas + 2);
    }
    if (pcVar17 == (c1xx_warning_state *)0x0) {
      pcVar17 = (c1xx_warning_state *)0x0;
    }
    else {
      *(c1_u8 *)((int)pcVar17 + 0x3ec) = '\0';
      *(c1_u8 *)((int)pcVar17 + 0x3ed) = '\0';
      *(c1_u8 *)((int)pcVar17 + 0x3ee) = '\0';
      *(c1_u8 *)((int)pcVar17 + 0x3ef) = '\0';
      *(c1xx_warning_state **)((int)pcVar17 + 0x3f0) = g_warning_state;
      *(uint *)((int)pcVar17 + 1000) = puVar13[0xfa];
      state_dst = (uint *)pcVar17;
      for (iVar16 = 0xfa; iVar16 != 0; iVar16 = iVar16 + -1) {
        *state_dst = *puVar13;
        puVar13 = puVar13 + 1;
        state_dst = state_dst + 1;
      }
    }
    g_warning_state = pcVar17;
    iVar16 = parse_translation_unit();
    if (iVar16 != 0) {
      instance->flags3 = instance->flags3 | 4;
    }
    if (bVar19) {
      pragma_pack_pop(0,0);
    }
    g_warning_state = g_warning_state->outer;
    if (iVar9 == 2) {
      decl_pop_linkage_specification();
    }
    ((instance->detail).cls)->flags3e = ((instance->detail).cls)->flags3e & 0xfb;
    if ((((instance->detail).cls)->flags3f & 0x80) == 0) {
      tmpl_work_queue_add(instance,(int *)0x0);
    }
    if (pcStack_1c != (c1_deferred_action *)0x0) {
      g_deferred_actions_tail = pcStack_18;
      g_tmpl_deduction_depth = iStack_14;
      g_deferred_actions_head = pcStack_1c;
    }
    if (g_token_source != (c1_token_source_frame *)0x0) {
      ppcVar1 = &g_token_source->prev;
      g_token_position = g_token_source->position;
      pp_Var2 = &g_token_source->on_pop;
      g_token_source = *ppcVar1;
      if (*pp_Var2 != (_func_193 *)0x0) {
        (**pp_Var2)();
      }
    }
    if (g_browse_file != (char *)0x0) {
      (*g_il_emitter->vtbl->end_module)();
    }
    if (g_deferred_member_bodies != (c1_deferred_body_list *)0x0) {
      g_deferred_member_bodies = g_deferred_member_bodies->outer;
    }
    func_parse_state_pop((c1_u8 **)&pcStack_20);
    ctx_vtbl = &PTR_tmpl_context_note_104c4c40;
    tmpl_pending_pop();
  }
  return;
}

