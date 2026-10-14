c2_tuple * __fastcall emit_callee_save_push(c2_function *fn,c2_symbol *reg,c2_tuple *after)

{
  int iVar1;
  c2_tuple *pcVar2;
  
  pcVar2 = insert_push_reg(reg->id,after);
  iVar1 = fn->callee_save_pushes;
  pcVar2->op = 0xba;
  fn->callee_save_pushes = iVar1 + 1;
  return pcVar2;
}

