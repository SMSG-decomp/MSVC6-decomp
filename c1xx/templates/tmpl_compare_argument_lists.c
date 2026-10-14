byte __thiscall tmpl_compare_argument_lists(c1_tmpl_deduction *deduction,c1_symbol *fn)

{
  c1_u16 cVar1;
  char *pcVar2;
  char *pcVar3;
  c1_type *type;
  c1_type *type2;
  c1_type *pcVar4;
  c1_type *pcVar5;
  byte bVar6;
  char cVar7;
  ushort uVar8;
  int *piVar9;
  int iVar10;
  uint saved_28_2;
  uint saved_24_2;
  int *piVar11;
  c1_deferred_action *pcVar12;
  uint saved_24;
  uint saved_28;
  uint saved_4;
  uint *params_b;
  uint *params_a;
  uint saved_24_3;
  uint saved_28_3;
  
  saved_28 = (uint)fn->type;
  saved_24 = (uint)deduction->tmpl->type;
  if (saved_24 == saved_28) {
    return 1;
  }
  params_a = *(uint **)((saved_24 & -(uint)((*(byte *)saved_24 & 0x80) != 0)) + 8);
  params_b = *(uint **)((-(uint)((*(byte *)saved_28 & 0x80) != 0) & saved_28) + 8);
  deduction->flags = deduction->flags | 0x10;
  bVar6 = fn->kind & 0x1f;
  if ((bVar6 == 0x11) || (bVar6 == 8)) {
    pcVar2 = (char *)*params_a;
    pcVar3 = (char *)*params_b;
    cVar7 = *pcVar2;
    while (cVar7 < '\0') {
      pcVar2 = *(char **)(pcVar2 + 4);
      cVar7 = *pcVar2;
    }
    cVar7 = *pcVar3;
    while (cVar7 < '\0') {
      pcVar3 = *(char **)(pcVar3 + 4);
      cVar7 = *pcVar3;
    }
    if (((*(ushort *)(pcVar3 + 2) ^ *(ushort *)(pcVar2 + 2)) & 0x3e0) != 0) {
      return 0;
    }
  }
  piVar9 = (int *)params_b[3];
  piVar11 = (int *)params_a[3];
  iVar10 = *piVar11;
  if ((iVar10 != *piVar9) || (iVar10 == 0)) {
    return 0;
  }
  type = (c1_type *)piVar11[2];
  type2 = (c1_type *)piVar9[2];
  piVar11 = piVar11 + 2;
  piVar9 = piVar9 + 2;
  cVar1 = type->code;
  do {
    if (cVar1 == 0x80d) {
      return type2->code == 0x80d;
    }
    uVar8 = tmpl_type_find_parameter(type,1,0);
    if (uVar8 == 0) {
      if ((g_compile_flags_cc & 0x200000) != 0) {
        cVar7 = (char)type->code;
        pcVar4 = type;
        while (cVar7 < '\0') {
          pcVar4 = pcVar4->base;
          cVar7 = (char)pcVar4->code;
        }
        cVar7 = (char)type2->code;
        pcVar5 = type2;
        while (cVar7 < '\0') {
          pcVar5 = pcVar5->base;
          cVar7 = (char)pcVar5->code;
        }
        if ((((pcVar4->code & 0x200) != 0) && ((pcVar5->code & 0x200) != 0)) &&
           (((((((pcVar4->extra).cls)->detail).cls)->flags3e & 2) != 0 ||
            ((((((pcVar5->extra).cls)->detail).cls)->flags3e & 2) != 0)))) goto LAB_104a9518;
      }
      if (type != type2) {
        return 0;
      }
    }
    else {
      if (type2 == (c1_type *)0x0) {
        return 0;
      }
LAB_104a9518:
      cVar7 = tmpl_unify_types(deduction,type,type2,'\x01');
      if (cVar7 == '\0') {
        g_deferred_actions_head = (c1_deferred_action *)0x0;
        g_deferred_actions_tail = (c1_deferred_action *)0x0;
        return 0;
      }
    }
    piVar11 = piVar11 + 1;
    piVar9 = piVar9 + 1;
    iVar10 = iVar10 + -1;
    if (iVar10 == 0) {
      saved_28_2 = (uint)type_function_return((c1_type *)saved_24);
      saved_24_2 = (uint)type_function_return((c1_type *)saved_28);
      if (saved_28_2 != saved_24_2) {
        deduction->param_type = (c1_type *)saved_28_2;
        deduction->arg_type = (c1_type *)saved_24_2;
        deduction->specialization = fn;
        cVar7 = tmpl_unify_types(deduction,(c1_type *)saved_28_2,(c1_type *)saved_24_2,'\0');
        pcVar12 = (c1_deferred_action *)g_arenas[5].cur;
        if (cVar7 == '\0') {
          if (g_ms_extensions != '\0') {
            uVar8 = *(ushort *)saved_28_2;
            if ((uVar8 & 0xfff) == 0x10) {
              uVar8 = *(ushort *)saved_24_2;
            }
            else if ((*(ushort *)saved_24_2 & 0xfff) != 0x10) goto LAB_104a96fe;
            if ((uVar8 & 0x110) != 0) goto LAB_104a9665;
          }
LAB_104a96fe:
          g_arenas[5].cur = g_arenas[5].cur + 0x18;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (pcVar12 == (c1_deferred_action *)0x0) {
            pcVar12 = (c1_deferred_action *)0x0;
          }
          else {
            saved_28_3 = (uint)deduction->arg_type;
            saved_24_3 = (uint)deduction->param_type;
            saved_4 = (uint)deduction->specialization;
            *(c1_symbol **)((int)pcVar12 + 4) = deduction->tmpl;
            *(c1_u8 *)((int)pcVar12 + 8) = '\0';
            *(c1_u8 *)((int)pcVar12 + 9) = '\0';
            *(c1_u8 *)((int)pcVar12 + 10) = '\0';
            *(c1_u8 *)((int)pcVar12 + 0xb) = '\0';
            *(uint *)((int)pcVar12 + 0xc) = saved_4;
            *(uint *)((int)pcVar12 + 0x10) = saved_24_3;
            *(uint *)((int)pcVar12 + 0x14) = saved_28_3;
            pcVar12->vtbl = &PTR_tmpl_deferred_report_c2785_104ceea0;
          }
          if (g_deferred_actions_head != (c1_deferred_action *)0x0) {
            g_deferred_actions_tail->next = pcVar12;
            g_deferred_actions_tail = pcVar12;
            return 0;
          }
          g_deferred_actions_head = pcVar12;
          g_deferred_actions_tail = pcVar12;
          return 0;
        }
      }
LAB_104a9665:
      pcVar12 = (c1_deferred_action *)g_arenas[5].cur;
      if (((*(byte *)(saved_28 + 2) ^ *(byte *)(saved_24 + 2)) & 7) != 0) {
        g_arenas[5].cur = g_arenas[5].cur + 0x10;
        if (g_arenas[5].end < g_arenas[5].cur) {
          arena_grow(g_arenas + 5);
        }
        if (pcVar12 == (c1_deferred_action *)0x0) {
          pcVar12 = (c1_deferred_action *)0x0;
        }
        else {
          *(c1_symbol **)((int)pcVar12 + 4) = deduction->tmpl;
          *(c1_u8 *)((int)pcVar12 + 8) = '\0';
          *(c1_u8 *)((int)pcVar12 + 9) = '\0';
          *(c1_u8 *)((int)pcVar12 + 10) = '\0';
          *(c1_u8 *)((int)pcVar12 + 0xb) = '\0';
          *(c1_symbol **)((int)pcVar12 + 0xc) = fn;
          pcVar12->vtbl = &PTR_tmpl_deferred_report_c2901_104ceec4;
        }
        if (g_deferred_actions_head == (c1_deferred_action *)0x0) {
          g_deferred_actions_head = pcVar12;
          g_deferred_actions_tail = pcVar12;
          return 1;
        }
        g_deferred_actions_tail->next = pcVar12;
        g_deferred_actions_tail = pcVar12;
      }
      return 1;
    }
    type = (c1_type *)*piVar11;
    cVar1 = type->code;
    type2 = (c1_type *)*piVar9;
  } while( true );
}

