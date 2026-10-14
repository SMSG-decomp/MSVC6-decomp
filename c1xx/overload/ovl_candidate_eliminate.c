char __thiscall ovl_candidate_eliminate(void *ctx,int cand)

{
  int iVar1;
  
  if ((*(byte *)(cand + 0x3c) & 0x80) == 0) {
    *(byte *)(cand + 0x3c) = *(byte *)(cand + 0x3c) | 0x80;
    iVar1 = *(int *)((int)ctx + 0xc) + -1;
    *(int *)((int)ctx + 0xc) = iVar1;
    if (iVar1 == 0) {
      ovl_report_call_failure(ctx,(c1_ovl_candidate *)cand,(c1_node *)0x0);
      return '\x01';
    }
  }
  return '\0';
}

