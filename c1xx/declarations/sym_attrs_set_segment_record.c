void __thiscall sym_attrs_set_segment_record(c1_symbol_attrs *attrs,c1_symbol *segment)

{
  if (segment == (c1_symbol *)0x0) {
    attrs->segment = (c1_symbol *)0x0;
    attrs->flags23 = attrs->flags23 & 0xfe;
    return;
  }
  attrs->segment = segment;
  attrs->flags23 = attrs->flags23 | 1;
  return;
}

