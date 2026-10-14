void __fastcall
switch_case_stats(c2_switch_case_range *cases,int ncases,int *values_covered,uint32_t *span,
                 int *ncmp)

{
  uint32_t uVar1;
  int iVar2;
  uint32_t uVar3;
  uint uVar4;
  uint uVar5;
  c2_switch_case_range *pcVar6;
  
  *span = cases->first;
  span[1] = cases->first_high;
  *values_covered = 0;
  *ncmp = 0;
  pcVar6 = (c2_switch_case_range *)0x0;
  for (; ncases != 0; ncases = ncases + -1) {
    iVar2 = *ncmp;
    *values_covered = *values_covered + (cases->last - cases->first) + 1;
    uVar3 = cases->last;
    uVar1 = cases->first;
    *ncmp = iVar2 + 1;
    if ((uVar3 != uVar1) || (cases->last_high != cases->first_high)) {
      *ncmp = iVar2 + 2;
    }
    pcVar6 = cases;
    cases = cases->next;
  }
  uVar4 = pcVar6->last;
  uVar5 = *span;
  iVar2 = pcVar6->last_high;
  *span = uVar4 - uVar5;
  span[1] = (iVar2 - span[1]) - (uint)(uVar4 < uVar5);
  return;
}

