void __cdecl enum_declare(fe_name *name,c1_type *enum_type,c1_u32 value_lo,int value_hi)

{
  c1_decl_record *pcVar1;
  int *piVar2;
  c1_symbol *pcVar3;
  uint uVar4;
  c1_lookup_entry *pcVar5;
  c1_declarator *d;
  int level;
  
  d = (c1_declarator *)g_arenas[5].cur;
  if (enum_type != (c1_type *)0x0) {
    if ((name->flags & 0x2000000) != 0) {
      pcVar5 = lookup_name_in_context(g_current_scope,name,0x20);
      if (pcVar5 == (c1_lookup_entry *)0x0) {
        pcVar3 = (c1_symbol *)0x0;
      }
      else {
        pcVar3 = pcVar5->sym;
      }
      diag_error(0x3a2,pcVar3,g_current_enum);
      return;
    }
    g_arenas[5].cur = g_arenas[5].cur + 0x58;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (d == (c1_declarator *)0x0) {
      d = (c1_declarator *)0x0;
    }
    else {
      d->name = name;
      *(c1_u8 *)((int)d + 0x28) = '\0';
      *(c1_u8 *)((int)d + 0x29) = '\0';
      *(c1_u8 *)((int)d + 0x2a) = '\0';
      *(c1_u8 *)((int)d + 0x2b) = '\0';
      *(c1_u8 *)((int)d + 0x30) = '\x01';
      *(c1_u8 *)((int)d + 0x4c) = '\t';
      *(c1_u8 *)((int)d + 0x4d) = '\0';
      *(c1_u8 *)((int)d + 0x4e) = '\0';
      *(c1_u8 *)((int)d + 0x4f) = '\0';
      pcVar1 = arena_alloc(g_arenas + 5,0x4c);
      if (pcVar1 == (c1_decl_record *)0x0) {
        *(c1_u8 *)((int)d + 4) = '\0';
        *(c1_u8 *)((int)d + 5) = '\0';
        *(c1_u8 *)((int)d + 6) = '\0';
        *(c1_u8 *)((int)d + 7) = '\0';
        *(int *)((int)d + 0x24) = g_token_position;
      }
      else {
        pcVar1 = decl_record_init_default(pcVar1,d->name,*(c1_overload_set **)((int)d + 0x28));
        *(c1_decl_record **)((int)d + 4) = pcVar1;
        *(int *)((int)d + 0x24) = g_token_position;
      }
    }
    d->type = enum_type;
    if ((((g_compile_flags_c4 & 0x20000) == 0) && (g_pch_precomp_types == 0)) &&
       ((g_current_enum->flags3 & 1) == 0)) {
      d->flags54 = d->flags54 | 0x10;
    }
    piVar2 = (int *)scope_lookup_for_declaration(g_current_scope->current,d,1);
    if (piVar2 == (int *)0x0) {
      pcVar3 = (c1_symbol *)0x0;
    }
    else {
      pcVar3 = (c1_symbol *)*piVar2;
    }
    if (pcVar3 == (c1_symbol *)0x0) {
      if ((-1 < g_class_depth) && (d->name == (g_class_def_stack[g_class_depth].cls)->name)) {
        enum_declare_enumerator();
        return;
      }
      pcVar3 = sym_new_from_declarator(d,0xffffffff);
      (*g_current_scope->current->vtbl->insert)(pcVar3);
    }
    if ((g_current_enum->x28).enumerators != (c1_symtab *)0x0) {
      symtab_insert((g_current_enum->x28).enumerators,name,pcVar3);
      if ((pcVar3->entity & 0xffffff) == 0) {
        if (0x7ffffffe < g_next_entity_id) {
          diag_fatal_simple(0x37);
        }
        uVar4 = pcVar3->entity ^ g_next_entity_id;
        g_next_entity_id = g_next_entity_id + 1;
        pcVar3->entity = uVar4 & 0xffffff ^ pcVar3->entity;
      }
      if ((((value_hi < 1) && ((value_hi < 0 || (value_lo < 0x80000000)))) && (-2 < value_hi)) &&
         ((-1 < value_hi || (0x7fffffff < value_lo)))) {
        uVar4 = 4;
      }
      else {
        uVar4 = 8;
      }
      if ((4 < uVar4) && (value_hi != 0)) {
        if (g_ms_extensions == '\0') {
          level = 1;
        }
        else {
          level = 3;
        }
        diag_warning(level,0x155,pcVar3);
      }
      pcVar3->x28 = (c1_symbol_x28)value_lo;
      g_enum_value._0_4_ = value_lo;
      g_enum_value._4_4_ = value_hi;
      if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
        (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,pcVar3);
      }
    }
  }
  return;
}

