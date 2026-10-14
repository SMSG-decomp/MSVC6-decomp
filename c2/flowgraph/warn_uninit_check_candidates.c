void __fastcall warn_uninit_check_candidates(c2_function *fn,c2_bitset *cands,int n)

{
  uint32_t n_00;
  uint32_t *cand_by_root;
  c2_bitset *bs;
  int iVar1;
  
  cand_by_root = arena_alloc(4,n * 4 + 4);
  bs = bitset_new(6);
  iVar1 = bitset_iter_next(cands);
  while (iVar1 != -1) {
    if ((g_uninit_local_symbols[iVar1]->storage->fe->storage & 0x10000) == 0) {
      n_00 = (g_uninit_local_symbols[iVar1]->storage->u30).local_number;
      bitset_set(bs,n_00);
      *(c2_symbol_u30 *)(cand_by_root + n_00) = g_uninit_local_symbols[iVar1]->u30;
    }
    iVar1 = bitset_iter_next((c2_bitset *)0x0);
  }
  iVar1 = bitset_iter_next(bs);
  while (iVar1 != -1) {
    clear_block_flag18_bit1(fn);
    warn_uninit_scan_block(fn,fn->cfg->first,cand_by_root[iVar1]);
    iVar1 = bitset_iter_next((c2_bitset *)0x0);
  }
  bitset_free(bs);
  return;
}

