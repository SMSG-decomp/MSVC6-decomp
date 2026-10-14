char * __cdecl decorate_function_symbol_type(char *out,c1_symbol *sym)

{
  char *pcVar1;
  
  pcVar1 = decorate_calling_convention(out,(uint)sym->type & -(uint)((sym->type->code & 0x80) != 0))
  ;
  if (((sym->flags1 & 0x10) == 0x10) || ((sym->flags1 & 0x20) == 0x20)) {
    *pcVar1 = '@';
    pcVar1 = pcVar1 + 1;
  }
  else {
    pcVar1 = decorate_return_type(pcVar1,sym->type,0);
  }
  pcVar1 = decorate_argument_list(pcVar1,sym->type);
  pcVar1 = decorate_put_Z(pcVar1);
  return pcVar1;
}

