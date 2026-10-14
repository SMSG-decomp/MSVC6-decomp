int __fastcall is_byte_zero_extend(c2_tuple *t)

{
  uint uVar1;
  
  uVar1 = t->op;
  if ((uVar1 == 0) || (0x143 < uVar1)) {
    if (((uVar1 == 0x15f) && ((t->type & 0xfff) == 4)) && (t->src->type == 0x1001)) {
      return 1;
    }
    return 0;
  }
  if ((t->op == 0xc4) && (((t->type & 0xfff) == 4 && ((t->src->type & 0xfff) == 1)))) {
    return 1;
  }
  return 0;
}

