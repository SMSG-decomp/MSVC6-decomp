c2_operand * __fastcall derived_iv_hoisted(uint16_t type,int op,int a,int b,c2_loop *loop)

{
  c2_operand *op_00;
  
  op_00 = get_derived_iv(type,op,(c2_operand *)a,(c2_operand *)b);
  if (op_00->sym != g_derived_iv_tail) {
    sr_hoist_invariant_operand(op_00,loop);
  }
  return op_00;
}

