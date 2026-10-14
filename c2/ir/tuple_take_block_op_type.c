uint16_t __fastcall tuple_take_block_op_type(c2_tuple *t,uint32_t *flag8)

{
  uint16_t uVar1;
  c2_operand *op;
  
  op = t->src;
  uVar1 = 0x6000;
  if (op != (c2_operand *)0x0) {
    while (op->kind != '\a') {
      op = op->next;
      if (op == (c2_operand *)0x0) {
        return 0x6000;
      }
    }
    uVar1 = *(uint16_t *)&op->u18;
    *flag8 = (op->flags11 & 8) >> 3;
    tuple_remove_src(t,op);
  }
  return uVar1;
}

