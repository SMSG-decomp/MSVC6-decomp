void __fastcall cse_number_memory_bases(c2_tuple *t)

{
  uint16_t uVar1;
  c2_operand *pcVar2;
  c2_const_operand *pcVar3;
  c2_symbol *pcVar4;
  
  for (pcVar2 = t->src; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    if ((1 << (pcVar2->kind & 0x1f) & 0x60U) != 0) {
      uVar1 = pcVar2->type;
      pcVar3 = operand_new_intconst(0x1004,pcVar2->tag,0);
      pcVar4 = cse_find_or_make(0x14c,uVar1,pcVar2->base,pcVar3);
      if ((pcVar3->flags & 0x10) == 0) {
        node_free((c2_node *)pcVar3);
      }
      if ((pcVar2->u18).reg != pcVar4) {
        (pcVar2->u18).reg = pcVar4;
        cse_add_copy_link(pcVar2->base->sym,pcVar4);
      }
    }
  }
  for (pcVar2 = t->dst; pcVar2 != (c2_operand *)0x0; pcVar2 = pcVar2->next) {
    if ((1 << (pcVar2->kind & 0x1f) & 0x60U) != 0) {
      uVar1 = pcVar2->type;
      pcVar3 = operand_new_intconst(0x1004,pcVar2->tag,0);
      pcVar4 = cse_find_or_make(0x14c,uVar1,pcVar2->base,pcVar3);
      if ((pcVar3->flags & 0x10) == 0) {
        node_free((c2_node *)pcVar3);
      }
      if ((pcVar2->u18).reg != pcVar4) {
        (pcVar2->u18).reg = pcVar4;
        cse_add_copy_link(pcVar2->base->sym,pcVar4);
      }
    }
  }
  return;
}

