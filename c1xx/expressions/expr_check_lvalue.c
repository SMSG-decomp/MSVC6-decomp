c1_node * __cdecl expr_check_lvalue(c1_node *node,c1_type *type)

{
  byte bVar1;
  ushort uVar2;
  c1_type *pcVar3;
  
  uVar2 = node->type->code;
  if (((-1 < (char)uVar2) || ((uVar2 = uVar2 & 0x8f, uVar2 != 0x86 && (uVar2 != 0x82)))) &&
     ((bVar1 = (byte)node->type->code, -1 < (char)bVar1 || ((bVar1 & 0x8f) != 0x80)))) {
    diag_error(0x66,0x31);
    return (c1_node *)0x0;
  }
  pcVar3 = type_pointer_with_qualifiers(type,0);
  node->type = pcVar3;
  if (((byte)g_compile_flags_c8 & 4) != 0) {
    node->kind = node->kind | 0x20;
  }
  return node;
}

