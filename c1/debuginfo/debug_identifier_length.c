int __cdecl debug_identifier_length(char *out,char *name)

{
  char *pcVar1;
  
  pcVar1 = debug_put_length_prefixed_name(out,name);
  return (int)pcVar1 - (int)out;
}

