void decl_check_modifier_over_reference_case80_fragment(c1_decl_record *rec,c1_type *layer)

{
  diag_error(0x211,rec->sym);
  layer->code = 0x82;
  rec->flags = rec->flags | 1;
  return;
}

