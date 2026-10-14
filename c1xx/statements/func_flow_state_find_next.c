c1_flow_state * __cdecl
func_flow_state_find_next(c1_flow_state *rec,int kind,char longjmp_if_missing)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if ((kind < 0xf) || (0x36 < kind)) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(g_token_op_flags + (kind & 0xffU) * 4 + 0xc4);
  }
  for (; rec != (c1_flow_state *)0x0; rec = rec->next) {
    if (rec->kind == kind) {
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) {
        return rec;
      }
    }
    else if (rec->kind == iVar1) {
      iVar2 = iVar2 + 1;
    }
  }
  if ((longjmp_if_missing != '\0') && (g_flow_error_jmpbuf != (void *)0x0)) {
    func_flow_state_reset();
    g_flow_state_abandoned = '\x01';
    longjmp(g_flow_error_jmpbuf,-1);
  }
  return (c1_flow_state *)0x0;
}

