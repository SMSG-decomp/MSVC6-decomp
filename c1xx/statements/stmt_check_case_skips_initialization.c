void __cdecl stmt_check_case_skips_initialization(int is_case)

{
  int iVar1;
  c1_flow_state *pcVar2;
  short n;
  void *pvVar3;
  
  iVar1 = g_flow_state_top->kind;
  pcVar2 = g_flow_state_top;
  while (iVar1 != 0x34) {
    if (pcVar2->kind == 0xe) {
      if ((pcVar2->flags & 1) != 0) {
        if (is_case == 0) {
          pvVar3 = pcVar2->subject;
          n = 0x169;
        }
        else {
          pvVar3 = pcVar2->subject;
          n = 0x168;
        }
        diag_error(n,pvVar3);
      }
    }
    else if (pcVar2->kind == 0x10) {
      pcVar2 = func_flow_state_find(pcVar2->prev,0xf,'\x01');
    }
    pcVar2 = pcVar2->prev;
    iVar1 = pcVar2->kind;
  }
  return;
}

