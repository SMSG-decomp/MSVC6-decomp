c1_node * __cdecl
expr_build_address_of_retype(byte storage,c1_symbol *sym,c1_node *node,c1_type *type)

{
  c1_type *pcVar1;
  
  if (storage < 7) {
    sym->storage = sym->storage & 0xf8 ^ 4;
  }
  pcVar1 = type_pointer_with_qualifiers(type,0);
  node->type = pcVar1;
  if (((byte)g_compile_flags_c8 & 4) != 0) {
    node->kind = node->kind | 0x20;
  }
  return node;
}

