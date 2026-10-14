c1_symbol * __thiscall
decl_declare_parameters
          (int scope_vector,c1_symbol *scope_sym,c1_u8 *spec,c1_declarator *d,uint cc_mask)

{
  c1_class_record *pcVar1;
  byte bVar2;
  c1_u16 cVar3;
  c1xx_scope *pcVar4;
  c1_lookup_result *result;
  c1_lookup_entry *pcVar5;
  c1_symbol *pcVar6;
  int *piVar7;
  uint uVar8;
  void *pvVar9;
  
  if ((scope_sym->kind & 0x1f) == 0x19) {
    if (scope_sym == (c1_symbol *)0x0) goto LAB_104041e6;
    result = (c1_lookup_result *)(**(code **)(**(int **)scope_sym->type + 0xc))(d->name,1);
    if (result == (c1_lookup_result *)0x0) {
      pcVar6 = (c1_symbol *)0x0;
LAB_104797c6:
      pcVar6 = decl_redeclare_or_new(d,pcVar6);
      if ((pcVar6 == (c1_symbol *)0x0) ||
         (piVar7 = arena_alloc(g_arenas + 5,0xc), piVar7 == (int *)0x0)) goto LAB_104041fa;
      *piVar7 = (int)pcVar6;
      piVar7[1] = 0;
      piVar7[2] = 0;
      goto LAB_104041f2;
    }
    pcVar5 = lookup_check_ambiguous_symbol(result,'\x01');
    if (pcVar5 != (c1_lookup_entry *)0x0) {
      pcVar6 = pcVar5->sym;
      goto LAB_104797c6;
    }
LAB_104041fa:
    pcVar6 = (c1_symbol *)0x0;
  }
  else {
    pcVar6 = *(c1_symbol **)(scope_vector + 4 + (short)scope_sym->scope_index * 4);
    if (pcVar6 != (c1_symbol *)0x0) {
      pcVar6 = decl_declare_parameters(scope_vector,pcVar6,spec,d,cc_mask);
      return pcVar6;
    }
LAB_104041e6:
    piVar7 = scope_lookup_for_declaration_innermost(g_current_scope,d);
LAB_104041f2:
    if (piVar7 == (int *)0x0) goto LAB_104041fa;
    pcVar6 = (c1_symbol *)*piVar7;
  }
  if (pcVar6 != (c1_symbol *)0x0) {
LAB_1040458f:
    if ((d->flags55 & 8) != 0) {
      pcVar6->flags4 = pcVar6->flags4 | 0x80;
    }
    if ((d->spec[3] & 0x40) != 0) {
      bVar2 = pcVar6->kind & 0x1f;
      if (bVar2 == 4) {
        if ((((pcVar6->detail).cls)->flags3f & 1) == 0) {
          diag_error(0x38f,pcVar6->name);
          return pcVar6;
        }
      }
      else if (bVar2 == 7) {
        bVar2 = *(byte *)((int)&pcVar6->tail + 9);
        if ((bVar2 & 0x80) == 0) {
          if ((bVar2 & 0x40) != 0) {
            diag_error(0x38c,0x44);
            return pcVar6;
          }
          diag_error(0x390,pcVar6);
          return pcVar6;
        }
      }
      else if (bVar2 == 10) {
        pvVar9 = symtab_14ac_lookup_by_name(pcVar6);
        if (pvVar9 == (void *)0x0) {
          if (d->sym != (c1_symbol *)0x0) {
            return d->sym;
          }
          pcVar6 = sym_new_from_declarator(d,5);
          return pcVar6;
        }
        pcVar1 = (g_scope_vector->entries[*(short *)((int)pvVar9 + 6)]->detail).cls;
        if ((pcVar1->flags3f & 1) == 0) {
          if ((pcVar1->flags3e & 1) == 0) {
            diag_error(0x38b,pvVar9);
          }
          else if ((pcVar6->key_ref & 3) != 0) {
            diag_error(0x38c,0x44,pvVar9);
            return pcVar6;
          }
        }
      }
    }
    return pcVar6;
  }
  if (g_block_depth < 2) {
    if ((g_ms_extensions == '\0') && (g_current_scope->current->kind == '\x01')) {
      pcVar5 = lookup_name_in_context(g_current_scope,d->name,0x132);
      if (pcVar5 == (c1_lookup_entry *)0x0) {
        pcVar6 = (c1_symbol *)0x0;
      }
      else {
        pcVar6 = pcVar5->sym;
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
    uVar8 = g_next_entity_id ^ pcVar6->entity;
    g_next_entity_id = g_next_entity_id + 1;
    pcVar6->entity = uVar8 & 0xffffff ^ pcVar6->entity;
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
  if (((g_compile_flags_cc & cc_mask) == 0) || ((d->kind != 7 && (d->kind != 8)))) {
    if ((d->spec[1] & 0x20) != 0) {
      (*g_current_scope->global_scope->vtbl->insert)(d->sym);
      return d->sym;
    }
    pcVar6 = d->sym;
    pcVar4 = scope_innermost_declaration_record(g_current_scope,'\x01');
    (*pcVar4->vtbl->insert)(pcVar6);
  }
  return d->sym;
}

