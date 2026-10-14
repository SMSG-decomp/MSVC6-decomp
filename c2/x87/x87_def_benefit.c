int __fastcall x87_def_benefit(c2_symbol *sym,c2_function *fn)

{
  uint8_t uVar1;
  int iVar2;
  
  if (g_opt_favor_speed == 0) {
    uVar1 = sym->cls;
    if ((((uVar1 == '\x03') || (uVar1 == '\x04')) || (uVar1 == '\x05')) ||
       (iVar2 = 6, uVar1 == '\x06')) {
      iVar2 = 3;
    }
  }
  else {
    iVar2 = 4;
    if (((sym->size == 4) || (uVar1 = sym->cls, uVar1 == '\a')) ||
       ((uVar1 == '\b' || (((fn->flags & 0x600000) != 0 && (uVar1 != '\x05')))))) {
      return 2;
    }
  }
  return iVar2;
}

