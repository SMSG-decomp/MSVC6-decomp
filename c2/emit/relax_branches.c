void __fastcall relax_branches(c2_function *fn)

{
  char cVar1;
  uint8_t uVar2;
  c2_tuple *pcVar3;
  c2_fe_symbol *pcVar4;
  int iVar5;
  char pass;
  c2_fe_symbol *pcVar6;
  c2_fe_symbol *pcVar7;
  uint32_t offset_after_branch;
  int growth_this_pass;
  c2_tuple *pcStack_14;
  int iStack_10;
  c2_fe_symbol *pcStack_c;
  c2_cfg *pcStack_8;
  
  pcStack_8 = (c2_cfg *)0x1073df8c;
  relax_init_sizes(fn);
  pcStack_8 = (c2_cfg *)0x1073df95;
  assign_code_offsets(fn,0);
  pcVar7 = fn->fsym;
  pcStack_c = pcVar7;
  pcVar4 = fe_symbol_lookup_id(pcVar7->section_id);
  pcStack_8 = fn->cfg;
  pcVar6 = (c2_fe_symbol *)0x0;
  pass = '\0';
  do {
    pass = pass + '\x01';
    offset_after_branch = pcVar7->offset;
    growth_this_pass = 0;
    iStack_10 = 0;
    pcStack_14 = pcStack_8->first->head;
    pcVar7 = pcVar6;
    if (pcStack_14 == (c2_tuple *)0x0) {
      return;
    }
    do {
      uVar2 = pcStack_14->kind;
      pcVar3 = pcStack_14->next;
      pcVar6 = pcVar4;
      if ((uVar2 != '\x17') && (pcVar6 = pcVar7, uVar2 != '\x16')) {
        if ((pcStack_14->flags & 1) == 0) {
          if (uVar2 == '\x1a') {
            cVar1 = *(char *)&pcStack_14->src[1].next;
            if ((cVar1 == 'T') || (cVar1 == 'U')) {
              pcVar7 = g_ehtext_section;
            }
            pcStack_14->src->rank = offset_after_branch;
            *(char *)(*(int *)((int)&pcStack_14->src[1].next + 2) + 0x12) = pass;
          }
        }
        else {
          offset_after_branch = offset_after_branch + pcStack_14->flags12;
        }
        pcVar6 = pcVar7;
        if (pcStack_14->kind == '\x11') {
          iVar5 = relax_widen_branch(&pcStack_14,offset_after_branch,pass,growth_this_pass,pcVar7);
          growth_this_pass = growth_this_pass + iVar5;
          offset_after_branch = offset_after_branch + iVar5;
          if ((iVar5 != 0) && (iStack_10 == 0)) {
            iStack_10 = 1;
          }
        }
      }
      pcStack_14 = pcVar3;
      pcVar7 = pcVar6;
    } while (pcVar3 != (c2_tuple *)0x0);
    pcVar7 = pcStack_c;
  } while (iStack_10 != 0);
  return;
}

