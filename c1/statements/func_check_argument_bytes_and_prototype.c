void __cdecl func_check_argument_bytes_and_prototype(c1_symbol *sym)

{
  uint uVar1;
  c1_symbol *pcVar2;
  
  uVar1 = (uint)sym->type & -(uint)((sym->type->code & 0x80) != 0);
  pcVar2 = sym;
  if ((sym->flags4 & 8) == 0) {
    if ((*(ushort *)(uVar1 + 2) & 0x2000) != 0) {
      diag_warning(1,0x114,sym);
      sym->detail = (void *)0x0;
      sym->flags4 = sym->flags4 | 0x40;
      return;
    }
    pcVar2 = (c1_symbol *)type_parameter_list_bytes(*(c1_param_list **)(uVar1 + 8));
  }
  if (0xffff < (int)pcVar2) {
    diag_fatal(0x1fc,sym);
  }
  sym->detail = (void *)((uint)pcVar2 & 0xffff);
  sym->flags4 = sym->flags4 | 0x40;
  return;
}

