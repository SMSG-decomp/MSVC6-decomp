int __fastcall late_cse_tuple_is_candidate(c2_tuple *t,c2_operand *op)

{
  uint uVar1;
  
  if ((t->type & 0xf000) == 0x4000) {
    return 0;
  }
  uVar1 = t->op;
  if (uVar1 != 0) {
    if ((uVar1 < 0x144) && ((g_x86_op_flags[uVar1] & 1) != 0)) {
      return 0;
    }
    if (((uVar1 != 0) && (uVar1 < 0x144)) && ((g_x86_op_flags[uVar1] & 0x40) != 0)) {
      return (uint)(op != t->src);
    }
  }
  return 1;
}

