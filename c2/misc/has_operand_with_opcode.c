int __fastcall has_operand_with_opcode(c2_tuple *t,uint32_t op,uint32_t wrapper)

{
  c2_operand *pcVar1;
  
  pcVar1 = t->src;
  while( true ) {
    if (pcVar1 == (c2_operand *)0x0) {
      return 0;
    }
    if (pcVar1->op == wrapper) {
      pcVar1 = (pcVar1->u18).children;
    }
    if (pcVar1->op == op) break;
    pcVar1 = pcVar1->next;
  }
  return 1;
}

