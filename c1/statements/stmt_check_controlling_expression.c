void __cdecl stmt_check_controlling_expression(c1_node *cond,c1_node *target,uint jump_if_true)

{
  uint uVar1;
  byte bVar2;
  c1_node *pcVar3;
  
  while( true ) {
    if (((byte)cond->type->code >> 6 & 1) != 0) {
      diag_error(0xb4);
    }
    bVar2 = cond->kind & 7;
    if ((bVar2 == 3) || (bVar2 == 5)) {
      diag_warning(4,0x7f);
    }
    uVar1 = g_tree_op_to_il_op[cond->op];
    if (uVar1 != 0x1a) break;
    cond = cond->left;
    jump_if_true = (uint)(jump_if_true == 0);
  }
  if (uVar1 == 0x1b) {
    pcVar3 = target;
    if (jump_if_true == 0) {
      pcVar3 = label_new(*(int *)((int)target->left + 0x24));
    }
    stmt_check_controlling_expression(cond->left,pcVar3,1);
    stmt_check_controlling_expression(cond->right,target,jump_if_true);
    if (jump_if_true == 0) {
      label_emit_definition(pcVar3);
    }
  }
  else {
    if (uVar1 != 0x1c) {
      if ((cond->type->code & 0x200) != 0) {
        diag_error(0x53,cond->type);
        return;
      }
      il_emit_pragma_or_segment_record(0x24);
      il_emit_expression_tree(cond);
      il_emit_tuple((jump_if_true != 0) + 0x38,target);
      return;
    }
    pcVar3 = target;
    if (jump_if_true != 0) {
      pcVar3 = label_new(*(int *)((int)target->left + 0x24));
    }
    stmt_check_controlling_expression(cond->left,pcVar3,0);
    stmt_check_controlling_expression(cond->right,target,jump_if_true);
    if (jump_if_true != 0) {
      label_emit_definition(pcVar3);
      return;
    }
  }
  return;
}

