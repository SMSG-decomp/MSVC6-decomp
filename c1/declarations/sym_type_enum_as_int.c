c1_type * __cdecl sym_type_enum_as_int(c1_symbol *sym)

{
  char cVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  
  pcVar3 = sym->type;
  cVar1 = (char)pcVar3->code;
  pcVar2 = pcVar3;
  while (cVar1 < '\0') {
    pcVar2 = pcVar2->base;
    cVar1 = (char)pcVar2->code;
  }
  if ((pcVar2->code & 0x100) != 0) {
    pcVar3 = g_type_int;
  }
  return pcVar3;
}

