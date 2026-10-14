int __cdecl
init_is_constant_initializer_fragment
          (c1_type *value_type,c1_symbol *addr_symbol,int addr_offset,c1_type *type,c1_symbol *sym,
          c1_node *node)

{
  char cVar1;
  c1_type *pcVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  
  pcVar2 = ((type->extra).sym)->type;
  if ((((char)pcVar2->code < '\0') && (pcVar2 != (c1_type *)0x0)) && ((node->kind & 0x80) == 0)) {
    if ((node->kind & 7) != 3) {
      return 0;
    }
    cVar1 = (char)value_type->code;
    while (cVar1 < '\0') {
      value_type = value_type->base;
      cVar1 = (char)value_type->code;
    }
    if ((value_type->code & 0xfff) != 0x13) {
      return 0;
    }
  }
  bVar3 = node->kind & 7;
  if ((bVar3 != 5) && (bVar3 != 3)) {
    iVar4 = init_split_address_constant(node,&addr_symbol,&addr_offset);
    if (iVar4 == 0) {
      return 0;
    }
    if (((addr_symbol != (c1_symbol *)0x0) && (bVar3 = addr_symbol->kind & 0x1f, bVar3 != 0)) &&
       ((bVar3 < 0xf && (bVar3 != 5)))) {
      if ((bVar3 == 0xe) && ((addr_symbol->entity & 0xffffff) == 6)) {
        return 0;
      }
      if (((addr_symbol->flags23 & 1) != 0) &&
         (pbVar5 = sym_segment_record(addr_symbol), (*pbVar5 & 0x1f) != 0xe)) {
        return 0;
      }
      if ((addr_symbol->storage & 7) == 4) {
        bVar3 = sym->kind & 0x1f;
        if (bVar3 == 3) {
          return 0;
        }
        if (bVar3 == 2) {
          return 0;
        }
        if ((sym->storage & 7) == 3) {
          return 0;
        }
      }
      if ((((addr_symbol->flags22 & 2) != 0) && (bVar3 = addr_symbol->kind & 0x1f, bVar3 != 7)) &&
         (bVar3 != 8)) {
        return 0;
      }
      if ((((addr_symbol->flags22 & 8) != 0) && (bVar3 = addr_symbol->kind & 0x1f, bVar3 != 7)) &&
         (bVar3 != 8)) {
        return 0;
      }
    }
  }
  return 1;
}

