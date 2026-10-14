char __thiscall ovl_eliminate_worse_candidates(c1_ovl_resolution *res,int reason,int unused)

{
  c1_ovl_candidate *pcVar1;
  c1_ovl_candidate *cand;
  c1_conversion *pcVar2;
  char cVar3;
  int iVar4;
  c1_conversion *conv_a;
  c1_conversion *conv_b;
  int local_c;
  c1_conversion *local_8;
  uint local_4;
  
  res->failure_count = 0;
  local_4 = 0;
  if (res->nargs != 0) {
    local_c = 0;
    do {
      pcVar1 = res->head;
      conv_b = (c1_conversion *)(&pcVar1->conversions->op + local_c);
      ovl_set_failure_reason(res,reason,local_4);
      pcVar2 = conv_b;
      for (pcVar1 = pcVar1->next; pcVar1 != (c1_ovl_candidate *)0x0; pcVar1 = pcVar1->next) {
        conv_a = (c1_conversion *)(&pcVar1->conversions->op + local_c);
        iVar4 = ovl_compare_conversion_sequences(conv_a,conv_b,0);
        local_8 = pcVar2;
        if (iVar4 < 0) {
          if (((byte)conv_a->rank & 0xf0) == 0x40) {
            cVar3 = ovl_candidate_remove(res,pcVar1,(c1_node *)0x0);
          }
          else {
            if ((pcVar1->flags & 0x80) != 0) goto LAB_10419873;
            cVar3 = ovl_candidate_eliminate(res,(int)pcVar1);
          }
          if (cVar3 != '\0') {
            return '\0';
          }
        }
        else if (0 < iVar4) {
          for (cand = res->head; conv_b = conv_a, local_8 = conv_a, cand != pcVar1;
              cand = cand->next) {
            if (((byte)pcVar2->rank & 0xf0) == 0x40) {
              if ((cand->flags & 0x10) != 0) {
                cVar3 = ovl_candidate_remove(res,cand,(c1_node *)0x0);
                goto joined_r0x104a6517;
              }
            }
            else if ((cand->flags & 0x80) == 0) {
              cVar3 = ovl_candidate_eliminate(res,(int)cand);
joined_r0x104a6517:
              if (cVar3 != '\0') {
                return '\0';
              }
            }
          }
        }
LAB_10419873:
        pcVar2 = local_8;
      }
      local_4 = local_4 + 1;
      local_c = local_c + 0x50;
    } while (local_4 < res->nargs);
  }
  return res->live != 0;
}

