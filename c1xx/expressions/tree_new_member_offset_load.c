c1_node * __cdecl tree_new_member_offset_load(c1_node *left,c1_node *operand,c1_type *type)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_unary('=',(c1_type *)
                              **(undefined4 **)
                                (*(int *)(((uint)type & -(uint)((type->code & 0x80) != 0)) + 4) + 8)
                          ,operand);
  pcVar1 = tree_new_binary(0x99,left,pcVar1);
  return pcVar1;
}

