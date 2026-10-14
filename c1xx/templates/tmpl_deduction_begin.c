c1_tmpl_deduction * __thiscall
tmpl_deduction_begin
          (c1_tmpl_deduction *deduction,c1_symbol *sym,c1_arg_list *explicit_args,byte member_match,
          char require_all)

{
  c1_arg_list *pcVar1;
  c1_u8 *pcVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  c1_sym_list *pcVar6;
  c1_symbol *pcVar7;
  c1_sym_link *pcVar8;
  c1_arg_list *pcVar9;
  c1_deferred_action *pcVar10;
  c1_arg_item *pcVar11;
  
  deduction->tmpl = sym;
  deduction->specialization = (c1_symbol *)0x0;
  deduction->args = (c1_arg_list *)0x0;
  deduction->param_type = (c1_type *)0x0;
  deduction->arg_type = (c1_type *)0x0;
  deduction->flags = (member_match & 1) << 4 | deduction->flags & 0xa0;
  pcVar2 = g_arenas[5].cur;
  iVar5 = **(int **)(*(int *)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 8) + 0xc)
  ;
  if ((sym->kind & 0x1f) == 8) {
    iVar5 = iVar5 + 1;
  }
  g_arenas[5].cur = g_arenas[5].cur + (iVar5 + 3U & 0xfffffffc);
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  deduction->param_bytes = pcVar2;
  pcVar6 = tmpl_lookup_parameter_list(deduction->tmpl);
  deduction->tparams = pcVar6;
  deduction->tparam_count = 0;
  if (pcVar6 == (c1_sym_list *)0x0) {
    if (((byte)g_compile_flags_cc & 0x20) == 0) {
      if (((deduction->flags & 0x10) == 0) ||
         ((bVar3 = sym->kind & 0x1f, bVar3 != 0x11 && (bVar3 != 8)))) {
        deduction->flags = deduction->flags | 1;
        return deduction;
      }
      pcVar7 = g_scope_vector->entries[(short)sym->scope_index];
      if ((((pcVar7->detail).cls)->flags3f & 0x80) != 0) {
        pcVar7 = tmpl_template_of_instance(pcVar7);
      }
      pcVar6 = tmpl_lookup_parameter_list(pcVar7);
      deduction->tparams = pcVar6;
    }
    else if (g_current_scope->current->kind == 0xfa) {
      deduction->tparams = (c1_sym_list *)g_current_scope->current->body;
    }
  }
  if (deduction->tparams == (c1_sym_list *)0x0) {
    pcVar8 = (c1_sym_link *)0x0;
  }
  else {
    pcVar8 = deduction->tparams->head;
  }
  for (; (pcVar8 != (c1_sym_link *)0x0 &&
         (deduction->tparam_count = deduction->tparam_count + 1, pcVar8 != (c1_sym_link *)0x0));
      pcVar8 = pcVar8->next) {
  }
  if (explicit_args == (c1_arg_list *)0x0) {
    _member_match = (c1_symbol *)0x0;
    if (deduction->tparam_count != 0) {
      do {
        pcVar11 = (c1_arg_item *)g_arenas[5].cur;
        g_arenas[5].cur = g_arenas[5].cur + 0x14;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        if (pcVar11 == (c1_arg_item *)0x0) {
          pcVar11 = (c1_arg_item *)0x0;
        }
        else {
          bVar3 = *(byte *)((int)pcVar11 + 0xc);
          *(c1_u8 *)((int)pcVar11 + 4) = '\0';
          *(c1_u8 *)((int)pcVar11 + 5) = '\0';
          *(c1_u8 *)((int)pcVar11 + 6) = '\0';
          *(c1_u8 *)((int)pcVar11 + 7) = '\0';
          *(c1_u8 *)((int)pcVar11 + 8) = '\0';
          *(c1_u8 *)((int)pcVar11 + 9) = '\0';
          *(c1_u8 *)((int)pcVar11 + 10) = '\0';
          *(c1_u8 *)((int)pcVar11 + 0xb) = '\0';
          *(byte *)((int)pcVar11 + 0xc) = bVar3 & 0xf8;
          *(c1_u8 *)((int)pcVar11 + 0x10) = '\0';
          *(c1_u8 *)((int)pcVar11 + 0x11) = '\0';
          *(c1_u8 *)((int)pcVar11 + 0x12) = '\0';
          *(c1_u8 *)((int)pcVar11 + 0x13) = '\0';
          pcVar11->vtbl = &PTR_pch_fixup_list_object_104c4c3c;
        }
        pcVar2 = g_arenas[5].cur;
        pcVar1 = deduction->args;
        if (pcVar1 == (c1_arg_list *)0x0) {
          g_arenas[5].cur = g_arenas[5].cur + 0xc;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (pcVar2 == (c1_u8 *)0x0) {
            deduction->args = (c1_arg_list *)0x0;
          }
          else {
            *(c1_arg_item **)pcVar2 = pcVar11;
            *(c1_arg_item **)(pcVar2 + 4) = pcVar11;
            pcVar2[8] = (pcVar11->kind >> 3 & 1 ^ pcVar2[8]) & 1 ^ pcVar2[8];
            deduction->args = (c1_arg_list *)pcVar2;
          }
        }
        else {
          pcVar1->last->next = pcVar11;
          pcVar11->prev = pcVar1->last;
          pcVar1->last = pcVar11;
          if ((pcVar11->kind & 8) != 0) {
            pcVar1->flags = pcVar1->flags | 1;
          }
        }
        _member_match = (c1_symbol *)((int)_member_match + 1);
      } while (_member_match < (uint)deduction->tparam_count);
    }
    return deduction;
  }
  pcVar11 = explicit_args->first;
  _member_match = (c1_symbol *)0x0;
  do {
    pcVar11 = pcVar11->next;
    _member_match = (c1_symbol *)((int)_member_match + 1);
  } while (pcVar11 != (c1_arg_item *)0x0);
  if ((uint)deduction->tparam_count < _member_match) {
    diag_error(0x3d1,sym);
    _member_match = (c1_symbol *)deduction->tparam_count;
  }
  pcVar11 = explicit_args->first;
  if (_member_match != (c1_symbol *)0x0) {
    sym = _member_match;
    pcVar7 = _member_match;
    do {
      pcVar2 = g_arenas[5].cur;
      bVar3 = pcVar11->kind & 3;
      if (bVar3 == 1) {
        g_arenas[5].cur = g_arenas[5].cur + 0x14;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        if (pcVar2 == (c1_u8 *)0x0) {
LAB_104a7abe:
          pcVar7 = (c1_symbol *)0x0;
        }
        else {
          pcVar2[4] = '\0';
          pcVar2[5] = '\0';
          pcVar2[6] = '\0';
          pcVar2[7] = '\0';
          pcVar2[8] = '\0';
          pcVar2[9] = '\0';
          pcVar2[10] = '\0';
          pcVar2[0xb] = '\0';
          bVar4 = (pcVar11->kind ^ pcVar2[0xc]) & 3 ^ pcVar2[0xc];
          pcVar2[0xc] = bVar4;
          bVar3 = pcVar11->kind;
          *(undefined ***)pcVar2 = &PTR_pch_mark_object_links_104ca9b4;
          pcVar2[0xc] = (bVar3 ^ bVar4) & 4 ^ bVar4;
          *(c1_arg_value *)(pcVar2 + 0x10) = pcVar11->value;
          *(undefined ***)pcVar2 = &PTR_pch_fixup_tree_list_object_104bcbcc;
          pcVar7 = (c1_symbol *)pcVar2;
        }
      }
      else if (bVar3 == 0) {
        g_arenas[5].cur = g_arenas[5].cur + 0x14;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        if (pcVar2 == (c1_u8 *)0x0) goto LAB_104a7abe;
        pcVar2[4] = '\0';
        pcVar2[5] = '\0';
        pcVar2[6] = '\0';
        pcVar2[7] = '\0';
        pcVar2[8] = '\0';
        pcVar2[9] = '\0';
        pcVar2[10] = '\0';
        pcVar2[0xb] = '\0';
        bVar4 = (pcVar11->kind ^ pcVar2[0xc]) & 3 ^ pcVar2[0xc];
        pcVar2[0xc] = bVar4;
        bVar3 = pcVar11->kind;
        *(undefined ***)pcVar2 = &PTR_pch_mark_object_links_104ca9b4;
        pcVar2[0xc] = (bVar3 ^ bVar4) & 4 ^ bVar4;
        *(c1_arg_value *)(pcVar2 + 0x10) = pcVar11->value;
        *(undefined ***)pcVar2 = &PTR_pch_fixup_list_object_104c4c3c;
        pcVar7 = (c1_symbol *)pcVar2;
      }
      pcVar9 = (c1_arg_list *)g_arenas[5].cur;
      pcVar1 = deduction->args;
      if (pcVar1 == (c1_arg_list *)0x0) {
        g_arenas[5].cur = g_arenas[5].cur + 0xc;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        if (pcVar9 == (c1_arg_list *)0x0) {
          pcVar9 = (c1_arg_list *)0x0;
        }
        else {
          *(c1_symbol **)pcVar9 = pcVar7;
          *(c1_symbol **)((int)pcVar9 + 4) = pcVar7;
          *(byte *)((int)pcVar9 + 8) =
               (*(byte *)&pcVar7->next >> 3 & 1 ^ *(byte *)((int)pcVar9 + 8)) & 1 ^
               *(byte *)((int)pcVar9 + 8);
        }
        deduction->args = pcVar9;
      }
      else {
        pcVar1->last->next = (c1_arg_item *)pcVar7;
        pcVar7->name = (fe_name *)pcVar1->last;
        pcVar1->last = (c1_arg_item *)pcVar7;
        if (((uint)pcVar7->next & 8) != 0) {
          pcVar1->flags = pcVar1->flags | 1;
        }
      }
      pcVar11 = pcVar11->next;
      sym = (c1_symbol *)((int)&sym[-1].tail + 0xb);
    } while (sym != (c1_symbol *)0x0);
  }
  pcVar10 = (c1_deferred_action *)g_arenas[5].cur;
  if ((c1_symbol *)deduction->tparam_count <= _member_match) {
    bVar3 = deduction->flags;
    deduction->flags = bVar3 | 2;
    deduction->flags = bVar3 | 0x22;
    return deduction;
  }
  if (require_all != '\0') {
    g_arenas[5].cur = g_arenas[5].cur + 0x10;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (pcVar10 == (c1_deferred_action *)0x0) {
      pcVar10 = (c1_deferred_action *)0x0;
    }
    else {
      *(c1_symbol **)((int)pcVar10 + 4) = deduction->tmpl;
      *(c1_u8 *)((int)pcVar10 + 8) = '\0';
      *(c1_u8 *)((int)pcVar10 + 9) = '\0';
      *(c1_u8 *)((int)pcVar10 + 10) = '\0';
      *(c1_u8 *)((int)pcVar10 + 0xb) = '\0';
      *(c1_symbol **)((int)pcVar10 + 0xc) = _member_match;
      pcVar10->vtbl = &PTR_tmpl_deferred_report_c2780_104cee94;
    }
    if (g_deferred_actions_head == (c1_deferred_action *)0x0) {
      g_deferred_actions_head = pcVar10;
      g_deferred_actions_tail = pcVar10;
      deduction->flags = deduction->flags | 4;
      return deduction;
    }
    g_deferred_actions_tail->next = pcVar10;
    g_deferred_actions_tail = pcVar10;
    deduction->flags = deduction->flags | 4;
    return deduction;
  }
  do {
    pcVar11 = (c1_arg_item *)g_arenas[5].cur;
    g_arenas[5].cur = g_arenas[5].cur + 0x14;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (pcVar11 == (c1_arg_item *)0x0) {
      pcVar11 = (c1_arg_item *)0x0;
    }
    else {
      bVar3 = *(byte *)((int)pcVar11 + 0xc);
      *(c1_u8 *)((int)pcVar11 + 4) = '\0';
      *(c1_u8 *)((int)pcVar11 + 5) = '\0';
      *(c1_u8 *)((int)pcVar11 + 6) = '\0';
      *(c1_u8 *)((int)pcVar11 + 7) = '\0';
      *(c1_u8 *)((int)pcVar11 + 8) = '\0';
      *(c1_u8 *)((int)pcVar11 + 9) = '\0';
      *(c1_u8 *)((int)pcVar11 + 10) = '\0';
      *(c1_u8 *)((int)pcVar11 + 0xb) = '\0';
      *(byte *)((int)pcVar11 + 0xc) = bVar3 & 0xf8;
      *(c1_u8 *)((int)pcVar11 + 0x10) = '\0';
      *(c1_u8 *)((int)pcVar11 + 0x11) = '\0';
      *(c1_u8 *)((int)pcVar11 + 0x12) = '\0';
      *(c1_u8 *)((int)pcVar11 + 0x13) = '\0';
      pcVar11->vtbl = &PTR_pch_fixup_list_object_104c4c3c;
    }
    pcVar1 = deduction->args;
    pcVar1->last->next = pcVar11;
    pcVar11->prev = pcVar1->last;
    pcVar1->last = pcVar11;
    if ((pcVar11->kind & 8) != 0) {
      pcVar1->flags = pcVar1->flags | 1;
    }
    _member_match = (c1_symbol *)&_member_match->flags1;
  } while (_member_match < (undefined1 *)deduction->tparam_count);
  deduction->flags = deduction->flags | 0x20;
  return deduction;
}

