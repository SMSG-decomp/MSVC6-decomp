void __fastcall conv_compute_conversion(c1_conversion *conv)

{
  int iVar1;
  
  iVar1 = type_category(conv->source);
  conv->source_class = iVar1;
  iVar1 = type_category(conv->target);
  conv->target_class = iVar1;
  (*g_conversion_rules[conv->source_class * 0x10 + iVar1].handler)();
  conv->flags4e = (conv->rank != 0x70 ^ conv->flags4e) & 1 ^ conv->flags4e;
  return;
}

