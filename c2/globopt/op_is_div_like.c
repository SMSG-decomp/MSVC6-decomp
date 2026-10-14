int __fastcall op_is_div_like(c2_tuple *t)

{
  ushort uVar1;
  uint32_t uVar2;
  
  uVar2 = t->op;
  if (((uVar2 != 0x171) && (uVar2 != 0x177)) &&
     ((uVar2 != 400 || ((uVar1 = (t->u20).intrinsic.id, uVar1 < 0xe9 || (0xeb < uVar1)))))) {
    return 0;
  }
  return 1;
}

