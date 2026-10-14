c2_tuple * __fastcall emit_callee_save_pop(c2_symbol *reg,c2_tuple *after)

{
  c2_tuple *pcVar1;
  
  pcVar1 = insert_pop_reg(reg->id,after);
  pcVar1->op = 0xb9;
  return pcVar1;
}

