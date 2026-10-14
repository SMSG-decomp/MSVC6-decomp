c1_type * __cdecl conv_usual_arithmetic(c1_u8 op,c1_type *left,c1_type *right)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  c1_type *pcVar4;
  uint uVar5;
  
  if (left == (c1_type *)0x0) goto LAB_10414e6a;
  if (right != (c1_type *)0x0) {
    uVar1 = left->code;
    uVar5 = (uint)uVar1;
    if ((char)(byte)uVar1 < '\0') {
      if (((right->code & 0x8f) == 0x82) && (((byte)right->base->code >> 6 & 1) != 0))
      goto LAB_10414e6a;
    }
    else {
      uVar2 = right->code;
      bVar3 = (byte)uVar2;
      if ((char)bVar3 < '\0') goto LAB_10414e6a;
      if (((byte)uVar1 >> 5 & 1) == 0) {
        if ((bVar3 >> 5 & 1) != 0) goto LAB_10414e6a;
        if (((uVar1 & 0x110) != 0) && ((uVar2 & 0x110) != 0)) {
          if (((char)(&g_type_rank_table)[uVar5 & 0xf] <= (char)(&g_type_rank_table)[uVar2 & 0xf])
             && (((char)(&g_type_rank_table)[uVar5 & 0xf] < (char)(&g_type_rank_table)[uVar2 & 0xf]
                 || (((uVar1 & 0x2000) == 0 &&
                     ((((uVar5 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) ||
                      (g_opt_J_unsigned_char == '\0')))))))) goto LAB_10414e6a;
        }
      }
      else if (((bVar3 >> 5 & 1) != 0) &&
              ((char)(&g_type_rank_table)[uVar5 & 0xf] < (char)(&g_type_rank_table)[uVar2 & 0xf]))
      goto LAB_10414e6a;
    }
  }
  right = left;
LAB_10414e6a:
  pcVar4 = right;
  if ((right->code & 0x8f) == 0x83) {
    pcVar4 = type_skip_arrays(right->base);
  }
  if ((pcVar4->flags & 0x1e0) == 0) {
    return right;
  }
  pcVar4 = type_strip_cv_qualifiers(right);
  return pcVar4;
}

