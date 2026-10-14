void __fastcall free_dominators(c2_function *fn)

{
  c2_block *pcVar1;
  
  for (pcVar1 = fn->cfg->first; pcVar1 != (c2_block *)0x0; pcVar1 = pcVar1->next) {
    if (pcVar1->dominators != (c2_bitvec *)0x0) {
      bitset_header_free(pcVar1->dominators);
      pcVar1->dominators = (c2_bitvec *)0x0;
    }
  }
  return;
}

