int __fastcall load_saving(c2_symbol *sym)

{
  uint8_t uVar1;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  
  if (g_opt_favor_speed != 0) {
    return (sym->cls != '\r') + 1;
  }
  uVar1 = sym->cls;
  if (uVar1 != '\r') {
    if ((((uVar1 != '\x03') && (uVar1 != '\x04')) && (uVar1 != '\x05')) && (uVar1 != '\x06')) {
      return 6;
    }
    return g_ebp_allocatable + 3;
  }
  pcVar2 = (sym->u28).const_operand;
  if (pcVar2->kind != '\a') {
    return 5;
  }
  pcVar3 = (pcVar2->u18).reg;
  if (pcVar3 == (c2_symbol *)0x0) {
    return 2;
  }
  if (pcVar3 == (c2_symbol *)0xffffffff) {
    return 3;
  }
  return (-(uint)((c2_symbol *)(int)*(char *)&pcVar2->u18 != pcVar3) & 2) + 3;
}

