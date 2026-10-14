void __fastcall lower_memcpy_operand_add_reg_use(c2_operand *op)

{
  uint8_t uVar1;
  c2_tuple *pos;
  c2_tuple *t;
  
  t = tuple_new_pseudo(0x19e,op->type);
  tuple_append_src(t,op);
  pos = op->sym->def;
  tuple_insert_after(pos,t);
  if ((pos->src->kind == '\x03') &&
     ((((uVar1 = pos->src->sym->cls, uVar1 == '\x03' || (uVar1 == '\x04')) || (uVar1 == '\x05')) ||
      (uVar1 == '\x06')))) {
    pos->op = 0x12;
    return;
  }
  pos->op = 1;
  return;
}

