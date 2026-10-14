c1_symbol * __thiscall
decl_check_auto_variable(c1_u8 *spec,c1_declarator *d,int kind3,c1_symbol *cls,char is_member)

{
  uint *puVar1;
  fe_name *name;
  c1_u32 cVar2;
  c1_class_record *pcVar3;
  byte bVar4;
  c1_u16 cVar5;
  int *piVar6;
  c1xx_scope *pcVar7;
  c1_overload_set *pcVar8;
  c1xx_hash_scope *scope;
  c1_symbol *pcVar9;
  c1_type *pcVar10;
  c1_lookup_result *result;
  void **result_cell;
  c1_lookup_entry *pcVar11;
  uint uVar12;
  void *pvVar13;
  char cVar14;
  c1_declarator *d_00;
  int iVar15;
  
  if (((3 < (*spec & 7)) && ((*spec & 7) < 7)) &&
     ((((d->type->code & 0x200) != 0 &&
       ((((((d->type->extra).cls)->detail).cls)->layout_flags3c & 1) == 0)) ||
      ((d->flags54 & 4) != 0)))) {
    pcVar9 = sym_ensure_declarator_symbol(d);
    diag_error(0x1e9,pcVar9);
  }
  if ((d->spec[2] & 2) != 0) {
    if ((((d->kind == kind3) || (d->kind == 2)) && ((*spec & 7) != 0)) && ((*spec & 7) < 4)) {
      uVar12 = type_classify_class_form(d->type,(int *)&cls);
      if (((uVar12 & 3) != 0) && ((((cls->detail).cls)->layout_flags3c & 1) == 0)) {
        pcVar9 = d->sym;
        if (pcVar9 == (c1_symbol *)0x0) {
          pcVar9 = sym_new_from_declarator(d,5);
        }
        diag_error_once_per_symbol(0x1e3,pcVar9);
      }
    }
    else {
      pcVar9 = d->sym;
      if (pcVar9 == (c1_symbol *)0x0) {
        pcVar9 = sym_new_from_declarator(d,5);
      }
      diag_error(0x1e0,pcVar9);
      d->spec[2] = d->spec[2] & 0xfd;
    }
    uVar12 = decl_dll_linkage_kind(spec);
    if ((char)uVar12 != '\0') {
      pcVar9 = sym_ensure_declarator_symbol(d);
      diag_error(0x1ec,pcVar9);
    }
  }
  if (((d->spec[3] & 1) != 0) &&
     (((d->kind != kind3 && (d->kind != 2)) || (((*spec & 7) == 0 || (3 < (*spec & 7))))))) {
    pcVar9 = d->sym;
    if (pcVar9 == (c1_symbol *)0x0) {
      pcVar9 = sym_new_from_declarator(d,5);
    }
    diag_error(0x1df,pcVar9);
    spec[3] = spec[3] & 0xfe;
  }
  if (((d->spec[3] & 0x10) != 0) && (d->kind != 7)) {
    pcVar9 = decl_check_declspec_applicability(d->kind,spec,d,kind3,is_member);
    return pcVar9;
  }
  if ((d->spec[2] & 0x40) != 0) {
    if ((d->kind == kind3) && ((d->flags54 & 4) != 0)) {
      bVar4 = *spec & 7;
      if (((bVar4 == 1) || (bVar4 == 2)) || ((bVar4 == 3 && ((*spec & 0x20) != 0)))) {
        d->spec[1] = d->spec[1] | 0x80;
        goto LAB_10404146;
      }
    }
    pcVar9 = d->sym;
    if (pcVar9 == (c1_symbol *)0x0) {
      pcVar9 = sym_new_from_declarator(d,5);
    }
    diag_error(0x1f0,pcVar9);
    bVar4 = *spec;
    d->spec[2] = d->spec[2] & 0xbf;
    *spec = bVar4 & 0xbf;
  }
LAB_10404146:
  if ((d->spec[3] & 0x80) != 0) {
    if ((d->kind == 2) && ((*spec & 7) != 3)) {
      if ((d->type->code & 0x8f) == 0x83) {
        do {
          pcVar10 = type_base(d->type);
          d->type = pcVar10;
        } while ((pcVar10->code & 0x8f) == 0x83);
        d->flags54 = d->flags54 & 0x7f;
        d->flags55 = d->flags55 & 0xfe;
      }
    }
    else {
      pcVar9 = d->sym;
      if (pcVar9 == (c1_symbol *)0x0) {
        pcVar9 = sym_new_from_declarator(d,5);
      }
      diag_error(0x30b,pcVar9);
      d->spec[3] = d->spec[3] & 0x7f;
    }
  }
  if ((((d->spec[0x14] & 1) != 0) && (d->kind != 7)) && (d->kind != 8)) {
    pcVar9 = d->sym;
    if (pcVar9 == (c1_symbol *)0x0) {
      pcVar9 = sym_new_from_declarator(d,5);
    }
    if ((pcVar9->flags3 & 4) == 0) {
      diag_error(0x1f1,pcVar9);
      pcVar9->flags3 = pcVar9->flags3 | 4;
    }
  }
  if (((d->spec[0x14] & 2) != 0) && (pcVar9 = d->sym, (pcVar9->kind & 0x1f) != 4)) {
    if (pcVar9 == (c1_symbol *)0x0) {
      pcVar9 = sym_new_from_declarator(d,5);
    }
    diag_error_once_per_symbol(0x1f2,pcVar9);
  }
  if (((d->flags56 & 1) != 0) && ((d->decl->flags & 4) != 0)) {
    pcVar9 = decl_check_conversion_syntax_2(spec,d,is_member);
    return pcVar9;
  }
  if ((d->flags54 & 0x40) != 0) {
    cVar2 = d->kind;
    if ((cVar2 == 2) || (cVar2 == 1)) {
      cVar14 = '\x01';
    }
    else {
      cVar14 = '\0';
    }
    if ((((is_member != cVar14) && (cVar2 != 7)) && (cVar2 != 8)) && (cVar2 != 0xc))
    goto LAB_10404280;
  }
  if (d->qualifier != (c1_overload_set *)0x0) {
    pcVar8 = (c1_overload_set *)decl_resolve_function_in_overload_set(d);
    d->qualifier = pcVar8;
    if (pcVar8 == (c1_overload_set *)0x0) {
      return (c1_symbol *)0x0;
    }
    pcVar9 = pcVar8->list->head->sym;
    if ((d->kind == 7) || (d->kind == 8)) {
      decl_check_redeclaration(d,pcVar9);
      return pcVar9;
    }
    if (((pcVar9->flags4 & 0x40) == 0) || ((pcVar9->kind & 0x1f) != 3)) {
      if ((g_compile_flags_c4 & 0x200) != 0) {
        decl_check_redeclaration(d,pcVar9);
        return pcVar9;
      }
      if ((pcVar9->scope_index != 0) &&
         (pcVar9 = g_scope_vector->entries[(short)pcVar9->scope_index],
         (pcVar9->kind & 0x1f) == 0x19)) {
        d->owner = pcVar9;
        result = (c1_lookup_result *)(**(code **)(**(int **)pcVar9->type + 0xc))(d->name,1);
        if (result == (c1_lookup_result *)0x0) {
          pcVar9 = decl_redeclare_or_new(d,(c1_symbol *)0x0);
          if (pcVar9 == (c1_symbol *)0x0) {
            return (c1_symbol *)0x0;
          }
          result_cell = arena_alloc(g_arenas + 5,0xc);
        }
        else {
          pcVar11 = lookup_check_ambiguous_symbol(result,'\x01');
          if (pcVar11 == (c1_lookup_entry *)0x0) {
            return (c1_symbol *)0x0;
          }
          pcVar9 = decl_redeclare_or_new(d,pcVar11->sym);
          if (pcVar9 == (c1_symbol *)0x0) {
            return (c1_symbol *)0x0;
          }
          result_cell = arena_alloc(g_arenas + 5,0xc);
        }
        if (result_cell != (void **)0x0) {
          *result_cell = pcVar9;
          result_cell[1] = (void *)0x0;
          result_cell[2] = (void *)0x0;
          if (result_cell != (void **)0x0) {
            return *result_cell;
          }
        }
        return (c1_symbol *)0x0;
      }
      goto LAB_104044bc;
    }
    if ((g_compile_flags_cc & 0x200000) != 0) {
      return pcVar9;
    }
    pvVar13 = sym_static_member_stand_in(pcVar9);
    d->name = *(fe_name **)((int)pvVar13 + 8);
    *spec = *spec & 0xfa | 2;
  }
  if ((*spec & 7) == 7) {
    d->flags55 = d->flags55 | 4;
    if (d->name != (fe_name *)0x0) {
      puVar1 = &d->name->flags;
      *puVar1 = *puVar1 | 0x20000;
    }
    pcVar10 = d->type;
    if (((pcVar10->code & 0x300) != 0) ||
       (((bVar4 = (byte)pcVar10->code, (char)bVar4 < '\0' && ((bVar4 & 0x8f) == 0x80)) &&
        (pcVar10 = pcVar10->base, (pcVar10->code & 0x300) != 0)))) {
      pcVar9 = (pcVar10->extra).cls;
      if (pcVar9 == (c1_symbol *)0x0) {
        d->flags54 = d->flags54 | 0x40;
        return d->sym;
      }
      if ((pcVar9->flags3 & 1) != 0) {
        if (d->kind == 2) {
          puVar1 = &d->name->flags;
          *puVar1 = *puVar1 | 0x40000;
        }
        pcVar9->name = d->name;
        pcVar9->flags3 = pcVar9->flags3 & 0xfe;
        ((pcVar9->detail).cls)->layout_flags3c = ((pcVar9->detail).cls)->layout_flags3c | 8;
        if (g_c9il_mode == '\0') {
          d->flags54 = d->flags54 | 0x10;
        }
      }
    }
    name = d->name;
    if ((name != (fe_name *)0x0) && ((name->flags & 0x2000000) != 0)) {
      pcVar9 = tmpl_check_typedef_redefinition(name,0);
      return pcVar9;
    }
  }
  if (is_member != '\0') {
LAB_104044bc:
    pcVar9 = sym_new_from_declarator(d,0xffffffff);
    return pcVar9;
  }
  if ((g_compile_flags_cc & 1) != 0) {
    if (d->kind == 7) {
      d->flags56 = d->flags56 | 0x20;
    }
    else if (d->kind == 8) {
      pcVar9 = scope_lookup_in_list_fragment(spec,d,0);
      return pcVar9;
    }
  }
  pcVar9 = scope_current_namespace(g_current_scope);
  if (pcVar9 != (c1_symbol *)0x0) {
    d->owner = pcVar9;
  }
  if ((d->qualifier == (c1_overload_set *)0x0) ||
     (iVar15 = sym_is_static_data_member(d->qualifier->list->head->sym), iVar15 == 0)) {
    if (((g_compile_flags_cc & 0x100000) == 0) || ((d->kind != 7 && (d->kind != 8)))) {
      if ((g_class_depth < 0) || ((d->spec[1] & 4) == 0)) goto LAB_104041e6;
      iVar15 = 0;
      d_00 = d;
      scope = scope_enclosing_namespace(g_current_scope,'\0');
      piVar6 = (int *)scope_lookup_for_declaration(scope,d_00,iVar15);
      goto LAB_104041f2;
    }
LAB_104041fa:
    pcVar9 = (c1_symbol *)0x0;
  }
  else {
    if (g_scope_vector->entries[(short)d->qualifier->list->head->key->sym->scope_index] !=
        (c1_symbol *)0x0) {
      pcVar9 = decl_declare_parameters
                         ((int)g_scope_vector,
                          g_scope_vector->entries
                          [(short)d->qualifier->list->head->key->sym->scope_index],spec,d,0x100000);
      return pcVar9;
    }
LAB_104041e6:
    piVar6 = scope_lookup_for_declaration_innermost(g_current_scope,d);
LAB_104041f2:
    if (piVar6 == (int *)0x0) goto LAB_104041fa;
    pcVar9 = (c1_symbol *)*piVar6;
  }
  if (pcVar9 == (c1_symbol *)0x0) {
    if (g_block_depth < 2) {
      if ((g_ms_extensions == '\0') && (g_current_scope->current->kind == '\x01')) {
        pcVar11 = lookup_name_in_context(g_current_scope,d->name,0x132);
        if (pcVar11 == (c1_lookup_entry *)0x0) {
          pcVar9 = (c1_symbol *)0x0;
        }
        else {
          pcVar9 = pcVar11->sym;
        }
        if ((pcVar9 != (c1_symbol *)0x0) && ((pcVar9->flags2 & 0x10) != 0)) {
          pcVar9 = d->sym;
          if (pcVar9 == (c1_symbol *)0x0) {
            pcVar9 = sym_new_from_declarator(d,5);
          }
          diag_warning(1,0xe0,pcVar9);
        }
      }
    }
    else {
      piVar6 = (int *)decl_bind_block_declaration(g_current_scope,d);
      if (piVar6 == (int *)0x0) {
        pcVar9 = (c1_symbol *)0x0;
      }
      else {
        pcVar9 = (c1_symbol *)*piVar6;
      }
      if (pcVar9 != (c1_symbol *)0x0) goto LAB_1040458f;
    }
    pcVar9 = sym_new_from_declarator(d,0xffffffff);
    d->sym = pcVar9;
    if ((pcVar9->entity & 0xffffff) == 0) {
      if (0x7ffffffe < g_next_entity_id) {
        diag_fatal_simple(0x37);
      }
      uVar12 = g_next_entity_id ^ pcVar9->entity;
      g_next_entity_id = g_next_entity_id + 1;
      pcVar9->entity = uVar12 & 0xffffff ^ pcVar9->entity;
    }
    if (1 < g_block_depth) {
      inline_function_instance_new(d->sym);
    }
    if (d->kind == 3) {
      if (((g_compile_flags_c4 & 0x20) != 0) || (cVar5 = g_block_number, (*spec & 7) == 1)) {
        cVar5 = 0;
      }
      (d->sym->x28).block_number = cVar5;
    }
    if (((g_compile_flags_cc & 0x100000) == 0) || ((d->kind != 7 && (d->kind != 8)))) {
      if ((d->spec[1] & 0x20) != 0) {
        (*g_current_scope->global_scope->vtbl->insert)(d->sym);
        return d->sym;
      }
      pcVar9 = d->sym;
      pcVar7 = scope_innermost_declaration_record(g_current_scope,'\x01');
      (*pcVar7->vtbl->insert)(pcVar9);
    }
LAB_10404280:
    return d->sym;
  }
LAB_1040458f:
  if ((d->flags55 & 8) != 0) {
    pcVar9->flags4 = pcVar9->flags4 | 0x80;
  }
  if ((d->spec[3] & 0x40) == 0) {
    return pcVar9;
  }
  bVar4 = pcVar9->kind & 0x1f;
  if (bVar4 == 4) {
    if ((((pcVar9->detail).cls)->flags3f & 1) != 0) {
      return pcVar9;
    }
    diag_error(0x38f,pcVar9->name);
    return pcVar9;
  }
  if (bVar4 == 7) {
    bVar4 = *(byte *)((int)&pcVar9->tail + 9);
    if ((bVar4 & 0x80) != 0) {
      return pcVar9;
    }
    if ((bVar4 & 0x40) == 0) {
      diag_error(0x390,pcVar9);
      return pcVar9;
    }
    diag_error(0x38c,0x44);
    return pcVar9;
  }
  if (bVar4 != 10) {
    return pcVar9;
  }
  pvVar13 = symtab_14ac_lookup_by_name(pcVar9);
  if (pvVar13 == (void *)0x0) {
    if (d->sym != (c1_symbol *)0x0) {
      return d->sym;
    }
    pcVar9 = sym_new_from_declarator(d,5);
    return pcVar9;
  }
  pcVar3 = (g_scope_vector->entries[*(short *)((int)pvVar13 + 6)]->detail).cls;
  if ((pcVar3->flags3f & 1) != 0) {
    return pcVar9;
  }
  if ((pcVar3->flags3e & 1) != 0) {
    if ((pcVar9->key_ref & 3) == 0) {
      return pcVar9;
    }
    diag_error(0x38c,0x44,pvVar13);
    return pcVar9;
  }
  diag_error(0x38b,pvVar13);
  return pcVar9;
}

