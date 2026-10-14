void __fastcall record_preheader_iv_inits(c2_loop *loop)

{
  c2_block *pcVar1;
  uint32_t uVar2;
  c2_list_cell *pcVar3;
  c2_tuple *pcVar4;
  c2_tuple *node;
  
  pcVar1 = loop->preheader;
  node = pcVar1->head->next;
  if (node != pcVar1->end) {
    do {
      if ((node->op == 0x15b) && (uVar2 = is_induction_variable_operand(node->dst), uVar2 != 0)) {
        pcVar3 = arena_alloc(0xd,8);
        pcVar4 = (c2_tuple *)node_clone((c2_node *)node);
        (pcVar3->u04).tuple = pcVar4;
        pcVar3->next = loop->iv_preheader_inits;
        loop->iv_preheader_inits = pcVar3;
      }
      node = node->next;
    } while (node != pcVar1->end);
  }
  return;
}

