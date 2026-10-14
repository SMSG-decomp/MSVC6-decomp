c1_symbol * __cdecl expr_lvalue_symbol_counting_calls(c1_node *node)

{
  c1_node *pcVar1;
  uint uVar2;
  
  g_callee_call_depth = 1;
  uVar2 = node->op - 6;
  if (0x6a < uVar2) {
switchD_1061dd2c_caseD_7:
    return (c1_symbol *)0x0;
  }
  do {
    switch((&switchD_1061dd2c::switchdataD_1061e124)[uVar2]) {
    case 6:
      return node->left;
    default:
      goto switchD_1061dd2c_caseD_7;
    case 0x36:
      pcVar1 = node->right;
      if (node->type != pcVar1->type) goto switchD_1061dd2c_caseD_41;
      goto LAB_1063416a;
    case 0x70:
      g_callee_call_depth = g_callee_call_depth + 1;
    case 0x41:
    case 0x50:
    case 0x5d:
switchD_1061dd2c_caseD_41:
      pcVar1 = node->left;
LAB_1063416a:
      uVar2 = pcVar1->op - 6;
      node = pcVar1;
      if (0x6a < uVar2) {
        return (c1_symbol *)0x0;
      }
    }
  } while( true );
}

