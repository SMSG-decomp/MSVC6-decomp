c1_tmpl_deduction * __cdecl
tmpl_deduce_from_overloaded_argument
          (c1_tmpl_deduction *deduction,c1_symbol *sym,c1_arg_list *explicit_args,c1_type *type,
          c1_symbol **specialization)

{
  fe_name **ppfVar1;
  c1_u8 *copy;
  byte bVar2;
  char cVar3;
  c1_symbol *pcVar4;
  int iVar5;
  c1_symbol *pcVar6;
  c1_symbol *pcVar7;
  c1_tmpl_deduction *deduction_00;
  c1_symbol *pcVar8;
  c1_lookup_entry *cell;
  c1_deferred_action *pcVar9;
  
  pcVar9 = (c1_deferred_action *)g_arenas[5].cur;
  pcVar7 = sym;
  if ((sym->kind & 0x1f) == 0x1a) {
    if (*(char *)((int)&sym->type->extra + 2) != '\0') {
      return (c1_tmpl_deduction *)0x0;
    }
    pcVar7 = *(c1_symbol **)sym->type;
  }
  bVar2 = pcVar7->kind & 0x1f;
  if (((bVar2 != 7) && (bVar2 != 8)) && (bVar2 != 6)) {
    sym = (c1_symbol *)0x0;
    if (bVar2 == 0x1b) {
      cell = *(c1_lookup_entry **)pcVar7->type;
      do {
        pcVar4 = (c1_symbol *)
                 tmpl_deduce_from_overloaded_argument
                           (deduction,cell->sym,explicit_args,type,specialization);
        pcVar7 = sym;
        if ((pcVar4 != (c1_symbol *)0x0) && (pcVar7 = pcVar4, sym != (c1_symbol *)0x0)) {
          diag_error(0x392,*(undefined4 *)(*(int *)sym + 8));
          return (c1_tmpl_deduction *)0x0;
        }
        sym = pcVar7;
        cell = cell->next;
      } while (cell != (c1_lookup_entry *)0x0);
    }
    else {
      ppfVar1 = &pcVar7->name;
      pcVar4 = (c1_symbol *)0x0;
      pcVar8 = sym;
      if (((ppfVar1 != (fe_name **)0x0) &&
          (iVar5 = sym_is_data_or_function_2(pcVar7), pcVar4 = (c1_symbol *)ppfVar1,
          (char)iVar5 == '\0')) && ((pcVar7->kind & 0x1f) != 0x1a)) {
        pcVar4 = (c1_symbol *)pcVar7->type;
      }
      while ((sym = pcVar8, ppfVar1 != (fe_name **)0x0 && (pcVar4 != (c1_symbol *)0x0))) {
        iVar5 = sym_is_data_or_function_2(pcVar7);
        if (((char)iVar5 == '\0') && ((pcVar7->kind & 0x1f) != 0x1a)) {
          pcVar8 = *(c1_symbol **)&pcVar4->flags4;
        }
        else {
          pcVar8 = (c1_symbol *)0x0;
        }
        pcVar6 = (c1_symbol *)
                 tmpl_deduce_from_overloaded_argument
                           (deduction,(c1_symbol *)((int)&pcVar4[-1].tail + 4),explicit_args,type,
                            specialization);
        pcVar4 = pcVar8;
        pcVar8 = sym;
        if ((pcVar6 != (c1_symbol *)0x0) && (pcVar8 = pcVar6, sym != (c1_symbol *)0x0)) {
          diag_error(0x392,*(undefined4 *)(*(int *)sym + 8));
          return (c1_tmpl_deduction *)0x0;
        }
      }
    }
    return (c1_tmpl_deduction *)sym;
  }
  bVar2 = *(byte *)((int)&pcVar7->tail + 9);
  if ((bVar2 & 0xc0) == 0) {
    if ((bVar2 & 0x20) != 0) {
      if (explicit_args == (c1_arg_list *)0x0) {
        g_arenas[5].cur = g_arenas[5].cur + 0x10;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        if (pcVar9 == (c1_deferred_action *)0x0) {
          pcVar9 = (c1_deferred_action *)0x0;
        }
        else {
          pcVar4 = deduction->tmpl;
          *(c1_u8 *)((int)pcVar9 + 8) = '\0';
          *(c1_u8 *)((int)pcVar9 + 9) = '\0';
          *(c1_u8 *)((int)pcVar9 + 10) = '\0';
          *(c1_u8 *)((int)pcVar9 + 0xb) = '\0';
          *(c1_symbol **)((int)pcVar9 + 4) = pcVar4;
          *(c1_symbol **)((int)pcVar9 + 0xc) = pcVar7;
          pcVar9->vtbl = &PTR_tmpl_deferred_report_c2896_104cee7c;
        }
        if (g_deferred_actions_head == (c1_deferred_action *)0x0) {
          g_deferred_actions_head = pcVar9;
          g_deferred_actions_tail = pcVar9;
          return (c1_tmpl_deduction *)0x0;
        }
        g_deferred_actions_tail->next = pcVar9;
        g_deferred_actions_tail = pcVar9;
        return (c1_tmpl_deduction *)0x0;
      }
      pcVar7 = tmpl_match_explicit_arguments(pcVar7,explicit_args);
      if (pcVar7 == (c1_symbol *)0x0) {
        return (c1_tmpl_deduction *)0x0;
      }
      *specialization = pcVar7;
    }
    copy = g_arenas[5].cur;
    g_arenas[5].cur = g_arenas[5].cur + 0x30;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (copy == (c1_u8 *)0x0) {
      deduction_00 = (c1_tmpl_deduction *)0x0;
    }
    else {
      deduction_00 = tmpl_deduction_copy((c1_tmpl_deduction *)copy,deduction);
    }
    if (((pcVar7->kind & 0x1f) != 6) &&
       (cVar3 = tmpl_unify_types(deduction_00,type,pcVar7->type,'\x01'), cVar3 != '\0')) {
      return deduction_00;
    }
  }
  return (c1_tmpl_deduction *)0x0;
}

