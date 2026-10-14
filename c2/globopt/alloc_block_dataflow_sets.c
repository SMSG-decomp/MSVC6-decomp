void __fastcall alloc_block_dataflow_sets(c2_function *fn,uint32_t mode)

{
  c2_bitset *pcVar1;
  c2_block *pcVar2;
  
  arena_reset(6);
  pcVar2 = fn->cfg->first;
  if (pcVar2 != (c2_block *)0x0) {
    do {
      if ((mode & 1) == 0) {
        pcVar2->set24 = (c2_bitset *)0x0;
        pcVar2->set28 = (c2_bitset *)0x0;
        pcVar2->de = (c2_bitset *)0x0;
        pcVar2->ue = (c2_bitset *)0x0;
        pcVar2->kill = (c2_bitset *)0x0;
        (pcVar2->avail_in).set = (c2_bitset *)0x0;
        (pcVar2->avail_out).set = (c2_bitset *)0x0;
        pcVar2->live_in = (c2_bitset *)0x0;
      }
      else {
        pcVar1 = bitset_new(6);
        pcVar2->set24 = pcVar1;
        pcVar1 = bitset_new(6);
        pcVar2->set28 = pcVar1;
        pcVar1 = bitset_new(6);
        pcVar2->de = pcVar1;
        pcVar1 = bitset_new(6);
        pcVar2->ue = pcVar1;
        pcVar1 = bitset_new(6);
        pcVar2->kill = pcVar1;
        pcVar1 = bitset_new(6);
        (pcVar2->avail_in).set = pcVar1;
        pcVar1 = bitset_new(6);
        (pcVar2->avail_out).set = pcVar1;
        pcVar1 = bitset_new(6);
        pcVar2->live_in = pcVar1;
      }
      if ((mode & 4) == 0) {
        pcVar2->live_out = (c2_bitset *)0x0;
        pcVar2->live = (c2_bitset *)0x0;
        pcVar2->set4c = (c2_bitset *)0x0;
        pcVar2->set50 = (c2_bitset *)0x0;
        pcVar2->set54 = (c2_bitset *)0x0;
        (pcVar2->u58).x87_stack = (c2_x87_block_stack *)0x0;
        pcVar2->set5c = (c2_bitset *)0x0;
      }
      else {
        pcVar1 = bitset_new(6);
        pcVar2->live_out = pcVar1;
        pcVar1 = bitset_new(6);
        pcVar2->live = pcVar1;
        pcVar1 = bitset_new(6);
        pcVar2->set4c = pcVar1;
        pcVar1 = bitset_new(6);
        pcVar2->set50 = pcVar1;
        pcVar1 = bitset_new(6);
        pcVar2->set54 = pcVar1;
        pcVar1 = bitset_new(6);
        (pcVar2->u58).set = pcVar1;
        pcVar1 = bitset_new(6);
        pcVar2->set5c = pcVar1;
      }
      pcVar2 = pcVar2->next;
    } while (pcVar2 != (c2_block *)0x0);
  }
  return;
}

