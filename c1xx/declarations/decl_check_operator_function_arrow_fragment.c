void __cdecl
decl_check_operator_function_arrow_fragment
          (uint pointee_code,int count,c1_symbol *cls,c1_type *ret_type,c1_symbol *sym,int nparams,
          uint ndefaults)

{
  uint uVar1;
  
  if ((pointee_code & 0xfff) != 0x802) {
    diag_warning(2,0x11c,cls,ret_type);
    count = nparams;
  }
  if (count < 2) {
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
  decl_check_operator_params_tail(sym,nparams,ndefaults);
  return;
}

