void __cdecl decl_check_operator_function_block_a(c1_symbol *sym,int nparams,uint ndefaults)

{
  uint uVar1;
  
  (sym->tail).fn.op_token = 0x86;
  uVar1 = (uint)(sym->tail).fn.op_token;
  if (uVar1 != 0x76) {
    if (uVar1 == 0x8c) {
      if ((int)(nparams - ndefaults) < 1) {
        diag_error(0x33e);
        sym->flags3 = sym->flags3 | 4;
      }
    }
    else if (ndefaults != 0) {
      diag_error(0x33f,uVar1);
      sym->flags3 = sym->flags3 | 4;
      return;
    }
  }
  return;
}

