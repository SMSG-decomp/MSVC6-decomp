c1_symbol * __cdecl class_begin_definition(c1_symbol *cls,c1_type *type)

{
  c1_u8 *pcVar1;
  c1_u32 class_ni;
  c1_class_instance_cell *pcVar2;
  uchar *puVar3;
  c1_scope_stack *stack;
  c1_class_instance_cell **ppcVar4;
  ushort uVar5;
  c1_line_map_row *pcVar6;
  int iVar7;
  c1_decl_state *pcVar8;
  c1xx_hash_scope *pcVar9;
  c1_class_instance_cell *pcVar10;
  byte bVar11;
  c1_symbol *pcVar12;
  uint uVar13;
  
  if (g_minimal_rebuild != '\0') {
    mre_mark_class_untracked(g_minimal_rebuild_tracker,cls);
  }
  if (g_pragma_mintypeinfo != '\0') {
    pcVar1 = &((cls->detail).cls)->flags3f;
    *pcVar1 = *pcVar1 | 8;
  }
  if ((g_token_source->stream->flags & 1) != 0) {
    pcVar6 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
    class_ni = ((cls->detail).cls)->gm_name_index;
    iVar7 = (*g_idb->vtbl->idb_class_begin)
                      (g_idb,CONCAT22((short)(class_ni >> 0x10),
                                      (short)pcVar6->line - (short)pcVar6->position) +
                             g_token_position,class_ni);
    if (iVar7 == 0) {
      diag_fatal(0x49,".\\esu.c",0x158);
    }
  }
  if ((g_browse_file != (char *)0x0) &&
     (((g_block_depth == '\0' || (g_opt_FR_browse != 0)) && ((cls->flags3 & 1) == 0)))) {
    (*g_il_emitter->vtbl->begin_block)();
    iVar7 = (*g_il_emitter->vtbl->mark_definition)(0,(int)cls->name);
    if (iVar7 == 0) {
      (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,cls);
    }
    (*g_il_emitter->vtbl->set_owner)((int)cls);
  }
  pcVar1 = g_arenas[0].cur;
  uVar13 = 0;
  if (-1 < g_class_depth) {
    pcVar12 = g_scope_vector->entries[(short)cls->scope_index];
    uVar13 = (g_class_def_stack[g_class_depth].flags & 0x10) >> 4;
    while (((((pcVar12->detail).cls)->flags3e & 1) == 0 ||
           ((((pcVar12->detail).cls)->flags3f & 0x80) != 0))) {
      pcVar12 = g_scope_vector->entries[(short)pcVar12->scope_index];
      if ((pcVar12 == (c1_symbol *)0x0) || ((pcVar12->kind & 0x1f) != 4)) goto LAB_104347a7;
    }
    if (g_class_template_instances == (c1_class_instance_cell **)0x0) {
      g_arenas[0].cur = g_arenas[0].cur + 4;
      if (g_arenas[0].end < g_arenas[0].cur) {
        arena_grow(g_arenas);
      }
      if (pcVar1 == (c1_u8 *)0x0) {
        g_class_template_instances = (c1_class_instance_cell **)0x0;
      }
      else {
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        g_class_template_instances = (c1_class_instance_cell **)pcVar1;
      }
    }
    ppcVar4 = g_class_template_instances;
    pcVar10 = arena_alloc(g_arenas,0xc);
    if (pcVar10 == (c1_class_instance_cell *)0x0) {
      pcVar10 = (c1_class_instance_cell *)0x0;
    }
    else {
      pcVar2 = *ppcVar4;
      pcVar10->instance = cls;
      pcVar10->bodies = (void *)0x0;
      pcVar10->next = pcVar2;
    }
    *ppcVar4 = pcVar10;
  }
LAB_104347a7:
  iVar7 = g_class_depth + 1;
  g_class_depth = iVar7;
  if (iVar7 == 0x10) {
    diag_fatal(0x2e,cls->type);
  }
  if ((uVar13 == 0) && (cls->name != g_name_unnamed)) {
    bVar11 = g_class_def_stack[iVar7].flags & 0xef;
  }
  else {
    bVar11 = g_class_def_stack[iVar7].flags | 0x10;
  }
  g_class_def_stack[iVar7].flags = bVar11;
  bVar11 = cls->flags5;
  if ((type->code & 0x20f) != 0x201) {
    bVar11 = ~bVar11;
  }
  g_class_def_stack[iVar7].flags =
       (bVar11 & 0x20 | 0x10) >> 4 | g_class_def_stack[iVar7].flags & 0xfd;
  g_class_def_stack[iVar7].unk10 = 0;
  ((cls->detail).cls)->layout_flags3b = ((cls->detail).cls)->layout_flags3b & 0xef;
  ((cls->detail).cls)->layout_flags3b = ((cls->detail).cls)->layout_flags3b & 0xbf;
  pcVar1 = g_arenas[8].cur;
  stack = g_current_scope;
  g_arenas[8].cur = g_arenas[8].cur + 0x1c;
  if (g_arenas[8].end < g_arenas[8].cur) {
    arena_grow(g_arenas + 8);
  }
  if (pcVar1 == (c1_u8 *)0x0) {
    pcVar8 = (c1_decl_state *)0x0;
  }
  else {
    pcVar8 = decl_state_snapshot((c1_decl_state *)pcVar1,stack,stack->saved,'\0');
  }
  stack->saved = pcVar8;
  if (g_paren_depth == 0) {
    if (cls->scope_index != 0) {
      pcVar9 = scope_enclosing_namespace(g_current_scope,'\x01');
      if (pcVar9 != (c1xx_hash_scope *)0x0) {
        ns_check_definition_scope(&cls->kind,(int)pcVar9->ns);
      }
      scope_enter_symbol_scope(g_scope_vector->entries[(short)cls->scope_index]);
    }
    lookup_overload_member(g_current_scope,cls,0xff);
  }
  g_class_def_stack[g_class_depth].flags = g_class_def_stack[g_class_depth].flags & 0xfb;
  ((cls->detail).cls)->layout_flags3c = ((cls->detail).cls)->layout_flags3c | 1;
  iVar7 = g_class_depth;
  uVar5 = type->code & 0x20f;
  if ((uVar5 == 0x201) || (uVar5 == 0x202)) {
    g_class_def_stack[g_class_depth].flags = g_class_def_stack[g_class_depth].flags | 8;
  }
  else {
    g_class_def_stack[g_class_depth].flags = g_class_def_stack[g_class_depth].flags & 0xf7;
  }
  g_class_def_stack[iVar7].cls = cls;
  g_class_def_stack[iVar7].unk04 = 0;
  g_class_def_stack[iVar7].offset = 0;
  g_class_def_stack[iVar7].bit_offset = '\0';
  g_class_def_stack[iVar7].flags = g_class_def_stack[iVar7].flags & 0xdf;
  g_class_def_stack[iVar7].bitfield_type = 0;
  g_class_def_stack[iVar7].type = type;
  g_class_def_stack[iVar7].alignment = 1;
  if (g_scope_pool_left < 0xc) {
    pool_reserve((c1xx_pool *)&g_scope_pool,0xc);
    iVar7 = g_class_depth;
  }
  puVar3 = g_scope_pool;
  g_scope_pool_left = g_scope_pool_left - 0xc;
  if (g_scope_pool == (uchar *)0x0) {
    g_scope_pool = g_scope_pool + 0xc;
    ((g_class_def_stack[iVar7].cls)->x28).members = (c1_sym_list *)0x0;
    return cls;
  }
  g_scope_pool = g_scope_pool + 0xc;
  puVar3[0] = '\0';
  puVar3[1] = '\0';
  puVar3[2] = '\0';
  puVar3[3] = '\0';
  puVar3[4] = '\0';
  puVar3[5] = '\0';
  puVar3[6] = '\0';
  puVar3[7] = '\0';
  puVar3[8] = '\0';
  puVar3[9] = '\0';
  puVar3[10] = '\0';
  puVar3[0xb] = '\0';
  ((g_class_def_stack[g_class_depth].cls)->x28).members = (c1_sym_list *)puVar3;
  return cls;
}

