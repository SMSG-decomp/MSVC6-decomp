int __cdecl type_member_pointer_size_kind(c1_type *t)

{
  char cVar1;
  int iVar2;
  c1_type *pcVar3;
  
  iVar2 = class_complete_for_use((t->extra).cls);
  switch(iVar2) {
  case 0:
  case 1:
    return 4;
  case 2:
    pcVar3 = type_int();
    cVar1 = (char)pcVar3->code;
    while (cVar1 < '\0') {
      pcVar3 = pcVar3->base;
      cVar1 = (char)pcVar3->code;
    }
    return (char)(&g_type_rank_table)[(byte)pcVar3->code & 0xf] + 4;
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
    return (char)(&g_type_rank_table)[(byte)pcVar3->code & 0xf] * 3 + 4;
  default:
    return 0;
  }
  while (cVar1 < '\0') {
    pcVar3 = pcVar3->base;
    cVar1 = (char)pcVar3->code;
  }
  return (char)(&g_type_rank_table)[(byte)pcVar3->code & 0xf] * 2 + 4;
}

