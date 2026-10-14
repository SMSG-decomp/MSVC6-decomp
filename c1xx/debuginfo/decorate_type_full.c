char * __cdecl decorate_type_full(char *out,c1_type *type)

{
  byte bVar1;
  char *pcVar2;
  
  bVar1 = (byte)type->code;
  if (((char)bVar1 < '\0') && ((bVar1 & 0x8f) == 0x80)) {
    pcVar2 = decorate_type_into(out,type,0);
    pcVar2 = decorate_array_type(pcVar2,type->base);
    return pcVar2;
  }
  pcVar2 = decorate_function_type_prefix(out,type);
  pcVar2 = debug_type_name_text(pcVar2,type->base);
  return pcVar2;
}

