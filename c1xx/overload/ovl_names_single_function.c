char __cdecl ovl_names_single_function(c1_symbol *sym,char flag)

{
  uint uVar1;
  
  uVar1 = ovl_name_function_count(sym,flag);
  return '\x01' - (uVar1 != 1);
}

