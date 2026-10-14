int __cdecl debug_identifier_length(byte *out,char *name)

{
  byte *pbVar1;
  
  pbVar1 = debug_put_length_prefixed_name(out,name);
  return (int)pbVar1 - (int)out;
}

