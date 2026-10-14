c1_node * __cdecl expr_build_bool_increment(c1_u8 op,c1_node *operand,c1_node *rhs)

{
  char cVar1;
  c1_node *pcVar2;
  uint uVar3;
  c1_node *left;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_node *local_c;
  void *visitor;
  int visitor_mask;
  
  pcVar2 = expr_lvalue_address(operand,1);
  if (pcVar2 == (c1_node *)0x0) {
    diag_error(0x69,op);
    return (c1_node *)0x0;
  }
  pcVar5 = (c1_node *)0x0;
  pcVar4 = pcVar2;
  if (pcVar2->op == '5') {
    pcVar4 = pcVar2->left;
    pcVar5 = pcVar2;
  }
  local_c = (c1_node *)0x0;
  visitor_mask = 0xff;
  visitor = &g_side_effect_visitor_vtable;
  cVar1 = tree_has_side_effects((c1_tree_visitor *)&visitor,pcVar4);
  if (cVar1 != '\0') {
    if ((g_bool_pointer_type_guard & 1) == 0) {
      g_bool_pointer_type_guard = g_bool_pointer_type_guard | 1;
      PTR_104d22f4 = type_pointer_with_qualifiers(g_type_bool,0);
    }
    uVar3 = sym_new_local_key();
    left = tree_new_leaf_9c(uVar3,PTR_104d22f4);
    local_c = tree_new_binary('4',left,pcVar4);
    pcVar4 = tree_new_leaf_9c(uVar3,PTR_104d22f4);
    pcVar4 = tree_new_unary('=',PTR_104d22f4,pcVar4);
  }
  if (pcVar5 != (c1_node *)0x0) {
    pcVar4 = tree_new_binary('5',pcVar4,pcVar5->right);
  }
  pcVar5 = tree_copy_to_arena(pcVar4,g_expr_arena_index);
  pcVar5 = tree_new_unary('=',g_type_bool,pcVar5);
  uVar3 = (uint)op;
  switch(uVar3) {
  case 0x33:
  case 0x3a:
  case 0x42:
  case 0x47:
  case 0x49:
  case 0x4b:
  case 0x4e:
  case 0x52:
  case 0x57:
  case 0x5c:
    switch((&BYTE_1047fb1d)[uVar3]) {
    case 0:
      operand._0_1_ = '1';
      break;
    case 1:
      operand._0_1_ = '9';
      break;
    case 2:
      operand._0_1_ = 'C';
      break;
    case 3:
      operand._0_1_ = 'F';
      break;
    case 4:
      operand._0_1_ = 'H';
      break;
    case 5:
      operand._0_1_ = 'J';
      break;
    case 6:
      operand._0_1_ = 'M';
      break;
    case 7:
      operand._0_1_ = 'Q';
      break;
    case 8:
      operand._0_1_ = 'X';
      break;
    case 9:
      operand._0_1_ = '[';
      break;
    case 10:
      diag_fatal(1,".\\trees.c",0x507);
    }
    pcVar2 = expr_build_builtin_binary((c1_u8)operand,pcVar5,rhs);
    pcVar2 = conv_convert_expression(op,g_type_bool,pcVar2,'\x02','\0');
    pcVar2 = tree_new_binary('4',pcVar4,pcVar2);
    break;
  default:
    diag_fatal(1,".\\trees.c",0x5a9);
  case 0x38:
  case 0x54:
    diag_error(0x1ac,uVar3);
    return pcVar2;
  case 0x40:
    uVar3 = sym_new_local_key();
    pcVar2 = tree_new_leaf_9c(uVar3,g_type_bool);
    pcVar2 = tree_new_binary('4',pcVar2,pcVar5);
    pcVar4 = tree_new_binary_typed_right('7',pcVar2,pcVar4);
    pcVar2 = tree_new_leaf_9c(uVar3,g_type_bool);
    pcVar5 = tree_new_unary('=',g_type_bool,pcVar2);
  case 0x55:
    pcVar2 = tree_new_int_constant(1);
    pcVar2 = tree_new_binary('4',pcVar4,pcVar2);
    pcVar2 = tree_new_binary_typed_right('7',pcVar2,pcVar5);
  }
  if (local_c != (c1_node *)0x0) {
    pcVar2 = tree_new_binary_typed_right('7',local_c,pcVar2);
  }
  return pcVar2;
}

