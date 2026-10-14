c1_flow_state * __cdecl func_flow_state_skip_kind_d(c1_flow_state *rec)

{
  int iVar1;
  
  iVar1 = rec->kind;
  while (iVar1 == 0xd) {
    rec = rec->next;
    iVar1 = rec->kind;
  }
  return rec;
}

