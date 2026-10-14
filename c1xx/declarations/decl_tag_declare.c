c1_symbol * __cdecl
decl_tag_declare(fe_name *name,c1_u16 tag_code,void **insert_fn,char is_definition)

{
  c1_declarator *d;
  c1_decl_record *pcVar1;
  int *piVar2;
  c1_symbol *pcVar3;
  c1xx_hash_scope *scope;
  c1_declarator *d_00;
  int flags;
  
  d = arena_alloc(g_arenas + 5,0x58);
  if (d == (c1_declarator *)0x0) {
    d = (c1_declarator *)0x0;
  }
  else {
    d->name = name;
    d->qualifier = (c1_overload_set *)0x0;
    d->op_token = '\x01';
    d->kind = 0xd;
    pcVar1 = arena_alloc(g_arenas + 5,0x4c);
    if (pcVar1 == (c1_decl_record *)0x0) {
      d->decl = (c1_decl_record *)0x0;
      d->position = g_token_position;
    }
    else {
      pcVar1 = decl_record_init_default(pcVar1,d->name,d->qualifier);
      d->decl = pcVar1;
      d->position = g_token_position;
    }
  }
  decl_tag_declarator_set_kind(d,tag_code,insert_fn,is_definition);
  if (name == (fe_name *)0x0) {
    if (0 < g_paren_depth) {
      if (is_definition == '\0') {
        diag_warning(1,0x74);
      }
      else {
        diag_error(0x1d1);
      }
    }
    if ((g_compile_flags_c8 & 0x10) != 0) {
      diag_error(0x1cf);
    }
    d->name = g_name_unnamed;
    d->flags54 = d->flags54 | 0x20;
    g_name_unnamed->flags = g_name_unnamed->flags | 0x20000;
    pcVar3 = sym_new_from_declarator(d,0xffffffff);
    goto LAB_10434241;
  }
  if ((g_compile_flags_c8 & 0x2000000) == 0) {
    piVar2 = (int *)scope_lookup_for_declaration(g_current_scope->current,d,1);
    if (piVar2 == (int *)0x0) {
LAB_10434205:
      pcVar3 = (c1_symbol *)0x0;
    }
    else {
      pcVar3 = (c1_symbol *)*piVar2;
    }
  }
  else {
    flags = 0;
    d_00 = d;
    scope = scope_enclosing_namespace(g_current_scope,'\0');
    piVar2 = (int *)scope_lookup_for_declaration(scope,d_00,flags);
    if (piVar2 == (int *)0x0) goto LAB_10434205;
    pcVar3 = (c1_symbol *)*piVar2;
  }
  if (pcVar3 == (c1_symbol *)0x0) {
    if (((is_definition != '\0') && (-1 < g_class_depth)) &&
       (name == (g_class_def_stack[g_class_depth].cls)->name)) {
      pcVar3 = d->sym;
      if (pcVar3 == (c1_symbol *)0x0) {
        pcVar3 = sym_new_from_declarator(d,5);
      }
      diag_error(0x244,pcVar3);
      return (c1_symbol *)0x0;
    }
    pcVar3 = sym_new_from_declarator(d,0xffffffff);
    if (((g_compile_flags_c8 & 0x10) != 0) && ((((pcVar3->detail).cls)->flags3e & 1) == 0)) {
      diag_error(0x1ce,pcVar3);
      class_check_member_pointer_representation(pcVar3);
      goto LAB_10434241;
    }
  }
  else if ((pcVar3->flags2 & 0x60) != 0) {
    *insert_fn = (void *)0x0;
  }
  class_check_member_pointer_representation(pcVar3);
LAB_10434241:
  if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
    (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,pcVar3);
    (*g_il_emitter->vtbl->mark_definition)(1,(int)pcVar3->name);
  }
  g_qualified_lookup_found_overloads = 1;
  return pcVar3;
}

