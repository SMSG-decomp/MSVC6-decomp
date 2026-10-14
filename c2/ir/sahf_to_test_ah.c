void __fastcall sahf_to_test_ah(c2_tuple *t)

{
  c2_operand *op;
  c2_tuple *pcVar1;
  uint32_t lo;
  c2_const_operand *op_00;
  uint8_t cc;
  c2_operand *use;
  
  use = (c2_operand *)t;
  pcVar1 = find_next_use_of_dst(t,&use);
  if (pcVar1->kind != '\x11') {
    return;
  }
  if (pcVar1->op != 0xf) {
    return;
  }
  switch((char)pcVar1->type) {
  case '\x01':
    cc = '\x02';
    lo = 0x40;
    break;
  case '\x02':
    cc = '\x01';
    lo = 0x40;
    break;
  default:
    goto switchD_1075d298_caseD_3;
  case '\a':
    cc = '\x02';
    lo = 1;
    break;
  case '\b':
    cc = '\x01';
    goto LAB_1077cec3;
  case '\t':
    cc = '\x02';
LAB_1077cec3:
    lo = 0x41;
    break;
  case '\n':
    cc = '\x01';
    lo = 1;
  }
  op_00 = operand_new_intconst(t->type,lo,0);
  tuple_append_src(t,op_00);
  op = t->src;
  operand_set_type(op,t->type);
  (op->u18).reg = g_reg_symbols + 0x15;
  t->op = 0x33;
  *(uint8_t *)&pcVar1->type = cc;
switchD_1075d298_caseD_3:
  return;
}

