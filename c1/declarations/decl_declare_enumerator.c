void __cdecl decl_declare_enumerator(void *name,c1_type *type,longlong value)

{
  longlong lVar1;
  c1_type_declarator *pcVar2;
  c1_scope_lookup *pcVar3;
  uint uVar4;
  c1_scope_lookup *cell;
  c1_declaration *decl;
  c1_symbol *sym;
  int level;
  
  decl = (c1_declaration *)g_arenas[3].cur;
  lVar1 = CONCAT44(g_enum_last_value_high,g_enum_last_value);
  if (type != (c1_type *)0x0) {
    g_arenas[3].cur = g_arenas[3].cur + 0x30;
    if (g_arenas[3].end < g_arenas[3].cur) {
      arena_grow(g_arenas + 3);
    }
    if (decl == (c1_declaration *)0x0) {
      decl = (c1_declaration *)0x0;
    }
    else {
      decl->name = name;
      *(uchar *)((int)decl + 0x24) = '\t';
      *(uchar *)((int)decl + 0x25) = '\0';
      *(uchar *)((int)decl + 0x26) = '\0';
      *(uchar *)((int)decl + 0x27) = '\0';
      pcVar2 = arena_alloc(g_arenas + 3,0x38);
      if (pcVar2 == (c1_type_declarator *)0x0) {
        *(uchar *)((int)decl + 4) = '\0';
        *(uchar *)((int)decl + 5) = '\0';
        *(uchar *)((int)decl + 6) = '\0';
        *(uchar *)((int)decl + 7) = '\0';
        *(int *)((int)decl + 0x18) = g_token_position;
      }
      else {
        pcVar2 = decl_new_declarator(pcVar2,decl->name);
        *(c1_type_declarator **)((int)decl + 4) = pcVar2;
        *(int *)((int)decl + 0x18) = g_token_position;
      }
    }
    decl->type = type;
    if ((((g_compile_flags_c4 & 0x20000) == 0) && (g_pch_precomp_types == '\0')) &&
       ((g_current_enum_tag->flags1 & 0x40) == 0)) {
      decl->flags2c = decl->flags2c | 0x10;
    }
    pcVar3 = (*g_current_scope->current->vtbl->lookup)(g_current_scope->current,(int)decl->name);
    if (((pcVar3 == (c1_scope_lookup *)0x0) ||
        (sym = decl_check_redefinition(decl,pcVar3->sym), sym == (c1_symbol *)0x0)) ||
       (cell = arena_alloc(g_arenas + 3,8), cell == (c1_scope_lookup *)0x0)) {
      sym = (c1_symbol *)0x0;
    }
    else {
      cell->sym = sym;
      cell->scope = (c1_scope_object *)0x0;
    }
    if (sym == (c1_symbol *)0x0) {
      sym = sym_new_from_declarator(decl,-1);
      (*g_current_scope->current->vtbl->insert)(g_current_scope->current,sym);
    }
    else {
      diag_error(0x56,sym);
    }
    lVar1 = CONCAT44(g_enum_last_value_high,g_enum_last_value);
    if (g_current_enum_tag->members != (fe_symtab *)0x0) {
      symtab_insert(g_current_enum_tag->members,name,sym);
      if ((sym->entity & 0xffffff) == 0) {
        if (0x7ffffffe < g_next_entity_id) {
          diag_fatal_simple(0x37);
        }
        uVar4 = sym->entity ^ g_next_entity_id;
        g_next_entity_id = g_next_entity_id + 1;
        sym->entity = uVar4 & 0xffffff ^ sym->entity;
      }
      if ((value < 0x80000000) && (-0x100000001 < value)) {
        if ((value < 0) && ((uint)value < 0x80000000)) {
          decl_warn_enum_value_out_of_range((uint)value,value._4_4_,sym);
          return;
        }
        uVar4 = 4;
      }
      else {
        uVar4 = 8;
      }
      if ((4 < uVar4) && (value._4_4_ != 0)) {
        if (g_ms_extensions == '\0') {
          level = 1;
        }
        else {
          level = 3;
        }
        diag_warning(level,0x155,sym);
      }
      (sym->x28).value = (uint)value;
      g_enum_last_value = (uint)value;
      g_enum_last_value_high = value._4_4_;
      lVar1 = value;
      if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
        (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,sym);
        lVar1 = CONCAT44(g_enum_last_value_high,g_enum_last_value);
      }
    }
  }
  g_enum_last_value_high = (int)((ulonglong)lVar1 >> 0x20);
  g_enum_last_value = (uint)lVar1;
  return;
}

