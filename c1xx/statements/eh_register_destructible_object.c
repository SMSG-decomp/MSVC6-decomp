void __cdecl eh_register_destructible_object(c1_symbol *sym,byte flag)

{
  c1_symbol *cls;
  c1_node *pcVar1;
  int iVar2;
  byte *pbVar3;
  uint mode;
  int flag_00;
  int do_delete;
  c1_symbol *sym_00;
  c1_u8 local_20 [4];
  byte local_1c;
  byte local_1b;
  c1_symbol *local_10;
  uint context;
  int local_8;
  int type_flags;
  
  if ((((sym->type->code & 0x200) != 0) &&
      (cls = (sym->type->extra).cls, (cls->flags1 & 0x20) == 0x20)) &&
     ((((cls->detail).cls)->implicit_state41 & 0x10) == 0)) {
    local_20[0] = '\x05';
    local_20[1] = '\0';
    local_20[2] = '\0';
    local_20[3] = '\0';
    do_delete = 0;
    pbVar3 = &local_1c;
    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
      pbVar3[0] = 0;
      pbVar3[1] = 0;
      pbVar3[2] = 0;
      pbVar3[3] = 0;
      pbVar3 = pbVar3 + 4;
    }
    flag_00 = 1;
    iVar2 = 3;
    mode = 4;
    local_1c = local_1c | 2;
    local_10 = sym;
    g_eh_context_kind = 5;
    sym_00 = cls;
    pcVar1 = expr_reference_named_entity(sym,0);
    pcVar1 = expr_build_address_of(pcVar1,mode);
    pcVar1 = expr_build_destructor_call(cls,pcVar1,iVar2,flag_00,do_delete);
    pcVar1 = expr_build_eh_state_update((c1_node *)0x0,pcVar1,sym_00);
    stmt_emit_expression(pcVar1);
    context = g_eh_previous_state;
    local_8 = g_eh_current_state;
    local_1b = local_1b ^ (local_1b ^ flag) & 1;
    type_flags = 1;
    g_eh_context_kind = 1;
    g_eh_state_table[g_eh_current_state].kind = 1;
    func_check_flow_state_complexity(local_20,0x20);
  }
  return;
}

