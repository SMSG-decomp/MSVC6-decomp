c1_tmpl_deduction * __thiscall tmpl_deduce_from_call(c1_ovl_resolution *res,c1_symbol *sym)

{
  c1_u16 cVar1;
  c1_type *type;
  c1_node *arg;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  c1_tmpl_deduction *pcVar5;
  uint uVar6;
  uint *record;
  int iVar7;
  c1_node *pcVar8;
  c1_arg_item *pcVar9;
  c1_u32 arg_count;
  uint *record_2;
  uint *arg_type_slot;
  
  pcVar5 = arena_alloc(g_arenas + 5,0x30);
  if (pcVar5 == (c1_tmpl_deduction *)0x0) {
    pcVar5 = (c1_tmpl_deduction *)0x0;
  }
  else {
    pcVar5 = tmpl_deduction_begin(pcVar5,sym,(res->extra).template_args,0,'\0');
  }
  if ((sym->kind & 0x1f) == 8) {
    arg_count = res->nargs - 1;
  }
  else {
    arg_count = res->nargs;
  }
  uVar6 = type_function_arity_match
                    ((c1_type *)((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)),arg_count
                    );
  if ((-1 < (int)uVar6) && ((int)uVar6 < 2)) {
    record = arena_alloc(g_arenas + 5,0x10);
    if (record == (uint *)0x0) {
      record = (uint *)0x0;
    }
    else {
      uVar6 = res->nargs;
      record[1] = (uint)sym;
      record[2] = 0;
      record[3] = uVar6;
      *record = (uint)&PTR_tmpl_deferred_report_c2780_104cee94;
    }
    if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
      g_deferred_actions_tail->next = (c1_deferred_action *)record;
      g_deferred_actions_tail = (c1_deferred_action *)record;
      return (c1_tmpl_deduction *)0x0;
    }
    g_deferred_actions_head = (c1_deferred_action *)record;
    g_deferred_actions_tail = (c1_deferred_action *)record;
    return (c1_tmpl_deduction *)0x0;
  }
  if ((pcVar5->flags & 2) == 0) {
    pcVar8 = res->args;
    arg_type_slot =
         (uint *)(*(int *)(*(int *)(((uint)sym->type & -(uint)((sym->type->code & 0x80) != 0)) + 8)
                          + 0xc) + 8);
    uVar6 = (uint)((sym->kind & 0x1f) == 8);
    if (uVar6 < res->nargs) {
      do {
        record_2 = (uint *)g_arenas[5].cur;
        pcVar8 = pcVar8->link;
        if (pcVar8->left == (void *)0x0) {
          g_arenas[5].cur = g_arenas[5].cur + 0xc;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (record_2 == (uint *)0x0) {
            record_2 = (uint *)0x0;
          }
          else {
            *(c1_symbol **)((int)record_2 + 4) = sym;
            *(c1_u8 *)((int)record_2 + 8) = '\0';
            *(c1_u8 *)((int)record_2 + 9) = '\0';
            *(c1_u8 *)((int)record_2 + 10) = '\0';
            *(c1_u8 *)((int)record_2 + 0xb) = '\0';
            *record_2 = (uint)&PTR_vtable_nop_104cee90;
          }
          if (g_deferred_actions_head == (c1_deferred_action *)0x0) {
            g_deferred_actions_head = (c1_deferred_action *)record_2;
            g_deferred_actions_tail = (c1_deferred_action *)record_2;
            return (c1_tmpl_deduction *)0x0;
          }
          g_deferred_actions_tail->next = (c1_deferred_action *)record_2;
          g_deferred_actions_tail = (c1_deferred_action *)record_2;
          return (c1_tmpl_deduction *)0x0;
        }
        type = (c1_type *)*arg_type_slot;
        if (type->code == 0x80d) break;
        uVar4 = tmpl_type_find_parameter(type,1,0);
        if (uVar4 != 0) {
          iVar7 = (uVar4 & 0xff) - 1;
          pcVar9 = pcVar5->args->first;
          if (0 < iVar7) {
            do {
              pcVar9 = pcVar9->next;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
          if ((pcVar9->kind & 4) != 4) {
            pcVar5->param_bytes[uVar6] = '\x01';
            arg = pcVar8->left;
            cVar1 = arg->type->code;
            if ((cVar1 == 0x80c) || (cVar1 == 0x80e)) {
              pcVar5 = tmpl_deduce_from_function_name_argument(pcVar5,type,arg);
              if (pcVar5 == (c1_tmpl_deduction *)0x0) {
                return (c1_tmpl_deduction *)0x0;
              }
            }
            else {
              bVar2 = tmpl_deduce_from_argument_type(pcVar5,type,arg);
              if (bVar2 == 0) {
                return (c1_tmpl_deduction *)0x0;
              }
            }
          }
        }
        arg_type_slot = arg_type_slot + 1;
        uVar6 = uVar6 + 1;
      } while (uVar6 < res->nargs);
    }
  }
  if (((pcVar5->flags & 0x20) != 0) &&
     (cVar3 = tmpl_check_explicit_argument_kinds(pcVar5), cVar3 == '\0')) {
    return (c1_tmpl_deduction *)0x0;
  }
  cVar3 = tmpl_specialize_function(pcVar5);
  return (c1_tmpl_deduction *)(-(uint)(cVar3 != '\0') & (uint)pcVar5);
}

