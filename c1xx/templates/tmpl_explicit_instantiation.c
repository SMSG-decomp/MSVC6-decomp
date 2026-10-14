void __thiscall
tmpl_explicit_instantiation(c1_declarator *d,c1_u8 prefix_keyword,c1xx_decl_specifiers *spec)

{
  c1_overload_set *pcVar1;
  c1_type *pcVar2;
  c1_class_record *pcVar3;
  bool bVar4;
  bool bVar5;
  c1xx_scope **ppcVar6;
  c1_scope_stack *pcVar7;
  c1_u8 *rec;
  byte bVar8;
  c1_decl_state *pcVar9;
  c1_symbol *pcVar10;
  c1_symbol *pcVar11;
  undefined4 local_4;
  
  if ((spec->spec[0] & 7) != 0) {
    local_4 = 1;
    switch(spec->spec[0] & 7) {
    case 1:
      local_4 = 10;
      break;
    case 3:
      local_4 = 9;
      break;
    case 4:
      local_4 = 8;
      break;
    case 5:
      local_4 = 0xb;
      break;
    case 7:
      local_4 = 0xc;
    }
    diag_error(0x3b4,local_4);
    spec->spec[0] = spec->spec[0] & 0xf8;
  }
  if (prefix_keyword != '\x01') {
    if ((g_ms_extensions == '\0') || (prefix_keyword != '\n')) {
      diag_error(0x3b,0x4c,prefix_keyword);
      prefix_keyword = '\x01';
    }
    else {
      diag_warning(3,0xe7,10);
    }
  }
  if (d->name == (fe_name *)0x0) {
    pcVar2 = spec->type;
    if ((((pcVar2->code & 0x200) != 0) &&
        (pcVar11 = (pcVar2->extra).cls, (pcVar11->kind & 0x1f) == 4)) &&
       (pcVar3 = (pcVar11->detail).cls, (pcVar3->flags3e & 1) != 0)) {
      if ((pcVar3->flags3f & 1) != 0) {
        pcVar3->flags3f = pcVar3->flags3f & 0xfe;
      }
      if ((pcVar11->flags2 & 4) == 0) {
        pcVar10 = tmpl_template_of_instance(pcVar11);
        if ((((pcVar10->detail).cls)->flags3e & 8) == 0) {
          diag_warning(1,0x296);
        }
        else {
          tmpl_instantiate(pcVar10,pcVar11);
        }
      }
      else {
        diag_warning(2,0x294);
      }
      pcVar3 = (pcVar11->detail).cls;
      bVar8 = pcVar3->flags3e;
      if (prefix_keyword == '\n') {
        if ((bVar8 & 0x10) != 0) {
          diag_error(0x3b5,pcVar11);
          return;
        }
        pcVar3->flags3e = bVar8 | 0x20;
        return;
      }
      if ((bVar8 & 0x20) != 0) {
        diag_error(0x3b5,pcVar11);
        return;
      }
      pcVar3->flags3e = bVar8 | 0x10;
      return;
    }
    if (pcVar2 != (c1_type *)0x0) {
      diag_error(0x3b2,pcVar2);
      return;
    }
    diag_error(0x3b1);
  }
  else {
    pcVar1 = d->qualifier;
    if ((pcVar1 == (c1_overload_set *)0x0) || ((pcVar1->kind & 0x1f) != 0x12)) {
      pcVar10 = d->owner;
      pcVar11 = (c1_symbol *)0x0;
      if (pcVar10 != (c1_symbol *)0x0) {
        d->owner = (c1_symbol *)0x0;
        pcVar11 = pcVar10;
      }
    }
    else {
      pcVar11 = pcVar1->list->head->key->sym;
      d->qualifier = (c1_overload_set *)0x0;
      bVar8 = g_current_scope->current->kind;
      if ((0xfa < bVar8) && (bVar8 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
    }
    rec = g_arenas[8].cur;
    pcVar7 = g_current_scope;
    bVar5 = false;
    bVar4 = bVar5;
    if (((pcVar11 != (c1_symbol *)0x0) && (bVar8 = pcVar11->kind & 0x1f, bVar8 != 4)) &&
       (bVar4 = false, bVar8 == 0x19)) {
      bVar4 = bVar5;
      if (g_current_scope->current != g_current_scope->global_scope) {
        g_arenas[8].cur = g_arenas[8].cur + 0x1c;
        if (g_arenas[8].end < g_arenas[8].cur) {
          arena_grow(g_arenas + 8);
        }
        if (rec == (c1_u8 *)0x0) {
          pcVar9 = (c1_decl_state *)0x0;
        }
        else {
          pcVar9 = decl_state_snapshot((c1_decl_state *)rec,pcVar7,pcVar7->saved,'\x01');
        }
        pcVar7->saved = pcVar9;
        pcVar7 = g_current_scope;
        bVar4 = true;
        ppcVar6 = &g_current_scope->global_scope;
        g_current_scope->depth = '\0';
        pcVar7->current = *ppcVar6;
        pcVar7->qual_class = (c1_symbol *)0x0;
        pcVar7->access_op = '\x01';
        pcVar7->qualified = '\0';
        pcVar7->reported = '\0';
        pcVar7->keep_aliases = '\0';
      }
      ns_enter_enclosing_namespaces(g_current_scope,pcVar11);
    }
    pcVar10 = decl_declare_and_check(d,spec->spec);
    pcVar7 = g_current_scope;
    if (pcVar11 != (c1_symbol *)0x0) {
      ppcVar6 = &g_current_scope->global_scope;
      g_current_scope->depth = '\0';
      pcVar7->current = *ppcVar6;
      pcVar7->qual_class = (c1_symbol *)0x0;
      pcVar7->access_op = '\x01';
      pcVar7->qualified = '\0';
      pcVar7->reported = '\0';
      pcVar7->keep_aliases = '\0';
    }
    if (bVar4) {
      decl_state_restore(g_current_scope,'\x01');
      decl_state_pop(g_current_scope);
    }
    if (pcVar10 != (c1_symbol *)0x0) {
      *(byte *)((int)&d->sym->tail + 9) = *(byte *)((int)&d->sym->tail + 9) & 0x7f;
      *(byte *)((int)&d->sym->tail + 9) = *(byte *)((int)&d->sym->tail + 9) | 0x40;
      bVar8 = pcVar10->flags22;
      if (prefix_keyword == '\n') {
        if ((bVar8 & 0x10) != 0) {
          diag_error(0x3a1,pcVar10);
          return;
        }
        pcVar10->flags22 = bVar8 | 0x20;
        return;
      }
      if ((bVar8 & 0x20) != 0) {
        diag_error(0x3a1,pcVar10);
      }
      if ((pcVar10->flags22 & 8) != 0) {
        if ((pcVar10->flags21 & 1) != 0) {
          pcVar10->flags22 = pcVar10->flags22 | 0x10;
          tmpl_work_queue_add(pcVar10,(int *)0x0);
          return;
        }
        diag_error(0x37f,pcVar10);
        return;
      }
      pcVar10->flags22 = pcVar10->flags22 | 0x10;
      pcVar10->flags21 = pcVar10->flags21 | 0x80;
      tmpl_work_queue_add(pcVar10,(int *)0x0);
      return;
    }
  }
  return;
}

