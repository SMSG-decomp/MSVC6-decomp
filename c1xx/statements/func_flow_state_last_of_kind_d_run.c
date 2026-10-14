c1_flow_state * __cdecl func_flow_state_last_of_kind_d_run(c1_flow_state *rec)

{
  int iVar1;
  c1_flow_state *pcVar2;
  c1_flow_state *pcVar3;
  
  iVar1 = rec->prev->kind;
  pcVar2 = rec->prev;
  while (pcVar3 = pcVar2, iVar1 == 0xd) {
    pcVar2 = pcVar3->prev;
    iVar1 = pcVar2->kind;
    rec = pcVar3;
  }
  return rec;
}

