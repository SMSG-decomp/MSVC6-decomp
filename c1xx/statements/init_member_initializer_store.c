int __cdecl init_member_initializer_store(int offset,ushort *type,c1_node *value,byte *member)

{
  ushort uVar1;
  bool bVar2;
  byte bVar3;
  c1_node *pcVar4;
  c1_type *type_00;
  c1_node *pcVar5;
  int iVar6;
  uint uVar7;
  c1_node *left;
  
  if (((char)(byte)*type < '\0') && (((byte)*type & 0x8f) == 0x80)) {
    uVar7 = init_value_is_class_call(value);
    if ((char)uVar7 != '\0') {
      diag_error(0x162,member);
      return 0;
    }
  }
  pcVar4 = expr_this_pointer((c1_symbol *)0x0);
  type_00 = type_with_storage_bits
                      ((c1_type *)type,
                       *(byte *)(((uint)pcVar4->type & -(uint)((pcVar4->type->code & 0x80) != 0)) +
                                2) & 0x18);
  pcVar5 = tree_new_int_constant(offset);
  pcVar4 = tree_new_node('S',pcVar4,pcVar5,type_00);
  if ((member != (byte *)0x0) && ((*member & 0x1f) == 2)) {
    pcVar5 = tree_new_int_constant((uint)member[0x29]);
    left = tree_new_int_constant((uint)member[0x28]);
    pcVar5 = tree_new_binary('6',left,pcVar5);
    pcVar4 = tree_new_binary('5',pcVar4,pcVar5);
    if (member[0x29] == 1) {
      bVar3 = pcVar4->flags | 4;
      pcVar4->flags = bVar3;
      uVar1 = pcVar4->type->code;
      if (((uVar1 & 0x2000) == 0) &&
         (((g_opt_J_unsigned_char == '\0' || (((byte)uVar1 & 0xf) != 1)) ||
          (((uVar1 & 0xfff) == 0x11 && ((uVar1 & 0x1000) != 0)))))) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      pcVar4->flags = (!bVar2 ^ bVar3) & 1 ^ bVar3;
    }
  }
  if ((g_token_class[value->op] == '`') && (value->right == (void *)0x0)) {
    value = value->left;
  }
  iVar6 = conv_check_copy_conversion(pcVar4,value);
  return iVar6;
}

