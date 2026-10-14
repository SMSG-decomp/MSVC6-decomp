int __fastcall final_op_is_simple_alu(c2_tuple *t)

{
  switch(t->op) {
  case 0x2d:
  case 0x2e:
  case 0x30:
  case 0x34:
  case 0xc1:
    return 1;
  default:
    return 0;
  }
}

