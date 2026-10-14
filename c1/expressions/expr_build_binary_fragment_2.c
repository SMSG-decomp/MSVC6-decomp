c1_node * __cdecl expr_build_binary_fragment_2(byte kind_bits,c1_node *node)

{
  node->kind = node->kind | kind_bits;
  return node;
}

