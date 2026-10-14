void __fastcall decl_parse_pointer_qualifiers(c1_specifier_state *spec)

{
  c1_u8 *pcVar1;
  ushort uVar2;
  c1_type *pcVar3;
  
  pcVar3 = spec->named_type;
  if (pcVar3 == (c1_type *)0x0) {
    if (spec->basic_type == 0) {
      if (spec->qualifiers == 0) {
        (spec->words).storage = (spec->words).storage | 0x10;
        spec->type = g_type_int;
        goto LAB_10606707;
      }
      spec->basic_type = 0x13;
    }
    else {
      pcVar1 = &(spec->words).flags8;
      *pcVar1 = *pcVar1 | 1;
    }
    pcVar3 = decl_basic_type_from_specifiers(spec->basic_type,spec->qualifiers);
    spec->type = pcVar3;
  }
  else {
    uVar2 = spec->qualifiers;
    if (uVar2 != 0) {
      if (spec->type_given == '\0') {
        if ((pcVar3->code & 0x8f) == 0x83) {
          pcVar3 = type_skip_arrays(pcVar3->base);
        }
        if ((pcVar3->flags & uVar2 & 0x3e0) != 0) {
          if (g_ms_extensions == '\0') {
            diag_error(0x121);
          }
          else {
            diag_warning(1,0x72);
          }
        }
      }
      if ((spec->named_type->code & 0x83) == 0x81) {
        diag_warning(1,0xb4);
        spec->qualifiers = 0;
        spec->type = spec->named_type;
        goto LAB_10606707;
      }
      pcVar3 = type_with_added_qualifiers(spec->named_type,spec->qualifiers);
    }
    spec->type = pcVar3;
  }
LAB_10606707:
  if ((spec->qualifiers & 0x300) != 0) {
    diag_error(0xdb);
  }
  return;
}

