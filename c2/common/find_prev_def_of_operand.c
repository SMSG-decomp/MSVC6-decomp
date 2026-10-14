c2_tuple * __fastcall find_prev_def_of_operand(c2_tuple *t,c2_operand *op,c2_operand **out)

{
  c2_tuple *pcVar1;
  
  pcVar1 = find_prev_def_of(t,op->sym,out);
  return pcVar1;
}

