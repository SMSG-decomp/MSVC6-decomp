void __fastcall basic_solve_liveness(c2_function *fn,uint32_t nbits)

{
  c2_edge *pcVar1;
  c2_bitset *b;
  c2_bitvec *vec;
  int iVar2;
  c2_block *pcVar3;
  int local_8;
  c2_cfg *local_4;
  
  vec = bitvec_new(6,nbits);
  local_4 = fn->cfg;
  do {
    local_8 = 0;
    pcVar3 = local_4->last->prev;
    if (pcVar3 == (c2_block *)0x0) {
      return;
    }
    do {
      bitvec_clear_words(vec);
      for (pcVar1 = pcVar3->succs; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_succ) {
        bitvec_or(vec,(c2_bitvec *)pcVar1->to->live_in);
      }
      b = pcVar3->live_out;
      iVar2 = bitvec_equal(vec,(c2_bitvec *)b);
      if (iVar2 == 0) {
        bitvec_copy((c2_bitvec *)b,vec);
        bitvec_transfer_in_kill_gen
                  ((c2_bitvec *)pcVar3->live_in,(c2_bitvec *)pcVar3->ue,vec,
                   (c2_bitvec *)pcVar3->kill,&local_8);
      }
      pcVar3 = pcVar3->prev;
    } while (pcVar3 != (c2_block *)0x0);
  } while (local_8 != 0);
  return;
}

