char __cdecl expr_full_expression_in_eh_state(uint flags)

{
  char cVar1;
  c1_flow_state *pcVar2;
  int iVar3;
  
  if ((flags & 1) != 0) {
    if ((g_flow_state_top != (c1_flow_state *)0x0) && (g_flow_state_top->kind == 0xd)) {
      return '\x01';
    }
    iVar3 = g_flow_operator_depth + 1;
    pcVar2 = g_flow_state_top;
    while( true ) {
      if (((flags & 2) == 0) && (iVar3 == 0)) {
        cVar1 = expr_member_lookup_return_false();
        return cVar1;
      }
      if (pcVar2 == (c1_flow_state *)0x0) break;
      if (pcVar2->kind == 0xd) {
        return '\x01';
      }
      if (pcVar2->kind != 0x3e) {
        return '\0';
      }
      pcVar2 = pcVar2->prev;
      iVar3 = iVar3 + -1;
    }
  }
  return '\0';
}

