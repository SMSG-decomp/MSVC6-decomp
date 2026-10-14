void __cdecl
decl_declare_anonymous_union_member(c1_symbol *object,c1_symbol *member,c1xx_decl_specifiers *spec)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_symbol *pcVar4;
  c1_decl_record *pcVar5;
  int *piVar6;
  c1_symbol *pcVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  c1_symbol *pcVar11;
  c1xx_decl_specifiers *pcVar12;
  c1_symbol *pcVar13;
  undefined4 *puVar14;
  c1_symbol **ppcVar15;
  uint in_stack_ffffffd8;
  void *in_stack_ffffffdc;
  uint spec_arg_word3;
  uint spec_arg_word2;
  
  pcVar7 = member;
  pcVar4 = arena_alloc(g_arenas + 5,0x58);
  if (pcVar4 == (c1_symbol *)0x0) {
    member = (c1_symbol *)0x0;
  }
  else {
    *(fe_name **)pcVar4 = member->name;
    (pcVar4->x28).members = (c1_sym_list *)0x0;
    *(undefined1 *)((int)&pcVar4->tail + 4) = 1;
    pcVar4[1].type = (c1_type *)0x3;
    pcVar5 = arena_alloc(g_arenas + 5,0x4c);
    member = pcVar4;
    if (pcVar5 == (c1_decl_record *)0x0) {
      pcVar4->flags4 = '\0';
      pcVar4->flags5 = '\0';
      pcVar4->scope_index = 0;
      (pcVar4->detail).value = g_token_position;
    }
    else {
      pcVar5 = decl_record_init_default
                         (pcVar5,*(void **)pcVar4,(c1_overload_set *)(pcVar4->x28).members);
      *(c1_decl_record **)&pcVar4->flags4 = pcVar5;
      (pcVar4->detail).value = g_token_position;
    }
  }
  if ((((g_block_depth == '\0') || (-1 < g_class_depth)) || ((g_compile_flags_c8 & 0x10000000) != 0)
      ) || (((((g_compile_flags_c8 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
             ((g_compile_flags_c4 & 0x200) == 0)) || (((byte)g_compile_flags_cc & 0x50) != 0)))) {
    iVar10 = 0;
  }
  else {
    iVar10 = 4;
  }
  spec_arg_word3 = 10;
  spec_arg_word2 = 0x1046b23a;
  pcVar4 = sym_take_free_record(10,(void *)0x0,iVar10);
  if (pcVar4 == (c1_symbol *)0x0) {
    pcVar4 = arena_alloc(g_arenas + iVar10,g_symbol_size_table[10] + 3 & 0xfffffffc);
    if (pcVar4 == (c1_symbol *)0x0) {
      pcVar4 = (c1_symbol *)0x0;
    }
    else {
      spec_arg_word3 = 10;
      spec_arg_word2 = 0x1046b273;
      pcVar4 = sym_init_kind(pcVar4,'\n',(void *)0x0,iVar10);
    }
  }
  uVar9 = g_symbol_size_table[pcVar7->kind & 0x1f];
  pcVar11 = pcVar7;
  pcVar13 = pcVar4;
  for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    cVar1 = pcVar11->flags1;
    cVar2 = pcVar11->flags2;
    cVar3 = pcVar11->flags3;
    pcVar13->kind = pcVar11->kind;
    pcVar13->flags1 = cVar1;
    pcVar13->flags2 = cVar2;
    pcVar13->flags3 = cVar3;
    pcVar11 = (c1_symbol *)&pcVar11->flags4;
    pcVar13 = (c1_symbol *)&pcVar13->flags4;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    pcVar13->kind = pcVar11->kind;
    pcVar11 = (c1_symbol *)&pcVar11->flags1;
    pcVar13 = (c1_symbol *)&pcVar13->flags1;
  }
  pcVar4->kind = pcVar4->kind & 0xca | 10;
  pcVar4->next = (c1_symbol *)0x0;
  pcVar4->flags5 = pcVar4->flags5 | 0x10;
  pcVar12 = spec;
  puVar14 = (undefined4 *)&stack0xffffffd8;
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar14 = *(undefined4 *)pcVar12->spec;
    pcVar12 = (c1xx_decl_specifiers *)(pcVar12->spec + 4);
    puVar14 = puVar14 + 1;
  }
  sym_apply_specifier_block
            (pcVar4,in_stack_ffffffd8,in_stack_ffffffdc,(void *)spec_arg_word2,
             (c1_guid *)spec_arg_word3);
  if (g_next_entity_id < 0x7fffffff) {
    uVar9 = pcVar4->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    pcVar4->entity = uVar9 & 0xffffff ^ pcVar4->entity;
    member->name = (fe_name *)pcVar7->type;
    ppcVar15 = &member->next;
    for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
      *ppcVar15 = *(c1_symbol **)spec->spec;
      spec = (c1xx_decl_specifiers *)(spec->spec + 4);
      ppcVar15 = ppcVar15 + 1;
    }
    sym_pair_table_insert(g_block_depth != '\0',pcVar4,object,pcVar7);
    piVar6 = (int *)scope_lookup_for_declaration(g_current_scope->current,(c1_declarator *)member,1)
    ;
    if (piVar6 == (int *)0x0) {
      pcVar7 = (c1_symbol *)0x0;
    }
    else {
      pcVar7 = (c1_symbol *)*piVar6;
    }
    if (pcVar7 == (c1_symbol *)0x0) {
      if ((-1 < g_class_depth) && (pcVar4->name == (g_class_def_stack[g_class_depth].cls)->name)) {
        diag_error(0x276);
        return;
      }
      (*g_current_scope->current->vtbl->insert)();
      pcVar7 = pcVar4;
    }
    if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
      (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,pcVar7);
    }
    return;
  }
  diag_fatal_simple(0x37);
}

