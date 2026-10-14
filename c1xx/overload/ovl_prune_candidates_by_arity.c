char __thiscall ovl_prune_candidates_by_arity(void *ctx,void *node)

{
  c1_ovl_candidate *cand;
  c1_type *pcVar1;
  char cVar2;
  uint uVar3;
  
  ovl_set_failure_reason(ctx,1,0);
  for (cand = *(c1_ovl_candidate **)((int)ctx + 0x18);
      (cand != (c1_ovl_candidate *)0x0 && ((cand->flags & 4) == 0)); cand = cand->next) {
    pcVar1 = cand->function->type;
    if ((cand->flags & 2) == 0) {
      uVar3 = *(uint *)((int)ctx + 0x10);
    }
    else {
      uVar3 = *(int *)((int)ctx + 0x10) - 1;
    }
    uVar3 = type_function_arity_match
                      ((c1_type *)((uint)pcVar1 & -(uint)((pcVar1->code & 0x80) != 0)),uVar3);
    if (-1 < (int)uVar3) {
      if ((int)uVar3 < 2) {
        cVar2 = ovl_candidate_remove(ctx,cand,node);
        if (cVar2 != '\0') {
          return '\0';
        }
      }
      else if (uVar3 == 3) {
        cand->flags = cand->flags | 0x10;
      }
    }
  }
  return '\x01';
}

