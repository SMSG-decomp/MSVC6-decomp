c2_bitvec ** __fastcall basic_solve_resume_dataflow(c2_function *fn,uint32_t nsites,uint32_t nbits)

{
  ushort uVar1;
  c2_cfg *pcVar2;
  c2_tuple *pcVar3;
  c2_bitset *pcVar4;
  c2_edge *pcVar5;
  bool bVar6;
  c2_bitvec **rows;
  c2_bitvec *pcVar7;
  int iVar8;
  c2_bitvec **ppcVar9;
  c2_block *pcVar10;
  int local_c;
  int local_8;
  uint32_t local_4;
  c2_tuple *walk;
  c2_block *resume_block;
  
  local_4 = nsites;
  rows = arena_alloc(4,nsites << 2);
  pcVar2 = fn->cfg;
  for (pcVar3 = pcVar2->first->head; pcVar3 != (c2_tuple *)0x0; pcVar3 = pcVar3->next) {
    if ((pcVar3->op == 0x18b) &&
       (uVar1._0_1_ = pcVar3->flags12, uVar1._1_1_ = pcVar3->flags13, uVar1 != 0)) {
      for (walk = *(c2_tuple **)((int)&pcVar3->src->sym->u30 + 2);
          (walk->kind != '\x19' || ((walk->u14).arg == (void *)0x0)); walk = walk->prev) {
      }
      resume_block = (walk->u14).block;
      resume_block->flags = resume_block->flags | 1;
      rows[uVar1] = (c2_bitvec *)resume_block->live_in;
    }
  }
  pcVar7 = bitvec_new(6,nbits);
  do {
    for (pcVar10 = pcVar2->first; pcVar10 != (c2_block *)0x0; pcVar10 = pcVar10->next) {
      pcVar4 = pcVar10->ue;
      bitvec_or_selected_rows((c2_bitvec *)pcVar4,(c2_bitvec *)(pcVar10->avail_in).set,rows);
      bitvec_or((c2_bitvec *)pcVar10->live_in,(c2_bitvec *)pcVar4);
    }
    local_8 = 0;
    do {
      bVar6 = false;
      pcVar10 = pcVar2->last->prev;
      if (pcVar10 == (c2_block *)0x0) break;
      do {
        bitvec_clear_words(pcVar7);
        for (pcVar5 = pcVar10->succs; pcVar5 != (c2_edge *)0x0; pcVar5 = pcVar5->next_succ) {
          bitvec_or(pcVar7,(c2_bitvec *)pcVar5->to->live_in);
        }
        pcVar4 = pcVar10->live_out;
        iVar8 = bitvec_equal(pcVar7,(c2_bitvec *)pcVar4);
        if (iVar8 == 0) {
          bitvec_copy((c2_bitvec *)pcVar4,pcVar7);
          local_c = 0;
          bitvec_transfer_in_kill_gen
                    ((c2_bitvec *)pcVar10->live_in,(c2_bitvec *)pcVar10->ue,pcVar7,
                     (c2_bitvec *)pcVar10->kill,&local_c);
          if ((local_c != 0) && (bVar6 = true, (pcVar10->flags & 1) != 0)) {
            local_8 = 1;
          }
        }
        pcVar10 = pcVar10->prev;
      } while (pcVar10 != (c2_block *)0x0);
    } while (bVar6);
    if (local_8 == 0) {
      if (local_4 < 2) {
        return rows;
      }
      iVar8 = local_4 - 1;
      ppcVar9 = rows;
      do {
        ppcVar9 = ppcVar9 + 1;
        pcVar7 = bitvec_clone(*ppcVar9);
        *ppcVar9 = pcVar7;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      return rows;
    }
  } while( true );
}

