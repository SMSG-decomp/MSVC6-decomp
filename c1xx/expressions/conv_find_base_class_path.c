char __thiscall
conv_find_base_class_path
          (c1_conversion *conv,c1_symbol *source_class,c1_symbol *target_class,char flag)

{
  c1_symbol *pcVar1;
  
  if ((source_class->flags2 & 4) == 0) {
    tmpl_instantiate_if_needed(source_class);
  }
  if ((target_class->flags2 & 4) == 0) {
    tmpl_instantiate_if_needed(target_class);
  }
  if (((source_class->flags2 & 4) != 0) && ((target_class->flags2 & 4) != 0)) {
    pcVar1 = class_lookup_qualified_member(g_current_scope,source_class,target_class,0x80);
    conv->overload_set = pcVar1;
    if (pcVar1 != (c1_symbol *)0x0) {
      conv->flags4e = (flag & 1U | 4) << 3 | conv->flags4e & 0xf7;
      return '\x01';
    }
    if ((3 < conv->mode) && (conv->mode < 10)) {
      pcVar1 = class_lookup_qualified_member(g_current_scope,target_class,source_class,0x80);
      conv->overload_set = pcVar1;
      if (pcVar1 != (c1_symbol *)0x0) {
        conv->flags4e = (flag == '\0' | 4U) << 3 | conv->flags4e & 0xf7;
        return '\x01';
      }
    }
  }
  return '\0';
}

