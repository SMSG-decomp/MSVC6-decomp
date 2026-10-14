c2_symbol * __fastcall
merge_defs_into_web(c2_symbol *prev_candidate,c2_bitset *candidates,c2_bitset *defs,
                   uint32_t *next_web)

{
  c2_symbol *pcVar1;
  c2_ra_candidate *pcVar2;
  c2_bitset_chunk *pcVar3;
  c2_ra_web_cell *pcVar4;
  int iVar5;
  uint32_t uVar6;
  c2_ra_web_cell *cell;
  c2_bitset *bs;
  uint32_t n;
  
  n = *next_web;
  iVar5 = bitset_iter_next(candidates);
  if (iVar5 == -1) {
    *next_web = n;
    return prev_candidate;
  }
  do {
    pcVar1 = g_candidate_symbols[iVar5];
    pcVar1->order_next = prev_candidate;
    if (prev_candidate != (c2_symbol *)0x0) {
      (((prev_candidate->u30).ra)->u10).prev_open = pcVar1;
    }
    pcVar2 = (pcVar1->u30).ra;
    pcVar3 = defs->chunks;
    (pcVar2->u10).prev_open = (c2_symbol *)0x0;
    if (pcVar3 != (c2_bitset_chunk *)0x0) {
      for (pcVar4 = (pcVar2->u0c).webs; pcVar4 != (c2_ra_web_cell *)0x0; pcVar4 = pcVar4->next) {
        uVar6 = bitset_first_common(pcVar4->defs,defs);
        if (uVar6 != 0xffffffff) {
          if (pcVar4 != (c2_ra_web_cell *)0x0) {
            pcVar2->web = uVar6;
            goto LAB_10718a9b;
          }
          break;
        }
      }
    }
    bitset_set(defs,n);
    cell = arena_alloc(4,8);
    bs = bitset_new(6);
    cell->defs = bs;
    bitset_set(bs,n);
    pcVar4 = (pcVar2->u0c).webs;
    (pcVar2->u0c).webs = cell;
    pcVar2->web = n;
    cell->next = pcVar4;
    n = n + 1;
LAB_10718a9b:
    iVar5 = bitset_iter_next((c2_bitset *)0x0);
    prev_candidate = pcVar1;
    if (iVar5 == -1) {
      *next_web = n;
      return pcVar1;
    }
  } while( true );
}

