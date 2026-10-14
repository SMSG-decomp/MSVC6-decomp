char * __cdecl decorate_name_swapped(int scope,c1_symbol *sym)

{
  char *pcVar1;
  
  pcVar1 = decorate_name(sym,(c1_symbol *)scope);
  return pcVar1;
}

