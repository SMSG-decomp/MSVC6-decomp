c1_node * __cdecl property_build_access(c1_u8 op,c1_node *node,c1_node *value)

{
  c1_symbol *key;
  c1_node *right;
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_symbol **accessors;
  c1_node *pcVar3;
  uint entity;
  c1_node *object;
  c1_node *left;
  c1_symbol *name;
  bool bVar4;
  c1_u8 op_00;
  
  right = node;
  bVar4 = value != (c1_node *)0x0;
  pcVar2 = node->right;
  pcVar3 = node->left;
  node = (c1_node *)0x0;
  pcVar1 = pcVar2;
  object = pcVar3;
  left = right;
  if (pcVar2->op == '`') {
    object = pcVar3->left;
    pcVar1 = pcVar3->right;
    left = pcVar3;
    node = pcVar2;
  }
  if (op == 'A') {
    pcVar2 = tree_append_list_item(node,value,2);
    pcVar2 = tree_new_binary(0xe8,left,pcVar2);
    return pcVar2;
  }
  key = pcVar1->left;
  accessors = symtab_1b40_lookup(key);
  if (bVar4) {
    switch(op) {
    case '1':
    case '2':
    case '7':
    case '9':
    case ';':
    case '<':
    case '>':
    case '?':
    case 'C':
    case 'D':
    case 'E':
    case 'F':
    case 'H':
    case 'J':
    case 'L':
    case 'M':
    case 'O':
    case 'Q':
    case 'X':
    case 'Y':
    case 'Z':
    case '[':
    case 't':
      goto switchD_10499042_caseD_31;
    case '3':
      op = '1';
      break;
    case '4':
      goto switchD_10499042_caseD_34;
    default:
      diag_fatal(1,".\\property.cpp",0x12d);
    case '8':
    case '@':
      entity = sym_new_local_key();
      pcVar2 = tree_new_leaf_9c(entity,key->type);
      pcVar2 = tree_new_binary('4',pcVar2,right);
      if (op == '@') {
        pcVar3 = tree_new_leaf_9c(entity,key->type);
        pcVar3 = tree_new_rvalue(pcVar3);
        op_00 = 'Q';
      }
      else {
        pcVar3 = tree_new_leaf_9c(entity,key->type);
        pcVar3 = tree_new_rvalue(pcVar3);
        op_00 = 'F';
      }
      pcVar3 = expr_build_binary(op_00,pcVar3,value);
      pcVar3 = expr_build_binary('4',right,pcVar3);
      if (pcVar3 != (c1_node *)0x0) {
        pcVar2 = tree_new_binary_typed_right('7',pcVar2,pcVar3);
        pcVar3 = tree_new_leaf_9c(entity,key->type);
        pcVar3 = tree_new_rvalue(pcVar3);
        pcVar2 = tree_new_binary_typed_right('7',pcVar2,pcVar3);
        return pcVar2;
      }
      return (c1_node *)0x0;
    case ':':
      op = '9';
      break;
    case 'B':
      op = 'C';
      break;
    case 'G':
    case 'T':
      op = 'F';
      break;
    case 'I':
      op = 'H';
      break;
    case 'K':
      op = 'J';
      break;
    case 'N':
      op = 'M';
      break;
    case 'R':
    case 'U':
      op = 'Q';
      break;
    case 'W':
      op = 'X';
      break;
    case '\\':
      op = '[';
    }
    value = expr_build_binary(op,right,value);
switchD_10499042_caseD_34:
    name = accessors[1];
  }
  else {
    name = *accessors;
  }
  if (name != (c1_symbol *)0x0) {
    pcVar2 = expr_prepare_member_access_object(g_current_scope,'S',object,'\x01');
    pcVar3 = expr_lookup_name_expression(name);
    pcVar2 = expr_build_member_access('S',pcVar2,pcVar3);
    if (bVar4) {
      pcVar3 = tree_append_list_item(node,value,2);
      pcVar2 = (c1_node *)expr_build_call(pcVar2,pcVar3);
      return pcVar2;
    }
    pcVar2 = (c1_node *)expr_build_call(pcVar2,node);
    return pcVar2;
  }
switchD_10499042_caseD_31:
  if (bVar4) {
    diag_error(0x306,key);
    return (c1_node *)0x0;
  }
  diag_error(0x307,key);
  return (c1_node *)0x0;
}

