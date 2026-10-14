int __fastcall operand_compare(c2_operand *a,c2_operand *b)

{
  byte bVar1;
  ushort b_00;
  uint16_t a_00;
  uint32_t uVar2;
  uint32_t uVar3;
  int iVar4;
  
  if (a == b) {
    return 0;
  }
  if (a != (c2_operand *)0x0) {
    if (b == (c2_operand *)0x0) {
      return 1;
    }
    bVar1 = a->kind;
    if (bVar1 != b->kind) {
      return (-(uint)(bVar1 < b->kind) & 0xfffffffe) + 1;
    }
    b_00 = b->type;
    a_00 = a->type;
    iVar4 = types_compatible(a_00,b_00);
    if (iVar4 == 0) {
      return (-(uint)(a_00 < b_00) & 0xfffffffe) + 1;
    }
    switch(bVar1) {
    case 0:
      halt_baddata();
    case 1:
      if ((a->u18).reg != (b->u18).reg) {
        return (-(uint)(((a->u18).reg)->id < ((b->u18).reg)->id) & 0xfffffffe) + 1;
      }
    default:
      iVar4 = symbol_compare(a->sym,b->sym);
      return iVar4;
    case 4:
      if (a->sym == b->sym) {
        return 0;
      }
      return (-(uint)((a->sym->u28).free_next < (b->sym->u28).free_next) & 0xfffffffe) + 1;
    case 5:
    case 6:
      if (a->disp != b->disp) {
        return ((b->disp <= a->disp) - 1 & 0xfffffffe) + 1;
      }
      if (((b->flags11 ^ a->flags11) & 7) != 0) {
        return (-(uint)((a->flags11 & 7) < (b->flags11 & 7)) & 0xfffffffe) + 1;
      }
      if (((b->flags ^ a->flags) & 0xf) != 0) {
        return (-(uint)((a->flags & 0xf) < (b->flags & 0xf)) & 0xfffffffe) + 1;
      }
      iVar4 = symbol_compare(a->base_sym,b->base_sym);
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar4 = operand_compare(a->base,b->base);
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar4 = operand_compare(a->index,b->index);
      if (iVar4 != 0) {
        return iVar4;
      }
      if (g_compare_alias_tags == 0) {
        return 0;
      }
      if (a->tag == b->tag) {
        return 0;
      }
      return (-(uint)(a->tag < b->tag) & 0xfffffffe) + 1;
    case 7:
      uVar2 = a->tag;
      uVar3 = b->tag;
      if (((a->u18).reg == (b->u18).reg) && (uVar2 == uVar3)) {
        return 0;
      }
      if ((int)uVar3 < (int)uVar2) {
        return 1;
      }
      if (((int)uVar3 <= (int)uVar2) && ((b->u18).reg <= (a->u18).reg)) {
        return 1;
      }
    }
  }
  return -1;
}

