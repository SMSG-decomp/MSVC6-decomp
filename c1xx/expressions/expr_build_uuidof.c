c1_node * __cdecl expr_build_uuidof(c1_type *type)

{
  c1_type *pcVar1;
  c1_symbol *pcVar2;
  c1_guid *guid;
  fe_name *name;
  c1_node *pcVar3;
  
  pcVar1 = type;
  if (type == (c1_type *)0x0) {
    return (c1_node *)0x0;
  }
  pcVar2 = type_class_symbol(type);
  if (pcVar2 == (c1_symbol *)0x0) {
    if (((g_compile_flags_c8 & 0x10000000) == 0) && ((g_compile_flags_cc & 0x300000) == 0)) {
      diag_error(0x312,pcVar1);
      return (c1_node *)0x0;
    }
  }
  else {
    type = (c1_type *)((uint)type & 0xffffff00);
    if ((pcVar2->flags21 & 0x40) != 0) {
      guid = sym_extra_record(pcVar2);
LAB_104997c2:
      name = guid_format_symbol_name(guid);
      pcVar2 = expr_uuidof_guid_symbol(name,guid);
      pcVar3 = expr_uuidof_guid_value(pcVar2);
      return pcVar3;
    }
    if ((((pcVar2->detail).cls)->flags3e & 1) != 0) {
      guid = expr_check_uuidof_unique(pcVar2,(c1_u8 *)&type);
      if (guid != (c1_guid *)0x0) goto LAB_104997c2;
      if ((char)type != '\0') {
        return (c1_node *)0x0;
      }
    }
    diag_error(0x313,pcVar2);
  }
  return (c1_node *)0x0;
}

