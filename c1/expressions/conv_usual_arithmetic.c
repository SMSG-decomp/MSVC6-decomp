c1_type * __cdecl conv_usual_arithmetic(c1_u8 op,c1_type *type,c1_type *type2)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  c1_type *pcVar4;
  uint uVar5;
  
  if (type == (c1_type *)0x0) goto LAB_1060d6f5;
  if (type2 != (c1_type *)0x0) {
    uVar1 = type->code;
    uVar5 = (uint)uVar1;
    if ((char)(byte)uVar1 < '\0') {
      if (((type2->code & 0x8f) == 0x82) && (((byte)type2->base->code >> 6 & 1) != 0))
      goto LAB_1060d6f5;
    }
    else {
      uVar2 = type2->code;
      bVar3 = (byte)uVar2;
      if ((char)bVar3 < '\0') goto LAB_1060d6f5;
      if (((byte)uVar1 >> 5 & 1) == 0) {
        if ((bVar3 >> 5 & 1) != 0) goto LAB_1060d6f5;
        if (((uVar1 & 0x110) != 0) && ((uVar2 & 0x110) != 0)) {
          if (((char)(&g_type_rank_table)[uVar5 & 0xf] <= (char)(&g_type_rank_table)[uVar2 & 0xf])
             && (((char)(&g_type_rank_table)[uVar5 & 0xf] < (char)(&g_type_rank_table)[uVar2 & 0xf]
                 || (((uVar1 & 0x2000) == 0 &&
                     ((((g_ms_extensions != '\0' || ((uVar5 & 0xfff) != 0x11)) ||
                       ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0'))))))))
          goto LAB_1060d6f5;
        }
      }
      else if (((bVar3 >> 5 & 1) != 0) &&
              ((char)(&g_type_rank_table)[uVar5 & 0xf] < (char)(&g_type_rank_table)[uVar2 & 0xf]))
      goto LAB_1060d6f5;
    }
  }
  type2 = type;
LAB_1060d6f5:
  pcVar4 = type2;
  if ((type2->code & 0x8f) == 0x83) {
    pcVar4 = type_skip_arrays(type2->base);
  }
  if ((pcVar4->flags & 0x1e0) != 0) {
    pcVar4 = type_strip_cv_qualifiers(type2);
    return pcVar4;
  }
  return type2;
}

