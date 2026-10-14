void __fastcall init_block_register_sets(c2_function *fn)

{
  c2_block *pcVar1;
  c2_bitset *pcVar2;
  
  for (pcVar1 = fn->cfg->first; pcVar1 != (c2_block *)0x0; pcVar1 = pcVar1->next) {
    pcVar2 = bitset_clone(pcVar1->live_in);
    pcVar1->live = pcVar2;
    pcVar2 = bitset_new(8);
    pcVar1->set24 = pcVar2;
    pcVar2 = bitset_new(8);
    pcVar1->set28 = pcVar2;
    pcVar2 = bitset_new(6);
    pcVar1->set4c = pcVar2;
    g_ra_block_count = g_ra_block_count + 1;
  }
  return;
}

