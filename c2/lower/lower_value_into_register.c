c2_operand * __fastcall lower_value_into_register(c2_tuple *t,c2_operand *op,c2_symbol *reg)

{
  c2_symbol *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  uint32_t uVar4;
  
  if ((1 << (op->kind & 0x1f) & 6U) != 0) {
    pcVar1 = op->sym;
    pcVar2 = pcVar1->def;
    if ((pcVar2 != (c2_tuple *)0x0) && (pcVar2->op == 0x15a)) {
      if (reg != (c2_symbol *)0x0) {
        pcVar3 = lower_arg_push_value(t,op);
        return pcVar3;
      }
      pcVar3 = pcVar2->dst;
      (op->u18).reg = pcVar1;
      (pcVar3->u18).reg = pcVar1;
      uVar4 = load_op_for_operand(pcVar2->src);
      pcVar2->op = uVar4;
      return op;
    }
  }
  pcVar3 = op;
  if (((op->u18).reg != reg) && (reg != (c2_symbol *)0x0)) {
    pcVar3 = operand_new_temp_in_reg(reg->id,0x1004);
    emit_copy_after(0x1004,pcVar3,op,t->prev);
  }
  return pcVar3;
}

