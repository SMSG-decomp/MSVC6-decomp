c1_symbol * __cdecl esu_check_tag_and_begin_enum(c1_symbol *sym,uint tag_code)

{
  c1_symbol *pcVar1;
  
  pcVar1 = class_check_tag_kind_consistency(sym,(c1_u16)tag_code);
  if (pcVar1 != (c1_symbol *)0x0) {
    if (((pcVar1->flags3 & 4) == 0) && ((tag_code & 0x100) != 0)) {
      g_current_enum_type = pcVar1->type;
      g_enum_value._0_4_ = 0xffffffff;
      g_enum_value._4_4_ = 0xffffffff;
      ((pcVar1->detail).cls)->size = 4;
      pcVar1->flags2 = pcVar1->flags2 | 4;
      g_current_enum = pcVar1;
    }
    return pcVar1;
  }
  return (c1_symbol *)0x0;
}

