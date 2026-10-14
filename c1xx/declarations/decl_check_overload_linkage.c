c1_symbol * __thiscall decl_check_overload_linkage(c1_declarator *d,c1_symbol *sym)

{
  c1_function_params *params;
  c1_symbol *sym_00;
  char cVar1;
  byte bVar2;
  c1_symbol *pcVar3;
  int index;
  int iVar4;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar5;
  c1_symbol *value;
  uint uVar6;
  c1_u32 *pcVar7;
  
  pcVar3 = d->sym;
  if (pcVar3 == (c1_symbol *)0x0) {
    pcVar3 = sym_new_from_declarator(d,5);
  }
  pcVar3 = (c1_symbol *)ovl_find_function_with_type(sym,d->type,1,0,pcVar3,d,1);
  if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
    g_deferred_actions_tail = (c1_deferred_action *)0x0;
    g_deferred_actions_head = (c1_deferred_action *)0x0;
  }
  if (pcVar3 != (c1_symbol *)0x0) {
    if (((((pcVar3->flags3 & 4) == 0) && ((d->flags54 & 0x40) == 0)) &&
        (cVar1 = decl_check_redeclaration(d,pcVar3), cVar1 == '\0')) &&
       (((bVar2 = pcVar3->kind & 0x1f, bVar2 != 7 && (bVar2 != 8)) ||
        ((*(byte *)((int)&pcVar3->tail + 9) & 0x80) == 0)))) {
      decl_merge_attributes(d,pcVar3);
    }
    return pcVar3;
  }
  pcVar3 = sym_new_from_declarator(d,0xffffffff);
  d->sym = pcVar3;
  if (((d->name->flags & 0x40000000) != 0) && (d->owner == (c1_symbol *)0x0)) {
    diag_error(0x2db,pcVar3);
  }
  if ((d->flags54 & 2) != 0) {
    pcVar3 = sym_find_c_linkage_function(sym);
    if (pcVar3 == (c1_symbol *)0x0) {
      index = intrinsic_lookup_by_name(d->name);
      if ((index != -1) && (iVar4 = intrinsic_is_enabled(index), (char)iVar4 != '\0')) {
        intrinsic_mark_function(d->sym,index);
      }
    }
    else {
      diag_error(0x2dd,d->sym);
    }
  }
  params = *(c1_function_params **)(((uint)d->type & -(uint)((d->type->code & 0x80) != 0)) + 8);
  if (params->default_count != '\0') {
    decl_check_missing_default_parameter(params,d->sym);
  }
  ns_using_declare_target(&sym,d->sym);
  if ((1 < g_block_depth) && (((byte)g_compile_flags_cc & 0x40) == 0)) {
    result = (*g_current_scope->global_scope->vtbl->lookup)(g_current_scope->global_scope,d->name,1)
    ;
    if ((result == (c1_lookup_result *)0x0) ||
       (pcVar5 = lookup_check_ambiguous_symbol(result,'\x01'), pcVar5 == (c1_lookup_entry *)0x0)) {
      pcVar3 = (c1_symbol *)0x0;
    }
    else {
      pcVar3 = pcVar5->sym;
    }
    if ((pcVar3 != (c1_symbol *)0x0) &&
       ((((((bVar2 = pcVar3->kind & 0x1f, bVar2 == 0x10 || (bVar2 == 7)) || (bVar2 == 6)) ||
          (((bVar2 == 0x11 || (bVar2 == 8)) || (bVar2 == 0x1b)))) ||
         ((bVar2 == 0x1a &&
          (((bVar2 = **(byte **)pcVar3->type & 0x1f, bVar2 == 0x10 || (bVar2 == 7)) ||
           ((bVar2 == 6 || (((bVar2 == 0x11 || (bVar2 == 8)) || (bVar2 == 0x1b)))))))))) &&
        (pcVar3 = (c1_symbol *)
                  ovl_find_function_with_type(pcVar3,d->type,1,0,d->sym,(c1_declarator *)0x0,0),
        pcVar3 != (c1_symbol *)0x0)))) {
      uVar6 = d->sym->entity;
      d->sym->entity = (pcVar3->entity ^ uVar6) & 0xffffff ^ uVar6;
      d->sym->flags2 = d->sym->flags2 | 8;
      pcVar3->flags2 = pcVar3->flags2 & 0xf7;
      if ((pcVar3->flags23 & 1) != 0) {
        value = sym_segment_record(pcVar3);
        sym_00 = d->sym;
        if (value == (c1_symbol *)0x0) {
          sym_00->flags23 = sym_00->flags23 & 0xfe;
          sym_mark_referenced(pcVar3);
          return d->sym;
        }
        sym_set_segment(sym_00,value);
      }
      sym_mark_referenced(pcVar3);
      return d->sym;
    }
  }
  pcVar7 = &d->sym->entity;
  if ((*pcVar7 & 0xffffff) == 0) {
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar6 = *pcVar7 ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    *pcVar7 = uVar6 & 0xffffff ^ *pcVar7;
  }
  return d->sym;
}

