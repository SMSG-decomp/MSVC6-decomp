int __cdecl type_data_member_pointer_size(c1_type *t)

{
  char cVar1;
  int iVar2;
  c1_type *pcVar3;
  
  iVar2 = class_complete_for_use((t->extra).cls);
  switch(iVar2) {
  case 1:
  case 2:
    pcVar3 = type_int();
    cVar1 = (char)pcVar3->code;
    while (cVar1 < '\0') {
      pcVar3 = pcVar3->base;
      cVar1 = (char)pcVar3->code;
    }
    return (int)(char)(&g_type_rank_table)[(byte)pcVar3->code & 0xf];
  case 3:
    pcVar3 = type_int();
    cVar1 = (char)pcVar3->code;
    break;
  case 4:
    pcVar3 = type_int();
    cVar1 = (char)pcVar3->code;
    while (cVar1 < '\0') {
      pcVar3 = pcVar3->base;
      cVar1 = (char)pcVar3->code;
    }
    return (char)(&g_type_rank_table)[(byte)pcVar3->code & 0xf] * 3;
  default:
    return 0;
  }
  while (cVar1 < '\0') {
    pcVar3 = pcVar3->base;
    cVar1 = (char)pcVar3->code;
  }
  return (int)(char)(&g_type_rank_table)[(byte)pcVar3->code & 0xf] << 1;
}

