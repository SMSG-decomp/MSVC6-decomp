c1_symbol * __cdecl type_require_complete(c1_symbol *sym)

{
  c1_u16 *pcVar1;
  c1_type *pcVar2;
  bool bVar3;
  c1xx_scope **ppcVar4;
  c1_scope_stack *pcVar5;
  c1_u8 *rec;
  c1_symbol *sym_00;
  byte bVar6;
  c1_decl_state *pcVar7;
  c1xx_hash_scope *pcVar8;
  c1_symbol *pcVar9;
  
  sym_00 = sym;
  bVar6 = sym->kind & 0x1f;
  if ((bVar6 == 7) || (bVar6 == 8)) {
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfeffffff | 0x40000300;
    g_declarator_paren_base = 1;
    pcVar1 = &sym->scope_index;
    bVar3 = false;
    sym._0_1_ = '\0';
    if (*pcVar1 != 0) {
      pcVar9 = g_scope_vector->entries[(short)*pcVar1];
      bVar6 = pcVar9->kind;
      while ((bVar6 & 0x1f) != 0x19) {
        pcVar9 = g_scope_vector->entries[(short)pcVar9->scope_index];
        if (pcVar9 == (c1_symbol *)0x0) goto LAB_1041a32a;
        bVar6 = pcVar9->kind;
      }
      pcVar8 = scope_enclosing_namespace(g_current_scope,'\x01');
      if ((pcVar8 != (c1xx_hash_scope *)0x0) && (pcVar8->ns != pcVar9)) {
        for (pcVar9 = g_scope_vector->entries[(short)pcVar9->scope_index];
            (pcVar9 != (c1_symbol *)0x0 && (pcVar9 != pcVar8->ns));
            pcVar9 = g_scope_vector->entries[(short)pcVar9->scope_index]) {
        }
        bVar3 = true;
        sym._0_1_ = '\x01';
      }
    }
LAB_1041a32a:
    rec = g_arenas[8].cur;
    pcVar5 = g_current_scope;
    g_arenas[8].cur = g_arenas[8].cur + 0x1c;
    if (g_arenas[8].end < g_arenas[8].cur) {
      arena_grow(g_arenas + 8);
    }
    if (rec == (c1_u8 *)0x0) {
      pcVar7 = (c1_decl_state *)0x0;
    }
    else {
      pcVar7 = decl_state_snapshot((c1_decl_state *)rec,pcVar5,pcVar5->saved,(char)sym);
    }
    pcVar5->saved = pcVar7;
    pcVar5 = g_current_scope;
    if (bVar3) {
      ppcVar4 = &g_current_scope->global_scope;
      g_current_scope->depth = '\0';
      pcVar5->current = *ppcVar4;
      pcVar5->qual_class = (c1_symbol *)0x0;
      pcVar5->access_op = '\x01';
      pcVar5->qualified = '\0';
      pcVar5->reported = '\0';
      pcVar5->keep_aliases = '\0';
    }
    if (sym_00->scope_index != 0) {
      g_member_function_class = g_scope_vector->entries[(short)sym_00->scope_index];
      scope_enter_symbol_scope(g_member_function_class);
      scope_stack_promote_class_scopes(g_current_scope);
    }
    sym_00->flags2 = sym_00->flags2 & 0xf7 | 4;
    decl_check_operator_function(sym_00,1);
    bVar6 = *(byte *)((int)&sym_00->tail + 9);
    sym_00->flags4 = sym_00->flags4 & 0xef | 0x80;
    if ((bVar6 & 1) != 0) {
      pcVar2 = sym_00->type->base;
      if ((pcVar2->code & 0x200) == 0) {
        pcVar9 = (c1_symbol *)0x0;
      }
      else {
        pcVar9 = (pcVar2->extra).cls;
      }
      if (((pcVar9->flags2 & 4) == 0) &&
         (tmpl_instantiate_if_needed(pcVar9), (pcVar9->flags2 & 4) == 0)) {
        diag_error(0x1b,pcVar9);
      }
      g_return_object_pointer_type = type_this_pointer(pcVar9,0,0);
      param_list_add_compiler_formal_front_or_back
                (0,&g_pending_parameter_scope,PTR_104d1648,g_return_object_pointer_type);
    }
    if ((sym_00->flags1 & 4) != 0) {
      if (((sym_00->flags1 & 0x10) == 0x10) &&
         ((((g_scope_vector->entries[(short)sym_00->scope_index]->detail).cls)->layout_flags3b &
          0x10) != 0)) {
        param_list_add_compiler_formal_front_or_back
                  (1,&g_pending_parameter_scope,PTR_104d162c,g_type_unsigned_int);
      }
      if ((*(byte *)((int)&sym_00->tail + 8) & 1) != 0) {
        param_list_add_compiler_formal_front_or_back
                  (0,&g_pending_parameter_scope,g_name_this,
                   (c1_type *)
                   **(undefined4 **)
                     (((uint)sym_00->type & -(uint)((sym_00->type->code & 0x80) != 0)) + 8));
      }
      bVar6 = sym_00->flags1;
      if ((((bVar6 & 0x10) == 0x10) || ((bVar6 & 0x20) == 0x20)) || ((bVar6 & 0x40) != 0)) {
        g_compile_flags_c4 = g_compile_flags_c4 | 0x1000000;
      }
      else {
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfeffffff;
      }
    }
    if (g_code_seg_name != (void *)0x0) {
      sym_set_segment_checked(sym_00,g_code_seg_name);
    }
    g_current_function = func_body_begin(sym_00);
    g_function_parameter_scope = g_pending_parameter_scope;
    g_function_context_word = g_pending_function_word;
    g_declarator_paren_base = g_declarator_paren_base + -1;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
  }
  return sym_00;
}

