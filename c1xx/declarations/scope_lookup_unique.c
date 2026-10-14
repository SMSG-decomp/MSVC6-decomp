int * __cdecl scope_lookup_unique(int *scope,void *name)

{
  c1_lookup_result *result;
  c1_lookup_entry *pcVar1;
  
  result = (c1_lookup_result *)(**(code **)(*scope + 0xc))(name,1);
  if (result != (c1_lookup_result *)0x0) {
    pcVar1 = lookup_check_ambiguous_symbol(result,'\x01');
    return (int *)pcVar1;
  }
  return (int *)0x0;
}

