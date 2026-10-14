void __fastcall remove_dead_iv_code(c2_loop *loop,c2_function *fn)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  uint32_t uVar4;
  int iVar5;
  c2_block *block;
  
  if (g_iv_syms->chunks != (c2_bitset_chunk *)0x0) {
    g_cse_full_mode = 0;
    block = loop->first;
    if (block != loop->last->next) {
      do {
        cse_block(block,fn);
        pcVar1 = block->end;
        pcVar2 = block->head->next;
        while (pcVar3 = pcVar2, pcVar3 != pcVar1) {
          pcVar2 = pcVar3->next;
          if ((((pcVar3->op < 0x16d) || (0x16e < pcVar3->op)) ||
              (uVar4 = is_induction_variable_operand(pcVar3->src), uVar4 == 0)) ||
             (((uVar4 = is_loop_invariant_operand(pcVar3->src->next), uVar4 == 0 ||
               (pcVar3->next->op != 0x15b)) ||
              ((iVar5 = operand_compare(pcVar3->dst,pcVar3->next->src), iVar5 != 0 ||
               (iVar5 = operand_compare(pcVar3->next->dst,pcVar3->src), iVar5 != 0)))))) {
            if (pcVar3->flags13 == '\x04') {
              pcVar3->flags13 = '\0';
            }
          }
          else {
            pcVar3->flags13 = '\x04';
            pcVar3->next->flags13 = '\x04';
            pcVar2 = pcVar3->next->next;
          }
        }
        block = block->next;
      } while (block != loop->last->next);
    }
    do {
      g_liveness_repeat_needed = 0;
      recompute_loop_liveness(loop,3);
    } while (g_liveness_repeat_needed != 0);
  }
  return;
}

