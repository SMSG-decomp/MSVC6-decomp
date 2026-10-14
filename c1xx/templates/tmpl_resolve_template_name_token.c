void __cdecl
tmpl_resolve_template_name_token(c1_u8 **token,c1_symbol *qualifier,char leading_global)

{
  c1_arena *a;
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 *pcVar3;
  fe_name *pfVar4;
  c1_scope_stack *pcVar5;
  byte bVar6;
  uint uVar7;
  c1_lookup_entry *pcVar8;
  byte *token_00;
  c1_symbol *pcVar9;
  c1_keyed_list *pcVar10;
  c1_symbol *pcVar11;
  void *pvVar12;
  c1_lookup_entry *tag_entry;
  c1_u8 *pcVar13;
  uint uVar14;
  int iVar15;
  uint *puVar16;
  c1_symbol *pcVar17;
  uint *puVar18;
  c1_symbol *tmpl;
  c1_symbol *local_c;
  byte saved_flag;
  
  uVar7 = g_compile_flags_c8 | 0x20000;
  uVar14 = g_compile_flags_c8 >> 0x11;
  local_c = (c1_symbol *)0x0;
  g_compile_flags_c8 = uVar7;
  if (qualifier == (c1_symbol *)0x0) {
    if (leading_global == '\0') {
      pvVar12 = *(void **)(*token + 8);
LAB_10424655:
      pcVar8 = (c1_lookup_entry *)expr_build_member_access_implicit(g_current_scope,pvVar12);
    }
    else {
      pcVar8 = (*g_current_scope->global_scope->vtbl->lookup_tag)
                         (g_current_scope->global_scope,*(void **)(*token + 8));
    }
    if (pcVar8 == (c1_lookup_entry *)0x0) {
LAB_104b636f:
      tmpl = (c1_symbol *)0x0;
    }
    else {
      tmpl = pcVar8->sym;
    }
  }
  else {
    pvVar12 = *(void **)(*token + 8);
    bVar6 = qualifier->kind & 0x1f;
    if (bVar6 == 0x19) {
      tag_entry = (c1_lookup_entry *)(**(code **)(**(int **)qualifier->type + 0x10))(pvVar12);
      if (tag_entry == (c1_lookup_entry *)0x0) goto LAB_104b636f;
      tmpl = tag_entry->sym;
    }
    else {
      if (bVar6 == 0xf) {
        qualifier = g_scope_vector->entries[(short)qualifier->key_ref];
      }
      if ((qualifier->flags2 & 4) == 0) {
        tmpl_instantiate_if_needed(qualifier);
      }
      pcVar10 = class_lookup_member_name(qualifier,pvVar12,0x20);
      if (pcVar10 == (c1_keyed_list *)0x0) {
        pvVar12 = *(void **)(*token + 8);
        goto LAB_10424655;
      }
      tmpl = pcVar10->head->sym;
    }
  }
  pcVar5 = g_current_scope;
  if ((tmpl == (c1_symbol *)0x0) && (cVar1 = g_current_scope->qualified, cVar1 != '\0')) {
    pcVar17 = g_current_scope->qual_class;
    saved_flag = g_current_scope->access_op;
    cVar2 = g_current_scope->reported;
    g_current_scope->reported = '\0';
    pcVar5->qual_class = (c1_symbol *)0x0;
    pcVar5->access_op = '\x01';
    pcVar5->qualified = '\0';
    pcVar13 = expr_build_member_access_implicit(g_current_scope,*(void **)(*token + 8));
    if (pcVar13 == (c1_u8 *)0x0) {
      tmpl = (c1_symbol *)0x0;
    }
    else {
      tmpl = *(c1_symbol **)pcVar13;
    }
    if (cVar1 == '\0') {
      g_current_scope->qual_class = (c1_symbol *)0x0;
      g_current_scope->access_op = '\x01';
      g_current_scope->qualified = '\0';
      g_current_scope->reported = '\0';
    }
    else {
      g_current_scope->qual_class = pcVar17;
      g_current_scope->access_op = saved_flag;
      g_current_scope->qualified = '\x01';
      g_current_scope->reported = cVar2;
    }
  }
  if ((uVar14 & 1) == 0) {
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffdffff;
  }
  if (tmpl == (c1_symbol *)0x0) {
    return;
  }
  if ((tmpl->kind & 0x1f) == 0x12) {
    tmpl = *(c1_symbol **)(*(int *)tmpl->type + 8);
  }
  if ((tmpl->kind & 0x1f) != 4) {
    if ((tmpl->flags2 & 0x20) == 0) {
      return;
    }
    if (tmpl->next == (c1_symbol *)0x0) {
      tmpl = (c1_symbol *)0x0;
    }
    else {
      tmpl = (c1_symbol *)((int)&tmpl->next[-1].tail + 4);
    }
    if ((tmpl->kind & 0x1f) != 4) {
      return;
    }
  }
  if ((((tmpl->detail).cls)->flags3e & 2) == 0) {
    return;
  }
  token_00 = token_next((c1_token_reader *)&g_token_position);
  if (*token_00 == 0x44) {
    pcVar9 = tmpl_parse_arguments(tmpl,(c1_arg_list *)0x0,'\0');
    lex_peek_token((uint *)&g_token_position);
    goto LAB_104246e5;
  }
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token_00);
  if ((((g_tmpl_current_instance == (c1_symbol *)0x0) ||
       (pcVar17 = g_tmpl_current_instance, (g_compile_flags_cc & 4) != 0)) &&
      ((g_current_function == (c1_symbol *)0x0 ||
       (((g_current_function->scope_index == 0 ||
         (pcVar17 = g_scope_vector->entries[(short)g_current_function->scope_index],
         (pcVar17->kind & 0x1f) != 4)) || ((((pcVar17->detail).cls)->flags3e & 1) == 0)))))) &&
     (((qualifier == (c1_symbol *)0x0 || ((qualifier->kind & 0x1f) != 4)) ||
      (pcVar17 = qualifier, (((qualifier->detail).cls)->flags3e & 1) == 0)))) {
    pvVar12 = tmpl_enclosing_class_scope(g_current_scope);
    if (pvVar12 == (void *)0x0) goto LAB_104b64d8;
    pcVar17 = *(c1_symbol **)((int)pvVar12 + 0x14);
    bVar6 = ((pcVar17->detail).cls)->flags3e;
    if ((bVar6 & 1) != 0) goto LAB_104247d1;
    if (((bVar6 & 2) == 0) || ((g_compile_flags_cc & 0x200000) == 0)) goto LAB_104b64d8;
  }
  else {
LAB_104247d1:
    if ((pcVar17 != (c1_symbol *)0x0) &&
       (pcVar11 = tmpl_template_of_instance(pcVar17), pcVar9 = pcVar17, pcVar11 == tmpl))
    goto LAB_104246e5;
LAB_104b64d8:
    pcVar17 = local_c;
  }
  if ((((g_token_class[*token_00] != 0x95) && (((byte)g_compile_flags_c4 & 2) == 0)) &&
      ((g_compile_flags_c8 & 0x10) == 0)) && ((g_compile_flags_c8 & 0x100) == 0)) {
    if (-1 < g_class_depth) {
      return;
    }
    if (g_current_function == (c1_symbol *)0x0) {
      if ((((byte)g_compile_flags_c4 & 1) != 0) && (g_block_depth == '\x01')) {
        return;
      }
    }
    else if ((((byte)g_compile_flags_c4 & 0x20) == 0) && (g_block_depth != '\0')) {
      return;
    }
  }
  if ((((((g_compile_flags_cc & 0x200000) == 0) || (g_paren_depth != 0)) ||
       (qualifier == (c1_symbol *)0x0)) ||
      (((qualifier->kind & 0x1f) != 4 ||
       (pcVar9 = tmpl, (((qualifier->detail).cls)->flags3e & 2) == 0)))) &&
     ((pcVar17 == (c1_symbol *)0x0 || (pcVar9 = pcVar17, pcVar17->name != *(fe_name **)(*token + 8))
      ))) {
    if ((g_compile_flags_cc & 4) == 0) {
      diag_error(0x3bb,tmpl);
      return;
    }
    uVar7 = g_compile_flags_c8 >> 0x11;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffdffff;
    diag_error(0x3bb,tmpl);
    if ((uVar7 & 1) == 0) {
      return;
    }
    g_compile_flags_c8 = g_compile_flags_c8 | 0x20000;
    return;
  }
