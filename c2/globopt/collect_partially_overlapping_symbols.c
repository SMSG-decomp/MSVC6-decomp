c2_bitset * __fastcall collect_partially_overlapping_symbols(int arena)

{
  c2_symbol *pcVar1;
  c2_bitset *bs;
  uint32_t uVar2;
  c2_symbol *pcVar3;
  
  bs = bitset_new(arena);
  uVar2 = bitset_iter_next(g_local_symbol_ids);
  while (uVar2 != 0xffffffff) {
    pcVar3 = symbol_by_id(uVar2);
    pcVar1 = pcVar3->storage;
    if (pcVar1 != pcVar3) {
      if ((pcVar1->offset < pcVar3->offset) ||
         (pcVar3->size + pcVar3->offset < pcVar1->size + pcVar1->offset)) {
        bitset_set(bs,pcVar3->id);
      }
    }
    uVar2 = bitset_iter_next((c2_bitset *)0x0);
  }
  uVar2 = bitset_iter_next(g_global_symbol_ids);
  while (uVar2 != 0xffffffff) {
    pcVar3 = symbol_by_id(uVar2);
    pcVar1 = pcVar3->storage;
    if (pcVar1 != pcVar3) {
      if ((pcVar1->offset < pcVar3->offset) ||
         (pcVar3->size + pcVar3->offset < pcVar1->size + pcVar1->offset)) {
        bitset_set(bs,pcVar3->id);
      }
    }
    uVar2 = bitset_iter_next((c2_bitset *)0x0);
  }
  return bs;
}

