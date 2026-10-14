void __fastcall narrow_shift_count(c2_tuple *t)

{
  c2_operand *op;
  c2_tuple *pcVar1;
  c2_symbol *pcVar2;
  
  op = t->src->next;
  if (((((1 << (op->kind & 0x1f) & 6U) != 0) && (pcVar1 = op->sym->def, pcVar1 != (c2_tuple *)0x0))
      && (pcVar1->op == 1)) &&
     (((pcVar1->src->kind != '\x01' || (pcVar2 = pcVar1->src->sym, pcVar2->cls != '\x03')) ||
      (pcVar2->def == (c2_tuple *)0x0)))) {
    operand_retype(op,0x1001,0);
    operand_retype(pcVar1->dst,0x1001,0);
    operand_retype(pcVar1->src,0x1001,0);
    pcVar1->type = 0x1001;
  }
  return;
}

