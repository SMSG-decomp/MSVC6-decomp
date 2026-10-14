void __fastcall solve_avail_dataflow_range(c2_block *block,c2_block *block2)

{
  c2_block *pcVar1;
  c2_block *pcVar2;
  c2_edge *pcVar3;
  c2_block *pcVar4;
  c2_block *local_4;
  
  pcVar1 = block2->next;
  local_4 = block;
  for (pcVar4 = block; pcVar2 = block, pcVar4 != pcVar1; pcVar4 = pcVar4->next) {
    compute_block_expression_local_sets(pcVar4);
  }
  do {
    if (pcVar2 == pcVar1) {
      do {
        local_4 = (c2_block *)0x0;
        pcVar4 = block;
        if (block == pcVar1) {
          return;
        }
        do {
          propagate_block_available_expressions(pcVar4,(uint32_t *)&local_4);
          pcVar4 = pcVar4->next;
        } while (pcVar4 != pcVar1);
      } while (local_4 != (c2_block *)0x0);
      return;
    }
    if (((pcVar2->loop != (c2_loop *)0x0) && ((pcVar2->loop->flags & 1) == 0)) &&
       (pcVar3 = pcVar2->succs, pcVar3 != (c2_edge *)0x0)) {
      do {
        if (pcVar3->to->rpo <= pcVar2->rpo) {
          bitset_set_range(pcVar2->set54,g_next_symbol_id);
          break;
        }
        pcVar3 = pcVar3->next_succ;
      } while (pcVar3 != (c2_edge *)0x0);
    }
    pcVar2 = pcVar2->next;
  } while( true );
}

