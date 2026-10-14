c1_symbol * __thiscall scope_lookup_in_list_fragment(c1_u8 *spec,c1_declarator *d,int zero)

{
  c1_class_record *pcVar1;
  byte bVar2;
  c1_u16 cVar3;
  c1_symbol *pcVar4;
  int *piVar5;
  c1xx_scope *pcVar6;
  c1xx_hash_scope *scope;
  c1_lookup_entry *pcVar7;
  uint uVar8;
  void *pvVar9;
  c1_declarator *d_00;
  int iVar10;
  
  d->flags56 = d->flags56 | 0x20;
  pcVar4 = scope_current_namespace(g_current_scope);
  if (pcVar4 != (c1_symbol *)zero) {
    d->owner = pcVar4;
  }
  if ((d->qualifier == (c1_overload_set *)0x0) ||
     (iVar10 = sym_is_static_data_member(d->qualifier->list->head->sym), iVar10 == 0)) {
    if (((g_compile_flags_cc & 0x100000) == 0) || ((d->kind != 7 && (d->kind != 8)))) {
      if ((g_class_depth < 0) || ((d->spec[1] & 4) == 0)) goto LAB_104041e6;
      iVar10 = 0;
      d_00 = d;
      scope = scope_enclosing_namespace(g_current_scope,'\0');
      piVar5 = (int *)scope_lookup_for_declaration(scope,d_00,iVar10);
      goto LAB_104041f2;
    }
LAB_104041fa:
    pcVar4 = (c1_symbol *)0x0;
  }
  else {
    if (g_scope_vector->entries[(short)d->qualifier->list->head->key->sym->scope_index] !=
        (c1_symbol *)0x0) {
      pcVar4 = decl_declare_parameters
                         ((int)g_scope_vector,
                          g_scope_vector->entries
                          [(short)d->qualifier->list->head->key->sym->scope_index],spec,d,0x100000);
      return pcVar4;
    }
LAB_104041e6:
    piVar5 = scope_lookup_for_declaration_innermost(g_current_scope,d);
LAB_104041f2:
    if (piVar5 == (int *)0x0) goto LAB_104041fa;
    pcVar4 = (c1_symbol *)*piVar5;
  }
  if (pcVar4 != (c1_symbol *)0x0) {
LAB_1040458f:
    if ((d->flags55 & 8) != 0) {
      pcVar4->flags4 = pcVar4->flags4 | 0x80;
    }
    if ((d->spec[3] & 0x40) != 0) {
      bVar2 = pcVar4->kind & 0x1f;
      if (bVar2 == 4) {
        if ((((pcVar4->detail).cls)->flags3f & 1) == 0) {
          diag_error(0x38f,pcVar4->name);
          return pcVar4;
        }
      }
      else if (bVar2 == 7) {
        bVar2 = *(byte *)((int)&pcVar4->tail + 9);
        if ((bVar2 & 0x80) == 0) {
          if ((bVar2 & 0x40) != 0) {
            diag_error(0x38c,0x44);
            return pcVar4;
          }
          diag_error(0x390,pcVar4);
          return pcVar4;
        }
      }
      else if (bVar2 == 10) {
        pvVar9 = symtab_14ac_lookup_by_name(pcVar4);
        if (pvVar9 == (void *)0x0) {
          if (d->sym != (c1_symbol *)0x0) {
            return d->sym;
          }
          pcVar4 = sym_new_from_declarator(d,5);
          return pcVar4;
        }
        pcVar1 = (g_scope_vector->entries[*(short *)((int)pvVar9 + 6)]->detail).cls;
        if ((pcVar1->flags3f & 1) == 0) {
          if ((pcVar1->flags3e & 1) == 0) {
            diag_error(0x38b,pvVar9);
          }
          else if ((pcVar4->key_ref & 3) != 0) {
            diag_error(0x38c,0x44,pvVar9);
            return pcVar4;
          }
        }
      }
    }
    return pcVar4;
  }
  if (g_block_depth < 2) {
    if ((g_ms_extensions == '\0') && (g_current_scope->current->kind == '\x01')) {
      pcVar7 = lookup_name_in_context(g_current_scope,d->name,0x132);
      if (pcVar7 == (c1_lookup_entry *)0x0) {
        pcVar4 = (c1_symbol *)0x0;
      }
      else {
        pcVar4 = pcVar7->sym;
      }
      if ((pcVar4 != (c1_symbol *)0x0) && ((pcVar4->flags2 & 0x10) != 0)) {
        pcVar4 = d->sym;
        if (pcVar4 == (c1_symbol *)0x0) {
          pcVar4 = sym_new_from_declarator(d,5);
        }
        diag_warning(1,0xe0,pcVar4);
      }
    }
  }
  else {
    piVar5 = (int *)decl_bind_block_declaration(g_current_scope,d);
    if (piVar5 == (int *)0x0) {
      pcVar4 = (c1_symbol *)0x0;
    }
    else {
      pcVar4 = (c1_symbol *)*piVar5;
    }
    if (pcVar4 != (c1_symbol *)0x0) goto LAB_1040458f;
  }
  pcVar4 = sym_new_from_declarator(d,0xffffffff);
  d->sym = pcVar4;
  if ((pcVar4->entity & 0xffffff) == 0) {
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar8 = g_next_entity_id ^ pcVar4->entity;
    g_next_entity_id = g_next_entity_id + 1;
    pcVar4->entity = uVar8 & 0xffffff ^ pcVar4->entity;
  }
  if (1 < g_block_depth) {
    inline_function_instance_new(d->sym);
  }
  if (d->kind == 3) {
    if ((((byte)g_compile_flags_c4 & 0x20) != 0) || (cVar3 = g_block_number, (*spec & 7) == 1)) {
      cVar3 = 0;
    }
    (d->sym->x28).block_number = cVar3;
  }
  if (((g_compile_flags_cc & 0x100000) == 0) || ((d->kind != 7 && (d->kind != 8)))) {
    if ((d->spec[1] & 0x20) != 0) {
      (*g_current_scope->global_scope->vtbl->insert)(d->sym);
      return d->sym;
    }
    pcVar4 = d->sym;
    pcVar6 = scope_innermost_declaration_record(g_current_scope,'\x01');
    (*pcVar6->vtbl->insert)(pcVar4);
  }
  return d->sym;
}

