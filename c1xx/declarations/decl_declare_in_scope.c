c1_symbol * __thiscall
decl_declare_in_scope(char pop_scope,c1_symbol *prev,c1_declarator *d,c1xx_decl_specifiers *spec)

{
  uint uVar1;
  char cVar2;
  c1_symbol *pcVar3;
  c1xx_hash_scope *pcVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  
  diag_error(0x28f,d->qualifier->list->head->sym);
  if ((((g_compile_flags_c8 & 0x20) != 0) && (g_block_depth == '\0')) &&
     (bVar6 = d->spec[0], (bVar6 & 7) == 0)) {
    d->spec[0] = bVar6 & 0xf9 | 1;
    d->spec[0] = bVar6 & 0xd9 | 1;
    spec->spec[0] = spec->spec[0] & 0xd9 | 1;
  }
  pcVar3 = decl_declare_in_current_scope(d,spec);
  d->sym = pcVar3;
  if (((pop_scope != '\0') && (bVar6 = g_current_scope->current->kind, 0xfa < bVar6)) &&
     (bVar6 != 0xfd)) {
    scope_pop_to_kind(g_current_scope,'\x01');
  }
  pcVar3 = d->sym;
  if (pcVar3 == (c1_symbol *)0x0) {
    if (prev == (c1_symbol *)0x0) {
      pcVar3 = sym_new_from_declarator(d,5);
      diag_error(0xf4,pcVar3);
      return (c1_symbol *)0x0;
    }
    if ((((prev->kind & 0x1f) != 0x12) && (prev->name != (fe_name *)0x0)) &&
       ((prev->name->flags & 0x2000000) != 0)) {
      return (c1_symbol *)0x0;
    }
    diag_error(0xf4,prev);
    return (c1_symbol *)0x0;
  }
  if ((pcVar3->flags3 & 4) != 0) {
    return (c1_symbol *)0x0;
  }
  if ((pcVar3->kind & 0x1f) == 4) {
    return pcVar3;
  }
  if ((((g_compile_flags_cc & 0x24) == 0) && (g_browse_file != (char *)0x0)) &&
     ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
    if ((pcVar3->entity & 0xffffff) == 0) {
      if (0x7ffffffe < g_next_entity_id) {
        diag_fatal_simple(0x37);
      }
      uVar1 = d->sym->entity;
      uVar7 = uVar1 ^ g_next_entity_id;
      g_next_entity_id = g_next_entity_id + 1;
      d->sym->entity = uVar7 & 0xffffff ^ uVar1;
    }
    (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,d->sym);
  }
  pcVar3 = d->sym;
  bVar6 = pcVar3->kind & 0x1f;
  if (((bVar6 == 7) || (bVar6 == 8)) || (bVar6 == 6)) {
    if ((d->flags54 & 4) != 0) {
      if (pcVar3 == (c1_symbol *)0x0) {
        pcVar3 = sym_new_from_declarator(d,5);
      }
      diag_error(0x48,pcVar3);
      return (c1_symbol *)0x0;
    }
    if ((pcVar3->flags4 & 0x10) != 0) {
      if (pcVar3 == (c1_symbol *)0x0) {
        pcVar3 = sym_new_from_declarator(d,5);
      }
      diag_error(0x88,pcVar3);
    }
    decl_check_operator_function(d->sym,0);
    if ((spec->spec[2] & 1) != 0) {
      pcVar3 = d->sym;
      if (pcVar3 == (c1_symbol *)0x0) {
        pcVar3 = sym_new_from_declarator(d,5);
      }
      diag_error(0x1e8,pcVar3);
    }
    goto LAB_10403d6d;
  }
  if ((((g_compile_flags_cc & 4) == 0) && ((g_compile_flags_cc & 0x200000) == 0)) &&
     ((pcVar3->flags22 & 8) == 0)) {
    if ((d->flags54 & 4) == 0) {
      if ((d->spec[0] & 7) == 1) {
        if ((d->spec[1] & 0x10) == 0) {
          pcVar3 = class_check_static_member_definition(pcVar3,1,8,d,spec->spec);
          return pcVar3;
        }
        goto LAB_10403e6f;
      }
    }
    else if ((g_block_depth != '\0') && ((pcVar3->storage & 7) == 1)) {
      pcVar3 = decl_check_extern_block_initializer(pcVar3,8,d,spec->spec);
      return pcVar3;
    }
    pcVar3->flags2 = pcVar3->flags2 | 4;
    if (((((g_pch_use_only != 0) && ((d->sym->kind & 0x20) == 0)) &&
         ((g_compile_flags_cc & 0x100000) == 0)) &&
        (((g_compile_flags_cc & 0x20) == 0 && ((g_compile_flags_c8 & 0x10000000) == 0)))) &&
       (cVar2 = sym_is_deferrable(d->sym), cVar2 != '\0')) {
      sym_defer_emission(d->sym);
    }
  }
LAB_10403e6f:
  if (d->qualifier != (c1_overload_set *)0x0) {
    pcVar3 = d->qualifier->list->head->sym;
    pcVar4 = scope_enclosing_namespace(g_current_scope,'\x01');
    if (pcVar4 != (c1xx_hash_scope *)0x0) {
      ns_check_definition_scope(&pcVar3->kind,(int)pcVar4->ns);
    }
    if ((g_scope_vector->entries[(short)pcVar3->scope_index]->kind & 0x1f) == 4) {
      iVar5 = sym_is_static_data_member(pcVar3);
      if (iVar5 != 0) {
        if (((g_compile_flags_cc & 4) == 0) && ((g_compile_flags_cc & 0x200000) == 0)) {
          pcVar3 = decl_merge_redeclaration(d->sym,d->qualifier,pcVar3);
          return pcVar3;
        }
        return pcVar3;
      }
      if ((g_compile_flags_c4 & 0x200) != 0) {
LAB_10403d6d:
        return d->sym;
      }
      diag_error(0x15e,d->qualifier);
    }
  }
  pcVar3 = d->sym;
  if ((((pcVar3->flags22 & 8) != 0) && (((pcVar3->flags2 & 4) != 0 || ((d->flags54 & 4) != 0)))) &&
     (((g_compile_flags_c4 & 0x20000) == 0 ||
      (((g_current_function->flags22 & 8) == 0 || ((g_current_function->flags21 & 1) == 0)))))) {
    if (pcVar3 == (c1_symbol *)0x0) {
      pcVar3 = sym_new_from_declarator(d,5);
    }
    diag_error(0x1eb,pcVar3,0x179);
  }
  pcVar3 = d->sym;
  bVar6 = pcVar3->storage & 7;
  if (((((bVar6 != 0) && (bVar6 != 7)) && ((spec->spec[0] & 7) != 1)) &&
      (((d->flags54 & 4) == 0 &&
       (((pcVar3->flags2 & 4) == 0 ||
        (pcVar3 = sym_class_needing_init(pcVar3), pcVar3 == (c1_symbol *)0x0)))))) &&
     ((d->sym->kind & 0x1f) == 10)) {
    iVar5 = sym_has_reference_type(d->sym);
    if ((char)iVar5 == '\0') {
      if (((d->sym->flags5 & 4) != 0) &&
         (bVar6 = (byte)d->sym->type->base->code, (char)bVar6 < '\0')) {
        pcVar3 = decl_check_reference_initialized(bVar6,d);
        return pcVar3;
      }
    }
    else {
      pcVar3 = d->sym;
      if (pcVar3 == (c1_symbol *)0x0) {
        pcVar3 = sym_new_from_declarator(d,5);
      }
      diag_error(0x212,pcVar3);
    }
    if ((d->sym->flags22 & 2) != 0) {
      pcVar3 = decl_based_variable_tail(d->sym,d);
      return pcVar3;
    }
  }
  decl_assign_data_segment_and_check(d);
  g_file_scope_decl_since_body = 1;
  return d->sym;
}

