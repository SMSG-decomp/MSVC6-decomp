void prune_unexposed_alias_members(void)

{
  c2_symbol *pcVar1;
  c2_ra_candidate *pcVar2;
  c2_ra_candidate *pcVar3;
  c2_ra_candidate *pcVar4;
  
  for (pcVar1 = g_alias_scope_symbols; pcVar1 != (c2_symbol *)0x0; pcVar1 = pcVar1->order_next) {
    pcVar3 = (pcVar1->u30).ra;
    pcVar2 = (c2_ra_candidate *)&pcVar1->u30;
    while (pcVar4 = pcVar3, pcVar4 != (c2_ra_candidate *)0x0) {
      if ((pcVar4->part_ids->pad_05[0] & 4) == 0) {
        pcVar2->id = pcVar4->id;
        pcVar4 = pcVar2;
      }
      pcVar2 = pcVar4;
      pcVar3 = (c2_ra_candidate *)pcVar4->id;
    }
  }
  return;
}

