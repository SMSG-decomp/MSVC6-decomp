void __fastcall mem_operand_replace_subop(c2_tuple *t,c2_operand *op,c2_operand *new_op)

{
  byte bVar1;
  c2_operand *pcVar2;
  c2_operand *local_4;
  
  local_4 = (c2_operand *)t;
  pcVar2 = find_mem_operand_using(t,op,&local_4);
  if (pcVar2->base == op) {
    pcVar2->base = new_op;
  }
  else {
    pcVar2->index = new_op;
  }
  bVar1 = new_op->flags;
  op->flags = op->flags & 0xdf;
  new_op->flags = bVar1 | 0x20;
  return;
}

