c2_tuple * __fastcall sched_region_end(c2_tuple *t)

{
  uint8_t uVar1;
  c2_tuple *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (t->op == 0x1b5) {
    t = t->next;
  }
  pcVar2 = t;
  for (iVar4 = 0; (pcVar2 != (c2_tuple *)0x0 && (iVar4 < 0x51)); iVar4 = iVar4 + 1) {
    switch(pcVar2->kind) {
    case '\x11':
    case '\x13':
    case '\x1a':
      goto switchD_1073a754_caseD_11;
    case '\x16':
      if (pcVar2->op == 0x1b5) goto switchD_1073a754_caseD_18;
      break;
    case '\x18':
      goto switchD_1073a754_caseD_18;
    }
    pcVar2 = pcVar2->next;
  }
  if (g_sched_fp_mode != 0) {
    iVar4 = 0;
    iVar5 = 0;
    pcVar2 = t;
    while( true ) {
      if (pcVar2 == (c2_tuple *)0x0) {
        return t;
      }
      uVar1 = pcVar2->kind;
      if (uVar1 == '\x11') {
        return pcVar2;
      }
      if (uVar1 == '\x16') {
        if (pcVar2->op == 0x1b5) {
          return pcVar2->prev;
        }
      }
      else {
        if (uVar1 == '\x1a') {
          return pcVar2;
        }
        iVar3 = x87_stack_effect(pcVar2);
        iVar4 = iVar4 + iVar3;
      }
      if ((0x4f < iVar5) && (iVar4 == 0)) break;
      pcVar2 = pcVar2->next;
      iVar5 = iVar5 + 1;
    }
    return pcVar2;
  }
switchD_1073a754_caseD_18:
  pcVar2 = pcVar2->prev;
switchD_1073a754_caseD_11:
  return pcVar2;
}

