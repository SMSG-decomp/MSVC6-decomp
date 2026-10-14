int __fastcall is_known_nonnegative(c2_operand *k)

{
  ushort uVar1;
  int iVar2;
  c2_operand *first_child;
  c2_operand *second_child;
  ushort uVar3;
  int64_t iVar4;
  
  second_child = k;
  first_child = k;
  if ((k->flags9 & 1) != 0) {
    second_child = ((k->u18).children)->next;
    first_child = (k->u18).children;
  }
  switch(k->op) {
  case 0x146:
    iVar4 = sign_extend_to_size(k,0x80000000);
    if (((uint)iVar4 & (k->u18).lo) == 0 && ((uint)((ulonglong)iVar4 >> 0x20) & k->tag) == 0) {
      return 1;
    }
    iVar2 = is_known_nonnegative_case_147();
    return iVar2;
  default:
    goto code_r0x10766f76;
  case 0x15f:
    uVar1 = first_child->type;
    if ((1 << (byte)(uVar1 >> 0xc) & 0xeU) == 0) {
      return 0;
    }
    uVar3 = k->type & 0xfff;
    if (uVar3 < (uVar1 & 0xfff)) {
      return 0;
    }
    if (((uVar1 & 0xf000) == 0x2000) && ((uVar1 & 0xfff) < uVar3)) {
      return 1;
    }
    break;
  case 0x172:
    iVar2 = is_known_nonnegative(first_child);
    first_child = second_child;
    if (iVar2 != 0) {
      return 1;
    }
    break;
  case 0x177:
    if (((k->type & 0xf000) == 0x2000) && (second_child->kind == '\a')) {
      return 1;
    }
  }
  iVar2 = is_known_nonnegative(first_child);
  if (iVar2 != 0) {
    return 1;
  }
code_r0x10766f76:
  return 0;
}

