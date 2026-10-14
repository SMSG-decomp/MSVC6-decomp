uint __cdecl func_takes_void_parameters(c1_symbol *fn)

{
  c1_type_list *pcVar1;
  
  if ((*(byte *)((int)&fn->tail + 8) & 0x10) == 0) {
    return (uint)fn & 0xffffff00;
  }
  pcVar1 = ((fn->type->extra).params)->list;
  if ((pcVar1->count == 1) && (pcVar1->types[0] == g_type_void)) {
    return 1;
  }
  return 0;
}

