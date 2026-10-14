void __fastcall relax_branches_iterate(c2_function *fn)

{
  char cVar1;
  uint8_t uVar2;
  c2_tuple *pcVar3;
  int iVar4;
  char pass;
  c2_fe_symbol *pcVar5;
  c2_fe_symbol *pcVar6;
  uint32_t offset_after_branch;
  int growth_this_pass;
  c2_tuple *local_14;
  int local_10;
  c2_fe_symbol *local_c;
  c2_cfg *local_8;
  c2_fe_symbol *local_4;
  
  pcVar6 = fn->fsym;
  local_c = pcVar6;
  local_4 = fe_symbol_lookup_id(pcVar6->section_id);
  local_8 = fn->cfg;
  pcVar5 = (c2_fe_symbol *)0x0;
  pass = '\0';
  do {
    pass = pass + '\x01';
    offset_after_branch = pcVar6->offset;
    growth_this_pass = 0;
    local_10 = 0;
    local_14 = local_8->first->head;
    pcVar6 = pcVar5;
    if (local_14 == (c2_tuple *)0x0) {
      return;
    }
    do {
      uVar2 = local_14->kind;
      pcVar3 = local_14->next;
      pcVar5 = local_4;
      if ((uVar2 != '\x17') && (pcVar5 = pcVar6, uVar2 != '\x16')) {
        if ((local_14->flags & 1) == 0) {
          if (uVar2 == '\x1a') {
            cVar1 = *(char *)&local_14->src[1].next;
            if ((cVar1 == 'T') || (cVar1 == 'U')) {
              pcVar6 = g_ehtext_section;
            }
            local_14->src->rank = offset_after_branch;
            *(char *)(*(int *)((int)&local_14->src[1].next + 2) + 0x12) = pass;
          }
        }
        else {
          offset_after_branch = offset_after_branch + local_14->flags12;
        }
        pcVar5 = pcVar6;
        if (local_14->kind == '\x11') {
          iVar4 = relax_widen_branch(&local_14,offset_after_branch,pass,growth_this_pass,pcVar6);
          growth_this_pass = growth_this_pass + iVar4;
          offset_after_branch = offset_after_branch + iVar4;
          if ((iVar4 != 0) && (local_10 == 0)) {
            local_10 = 1;
          }
        }
      }
      local_14 = pcVar3;
      pcVar6 = pcVar5;
    } while (pcVar3 != (c2_tuple *)0x0);
    pcVar6 = local_c;
  } while (local_10 != 0);
  return;
}

