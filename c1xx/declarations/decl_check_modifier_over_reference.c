void __thiscall decl_check_modifier_over_reference(c1_decl_record *rec,c1_type *layer)

{
  short n;
  
  if (rec->chain_head != (c1_type *)0x0) {
    switch((byte)rec->chain_tail->code & 0x8f) {
    case 0x80:
      n = 0x211;
      break;
    default:
      goto switchD_10432681_caseD_81;
    case 0x82:
      n = 0x210;
      break;
    case 0x83:
      n = 0xea;
      break;
    case 0x8a:
      n = 0x27c;
    }
    diag_error(n,rec->sym);
    layer->code = 0x82;
    rec->flags = rec->flags | 1;
  }
switchD_10432681_caseD_81:
  return;
}

