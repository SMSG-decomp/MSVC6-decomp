void __thiscall sym_inherit_scope_index(c1_symbol *sym,byte *from)

{
  byte bVar1;
  
  bVar1 = *from & 0x1f;
  if (bVar1 == 0x1c) {
    do {
    } while (from != (byte *)0x0);
  }
  else {
    if (bVar1 == 4) {
      sym->scope_index = *(c1_u16 *)(*(int *)(from + 0x24) + 0x2c);
      return;
    }
    if (bVar1 == 0x19) {
      sym->scope_index = *(c1_u16 *)(*(int *)(from + 0x14) + 4);
      return;
    }
    if ((bVar1 == 7) || (bVar1 == 8)) {
      if (*(short *)(from + 0x28) == 0) {
        scope_vector_add((c1_symbol *)from,'\a');
      }
      sym->scope_index = *(c1_u16 *)(from + 0x28);
      if ((sym->kind & 0x1f) == 4) {
        ((sym->detail).cls)->unk38 = g_block_number;
      }
    }
  }
  return;
}

