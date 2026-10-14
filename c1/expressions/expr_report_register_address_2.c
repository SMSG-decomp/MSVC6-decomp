c1_node * __cdecl expr_report_register_address_2(uint storage,c1_node *node,c1_type *type)

{
  c1_type *pcVar1;
  
  if ((byte)storage < 7) {
    diag_error(0x67,0x31);
    return node;
  }
  pcVar1 = type_pointer_with_qualifiers(type,0);
  node->type = pcVar1;
  return node;
}

