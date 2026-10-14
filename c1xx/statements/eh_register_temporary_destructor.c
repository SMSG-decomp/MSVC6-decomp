void __cdecl eh_register_temporary_destructor(c1_node *node,c1_type *type)

{
  c1_symbol *cls;
  int iVar1;
  byte *pbVar2;
  c1_u8 local_24 [4];
  byte local_20 [12];
  c1_node *local_14;
  uint context;
  int local_8;
  int type_flags;
  
  local_24[0] = '\r';
  local_24[1] = '\0';
  local_24[2] = '\0';
  local_24[3] = '\0';
  pbVar2 = local_20;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    pbVar2[0] = 0;
    pbVar2[1] = 0;
    pbVar2[2] = 0;
    pbVar2[3] = 0;
    pbVar2 = pbVar2 + 4;
  }
  if (((g_flow_state_abandoned == '\0') && (g_sizeof_depth == 0)) && (type != (c1_type *)0x0)) {
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
      local_20[0] = local_20[0] & 0xfc;
      local_14 = node;
      if (g_eh_unresolved_dtor_class == cls) {
        expr_build_destructor_call(cls,node,3,1,0);
      }
      else {
        context = g_eh_previous_state;
        local_8 = g_eh_current_state;
        type_flags = 0;
        g_eh_state_table[g_eh_current_state].kind = 6;
        g_eh_state_table[g_eh_current_state].cls = (c1_symbol *)0x0;
      }
      g_eh_unresolved_dtor_class = (c1_symbol *)0x0;
      func_check_flow_state_complexity(local_24,0x24);
    }
  }
  return;
}

