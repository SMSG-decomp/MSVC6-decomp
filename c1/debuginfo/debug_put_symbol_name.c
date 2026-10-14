int __cdecl debug_put_symbol_name(char *out,c1_symbol *sym)

{
  int iVar1;
  
  iVar1 = debug_identifier_length(out,sym->name->text);
  return iVar1;
}

