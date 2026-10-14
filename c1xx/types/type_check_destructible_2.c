void __cdecl type_check_destructible_2(c1_symbol *sym)

{
  byte bVar1;
  uint uVar2;
  c1_node *pcVar3;
  int iVar4;
  int iVar5;
  c1_eh_state *pcVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  c1_symbol *local_24;
  c1_u8 local_20 [4];
  byte local_1c [12];
  c1_symbol *local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_20[0] = '\x0e';
  local_20[1] = '\0';
  local_20[2] = '\0';
  local_20[3] = '\0';
  pbVar8 = local_1c;
  for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
    pbVar8[0] = 0;
    pbVar8[1] = 0;
    pbVar8[2] = 0;
    pbVar8[3] = 0;
    pbVar8 = pbVar8 + 4;
  }
  if (g_flow_state_abandoned != '\0') {
    return;
  }
  iVar5 = 0;
  if (sym != (c1_symbol *)0x0) {
    local_1c[0] = sym->flags4 >> 2 & 1 | local_1c[0] & 0xfe;
    uVar2 = type_classify_class_form(sym->type,(int *)&local_24);
    if ((uVar2 & 3) != 0) {
      if (((sym->flags4 & 4) != 0) || ((((local_24->detail).cls)->implicit_state41 & 2) == 0)) {
        local_1c[0] = local_1c[0] | 1;
      }
      if ((local_24->flags1 & 0x20) == 0x20) {
        if ((((((local_24->detail).cls)->implicit_state41 & 0x10) == 0) &&
            (bVar1 = sym->storage & 7, 3 < bVar1)) && (bVar1 < 7)) {
          local_1c[0] = local_1c[0] | 2;
          if (g_eh_unresolved_dtor_class == local_24) {
            iVar7 = 0;
            iVar9 = 1;
            iVar5 = 3;
            uVar2 = 4;
            pcVar3 = expr_reference_named_entity(sym,0);
            pcVar3 = expr_build_address_of(pcVar3,uVar2);
            expr_build_destructor_call(local_24,pcVar3,iVar5,iVar9,iVar7);
            g_eh_unresolved_dtor_class = (c1_symbol *)0x0;
          }
          else {
            if (g_error_count == 0) {
              local_8 = g_eh_current_state;
              local_c = g_eh_previous_state;
              local_4 = 1;
              if ((uVar2 == 2) && (local_4 = iVar5, g_eh_previous_state < g_eh_current_state)) {
                iVar4 = g_eh_current_state << 4;
                pcVar6 = g_eh_state_table;
                iVar9 = g_eh_previous_state;
                iVar7 = g_eh_current_state;
                do {
                  if (*(int *)(pcVar6->pad01 + iVar4 + 3) == 7) {
                    *(undefined4 *)(pcVar6->pad01 + iVar4 + 3) = 1;
                    iVar5 = iVar5 + 1;
                    pcVar6 = g_eh_state_table;
                    iVar9 = g_eh_previous_state;
                  }
                  iVar7 = iVar7 + -1;
                  iVar4 = iVar4 + -0x10;
                  local_4 = iVar5;
                } while (iVar9 < iVar7);
              }
            }
            g_eh_unresolved_dtor_class = (c1_symbol *)0x0;
          }
          goto LAB_10426024;
        }
      }
      else {
        diag_error(0x106,sym);
      }
    }
    local_1c[0] = local_1c[0] & 0xfd;
  }
LAB_10426024:
  if ((g_flow_state_top != (c1_flow_state *)0x0) && (g_flow_state_top->kind == 0xd)) {
    pcVar3 = expr_full_expression_guarded((c1_node *)0x0,2);
    stmt_emit_merged_expression(pcVar3);
  }
  if ((local_1c[0] & 3) != 0) {
    local_10 = sym;
    func_check_flow_state_complexity(local_20,0x20);
  }
  g_brace_init_active = 0;
  g_init_target_is_reference = '\0';
  PTR_104d2c58 = (c1_symbol *)0x0;
  return;
}

