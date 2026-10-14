void __cdecl eh_register_named_object_destructor(c1_symbol *sym,c1_type *type)

{
  c1_node *pcVar1;
  int iVar2;
  c1_symbol *cls;
  byte *pbVar3;
  uint mode;
  int flag;
  int do_delete;
  c1_u8 local_24 [4];
  byte local_20 [12];
  c1_symbol *local_14;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  local_24[0] = '\r';
  local_24[1] = '\0';
  local_24[2] = '\0';
  local_24[3] = '\0';
  pbVar3 = local_20;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    pbVar3[0] = 0;
    pbVar3[1] = 0;
    pbVar3[2] = 0;
    pbVar3[3] = 0;
    pbVar3 = pbVar3 + 4;
  }
  if (((g_flow_state_abandoned == '\0') && (g_block_depth != '\0')) && (g_sizeof_depth == 0)) {
    if ((type->code & 0x200) == 0) {
      if (((char)type->code < '\0') && ((type->base->code & 0x200) != 0)) {
        cls = (type->base->extra).cls;
      }
      else {
        cls = (c1_symbol *)0x0;
      }
    }
    else {
      cls = (type->extra).cls;
    }
    if (((cls->flags1 & 0x20) == 0x20) && ((((cls->detail).cls)->implicit_state41 & 0x10) == 0)) {
      local_20[0] = local_20[0] | 3;
      local_14 = sym;
      if (g_eh_unresolved_dtor_class == cls) {
        do_delete = 0;
        flag = 1;
        iVar2 = 3;
        mode = 0;
        pcVar1 = expr_reference_named_entity(sym,0);
        pcVar1 = expr_build_address_of(pcVar1,mode);
        expr_build_destructor_call(cls,pcVar1,iVar2,flag,do_delete);
      }
      else {
        local_8 = g_eh_current_state;
        local_c = g_eh_previous_state;
        local_4 = 0;
        g_eh_state_table[g_eh_current_state].kind = 1;
        g_eh_state_table[g_eh_current_state].cls = (c1_symbol *)0x0;
      }
      g_eh_unresolved_dtor_class = (c1_symbol *)0x0;
      func_check_flow_state_complexity(local_24,0x24);
    }
  }
  return;
}

