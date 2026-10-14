c1_node * __cdecl conv_convert_to_type_fragment(c1_node *node,c1_type *type)

{
  node->type = type;
  node->kind = node->kind & 0x7f;
  return node;
}

