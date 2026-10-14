void __fastcall tuple_append_int_const(c2_tuple *t,uint16_t v,uint8_t flag8)

{
  c2_const_operand *op;
  
  op = operand_new_intconst(0x1004,(uint)v,0);
  tuple_append_src(t,op);
  op->flags11 = (flag8 & 1) << 3 | op->flags11 & 0xf7;
  return;
}

