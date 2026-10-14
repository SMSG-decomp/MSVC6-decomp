char __fastcall tmpl_check_explicit_argument_kinds(c1_tmpl_deduction *deduction)

{
  c1_u32 *pcVar1;
  byte bVar2;
  c1_symbol *pcVar3;
  ushort uVar4;
  c1_deferred_action *pcVar5;
  c1_type *pcVar6;
  c1_node *pcVar7;
  c1_type *type;
  char local_11;
  c1_arg_item *local_10;
  c1_sym_link *local_4;
  
  local_10 = deduction->args->first;
  local_11 = '\x01';
  if (deduction->tparams == (c1_sym_list *)0x0) {
    local_4 = (c1_sym_link *)0x0;
  }
  else {
    local_4 = deduction->tparams->head;
  }
  if (local_4 != (c1_sym_link *)0x0) {
    do {
      pcVar5 = (c1_deferred_action *)g_arenas[5].cur;
      pcVar1 = &local_4[-1].position;
      bVar2 = local_10->kind;
      if ((bVar2 & 4) == 4) {
        if ((*pcVar1 & 0x1f) == 0x16) {
          if ((bVar2 & 3) != 0) {
            pcVar5 = arena_alloc(g_arenas + 5,0x14);
            if (pcVar5 == (c1_deferred_action *)0x0) {
              pcVar5 = (c1_deferred_action *)0x0;
            }
            else {
              pcVar3 = deduction->tmpl;
              pcVar5->next = (c1_deferred_action *)0x0;
              pcVar5->sym = pcVar3;
              pcVar5->arg = pcVar1;
              (pcVar5->detail).type_expected = '\x01';
              pcVar5->vtbl = &PTR_tmpl_deferred_report_c2975_104ceea8;
            }
            if (g_deferred_actions_head == (c1_deferred_action *)0x0) {
              local_11 = '\0';
              g_deferred_actions_head = pcVar5;
              g_deferred_actions_tail = pcVar5;
            }
            else {
              local_11 = '\0';
              g_deferred_actions_tail->next = pcVar5;
              g_deferred_actions_tail = pcVar5;
            }
          }
        }
        else if ((bVar2 & 3) == 1) {
          pcVar7 = (local_10->value).expr;
          if (pcVar7->type->code == 0x80c) {
            type = (local_4->type).type;
            uVar4 = tmpl_type_find_parameter(type,1,0);
            if (uVar4 != 0) {
              pcVar6 = tmpl_substitute_type(type,deduction->args);
              if (pcVar6 != (c1_type *)0x0) {
                type = pcVar6;
              }
            }
            pcVar7 = expr_resolve_function_address(type,pcVar7);
            if (pcVar7 != (c1_node *)0x0) {
              pcVar7 = tree_copy_to_arena(pcVar7,0);
              (local_10->value).expr = pcVar7;
            }
          }
        }
        else {
          g_arenas[5].cur = g_arenas[5].cur + 0x14;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (pcVar5 == (c1_deferred_action *)0x0) {
            pcVar5 = (c1_deferred_action *)0x0;
          }
          else {
            pcVar3 = deduction->tmpl;
            *(c1_u8 *)((int)pcVar5 + 8) = '\0';
            *(c1_u8 *)((int)pcVar5 + 9) = '\0';
            *(c1_u8 *)((int)pcVar5 + 10) = '\0';
            *(c1_u8 *)((int)pcVar5 + 0xb) = '\0';
            *(c1_symbol **)((int)pcVar5 + 4) = pcVar3;
            *(c1_u32 **)((int)pcVar5 + 0xc) = pcVar1;
            *(c1_u8 *)((int)pcVar5 + 0x10) = '\0';
            pcVar5->vtbl = &PTR_tmpl_deferred_report_c2975_104ceea8;
          }
          if (g_deferred_actions_head == (c1_deferred_action *)0x0) {
            local_11 = '\0';
            g_deferred_actions_head = pcVar5;
            g_deferred_actions_tail = pcVar5;
          }
          else {
            local_11 = '\0';
            g_deferred_actions_tail->next = pcVar5;
            g_deferred_actions_tail = pcVar5;
          }
        }
      }
      local_10 = local_10->next;
    } while ((local_4 != (c1_sym_link *)0x0) &&
            (local_4 = local_4->next, local_4 != (c1_sym_link *)0x0));
    return local_11;
  }
  return '\x01';
}