LAB_104246e5:
  iVar15 = g_token_arena_index;
  if (pcVar9 != (c1_symbol *)0x0) {
    pcVar13 = g_arenas[g_token_arena_index].cur;
    pcVar3 = g_arenas[g_token_arena_index].end;
    a = g_arenas + g_token_arena_index;
    a->cur = pcVar13 + 0xc;
    if (pcVar3 < pcVar13 + 0xc) {
      arena_grow(a);
    }
    if (pcVar13 == (c1_u8 *)0x0) {
      g_yylval = 0;
    }
    else {
      pfVar4 = pcVar9->name;
      pcVar13[4] = '\0';
      pcVar13[5] = '\0';
      pcVar13[6] = '\0';
      pcVar13[7] = '\0';
      *(fe_name **)pcVar13 = pfVar4;
      *(c1_symbol **)(pcVar13 + 8) = pcVar9;
      g_yylval = (uint)pcVar13;
    }
    pcVar13 = a->cur;
    pcVar3 = g_arenas[iVar15].end;
    a->cur = pcVar13 + 0x30;
    if (pcVar3 < pcVar13 + 0x30) {
      arena_grow(a);
    }
    if (pcVar13 != (c1_u8 *)0x0) {
      *pcVar13 = 0xe4;
      puVar16 = &g_yylval;
      puVar18 = (uint *)(pcVar13 + 8);
      for (iVar15 = 10; iVar15 != 0; iVar15 = iVar15 + -1) {
        *puVar18 = *puVar16;
        puVar16 = puVar16 + 1;
        puVar18 = puVar18 + 1;
      }
      *token = pcVar13;
      return;
    }
    *token = (c1_u8 *)0x0;
  }
  return;
}

