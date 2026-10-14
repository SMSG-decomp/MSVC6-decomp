void hoist_candidate_reloads_part(c2_block *block,c2_block *block2)

{
  short sVar1;
  c2_edge *pcVar2;
  c2_block *pcVar3;
  c2_symbol *sym;
  c2_bitset *bs;
  uint32_t uVar4;
  int iVar5;
  uint32_t uVar6;
  c2_tuple *pcVar7;
  c2_bitset *bs_00;
  c2_block *in_stack_00000010;
  c2_bitset *pcStack00000014;
  c2_bitset *in_stack_00000018;
  c2_bitvec *in_stack_0000001c;
  c2_edge *in_stack_00000020;
  uint32_t in_stack_00000024;
  c2_function *in_stack_00000028;
  
  do {
    bs_00 = (c2_bitset *)0x0;
    pcStack00000014 = (c2_bitset *)0x0;
    uVar4 = bitset_iter_next(in_stack_00000018);
    if (uVar4 != 0xffffffff) {
      do {
        sym = g_candidate_symbols[uVar4];
        if ((sym->cls == '\r') ||
           (iVar5 = reload_hoist_path_clear(uVar4,in_stack_00000010,block2), iVar5 != 0)) {
          if (bs_00 == (c2_bitset *)0x0) {
            bs_00 = bitset_new(6);
            pcStack00000014 = bs_00;
          }
          bitset_set(bs_00,uVar4);
          bs = block2->live_out;
          uVar6 = bitset_test(bs,uVar4);
          bs_00 = pcStack00000014;
          if (uVar6 == 0) {
            bitset_set(bs,uVar4);
            bitset_set(block2->kill,uVar4);
            bitset_set(block2->de,uVar4);
            pcVar7 = find_block_exit_insert_point(block2,sym,in_stack_00000028);
            insert_live_range_reload(sym,&g_register_candidate_home,pcVar7);
            bs_00 = pcStack00000014;
          }
        }
        uVar4 = bitset_iter_next((c2_bitset *)0x0);
      } while (uVar4 != 0xffffffff);
      block = in_stack_00000010;
      if (bs_00 != (c2_bitset *)0x0) {
        liveness_extend_to_preds(bs_00,in_stack_00000010,block2);
        bitset_free(bs_00);
      }
    }
    do {
      do {
        do {
          in_stack_00000020 = in_stack_00000020->next_pred;
          pcVar2 = in_stack_00000020;
          while (pcVar2 == (c2_edge *)0x0) {
            do {
              block = block->prev;
              if (block == (c2_block *)0x0) {
                bitset_free(in_stack_00000018);
                return;
              }
              in_stack_00000020 = block->preds;
            } while (in_stack_00000020 == (c2_edge *)0x0);
            in_stack_00000010 = block;
            pcVar2 = in_stack_00000020->next_pred;
          }
          sVar1 = block->rpo;
          pcVar3 = in_stack_00000020->from;
        } while (sVar1 <= pcVar3->rpo);
        bitset_copy(in_stack_00000018,block->live_in);
        bitset_andnot(in_stack_00000018,pcVar3->live_out);
      } while (in_stack_00000018->chunks == (c2_bitset_chunk *)0x0);
      if (in_stack_0000001c == (c2_bitvec *)0x0) {
        in_stack_0000001c = bitvec_clone(block->dominators);
      }
      else {
        bitvec_copy(in_stack_0000001c,block->dominators);
      }
      bitvec_and(in_stack_0000001c,pcVar3->dominators);
      uVar4 = bitvec_iter_next(in_stack_0000001c);
      while (uVar6 = uVar4, uVar6 != 0xffffffff) {
        uVar4 = bitvec_iter_next((c2_bitvec *)0x0);
        in_stack_00000024 = uVar6;
      }
    } while (sVar1 <= (short)in_stack_00000024);
    for (block2 = block->prev;
        (block2 != (c2_block *)0x0 && (block2->rpo != (short)in_stack_00000024));
        block2 = block2->prev) {
    }
    pcVar7 = block2->end->prev;
  } while (((pcVar7->kind != '\x11') || (pcVar7->prev->kind != '\x19')) ||
          (pcVar7->src->next == (c2_operand *)0x0));
  hoist_candidate_reloads_part(block,block2->prev);
  return;
}

