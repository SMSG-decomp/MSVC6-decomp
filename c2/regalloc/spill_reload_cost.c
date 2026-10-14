int __fastcall spill_reload_cost(c2_symbol *sym)

{
  uint8_t uVar1;
  
  if (g_opt_favor_speed != 0) {
    return 2;
  }
  uVar1 = sym->cls;
  if ((((uVar1 != '\x03') && (uVar1 != '\x04')) && (uVar1 != '\x05')) && (uVar1 != '\x06')) {
    return 6;
  }
  return g_ebp_allocatable + 3;
}

