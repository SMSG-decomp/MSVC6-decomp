void __fastcall conv_rule_class_to_class(c1_conversion *conv)

{
  byte bVar1;
  c1_symbol *source_class;
  c1_symbol *target_class;
  bool bVar2;
  char cVar3;
  
  bVar1 = conv->mode;
  if ((bVar1 == 7) || (bVar1 == 8)) {
    conv->rank = 0x70;
    conv->note = 0x1796;
  }
  else {
    source_class = (conv->source->extra).cls;
    target_class = (conv->target->extra).cls;
    if ((source_class == target_class) && ((conv->flags & 8) != 0)) {
      conv->rank = 0;
      conv->note = 0x17d4;
      conv->build = conv_build_same_class;
      return;
    }
    bVar2 = false;
    if ((bVar1 != 1) && ((bVar1 < 4 || (6 < bVar1)))) {
      if ((source_class != target_class) &&
         (cVar3 = conv_find_base_class_path(conv,source_class,target_class,'\0'), cVar3 == '\0')) {
        conv_rule_converting_constructor(conv);
        conv_rule_conversion_function(conv);
        return;
      }
      bVar2 = true;
      conv->flags = conv->flags & 0xdf;
    }
    conv_rule_converting_constructor(conv);
    if ((conv->rank != 0x70) && (bVar2)) {
      conv->rank = -(uint)(source_class != target_class) & 0x20;
      return;
    }
  }
  return;
}

