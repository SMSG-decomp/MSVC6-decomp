int __cdecl debug_identifier_length_2(byte *out,c1_symbol *member,char qualified)

{
  char *name;
  int iVar1;
  
  name = debug_symbol_name(member,qualified);
  iVar1 = debug_identifier_length(out,name);
  return iVar1 + -1;
}

