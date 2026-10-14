c1_node * __cdecl init_record_constant_value(c1_symbol *sym,c1_node *init)

{
  byte bVar1;
  ushort uVar2;
  c1_type *pcVar3;
  c1_type *pcVar4;
  
  if (init != (c1_node *)0x0) {
    if ((init->kind & 7) == 3) {
      pcVar3 = sym->type;
      pcVar4 = pcVar3;
      if ((pcVar3->code & 0x8f) == 0x83) {
        pcVar4 = type_skip_arrays(pcVar3->base);
      }
      if ((((byte)pcVar4->flags >> 5 & 1) != 0) &&
         (((uVar2 = pcVar3->code, (char)uVar2 < '\0' &&
           ((((uVar2 & 0x8f) == 0x86 || ((uVar2 & 0x8f) == 0x82)) && (-1 < (char)pcVar3->base->code)
            ))) || ((uVar2 & 0x110) != 0)))) {
        bVar1 = sym->flags5;
        (sym->tail).data.value_lo = (c1_u32)init->left;
        (sym->tail).fn.record = init->right;
        sym->flags5 = bVar1 | 0x40;
      }
    }
    if (((init->kind & 7) == 0) && (init->op == 0x98)) {
      diag_error(0x113,init->left);
      return (c1_node *)0x0;
    }
  }
  return init;
}

