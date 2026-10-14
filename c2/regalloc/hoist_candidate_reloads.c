void __fastcall hoist_candidate_reloads(c2_function *fn)

{
  short sVar1;
  c2_block *block;
  c2_edge *pcVar2;
  c2_edge *pcVar3;
  c2_block *pcVar4;
  c2_symbol *sym;
  c2_bitset *bs;
  c2_bitset *dst;
  uint32_t uVar5;
  int iVar6;
  uint32_t uVar7;
  c2_tuple *pcVar8;
  c2_bitset *bs_00;
  c2_bitset *pcStack_18;
  c2_bitvec *local_10;
  uint32_t uStack_8;
  
  local_10 = (c2_bitvec *)0x0;
  dst = bitset_new(6);
  block = fn->cfg->last;
  do {
    if (block == (c2_block *)0x0) {
      bitset_free(dst);
      return;
    }
    pcVar2 = block->preds;
    if (pcVar2 != (c2_edge *)0x0) {
      pcVar3 = pcVar2->next_pred;
      while (pcVar3 != (c2_edge *)0x0) {
        sVar1 = block->rpo;
        pcVar4 = pcVar2->from;
        if (pcVar4->rpo < sVar1) {
          bitset_copy(dst,block->live_in);
          bitset_andnot(dst,pcVar4->live_out);
          if (dst->chunks != (c2_bitset_chunk *)0x0) {
            if (local_10 == (c2_bitvec *)0x0) {
              local_10 = bitvec_clone(block->dominators);
            }
            else {
              bitvec_copy(local_10,block->dominators);
            }
            bitvec_and(local_10,pcVar4->dominators);
            uVar5 = bitvec_iter_next(local_10);
            while (uVar7 = uVar5, uVar7 != 0xffffffff) {
              uVar5 = bitvec_iter_next((c2_bitvec *)0x0);
              uStack_8 = uVar7;
            }
            if ((short)uStack_8 < sVar1) {
              for (pcVar4 = block->prev;
                  (pcVar4 != (c2_block *)0x0 && (pcVar4->rpo != (short)uStack_8));
                  pcVar4 = pcVar4->prev) {
              }
              pcVar8 = pcVar4->end->prev;
              if (((pcVar8->kind == '\x11') && (pcVar8->prev->kind == '\x19')) &&
                 (pcVar8->src->next != (c2_operand *)0x0)) {
                hoist_candidate_reloads_part(block,pcVar4->prev);
                return;
              }
              bs_00 = (c2_bitset *)0x0;
              pcStack_18 = (c2_bitset *)0x0;
              uVar5 = bitset_iter_next(dst);
              if (uVar5 != 0xffffffff) {
                do {
                  sym = g_candidate_symbols[uVar5];
                  if ((sym->cls == '\r') ||
                     (iVar6 = reload_hoist_path_clear(uVar5,block,pcVar4), iVar6 != 0)) {
                    if (bs_00 == (c2_bitset *)0x0) {
                      bs_00 = bitset_new(6);
                      pcStack_18 = bs_00;
                    }
                    bitset_set(bs_00,uVar5);
                    bs = pcVar4->live_out;
                    uVar7 = bitset_test(bs,uVar5);
                    bs_00 = pcStack_18;
                    if (uVar7 == 0) {
                      bitset_set(bs,uVar5);
                      bitset_set(pcVar4->kill,uVar5);
                      bitset_set(pcVar4->de,uVar5);
                      pcVar8 = find_block_exit_insert_point(pcVar4,sym,fn);
                      insert_live_range_reload(sym,&g_register_candidate_home,pcVar8);
                    }
                  }
                  uVar5 = bitset_iter_next((c2_bitset *)0x0);
                } while (uVar5 != 0xffffffff);
                if (bs_00 != (c2_bitset *)0x0) {
                  liveness_extend_to_preds(bs_00,block,pcVar4);
                  bitset_free(bs_00);
                }
              }
            }
          }
        }
        pcVar2 = pcVar2->next_pred;
        pcVar3 = pcVar2;
      }
    }
    block = block->prev;
  } while( true );
}

