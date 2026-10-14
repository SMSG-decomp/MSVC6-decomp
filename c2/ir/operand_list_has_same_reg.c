int __fastcall operand_list_has_same_reg(c2_operand *op)

{
  c2_operand *pcVar1;
  
  pcVar1 = op->next;
  while( true ) {
    if (pcVar1 == (c2_operand *)0x0) {
      return 0;
    }
    if ((pcVar1->kind == '\x01') && ((pcVar1->u18).reg == (op->u18).reg)) break;
    pcVar1 = pcVar1->next;
  }
  return 1;
}

