char * __cdecl debug_type_name_text(char *out,c1_type *type)

{
  char *pcVar1;
  
  pcVar1 = decorate_calling_convention(out,-(uint)((type->code & 0x80) != 0) & (uint)type);
  pcVar1 = decorate_return_type(pcVar1,type,0);
  pcVar1 = decorate_argument_list(pcVar1,type);
  pcVar1 = decorate_put_Z(pcVar1);
  return pcVar1;
}

