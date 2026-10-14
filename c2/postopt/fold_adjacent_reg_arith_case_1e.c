int __fastcall
fold_adjacent_reg_arith_case_1e
          (c2_tuple *t,c2_operand *t_reg,uint32_t prev_op,c2_operand *prev_reg,c2_tuple **next)

{
  int iVar1;
  
  iVar1 = fold_add_sub_constant_pair(t,t_reg,prev_op,0xffffffff,0xffffffff,prev_reg,next);
  return iVar1;
}

