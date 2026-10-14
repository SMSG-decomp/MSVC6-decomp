byte * __cdecl class_find_complete_destructor(c1_type *type)

{
  char cVar1;
  c1_type *pcVar2;
  void *name;
  byte *pbVar3;
  
  cVar1 = (char)type->code;
  pcVar2 = type;
  while (cVar1 < '\0') {
    pcVar2 = pcVar2->base;
    cVar1 = (char)pcVar2->code;
  }
  name = g_name_vbase_dtor;
  if ((((((pcVar2->extra).cls)->detail).cls)->layout_flags3b & 0x20) == 0) {
    name = g_name_dtor;
  }
  pbVar3 = class_find_member_function_matching(type,(int)name,(void *)0x0);
  return pbVar3;
}

