void __thiscall type_check_array_of_functions(c1_type_declarator *declarator,c1_type *layer)

{
  c1_u16 *pcVar1;
  c1_type *pcVar2;
  ushort auStack_10 [2];
  uint extra_position;
  ushort auStack_8 [2];
  uint mods_position;
  
  declarator->flags14 = declarator->flags14 | 1;
  if (declarator->first != (c1_type *)0x0) {
    switch((byte)declarator->last->code & 0x8f) {
    case 0x81:
    case 0x85:
      diag_error(0x5b);
      auStack_10[0] = 0;
      extra_position = 0;
      auStack_8[0] = 0;
      mods_position = 0;
      decl_add_pointer_modifier(declarator,auStack_8,auStack_10);
      declarator->last->code = 0x86;
      break;
    case 0x82:
      declarator->last->code = (c1_u16)CONCAT31((byte)(layer->code >> 8) & 0xe0,0x86);
      break;
    case 0x83:
      diag_error(0x5c);
      (declarator->last->extra).sym = (c1_symbol *)0x0;
      declarator->last->code = 0x82;
    }
    pcVar2 = declarator->last;
    if ((pcVar2->code & 0x8f) == 0x83) {
      pcVar2 = type_skip_arrays(pcVar2->base);
    }
    if ((pcVar2->flags & 8) != 0) {
      diag_error(0xd4,declarator->sym);
      declarator->flags30 = declarator->flags30 | 1;
      pcVar1 = &declarator->last->flags;
      *pcVar1 = *pcVar1 & 0xffe7;
    }
  }
  return;
}

