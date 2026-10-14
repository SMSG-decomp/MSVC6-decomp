c1_flow_state * __cdecl func_flow_state_find(c1_flow_state *rec,int kind,char longjmp_if_missing)

{
  int iVar1;
  c1_flow_state *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 1;
  if ((kind < 0xf) || (0x36 < kind)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(g_token_op_flags + (kind & 0xffU) * 4 + 0xc4);
  }
  if (rec == (c1_flow_state *)0x0) {
    pcVar2 = func_flow_state_find_not_found(longjmp_if_missing);
    return pcVar2;
  }
  do {
    iVar1 = rec->kind;
    if (iVar1 == 1) {
      if (kind == 1) {
        return rec;
      }
      break;
    }
    if (iVar1 == kind) {
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) {
        return rec;
      }
    }
    else if (iVar1 == iVar3) {
      iVar4 = iVar4 + 1;
    }
    rec = rec->prev;
  } while (rec != (c1_flow_state *)0x0);
  if ((longjmp_if_missing != '\0') && (g_flow_error_jmpbuf != (void *)0x0)) {
    func_flow_state_reset();
    g_flow_state_abandoned = '\x01';
    longjmp(g_flow_error_jmpbuf,-1);
  }
  return (c1_flow_state *)0x0;
}

