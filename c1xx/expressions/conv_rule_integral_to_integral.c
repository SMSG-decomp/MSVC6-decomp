void __fastcall conv_rule_integral_to_integral(c1_conversion *conv)

{
  ushort uVar1;
  ushort uVar2;
  
  if ((6 < conv->mode) && (conv->mode < 10)) {
    conv->rank = 0x70;
    conv->note = 0x1773;
    return;
  }
  uVar1 = conv->target->code;
  uVar2 = conv->source->code;
  if (((uVar1 & 0xfff) == 0x10) && ((uVar2 & 0xfff) != 0x10)) {
    conv->build = conv_build_to_bool;
  }
  else {
    conv->build = conv_build_integral_conversion;
    conv->build_constant = conv_build_integral_constant;
  }
  if (uVar2 != uVar1) {
    if ((((((byte)uVar1 & 0x1f) == 0x13) && ((uVar1 & 0x2000) == 0)) &&
        (((g_opt_J_unsigned_char == '\0' || (((byte)uVar1 & 0xf) != 1)) ||
         (((uVar1 & 0xfff) == 0x11 && ((uVar1 & 0x1000) != 0)))))) &&
       (((char)(&g_type_rank_table)[uVar2 & 0xf] < '\x04' ||
        (((uVar2 & 0x100) != 0 ||
         (((&g_type_rank_table)[uVar2 & 0xf] == (&g_type_rank_table)[uVar1 & 0xf] &&
          (((uVar2 ^ uVar1) & 0x3000) == 0)))))))) {
      conv->rank = 0x10;
      conv->note = 0x17d5;
      return;
    }
    conv->rank = 0x20;
    conv->note = 0x17d7;
    return;
  }
  conv->rank = 0;
  conv->note = 0x17d4;
  return;
}

