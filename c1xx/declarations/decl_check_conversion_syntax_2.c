c1_symbol * __thiscall decl_check_conversion_syntax_2(c1_u8 *spec,c1_declarator *d,char is_member)

{
  uint *puVar1;
  fe_name *name;
  c1_u32 cVar2;
  c1_class_record *pcVar3;
  byte bVar4;
  c1_u16 cVar5;
  c1_symbol *pcVar6;
  int *piVar7;
  c1xx_scope *pcVar8;
  c1_overload_set *pcVar9;
  c1xx_hash_scope *scope;
  c1_lookup_result *result;
  void **lookup_result;
  c1_lookup_entry *pcVar10;
  uint uVar11;
  void *pvVar12;
  char cVar13;
  c1_type *pcVar14;
  c1_declarator *d_00;
  int iVar15;
  
  diag_error(0x24a);
  if ((d->flags54 & 0x40) != 0) {
    cVar2 = d->kind;
    if ((cVar2 == 2) || (cVar2 == 1)) {
      cVar13 = '\x01';
    }
    else {
      cVar13 = '\0';
    }
    if ((((is_member != cVar13) && (cVar2 != 7)) && (cVar2 != 8)) && (cVar2 != 0xc))
    goto LAB_10404280;
  }
  if (d->qualifier != (c1_overload_set *)0x0) {
    pcVar9 = (c1_overload_set *)decl_resolve_function_in_overload_set(d);
    d->qualifier = pcVar9;
    if (pcVar9 == (c1_overload_set *)0x0) {
      return (c1_symbol *)0x0;
    }
    pcVar6 = pcVar9->list->head->sym;
    if ((d->kind == 7) || (d->kind == 8)) {
      decl_check_redeclaration(d,pcVar6);
      return pcVar6;
    }
    if (((pcVar6->flags4 & 0x40) == 0) || ((pcVar6->kind & 0x1f) != 3)) {
      if ((g_compile_flags_c4 & 0x200) != 0) {
        decl_check_redeclaration(d,pcVar6);
        return pcVar6;
      }
      if ((pcVar6->scope_index != 0) &&
         (pcVar6 = g_scope_vector->entries[(short)pcVar6->scope_index],
         (pcVar6->kind & 0x1f) == 0x19)) {
        d->owner = pcVar6;
        result = (c1_lookup_result *)(**(code **)(**(int **)pcVar6->type + 0xc))(d->name,1);
        if (result == (c1_lookup_result *)0x0) {
          pcVar6 = decl_redeclare_or_new(d,(c1_symbol *)0x0);
          if (pcVar6 == (c1_symbol *)0x0) {
            return (c1_symbol *)0x0;
          }
          lookup_result = arena_alloc(g_arenas + 5,0xc);
        }
        else {
          pcVar10 = lookup_check_ambiguous_symbol(result,'\x01');
          if (pcVar10 == (c1_lookup_entry *)0x0) {
            return (c1_symbol *)0x0;
          }
          pcVar6 = decl_redeclare_or_new(d,pcVar10->sym);
          if (pcVar6 == (c1_symbol *)0x0) {
            return (c1_symbol *)0x0;
          }
          lookup_result = arena_alloc(g_arenas + 5,0xc);
        }
        if (lookup_result != (void **)0x0) {
          *lookup_result = pcVar6;
          lookup_result[1] = (void *)0x0;
          lookup_result[2] = (void *)0x0;
          if (lookup_result != (void **)0x0) {
            return *lookup_result;
          }
        }
        return (c1_symbol *)0x0;
      }
      goto LAB_104044bc;
    }
    if ((g_compile_flags_cc & 0x200000) != 0) {
      return pcVar6;
    }
    pvVar12 = sym_static_member_stand_in(pcVar6);
    d->name = *(fe_name **)((int)pvVar12 + 8);
    *spec = *spec & 0xfa | 2;
  }
  if ((*spec & 7) == 7) {
    d->flags55 = d->flags55 | 4;
    if (d->name != (fe_name *)0x0) {
      puVar1 = &d->name->flags;
      *puVar1 = *puVar1 | 0x20000;
    }
    pcVar14 = d->type;
    if (((pcVar14->code & 0x300) != 0) ||
       (((bVar4 = (byte)pcVar14->code, (char)bVar4 < '\0' && ((bVar4 & 0x8f) == 0x80)) &&
        (pcVar14 = pcVar14->base, (pcVar14->code & 0x300) != 0)))) {
      pcVar6 = (pcVar14->extra).cls;
      if (pcVar6 == (c1_symbol *)0x0) {
        d->flags54 = d->flags54 | 0x40;
        return d->sym;
      }
      if ((pcVar6->flags3 & 1) != 0) {
        if (d->kind == 2) {
          puVar1 = &d->name->flags;
          *puVar1 = *puVar1 | 0x40000;
        }
        pcVar6->name = d->name;
        pcVar6->flags3 = pcVar6->flags3 & 0xfe;
        ((pcVar6->detail).cls)->layout_flags3c = ((pcVar6->detail).cls)->layout_flags3c | 8;
        if (g_c9il_mode == '\0') {
          d->flags54 = d->flags54 | 0x10;
        }
      }
    }
    name = d->name;
    if ((name != (fe_name *)0x0) && ((name->flags & 0x2000000) != 0)) {
      pcVar6 = tmpl_check_typedef_redefinition(name,0);
      return pcVar6;
    }
  }
  if (is_member != '\0') {
LAB_104044bc:
    pcVar6 = sym_new_from_declarator(d,0xffffffff);
    return pcVar6;
  }
  if ((g_compile_flags_cc & 1) != 0) {
    if (d->kind == 7) {
      d->flags56 = d->flags56 | 0x20;
    }
    else if (d->kind == 8) {
      pcVar6 = scope_lookup_in_list_fragment(spec,d,0);
      return pcVar6;
    }
  }
  pcVar6 = scope_current_namespace(g_current_scope);
  if (pcVar6 != (c1_symbol *)0x0) {
    d->owner = pcVar6;
  }
  if ((d->qualifier == (c1_overload_set *)0x0) ||
     (iVar15 = sym_is_static_data_member(d->qualifier->list->head->sym), iVar15 == 0)) {
    if (((g_compile_flags_cc & 0x100000) == 0) || ((d->kind != 7 && (d->kind != 8)))) {
      if ((g_class_depth < 0) || ((d->spec[1] & 4) == 0)) goto LAB_104041e6;
      iVar15 = 0;
      d_00 = d;
      scope = scope_enclosing_namespace(g_current_scope,'\0');
      piVar7 = (int *)scope_lookup_for_declaration(scope,d_00,iVar15);
      goto LAB_104041f2;
    }
LAB_104041fa:
    pcVar6 = (c1_symbol *)0x0;
  }
  else {
    if (g_scope_vector->entries[(short)d->qualifier->list->head->key->sym->scope_index] !=
        (c1_symbol *)0x0) {
      pcVar6 = decl_declare_parameters
                         ((int)g_scope_vector,
                          g_scope_vector->entries
                          [(short)d->qualifier->list->head->key->sym->scope_index],spec,d,0x100000);
      return pcVar6;
    }
LAB_104041e6:
    piVar7 = scope_lookup_for_declaration_innermost(g_current_scope,d);
LAB_104041f2:
    if (piVar7 == (int *)0x0) goto LAB_104041fa;
    pcVar6 = (c1_symbol *)*piVar7;
  }
  if (pcVar6 == (c1_symbol *)0x0) {
    if (g_block_depth < 2) {
      if ((g_ms_extensions == '\0') && (g_current_scope->current->kind == '\x01')) {
        pcVar10 = lookup_name_in_context(g_current_scope,d->name,0x132);
        if (pcVar10 == (c1_lookup_entry *)0x0) {
          pcVar6 = (c1_symbol *)0x0;
        }
        else {
          pcVar6 = pcVar10->sym;
        }
        if ((pcVar6 != (c1_symbol *)0x0) && ((pcVar6->flags2 & 0x10) != 0)) {
          pcVar6 = d->sym;
          if (pcVar6 == (c1_symbol *)0x0) {
            pcVar6 = sym_new_from_declarator(d,5);
          }
          diag_warning(1,0xe0,pcVar6);
        }
      }
    }
    else {
      piVar7 = (int *)decl_bind_block_declaration(g_current_scope,d);
      if (piVar7 == (int *)0x0) {
        pcVar6 = (c1_symbol *)0x0;
      }
      else {
        pcVar6 = (c1_symbol *)*piVar7;
      }
      if (pcVar6 != (c1_symbol *)0x0) goto LAB_1040458f;
    }
    pcVar6 = sym_new_from_declarator(d,0xffffffff);
    d->sym = pcVar6;
    if ((pcVar6->entity & 0xffffff) == 0) {
      if (0x7ffffffe < g_next_entity_id) {
        diag_fatal_simple(0x37);
      }
      uVar11 = g_next_entity_id ^ pcVar6->entity;
      g_next_entity_id = g_next_entity_id + 1;
      pcVar6->entity = uVar11 & 0xffffff ^ pcVar6->entity;
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
      pcVar6 = d->sym;
      pcVar8 = scope_innermost_declaration_record(g_current_scope,'\x01');
      (*pcVar8->vtbl->insert)(pcVar6);
    }
LAB_10404280:
    return d->sym;
  }
LAB_1040458f:
  if ((d->flags55 & 8) != 0) {
    pcVar6->flags4 = pcVar6->flags4 | 0x80;
  }
  if ((d->spec[3] & 0x40) == 0) {
    return pcVar6;
  }
  bVar4 = pcVar6->kind & 0x1f;
  if (bVar4 == 4) {
    if ((((pcVar6->detail).cls)->flags3f & 1) != 0) {
      return pcVar6;
    }
    diag_error(0x38f,pcVar6->name);
    return pcVar6;
  }
  if (bVar4 == 7) {
    bVar4 = *(byte *)((int)&pcVar6->tail + 9);
    if ((bVar4 & 0x80) != 0) {
      return pcVar6;
    }
    if ((bVar4 & 0x40) == 0) {
      diag_error(0x390,pcVar6);
      return pcVar6;
    }
    diag_error(0x38c,0x44);
    return pcVar6;
  }
  if (bVar4 != 10) {
    return pcVar6;
  }
  pvVar12 = symtab_14ac_lookup_by_name(pcVar6);
  if (pvVar12 == (void *)0x0) {
    if (d->sym != (c1_symbol *)0x0) {
      return d->sym;
    }
    pcVar6 = sym_new_from_declarator(d,5);
    return pcVar6;
  }
  pcVar3 = (g_scope_vector->entries[*(short *)((int)pvVar12 + 6)]->detail).cls;
  if ((pcVar3->flags3f & 1) != 0) {
    return pcVar6;
  }
  if ((pcVar3->flags3e & 1) != 0) {
    if ((pcVar6->key_ref & 3) == 0) {
      return pcVar6;
    }
    diag_error(0x38c,0x44,pvVar12);
    return pcVar6;
  }
  diag_error(0x38b,pvVar12);
  return pcVar6;
}

