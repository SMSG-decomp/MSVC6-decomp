void __fastcall inline_free_callee_body(c2_function *fn)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  c2_tuple *pcVar4;
  c2_tuple *node;
  
  pcVar4 = fn->cfg->first->head;
  while (node = pcVar4, node != (c2_tuple *)0x0) {
    pcVar4 = node->next;
    if ((node->flags & 1) != 0) {
      for (pcVar2 = node->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if ((1 << (pcVar2->kind & 0x1f) & 6U) != 0) {
          pcVar3 = pcVar2->sym;
          uVar1 = pcVar3->cls;
          if (((((uVar1 == '\x03') || (uVar1 == '\x04')) || (uVar1 == '\x05')) || (uVar1 == '\x06'))
             && ((pcVar3 != g_eh_guard_local && ((pcVar3->storage->flags5 & 0x80) == 0)))) {
            symbol_free_chain(pcVar3->storage);
          }
        }
      }
      for (pcVar2 = node->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
        if (pcVar2->kind == '\x02') {
          pcVar3 = pcVar2->sym;
          uVar1 = pcVar3->cls;
          if ((((uVar1 == '\x03') || (uVar1 == '\x04')) || ((uVar1 == '\x05' || (uVar1 == '\x06'))))
             && ((pcVar3 != g_eh_guard_local && ((pcVar3->storage->flags5 & 0x80) == 0)))) {
            symbol_free_chain(pcVar3->storage);
          }
        }
      }
    }
    if (node->kind != '\x1a') {
      node_free((c2_node *)node);
    }
  }
  return;
}

