void __cdecl decl_check_operator_params_tail(c1_symbol *sym,int nparams,uint ndefaults)

{
  byte bVar1;
  c1_symbol *pcVar2;
  uint uVar3;
  short n;
  
  bVar1 = (sym->tail).fn.op_token;
  if (bVar1 == 0x8f) {
    n = 0x343;
    pcVar2 = sym;
  }
  else {
    pcVar2 = (c1_symbol *)(uint)bVar1;
    n = 0x328;
  }
  diag_error(n,pcVar2);
  sym->flags3 = sym->flags3 | 4;
  uVar3 = (uint)(sym->tail).fn.op_token;
  if (uVar3 != 0x76) {
    if (uVar3 == 0x8c) {
      if ((int)(nparams - ndefaults) < 1) {
        diag_error(0x33e);
        sym->flags3 = sym->flags3 | 4;
      }
    }
    else if (ndefaults != 0) {
      diag_error(0x33f,uVar3);
      sym->flags3 = sym->flags3 | 4;
      return;
    }
  }
  return;
}

