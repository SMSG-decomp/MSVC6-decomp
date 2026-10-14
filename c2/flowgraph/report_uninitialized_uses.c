void __fastcall report_uninitialized_uses(c2_function *fn,c2_bitset *set,int n,int check_paths)

{
  c2_block *b;
  c2_bitset *dst;
  int iVar1;
  
  b = fn->cfg->first;
  do {
    if (b == (c2_block *)0x0) {
      if ((set->chunks != (c2_bitset_chunk *)0x0) &&
         (iVar1 = warning_state_lookup(0x2bd), iVar1 <= g_opt_warning_level)) {
        warn_uninit_check_candidates(fn,set,n);
      }
      return;
    }
    if ((b->flags & 1) != 0) {
      dst = b->ue;
      bitset_and(dst,set);
      if ((dst->chunks != (c2_bitset_chunk *)0x0) &&
         (bitset_andnot(dst,b->live_in), dst->chunks != (c2_bitset_chunk *)0x0)) {
        warn_uninit_scan_uses(fn,b,dst,set,check_paths);
      }
      if (set->chunks == (c2_bitset_chunk *)0x0) {
        return;
      }
    }
    b = b->next;
  } while( true );
}

