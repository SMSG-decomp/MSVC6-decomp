char __cdecl parse_begin_compound_value(c1_node *node)

{
  func_begin_compound_statement();
  if (node != (c1_node *)0x0) {
    node->kind = node->kind & 0xfe | 6;
  }
  return '\x01';
}

