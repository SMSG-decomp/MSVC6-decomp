int * __thiscall ovl_select_best_candidate(void *ctx,byte *ambiguous_out,void *fallback)

{
  char cVar1;
  c1_ovl_candidate *pcVar2;
  int *piVar3;
  
  if (*(int *)((int)ctx + 0xc) == 0) {
    return (int *)0x0;
  }
  if (*(int *)((int)ctx + 0xc) != 1) {
    cVar1 = ovl_eliminate_worse_candidates(ctx,4,1);
    if (cVar1 == '\0') {
      piVar3 = (int *)ovl_report_ambiguous_flag((char *)ambiguous_out);
      return piVar3;
    }
  }
  if (*(int *)((int)ctx + 0xc) == 1) {
    pcVar2 = (c1_ovl_candidate *)ovl_first_live_candidate((int)ctx);
  }
  else {
    pcVar2 = ovl_reeliminate_survivors(ctx);
    if (pcVar2 == (c1_ovl_candidate *)0x0) {
      pcVar2 = ovl_prefer_by_object_qualifier(ctx);
      if ((pcVar2 == (c1_ovl_candidate *)0x0) && (fallback != (void *)0x0)) {
        pcVar2 = (c1_ovl_candidate *)(*fallback)();
        if ((pcVar2 == (c1_ovl_candidate *)0x0) && (ambiguous_out != (byte *)0x0)) {
          *ambiguous_out = 1;
          return (int *)0x0;
        }
      }
      else if (ambiguous_out != (byte *)0x0) {
        *ambiguous_out = 1;
        return (int *)pcVar2;
      }
    }
    else if (ambiguous_out != (byte *)0x0) {
      *ambiguous_out = 1;
      return (int *)pcVar2;
    }
  }
  return (int *)pcVar2;
}

