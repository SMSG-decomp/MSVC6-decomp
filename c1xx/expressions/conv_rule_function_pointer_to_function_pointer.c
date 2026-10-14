void __fastcall conv_rule_function_pointer_to_function_pointer(c1_conversion *conv)

{
  c1_u8 cVar1;
  char cVar2;
  c1_type *a;
  c1_type *b;
  
  a = type_base(conv->source);
  b = type_base(conv->target);
  cVar2 = type_compare_function(a,b,0);
  if (cVar2 != '\0') {
    conv->rank = 0;
    conv->build = conv_build_identity;
    conv->note = 0x17d4;
    return;
  }
  cVar1 = conv->mode;
  if (((cVar1 == '\a') || (cVar1 == '\x04')) || (cVar1 == '\x05')) {
    conv->rank = 0x50;
    conv->build = conv_apply_standard_conversion;
    conv->note_fn = conv_note_none;
    cVar2 = conv_function_cast_is_unsafe(conv,a,b,'\0');
    if (cVar2 != '\0') {
      diag_warning(3,0xbf,(uint)conv->op,conv->source,conv->target);
      return;
    }
  }
  else {
    conv->rank = 0x70;
    conv->note = 0x1787;
  }
  return;
}

