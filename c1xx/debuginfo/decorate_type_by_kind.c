char * __cdecl decorate_type_by_kind(char *out,c1_type *type)

{
  ushort uVar1;
  char *pcVar2;
  
  uVar1 = type->code & 0x8f;
  if (((uVar1 != 0x82) && (uVar1 != 0x83)) && (uVar1 != 0x8a)) {
    pcVar2 = decorate_function_type_prefix(out,type);
    pcVar2 = debug_type_name_text(pcVar2,type->base);
    return pcVar2;
  }
  pcVar2 = decorate_type_into(out,type,0);
  pcVar2 = decorate_type_code(pcVar2,type->base);
  return pcVar2;
}

