int __cdecl pm_value_may_be_null(char *node)

{
  c1_node *pcVar1;
  
  if ((node != (char *)0x0) && (*node == 'e')) {
    pcVar1 = expr_member_pointer_null_constant(*(c1_type **)(node + 4));
    if ((*(void **)(node + 0x10) != pcVar1->left) || (*(void **)(node + 0x14) != pcVar1->right)) {
      return 0;
    }
  }
  return 1;
}

