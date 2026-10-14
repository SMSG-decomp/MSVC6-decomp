int __fastcall init_check_member_kind(c1_conversion *conv)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = (byte)conv->rank;
  do {
    if ((bVar1 & 0xf0) == 0x30) {
      return 0;
    }
    uVar2 = conv->target_class - 6;
    switch(uVar2) {
    case 2:
      if ((((conv->flags4e & 0x20) == 0) || (conv->overload_set == (c1_symbol *)0x0)) ||
         (uVar2 = sym_list_has_flagged_scope_entry((int)conv->overload_set), (char)uVar2 == '\0'))
      goto switchD_104483c9_caseD_1;
    case 0:
switchD_104483c9_caseD_0:
      return uVar2 & 0xffffff00;
    case 6:
      uVar2 = class_complete_type_of(conv->target);
      if (2 < (int)uVar2) {
        return uVar2 & 0xffffff00;
      }
    default:
switchD_104483c9_caseD_1:
      return CONCAT31((int3)(uVar2 >> 8),1);
    case 7:
      if (conv->source_class != 0) {
        uVar2 = class_complete_type_of(conv->target);
        if (1 < (int)uVar2) {
          return uVar2 & 0xffffff00;
        }
        goto switchD_104483c9_caseD_1;
      }
      conv = conv->first;
      break;
    case 8:
    case 9:
      uVar2 = conv->source_class;
      if ((uVar2 != 0) && ((conv->flags4e & 0x10) == 0)) goto switchD_104483c9_caseD_0;
      conv = conv->first;
      if (conv == (c1_conversion *)0x0) goto switchD_104483c9_caseD_1;
    }
    bVar1 = (byte)conv->rank;
  } while( true );
}

