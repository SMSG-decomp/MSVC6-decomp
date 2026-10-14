int __fastcall lookup_unique_symbol(void *result)

{
  c1_lookup_entry *pcVar1;
  
  pcVar1 = lookup_check_ambiguous_symbol(result,'\x01');
  if (pcVar1 != (c1_lookup_entry *)0x0) {
    return (int)pcVar1->sym;
  }
  return 0;
}

