int __cdecl init_is_constant_initializer(c1_symbol *sym,c1_node **value)

{
  char cVar1;
  c1_node *node;
  c1_type *value_type;
  c1_type *pcVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  ushort uVar6;
  c1_symbol *sym_00;
  
  sym_00 = (c1_symbol *)0x0;
  node = *value;
  if (node == (c1_node *)0x0) {
    return 0;
  }
  value_type = node->type;
  pcVar2 = sym->type;
  if (((value_type != pcVar2) && ((char)pcVar2->code < '\0')) &&
     ((uVar6 = pcVar2->code & 0x8f, uVar6 == 0x86 || (uVar6 == 0x82)))) {
    uVar6 = pcVar2->flags & 0x18;
    if (uVar6 == 0x18) {
      pcVar2 = ((pcVar2->extra).sym)->type;
      if ((((char)pcVar2->code < '\0') && (pcVar2 != (c1_type *)0x0)) && ((node->kind & 0x80) == 0))
      {
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
    }
    else if (uVar6 == 8) {
      iVar4 = init_is_constant_initializer_fragment(value_type,(c1_symbol *)0x0,0,pcVar2,sym,node);
      return iVar4;
    }
  }
  bVar3 = node->kind & 7;
  if ((bVar3 != 5) && (bVar3 != 3)) {
    iVar4 = init_split_address_constant(node,(void **)&stack0xfffffff8,(int *)&stack0xfffffffc);
    if (iVar4 == 0) {
      return 0;
    }
    if (((sym_00 != (c1_symbol *)0x0) && (bVar3 = sym_00->kind & 0x1f, bVar3 != 0)) &&
       ((bVar3 < 0xf && (bVar3 != 5)))) {
      if ((bVar3 == 0xe) && ((sym_00->entity & 0xffffff) == 6)) {
        return 0;
      }
      if (((sym_00->flags23 & 1) != 0) &&
         (pbVar5 = sym_segment_record(sym_00), (*pbVar5 & 0x1f) != 0xe)) {
        return 0;
      }
      if ((sym_00->storage & 7) == 4) {
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
      if ((((sym_00->flags22 & 2) != 0) && (bVar3 = sym_00->kind & 0x1f, bVar3 != 7)) &&
         (bVar3 != 8)) {
        return 0;
      }
      if ((((sym_00->flags22 & 8) != 0) && (bVar3 = sym_00->kind & 0x1f, bVar3 != 7)) &&
         (bVar3 != 8)) {
        return 0;
      }
    }
  }
  return 1;
}

