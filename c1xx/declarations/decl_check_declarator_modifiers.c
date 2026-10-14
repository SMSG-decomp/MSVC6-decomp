void __fastcall decl_check_declarator_modifiers(c1_decl_record *rec)

{
  byte bVar1;
  c1_type *layer;
  
  bVar1 = (byte)rec->spec_type->code;
  if (-1 < (char)bVar1) {
    if (rec->chain_head != (c1_type *)0x0) {
      if ((bVar1 >> 6 & 1) != 0) {
        bVar1 = (byte)rec->chain_tail->code & 0x8f;
        if ((bVar1 == 0x80) || (bVar1 == 0x83)) {
          diag_error(0xb6,rec->sym);
          rec->flags = rec->flags | 1;
          rec->spec_type = g_type_int;
        }
        else if (bVar1 == 0x8a) {
          decl_check_declarator_void_fragment((int *)rec);
          return;
        }
      }
      if ((((rec->chain_tail->code & 0x8f) == 0x83) && ((rec->spec_type->code & 0x200) != 0)) &&
         ((((rec->spec_type->extra).cls)->flags5 & 1) != 0)) {
        diag_error(0xe9,rec->sym);
        rec->flags = rec->flags | 1;
      }
      rec->chain_tail->base = rec->spec_type;
    }
    return;
  }
  layer = type_descriptor_copy_transient(rec->spec_type);
  switch((byte)layer->code & 0x8f) {
  case 0x80:
  case 0x84:
    decl_check_modifier_over_reference(rec,layer);
    break;
  case 0x81:
  case 0x85:
    decl_append_derived_check(rec,layer);
    break;
  case 0x83:
    type_check_array_declarator(rec,layer);
  }
  if (rec->chain_tail != (c1_type *)0x0) {
    rec->chain_tail->base = layer;
    rec->chain_tail = layer;
    return;
  }
  rec->chain_tail = layer;
  rec->chain_head = layer;
  return;
}

