c1_symbol * __thiscall decl_declare_and_check(c1_declarator *d,byte *spec)

{
  c1_keyed_list *pcVar1;
  uint uVar2;
  bool bVar3;
  char cVar4;
  c1_symbol *pcVar5;
  c1xx_hash_scope *pcVar6;
  int iVar7;
  c1_symbol *pcVar8;
  byte bVar9;
  uint uVar10;
  
  pcVar8 = d->sym;
  if (pcVar8 == (c1_symbol *)0x0) {
    pcVar8 = (c1_symbol *)d->qualifier;
  }
  bVar3 = false;
  if (d->qualifier != (c1_overload_set *)0x0) {
    pcVar1 = d->qualifier->list;
    if (pcVar1 == (c1_keyed_list *)0x0) {
      return (c1_symbol *)0x0;
    }
    iVar7 = sym_is_static_data_member(pcVar1->head->sym);
    if (iVar7 == 0) {
      bVar3 = true;
    }
    else if (g_block_depth != '\0') {
      pcVar8 = decl_declare_in_scope('\0',pcVar8,d,(c1xx_decl_specifiers *)spec);
      return pcVar8;
    }
  }
  if ((((g_compile_flags_c8 & 0x20) != 0) && (g_block_depth == '\0')) &&
     (bVar9 = d->spec[0], (bVar9 & 7) == 0)) {
    d->spec[0] = bVar9 & 0xf9 | 1;
    d->spec[0] = bVar9 & 0xd9 | 1;
    *spec = *spec & 0xd9 | 1;
  }
  pcVar5 = decl_declare_in_current_scope(d,(c1xx_decl_specifiers *)spec);
  d->sym = pcVar5;
  if (((bVar3) && (bVar9 = g_current_scope->current->kind, 0xfa < bVar9)) && (bVar9 != 0xfd)) {
    scope_pop_to_kind(g_current_scope,'\x01');
  }
  pcVar5 = d->sym;
  if (pcVar5 == (c1_symbol *)0x0) {
    if (pcVar8 == (c1_symbol *)0x0) {
      pcVar8 = sym_new_from_declarator(d,5);
      diag_error(0xf4,pcVar8);
      return (c1_symbol *)0x0;
    }
    if ((((pcVar8->kind & 0x1f) != 0x12) && (pcVar8->name != (fe_name *)0x0)) &&
       ((pcVar8->name->flags & 0x2000000) != 0)) {
      return (c1_symbol *)0x0;
    }
    diag_error(0xf4,pcVar8);
    return (c1_symbol *)0x0;
  }
  if ((pcVar5->flags3 & 4) != 0) {
    return (c1_symbol *)0x0;
  }
  if ((pcVar5->kind & 0x1f) == 4) {
    return pcVar5;
  }
  if ((((g_compile_flags_cc & 0x24) == 0) && (g_browse_file != (char *)0x0)) &&
     ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
    if ((pcVar5->entity & 0xffffff) == 0) {
      if (0x7ffffffe < g_next_entity_id) {
        diag_fatal_simple(0x37);
      }
      uVar2 = d->sym->entity;
      uVar10 = uVar2 ^ g_next_entity_id;
      g_next_entity_id = g_next_entity_id + 1;
      d->sym->entity = uVar10 & 0xffffff ^ uVar2;
    }
    (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,d->sym);
  }
  pcVar8 = d->sym;
  bVar9 = pcVar8->kind & 0x1f;
  if (((bVar9 == 7) || (bVar9 == 8)) || (bVar9 == 6)) {
    if ((d->flags54 & 4) != 0) {
      if (pcVar8 == (c1_symbol *)0x0) {
        pcVar8 = sym_new_from_declarator(d,5);
      }
      diag_error(0x48,pcVar8);
      return (c1_symbol *)0x0;
    }
    if ((pcVar8->flags4 & 0x10) != 0) {
      if (pcVar8 == (c1_symbol *)0x0) {
        pcVar8 = sym_new_from_declarator(d,5);
      }
      diag_error(0x88,pcVar8);
    }
    decl_check_operator_function(d->sym,0);
    if ((spec[2] & 1) != 0) {
      pcVar8 = d->sym;
      if (pcVar8 == (c1_symbol *)0x0) {
        pcVar8 = sym_new_from_declarator(d,5);
      }
      diag_error(0x1e8,pcVar8);
    }
    goto LAB_10403d6d;
  }
  if ((((g_compile_flags_cc & 4) == 0) && ((g_compile_flags_cc & 0x200000) == 0)) &&
     ((pcVar8->flags22 & 8) == 0)) {
    if ((d->flags54 & 4) == 0) {
      if ((d->spec[0] & 7) == 1) {
        if ((d->spec[1] & 0x10) == 0) {
          pcVar8 = class_check_static_member_definition(pcVar8,1,8,d,spec);
          return pcVar8;
        }
        goto LAB_10403e6f;
      }
    }
    else if ((g_block_depth != '\0') && ((pcVar8->storage & 7) == 1)) {
      pcVar8 = decl_check_extern_block_initializer(pcVar8,8,d,spec);
      return pcVar8;
    }
    pcVar8->flags2 = pcVar8->flags2 | 4;
    if (((((g_pch_use_only != 0) && ((d->sym->kind & 0x20) == 0)) &&
         ((g_compile_flags_cc & 0x100000) == 0)) &&
        (((g_compile_flags_cc & 0x20) == 0 && ((g_compile_flags_c8 & 0x10000000) == 0)))) &&
       (cVar4 = sym_is_deferrable(d->sym), cVar4 != '\0')) {
      sym_defer_emission(d->sym);
    }
  }
LAB_10403e6f:
  if (d->qualifier != (c1_overload_set *)0x0) {
    pcVar8 = d->qualifier->list->head->sym;
    pcVar6 = scope_enclosing_namespace(g_current_scope,'\x01');
    if (pcVar6 != (c1xx_hash_scope *)0x0) {
      ns_check_definition_scope(&pcVar8->kind,(int)pcVar6->ns);
    }
    if ((g_scope_vector->entries[(short)pcVar8->scope_index]->kind & 0x1f) == 4) {
      iVar7 = sym_is_static_data_member(pcVar8);
      if (iVar7 != 0) {
        if (((g_compile_flags_cc & 4) == 0) && ((g_compile_flags_cc & 0x200000) == 0)) {
          pcVar8 = decl_merge_redeclaration(d->sym,d->qualifier,pcVar8);
          return pcVar8;
        }
        return pcVar8;
      }
      if ((g_compile_flags_c4 & 0x200) != 0) {
LAB_10403d6d:
        return d->sym;
      }
      diag_error(0x15e,d->qualifier);
    }
  }
  pcVar8 = d->sym;
  if ((((pcVar8->flags22 & 8) != 0) && (((pcVar8->flags2 & 4) != 0 || ((d->flags54 & 4) != 0)))) &&
     (((g_compile_flags_c4 & 0x20000) == 0 ||
      (((g_current_function->flags22 & 8) == 0 || ((g_current_function->flags21 & 1) == 0)))))) {
    if (pcVar8 == (c1_symbol *)0x0) {
      pcVar8 = sym_new_from_declarator(d,5);
    }
    diag_error(0x1eb,pcVar8,0x179);
  }
  pcVar8 = d->sym;
  bVar9 = pcVar8->storage & 7;
  if (((((bVar9 != 0) && (bVar9 != 7)) && ((*spec & 7) != 1)) &&
      (((d->flags54 & 4) == 0 &&
       (((pcVar8->flags2 & 4) == 0 ||
        (pcVar8 = sym_class_needing_init(pcVar8), pcVar8 == (c1_symbol *)0x0)))))) &&
     ((d->sym->kind & 0x1f) == 10)) {
    iVar7 = sym_has_reference_type(d->sym);
    if ((char)iVar7 == '\0') {
      if (((d->sym->flags5 & 4) != 0) &&
         (bVar9 = (byte)d->sym->type->base->code, (char)bVar9 < '\0')) {
        pcVar8 = decl_check_reference_initialized(bVar9,d);
        return pcVar8;
      }
    }
    else {
      pcVar8 = d->sym;
      if (pcVar8 == (c1_symbol *)0x0) {
        pcVar8 = sym_new_from_declarator(d,5);
      }
      diag_error(0x212,pcVar8);
    }
    if ((d->sym->flags22 & 2) != 0) {
      pcVar8 = decl_based_variable_tail(d->sym,d);
      return pcVar8;
    }
  }
  decl_assign_data_segment_and_check(d);
  g_file_scope_decl_since_body = 1;
  return d->sym;
}

